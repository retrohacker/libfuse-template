#ifndef chmod_h
#define chmod_h
#include <sys/stat.h> /* mode_t */
#include "./deps/liborion/orion.h" /* logger */
int o_chmod(const char*, mode_t);
#endif
