#ifndef lock_h
#define lock_h
#include <fuse.h> /* fuse_file_info */
#include "./deps/liborion/orion.h" /* logger */
int o_lock(const char*, struct fuse_file_info*, int, struct flock*);
#endif
