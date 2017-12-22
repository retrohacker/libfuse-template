#include "write.h"

int o_write(
    const char* path,
    const char *buf,
    size_t size,
    off_t offset,
    struct fuse_file_info* fi
) {
  logger(ERROR, "UNIMPLEMENTED: write\n");
  return -1;
}
