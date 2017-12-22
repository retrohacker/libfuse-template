#ifndef fsyncdir_h
#define fsyncdir_h
#include <fuse.h> /* fuse_file_info */
#include "./deps/liborion/orion.h" /* logger */
int o_fsyncdir(const char*, int, struct fuse_file_info*);
#endif
