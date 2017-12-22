#ifndef getattr_h
#define getattr_h
#include "./prefix.h" /* resolve_prefix */
#include "./deps/liborion/orion.h" /* logger */
#include <sys/stat.h> /* lstat stat */
#include <string.h> /* strerror */
#include <errno.h> /* errno */
int o_getattr(const char*, struct stat*);
#endif
