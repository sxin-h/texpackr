ACLOCAL_AMFLAGS = -I m4

AM_CFLAGS = -Wall \
						-std=c99 \
						-O2 \
						-pedantic

# cli program
bin_PROGRAMS = texpackr
texpackr_CFLAGS = -I./include
texpackr_LDFLAGS = -lhashmap_c \
									 -lpng \
									 -lz
texpackr_SOURCES = src/lib.c \
									 src/cli.c \
									 src/meta.c \
									 src/png_util.c \
									 src/sprite.c \
									 src/treetrv.c

# lib
lib_LTLIBRARIES = libtexpackr.la
libtexpackr_la_CFLAGS = -I./include
libtexpackr_la_LDFLAGS = -no-defined -version-info 0:1:0 \
												 -lhashmap_c \
												 -lpng \
												 -lz
libtexpackr_la_SOURCES = src/lib.c \
												 src/meta.c \
												 src/png_util.c \
												 src/sprite.c \
												 src/treetrv.c

libtexpackrdir=$(includedir)/texpackr
libtexpackr_HEADERS = include/texpackr/internal.h \
									    include/texpackr/log.h \
									    include/texpackr/meta.h \
									    include/texpackr/png_util.h \
									    include/texpackr/sprite.h \
									    include/texpackr/texpackr.h \
									    include/texpackr/types.h

# tests program
check_PROGRAMS = test/tests
TESTS = $(check_PROGRAMS)
test_tests_SOURCES = test/test.c
test_tests_CFLAGS = -I./include
test_tests_LDFLAGS = -ltexpackr \
										 -lhashmap_c \
										 -lpng \
										 -lz