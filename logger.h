#ifndef LOGGING_HEADERS
#define LOGGING_HEADERS
#include <stdio.h>
enum log_level_t { DEBUG, WARN, ERROR, OFF };
typedef enum log_level_t log_level;
void set_log_level(log_level level);
void set_log_output(FILE *level);
void logger(log_level, char *s, ...);
#endif
