#ifndef fsync_h
#define fsync_h
#include "./logger.h" /* logger */
#include <fuse.h> /* fuse_File_info */
int o_fsync(const char*, int, struct fuse_file_info*);
#endif
