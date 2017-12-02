#define FUSE_USE_VERSION 31
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

#include "./deps/liborion/orion.h"

// Directory is the passthrough directory we create for the filesystem
char* directory = "bar";
// Prefix is the directory aboved resolved to the cwd so it is an absolute path
char* prefix = NULL;

char* resolve_prefix(const char* path) {
  long long path_len = strlen(path);
  long long prefix_len = strlen(prefix);
  long long result_len = path_len + prefix_len + 1;
  char* result = malloc(result_len * sizeof(char));
  strcpy(result, prefix);
  if(path[path_len - 1] != '/') {
    strcat(result, "/");
  }
  strcat(result, path);
  return result;
}

static void* o_init(struct fuse_conn_info *conn) {
  logger(DEBUG, "Creating the directory %s for passhthrough\n", prefix);
  int res = mkdir(prefix, 0777);
  if(res == -1) {
    logger(DEBUG, "Failed to create directory due to %s\n", strerror(errno));
    if(errno != EEXIST) {
      exit(1);
    }
    logger(DEBUG, "Directory already existed, continuing execution\n");
  }
  logger(DEBUG, "Orion started\n");
}

static int o_getattr(const char* path, struct stat *sbuf) {
  char* prefixed_path = resolve_prefix(path);
  logger(DEBUG, "lstat: %s\n", prefixed_path);
  int res = lstat(prefixed_path, sbuf);
  if(res == -1) {
    logger(ERROR, "Failed to lstat: %s %s\n", strerror(errno), prefixed_path);
    free(prefixed_path);
    return -errno;
  }
  free(prefixed_path);
  return 0;
}

static int o_access(const char* path, int mode) {
  char* prefixed_path = resolve_prefix(path);
  int res = access(prefixed_path, mode);
  free(prefixed_path);
  return res;
}

static int o_readdir(
  const char* path, void* buf, fuse_fill_dir_t filler, off_t offset,
  struct fuse_file_info* fi
) {
  logger(DEBUG, "Calling readdir\n");
  DIR *dp;
  struct dirent *de;

  dp = opendir(path);
  if(dp = NULL) {
    logger(ERROR, "Failed to open dir %s: %s\n", path, strerror(errno));
    return -errno;
  }

  while((de = readdir(dp)) != NULL) {
    logger(DEBUG, "Found %s\n", de->d_name);
    struct stat st;
    st.st_ino = de->d_ino;
    st.st_mode = de->d_type;
    if(filler(buf, de->d_name, &st, 0)) {
      break;
    }
  }

  closedir(dp);
  return 0;
}

static struct fuse_operations ops = {
  .init = o_init,
  .getattr = o_getattr,
  .access = o_access,
  .readdir = o_readdir,
};

int main(int argc, char** argv) {
  set_log_level(DEBUG);
  set_log_output(stdout);
  long long cwd_len = 0;
  char* cwd = NULL;
  do {
    cwd_len += 10;
    logger(DEBUG, "Attempting to copy cwd into buffer of size %lld\n", cwd_len);
    if(cwd != NULL) {
      free(cwd);
    }
    cwd = malloc(cwd_len * sizeof(char));
    errno = 0;
    getcwd(cwd, cwd_len * sizeof(char));
    logger(DEBUG, "%s\n", strerror(errno));
  } while(errno == ERANGE);
  cwd_len = strlen(cwd);
  logger(DEBUG, "Started in directory: %s (%lld)\n", cwd, cwd_len);
  long long directory_len = strlen(directory);
  long long prefix_len = cwd_len + directory_len + 2;
  prefix = malloc(prefix_len * sizeof(char));
  strcpy(prefix, cwd);
  strcat(prefix, "/");
  strcat(prefix, directory);
  logger(DEBUG, "Mounting orion at %s\n", argv[2]);

  return fuse_main(argc, argv, &ops, NULL);
}
