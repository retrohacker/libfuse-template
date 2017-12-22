#include "getattr.h"

int o_getattr(const char* path, struct stat* sbuf) {
  logger(ERROR, "UNIMPLEMENTED: getattr, path: %s\n", path);
  return -1;
}

