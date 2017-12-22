#ifndef opendir_h
#define opendir_h
#include <fuse.h> /* fuse_file_info */
#include "./deps/liborion/orion.h" /* logger */
int o_opendir(const char*, struct fuse_file_info*);
#endif
