#ifndef readdir_h
#define readdir_h
#include "./prefix.h" /* resolve_prefix */
#include "./deps/liborion/orion.h" /* logger */
#include <fuse.h> /* fuse_fill_dir_t fuse_file_info */
#include <dirent.h> /* DIR opendir */
#include <string.h> /* strerror */
#include <errno.h> /* errno */
int o_readdir(
    const char*, void*, fuse_fill_dir_t, off_t, struct fuse_file_info*);
#endif