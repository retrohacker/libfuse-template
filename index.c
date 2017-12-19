#include "./prefix.h" /* resolve_prefix generate_prefix */
#include "./init.h" /* o_init */
#include "./getattr.h" /* o_getattr */
#include "./access.h" /* o_access */
#include "./readdir.h" /* o_readdir */

#include <fuse.h> /* fuse_main */

#include "./deps/liborion/orion.h" /* set_log_level set_log_output logger */

static struct fuse_operations ops = {
  .init = o_init,
  .getattr = o_getattr,
  .access = o_access,
  .readdir = o_readdir,
};

int main(int argc, char** argv) {
  set_log_level(DEBUG);
  set_log_output(stdout);
  generate_prefix();
  logger(DEBUG, "Mounting orion at %s\n", argv[2]);

  return fuse_main(argc, argv, &ops, NULL);
}
