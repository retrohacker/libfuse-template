#ifndef open_h
#define open_h
#include "./logger.h" /* logger */
#include <fuse.h> /* fuse_file_info */
int o_open(const char*, struct fuse_file_info*);
#endif
