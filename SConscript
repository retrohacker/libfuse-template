# LIBS will hold all of the libraries we want to link against
LIBS = []
# LIBPATH will hold where those LIBS live
LIBPATH = []
# Flags to pass to GCC
CCFLAGS = []

# Add fuse
LIBS.extend(["fuse"])
CCFLAGS.extend(["-D_FILE_OFFSET_BITS=64"])
CCFLAGS.extend(["-D FUSE_USE_VERSION=31"])


# Add liborion
LIBS.extend(["orion"])
LIBPATH.extend(["./deps/liborion"])
SConscript("./deps/liborion/SConscript")

# Tell scons about everything we setup above
env = Environment(LIBS = LIBS, LIBPATH = LIBPATH, CCFLAGS = CCFLAGS)

env.Program("orion", [
    "readdir.c",
    "access.c",
    "getattr.c",
    "prefix.c",
    "init.c",
    "index.c"
])
