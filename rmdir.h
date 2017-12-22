#ifndef rmdir_h
#define rmdir_h
#include "./deps/liborion/orion.h" /* logger */
#include <fuse.h> /* fuse_file_info */
int o_rmdir(const char*);
#endif
