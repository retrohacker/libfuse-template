#include "releasedir.h"

int o_releasedir(const char* path, struct fuse_file_info* fi) {
  logger(ERROR, "UNIMPLEMENTED: releasedir, path: %s\n", path);
  return -1;
}
