#include "prefix.h" /* prefix directory cwd */

char* directory = "bar";
char* prefix = NULL;
char* cwd = NULL;

char* resolve_prefix(const char* path) {
  long long path_len = strlen(path);
  long long prefix_len = strlen(prefix);
  long long result_len = path_len + prefix_len + 1;
  char* result = malloc(result_len * sizeof(char));
  strcpy(result, prefix);
  strcat(result, path);
  return result;
}

void generate_prefix() {
  long long cwd_len = 0;
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
}
