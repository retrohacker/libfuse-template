#ifndef flush_h
#define flush_h
#include <fuse.h> /* fuse_file_info */
#include "./deps/liborion/orion.h" /* logger */
int o_flush(const char* path, struct fuse_file_info* fi);
#endif
