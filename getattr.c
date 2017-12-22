#include "getattr.h"

int o_getattr(const char* path, struct stat* sbuf) {
  char* prefixed_path = resolve_prefix(path);
  logger(DEBUG, "getattr: %s\n", prefixed_path);
  int res = lstat(prefixed_path, sbuf);
  if(res == -1) {
    logger(ERROR, "getattr: %s %s\n", strerror(errno), prefixed_path);
    return -errno;
  }
  return 0;
}

