#ifndef getattr_h
#define getattr_h
#include "./deps/liborion/orion.h" /* logger */
#include <sys/stat.h> /* stat */
int o_getattr(const char*, struct stat*);
#endif
