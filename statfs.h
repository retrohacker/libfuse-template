#ifndef statfs_h
#define statfs_h
#include <sys/statvfs.h> /* statvfs */
#include "./deps/liborion/orion.h" /* logger */
int o_statfs(const char*, struct statvfs*);
#endif
