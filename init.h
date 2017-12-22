#ifndef init_h
#define init_h
#include "./logger.h" /* logger */
#include <fuse.h> /* fuse_conn_info */
void* o_init(struct fuse_conn_info*);
#endif
