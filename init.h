#ifndef init_h
#define init_h
#include "./deps/liborion/orion.h" /* logger */
#include <fuse.h> /* fuse_conn_info */
void* o_init(struct fuse_conn_info*);
#endif
