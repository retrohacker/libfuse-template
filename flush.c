#include "flush.h"

int o_flush(const char* path, struct fuse_file_info* fi) {
  logger(ERROR, "UNIMPLEMENTED: flush\n");
  return -1;
}
