#include "./mkdir.h"

int o_mkdir(const char* path, mode_t mode) {
  logger(
    ERROR,
    "UNIMPLEMENTED: mkdir, path: %s, mode: %lo\n",
    path,
    (unsigned long) mode
  );
  return -1;
}
