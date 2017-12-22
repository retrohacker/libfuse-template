#ifndef utimens_h
#define utimens_h
#include "./logger.h" /* logger */
#include <fuse.h> /* fuse_file_info */
int o_utimens(const char*, const struct timespec[2]);
#endif
