#ifndef truncate_h
#define truncate_h
#include "./deps/liborion/orion.h" /* logger */
int o_truncate(const char* path, off_t size);
#endif
