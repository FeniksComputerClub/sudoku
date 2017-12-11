include $(srcdir)/cwm4/root_makefile_top.am

SUBDIRS = @CW_SUBDIRS@

bin_PROGRAMS = sudoku

sudoku_SOURCES = \
	main.cpp \
	Field.cpp \
	Field.h \
	NumberSet.cpp \
	NumberSet.h \
	Debug.h

sudoku_CXXFLAGS = -std=c++14 @LIBCWD_FLAGS@
sudoku_LDADD = @LIBCWD_LIBS@

include $(srcdir)/cwm4/root_makefile_bottom.am
