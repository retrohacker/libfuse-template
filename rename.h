#ifndef rename_h
#define rename_h
#include <fuse.h> /* fuse_file_info */
#include "./deps/liborion/orion.h" /* logger */
int o_rename(const char*, const char*);
#endif
