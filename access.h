#ifndef access_h
#define access_h
#include "./prefix.h" /* resolve_prefix */
#include "./deps/liborion/orion.h" /* logger */
#include <unistd.h> /* access */
int o_access(const char*, int);
#endif
