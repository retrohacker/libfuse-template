#ifndef open_h
#define open_h
#include <fuse.h> /* fuse_file_info */
#include "./deps/liborion/orion.h" /* logger */
int o_open(const char*, struct fuse_file_info*);
#endif
