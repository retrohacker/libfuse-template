#ifndef init_h
#define init_h
#include "./prefix.h" /* resolve_prefix */
#include "./deps/liborion/orion.h" /* logger */
#include <sys/stat.h> /* mkdir */
#include <errno.h> /* errno */
#include <fuse.h> /* fuse_conn_info */
#include <string.h> /* strerror */
#include <stdlib.h> /* exit */

void* o_init(struct fuse_conn_info*);
#endif
