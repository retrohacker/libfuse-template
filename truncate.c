#include "truncate.h"

int o_truncate(const char* path, off_t size) {
  logger(ERROR, "UNIMPLEMENTED: truncate, path: %s\n", path);
  return -1;
}
