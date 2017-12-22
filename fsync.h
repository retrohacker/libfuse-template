#ifndef fsync_h
#define fsync_h
#include <fuse.h> /* fuse_File_info */
#include "./deps/liborion/orion.h" /* logger */
int o_fsync(const char*, int, struct fuse_file_info*);
#endif
