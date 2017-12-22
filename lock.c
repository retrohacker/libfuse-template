#include "lock.h"

int o_lock(
    const char* path,
    struct fuse_file_info* fi,
    int cmd,
    struct flock* locks
) {
  logger(ERROR, "UNIMPLEMENTED: lock\n");
  return -1;
}
