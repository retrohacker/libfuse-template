#ifndef releasedir_h
#define releasedir_h
#include <fuse.h> /* fuse_file_info */
#include "./deps/liborion/orion.h" /* logger */
int o_releasedir(const char*, struct fuse_file_info*);
#endif
