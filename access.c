#include "access.h"

int o_access(const char* path, int mode) {
  char* prefixed_path = resolve_prefix(path);
  logger(DEBUG, "access: %s\n", prefixed_path);
  int res = access(prefixed_path, mode);
  return res;
}
