#ifndef chmod_h
#define chmod_h
#include "./deps/liborion/orion.h" /* logger */
#include <sys/stat.h> /* mode_t */
int o_chmod(const char*, mode_t);
#endif
