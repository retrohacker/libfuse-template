#ifndef fsyncdir_h
#define fsyncdir_h
#include "./logger.h" /* logger */
#include <fuse.h> /* fuse_file_info */
int o_fsyncdir(const char*, int, struct fuse_file_info*);
#endif
