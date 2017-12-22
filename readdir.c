#include "readdir.h"

int o_readdir(
  const char* path, void* buf, fuse_fill_dir_t filler, off_t offset,
  struct fuse_file_info* fi
) {
  logger(ERROR, "UNIMPLEMENTED: readdir, path: %s\n", path);
  return -1;
}
