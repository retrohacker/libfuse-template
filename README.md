# libfuse template

This template is a jumping off point for those interested in implementing a
libfuse filesystem in C!

The repository has been structure so that each fuse operation lives in it's own
file. For getting started, we have stubbed out each operation and have included
a simple logger that let's you know when these stubs are being called. This
should give you a good understanding of what order you need to implement
operations in, simply start playing around with the filesystem and implement
whatever stubs you see being activated!

# Building

This project uses [scons](http://scons.org/) for building. Scons is a super
simple build tool for compiling C, it can be much easier to read compared to a
Makefile, plus it is 100% python so you can do as much or as little with it as
you like. The philosophy of this template was to keep the build tooling simple,
so that it stayed out of the way when trying to build a filesystem. Scons
allows us to do that!

## Dependencies

* gcc
* [libfuse-dev](https://packages.debian.org/wheezy/libfuse-dev) or [osxfuse](https://osxfuse.github.io/)
* scons

## Building

Once the dependencies are installed, compiling should be simple!

```
$ scons
scons: Reading SConscript files ...
scons: done reading SConscript files.
scons: Building targets ...
gcc -o access.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" access.c
gcc -o chmod.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" chmod.c
gcc -o chown.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" chown.c
gcc -o destroy.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" destroy.c
gcc -o flush.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" flush.c
gcc -o fsync.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" fsync.c
gcc -o fsyncdir.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" fsyncdir.c
gcc -o getattr.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" getattr.c
gcc -o index.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" index.c
gcc -o init.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" init.c
gcc -o lock.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" lock.c
gcc -o logger.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" logger.c
gcc -o mkdir.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" mkdir.c
gcc -o open.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" open.c
gcc -o opendir.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" opendir.c
gcc -o prefix.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" prefix.c
gcc -o read.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" read.c
gcc -o readdir.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" readdir.c
gcc -o release.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" release.c
gcc -o releasedir.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" releasedir.c
gcc -o rename.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" rename.c
gcc -o rmdir.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" rmdir.c
gcc -o statfs.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" statfs.c
gcc -o truncate.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" truncate.c
gcc -o unlink.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" unlink.c
gcc -o utimens.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" utimens.c
gcc -o write.o -c -D_FILE_OFFSET_BITS=64 "-D FUSE_USE_VERSION=26" write.c
gcc -o fuse access.o chmod.o chown.o destroy.o flush.o fsync.o fsyncdir.o getattr.o index.o init.o lock.o logger.o mkdir.o open.o opendir.o prefix.o read.o readdir.o release.o releasedir.o rename.o rmdir.o statfs.o truncate.o unlink.o utimens.o write.o -lfuse
scons: done building targets.
```

## Cleanup

To remove all build files, simply:

```
$ scons -c
scons: Reading SConscript files ...
scons: done reading SConscript files.
scons: Cleaning targets ...
Removed access.o
Removed chmod.o
Removed chown.o
Removed destroy.o
Removed flush.o
Removed fsync.o
Removed fsyncdir.o
Removed getattr.o
Removed index.o
Removed init.o
Removed lock.o
Removed logger.o
Removed mkdir.o
Removed open.o
Removed opendir.o
Removed prefix.o
Removed read.o
Removed readdir.o
Removed release.o
Removed releasedir.o
Removed rename.o
Removed rmdir.o
Removed statfs.o
Removed truncate.o
Removed unlink.o
Removed utimens.o
Removed write.o
Removed fuse
scons: done cleaning targets.
```

# Running

If you look at `index.c`, you can see `fuse_main` from libfuse itself will
parse arguments passed to the binary. This allows us to pass the `-f` flag
(foreground so we can see the logs) and the mountpoint (the directory to mount
the filesystem too).

```
$ ./fuse -f foo
Attempting to copy cwd into buffer of size 10
Result too large
Attempting to copy cwd into buffer of size 20
Result too large
Attempting to copy cwd into buffer of size 30
Result too large
Attempting to copy cwd into buffer of size 40
Undefined error: 0
Started in directory: /Users/wblankenship/Development/orionfs (39)
Mounting fuse at foo
UNIMPLEMENTED: init
UNIMPLEMENTED: statfs, path: /
UNIMPLEMENTED: getattr, path: /
UNIMPLEMENTED: getattr, path: /
UNIMPLEMENTED: getattr, path: /.MobileBackups
UNIMPLEMENTED: getattr, path: /
UNIMPLEMENTED: getattr, path: /.MobileBackups.trash
UNIMPLEMENTED: getattr, path: /
UNIMPLEMENTED: getattr, path: /.MobileBackups.trash
UNIMPLEMENTED: statfs, path: /
UNIMPLEMENTED: statfs, path: /
UNIMPLEMENTED: statfs, path: /
UNIMPLEMENTED: getattr, path: /
UNIMPLEMENTED: getattr, path: /
UNIMPLEMENTED: getattr, path: /
UNIMPLEMENTED: destroy
```

This will start the fuse binary in the foreground and bind it to the directory
`./foo`.

To stop it, simply hit `ctrl-c`.

# Gotchas

## Current Working Directory

`fuse_main` has a somewhat frustrating behaviour. It behaves in two different
ways depending on whether or not you start it in the foreground or not. In the
background, it will change the current working directory when invoked. It
doesn't do this when in the foreground, This has the nasty side effect of
creating bugs that only happen when you aren't looking at stdout!

To help with this case, we included the file `./prefix.c` which allows us to
capture the current working directory prior to starting fuse.

## Free dynamic memory

If you use `resolve_prefix` you need to call `free` on the returned string, otherwise your application will leak memory.

# Files

* `index.c` - Configures and starts the fuse filesystem
* `Sconscript` - Handles building the binary
* `prefix.{c,h}` - Handles capturing the current working directory at start
* `logger.{c,h}` - A super simple logger supporting writing to stdout or a file
* Everything else maps to a fuse operation!

# Documentation

There is a handy [doxygen
site](http://libfuse.github.io/doxygen/include_2fuse_8h.html) for libfuse,
however it only tracks the latest release which probably doesn't match what you
are going to be developing against. Luckily, the doxygen site is generated
directly from the source code, so we can still find the documentation we need.
On GitHub, libfuse tags releases. The release number X.Y.Z corresponds to the
`FUSE_USE_VERSION=XY`, so `26` would be `2.6.Z` where `Z` is the highest
released version. Choose the tag for your release (we link to `26` here) and
you are set!

For the documentation for each of the fuse operations (i.e. `getattr`) refer to
the declaration in
[`fuse.h`](https://github.com/libfuse/libfuse/blob/fuse_2_6_5/include/fuse.h#L299)

For `fuse_file_info`, refere to the declaration in
[`fuse_common.h`](https://github.com/libfuse/libfuse/blob/fuse_2_6_5/include/fuse_common.h#L37)

The top level fuse functions (i.e. `fuse_main`) are all in [`fuse.h`](https://github.com/libfuse/libfuse/blob/fuse_2_6_5/include/fuse.h)
