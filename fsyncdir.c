#include "fsyncdir.h"

int o_fsyncdir(const char* path, int isdatasync, struct fuse_file_info* fi) {
  logger(ERROR, "UNIMPLEMENTED: fsyncdir, path: %s\n", path);
  return -1;
}
