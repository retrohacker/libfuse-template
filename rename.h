#ifndef rename_h
#define rename_h
#include "./logger.h" /* logger */
#include <fuse.h> /* fuse_file_info */
int o_rename(const char*, const char*);
#endif
