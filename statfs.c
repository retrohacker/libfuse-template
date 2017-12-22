#include "statfs.h"

int o_statfs(const char* path, struct statvfs* stbuf) {
  logger(ERROR, "UNIMPLEMENTED: statfs\n");
  return -1;
}
