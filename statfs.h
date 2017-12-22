#ifndef statfs_h
#define statfs_h
#include "./deps/liborion/orion.h" /* logger */
#include <sys/statvfs.h> /* statvfs */
int o_statfs(const char*, struct statvfs*);
#endif
