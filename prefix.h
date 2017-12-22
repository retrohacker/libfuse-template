#ifndef prefix_h
#define prefix_h
#include "./logger.h" /* logger */
#include <string.h> /* strlen strcat strcpy */
#include <unistd.h> /* getcwd */
#include <stdlib.h> /* malloc free */
#include <string.h> /* strcat strcpy */
#include <errno.h> /* errno */
// Directory is the passthrough directory we create for the filesystem
char* directory;
// Prefix is the directory aboved resolved to the cwd so it is an absolute path
char* prefix;
// The current working directory for the process
char* cwd;
char* resolve_prefix(const char*);
void generate_prefix();
#endif
