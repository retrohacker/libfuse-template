#include "opendir.h"

int o_opendir(const char* path, struct fuse_file_info* fi) {
  logger(ERROR, "UNIMPLEMENTED: opendir\n");
  return -1;
}
