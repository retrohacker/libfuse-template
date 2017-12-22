#ifndef lock_h
#define lock_h
#include "./deps/liborion/orion.h" /* logger */
#include <fuse.h> /* fuse_file_info */
int o_lock(const char*, struct fuse_file_info*, int, struct flock*);
#endif
