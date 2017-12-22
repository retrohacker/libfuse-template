# LIBS will hold all of the libraries we want to link against
LIBS = []
# LIBPATH will hold where those LIBS live
LIBPATH = []
# Flags to pass to GCC
CCFLAGS = []

# Add fuse
LIBS.extend(["fuse"])
CCFLAGS.extend(["-D_FILE_OFFSET_BITS=64"])
CCFLAGS.extend(["-D FUSE_USE_VERSION=26"])

# Tell scons about everything we setup above
env = Environment(LIBS = LIBS, LIBPATH = LIBPATH, CCFLAGS = CCFLAGS)

env.Program("fuse", Glob("*.c"))
