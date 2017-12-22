#ifndef release_h
#define release_h
#include "./logger.h" /* logger */
#include <fuse.h> /* fuse_file_info */
int o_release(const char*, struct fuse_file_info*);
#endif
