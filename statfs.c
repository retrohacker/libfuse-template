#include "statfs.h"

int o_statfs(const char* path, struct statvfs* stbuf) {
  logger(ERROR, "UNIMPLEMENTED: statfs, path: %s\n", path);
  return -1;
}
