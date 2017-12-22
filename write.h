#ifndef write_h
#define write_h
#include "./deps/liborion/orion.h" /* logger */
#include <fuse.h> /* fuse_file_info */
int o_write(const char*, const char*, size_t, off_t, struct fuse_file_info*);
#endif
