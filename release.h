#ifndef release_h
#define release_h
#include <fuse.h> /* fuse_file_info */
#include "./deps/liborion/orion.h" /* logger */
int o_release(const char*, struct fuse_file_info*);
#endif
