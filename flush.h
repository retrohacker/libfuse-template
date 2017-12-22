#ifndef flush_h
#define flush_h
#include "./logger.h" /* logger */
#include <fuse.h> /* fuse_file_info */
int o_flush(const char* path, struct fuse_file_info* fi);
#endif
