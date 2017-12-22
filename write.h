#ifndef write_h
#define write_h
#include <fuse.h> /* fuse_file_info */
#include "./deps/liborion/orion.h" /* logger */
int o_write(const char*, const char*, size_t, off_t, struct fuse_file_info*);
#endif
