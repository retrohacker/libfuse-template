#ifndef chown_h
#define chown_h
#include "./logger.h" /* logger */
#include <unistd.h> /* uid_t gid_t */
int o_chown(const char*, uid_t, gid_t);
#endif
