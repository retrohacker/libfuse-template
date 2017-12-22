#include "utimens.h"

int o_utimens(const char* path, const struct timespec ts[2]) {
  logger(ERROR, "UNIMPLEMENTED: utimens, path: %s\n", path);
  return -1;
}
