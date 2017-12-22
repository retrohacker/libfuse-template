#include "read.h"

int o_read(
    const char* path,
    char *buf,
    size_t size,
    off_t offset,
    struct fuse_file_info* fi
) {
  logger(ERROR, "UNIMPLEMENTED: read, path: %s\n", path);
  return -1;
}
