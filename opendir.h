#ifndef opendir_h
#define opendir_h
#include "./deps/liborion/orion.h" /* logger */
#include <fuse.h> /* fuse_file_info */
int o_opendir(const char*, struct fuse_file_info*);
#endif
