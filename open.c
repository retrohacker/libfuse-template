#include "open.h"

int o_open(const char* path, struct fuse_file_info* fi) {
  logger(ERROR, "UNIMPLEMENTED: open, path: %s\n", path);
  return -1;
}
