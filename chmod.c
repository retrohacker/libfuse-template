#include "chmod.h"

int o_chmod(const char* path, mode_t mode) {
  logger(
    ERROR,
    "UNIMPLEMENTED: chmod, path: %s, mode_t: %lo\n",
    path,
    (unsigned long) mode
  );
  return -1;
}
