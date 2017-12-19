#include "readdir.h"

int o_readdir(
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
