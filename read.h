#ifndef read_h
#define read_h
#include "./deps/liborion/orion.h" /* logger */
#include <fuse.h> /* fuse_file_info */
int o_read(const char*, char*, size_t, off_t, struct fuse_file_info*);
#endif
