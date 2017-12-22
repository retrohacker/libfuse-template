#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

FILE *OUTPUT = NULL;
log_level LOG_LEVEL = ERROR;

void set_log_level(log_level level) {
  LOG_LEVEL = level;
}

void set_log_output(FILE *target) {
  OUTPUT = target;
}

void logger(log_level level, char *s, ...) {
  if(level == OFF) {
    return;
  }
  if(level == DEBUG && LOG_LEVEL != DEBUG) {
    return;
  }
  if(level == WARN && (LOG_LEVEL != WARN && LOG_LEVEL != DEBUG)) {
    return;
  }
  if(OUTPUT == NULL) {
    return;
  }
  va_list args;
  va_start(args, s);
  vfprintf(OUTPUT, s, args);
  fflush(OUTPUT);
}
