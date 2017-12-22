#include "utimens.h"

int o_utimens(const char* path, const struct timespec ts[2]) {
  logger(ERROR, "UNIMPLEMENTED: utimens\n");
  return -1;
}
