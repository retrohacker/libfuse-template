#include "init.h"

void* o_init(struct fuse_conn_info* conn) {
  logger(DEBUG, "Creating the directory %s for passhthrough\n", prefix);
  int res = mkdir(prefix, 0777);
  if(res == -1) {
    logger(DEBUG, "Failed to create directory due to %s\n", strerror(errno));
    if(errno != EEXIST) {
      exit(1);
    }
    logger(DEBUG, "Directory already existed, continuing execution\n");
  }
  logger(DEBUG, "Orion started\n");
}
