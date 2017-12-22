#ifndef unlink_h
#define unlink_h
#include "./deps/liborion/orion.h" /* logger */
#include <fuse.h> /* fuse_file_info */
int o_unlink(const char* path);
#endif
