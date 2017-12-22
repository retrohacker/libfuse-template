#ifndef chown_h
#define chown_h
#include <unistd.h> /* uid_t gid_t */
#include "./deps/liborion/orion.h" /* logger */
int o_chown(const char*, uid_t, gid_t);
#endif
