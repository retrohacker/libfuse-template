#ifndef mkdir_h
#define mkdir_h
#include "./logger.h" /* logger */
#include <sys/stat.h> /* mode_t */
int o_mkdir(const char*, mode_t);
#endif
