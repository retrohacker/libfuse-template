#ifndef unlink_h
#define unlink_h
#include <fuse.h> /* fuse_file_info */
#include "./deps/liborion/orion.h" /* logger */
int o_unlink(const char* path);
#endif
