AM_CPPFLAGS = -iquote $(top_srcdir) -iquote $(top_srcdir)/cwds

bin_PROGRAMS = sudoku

sudoku_SOURCES = \
	main.cpp \
	Field.cpp \
	Field.h \
	NumberSet.cpp \
	NumberSet.h \
	Debug.h \
	Direction.h \
	Direction.cpp

sudoku_CXXFLAGS = -std=c++11 @LIBCWD_FLAGS@
sudoku_LDADD = $(top_builddir)/cwds/libcwds.la

# --------------- Maintainer's Section

MAINTAINERCLEANFILES = $(srcdir)/Makefile.in
