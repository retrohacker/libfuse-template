#ifndef utimens_h
#define utimens_h
#include <fuse.h> /* fuse_file_info */
#include "./deps/liborion/orion.h" /* logger */
int o_utimens(const char*, const struct timespec[2]);
#endif
