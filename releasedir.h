#ifndef releasedir_h
#define releasedir_h
#include "./logger.h" /* logger */
#include <fuse.h> /* fuse_file_info */
int o_releasedir(const char*, struct fuse_file_info*);
#endif
