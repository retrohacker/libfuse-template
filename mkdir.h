#ifndef mkdir_h
#define mkdir_h
#include <sys/stat.h> /* mode_t */
#include "./deps/liborion/orion.h" /* logger */
int o_mkdir(const char*, mode_t);
#endif
