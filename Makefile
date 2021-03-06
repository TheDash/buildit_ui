#############################################################################
# Makefile for building: buildit_ui
# Generated by qmake (2.01a) (Qt 4.8.1) on: Sun Feb 8 11:36:55 2015
# Project:  buildit_ui.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile buildit_ui.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/buildit_config.cpp \
		src/main.cpp \
		src/mount_points_tab_widget.cpp \
		src/myviz.cpp \
		src/start_screen.cpp \
		src/start_screen_tab_widget.cpp moc_mount_points_tab_widget.cpp \
		moc_myviz.cpp \
		moc_start_screen.cpp \
		moc_start_screen_tab_widget.cpp
OBJECTS       = buildit_config.o \
		main.o \
		mount_points_tab_widget.o \
		myviz.o \
		start_screen.o \
		start_screen_tab_widget.o \
		moc_mount_points_tab_widget.o \
		moc_myviz.o \
		moc_start_screen.o \
		moc_start_screen_tab_widget.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		buildit_ui.pro
QMAKE_TARGET  = buildit_ui
DESTDIR       = 
TARGET        = buildit_ui

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: buildit_ui.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile buildit_ui.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile buildit_ui.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/buildit_ui1.0.0 || $(MKDIR) .tmp/buildit_ui1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/buildit_ui1.0.0/ && $(COPY_FILE) --parents include/buildit_ui/buildit_config.h include/buildit_ui/mount_points_tab_widget.h include/buildit_ui/myviz.h include/buildit_ui/start_screen.h include/buildit_ui/start_screen_tab_widget.h .tmp/buildit_ui1.0.0/ && $(COPY_FILE) --parents src/buildit_config.cpp src/main.cpp src/mount_points_tab_widget.cpp src/myviz.cpp src/start_screen.cpp src/start_screen_tab_widget.cpp .tmp/buildit_ui1.0.0/ && (cd `dirname .tmp/buildit_ui1.0.0` && $(TAR) buildit_ui1.0.0.tar buildit_ui1.0.0 && $(COMPRESS) buildit_ui1.0.0.tar) && $(MOVE) `dirname .tmp/buildit_ui1.0.0`/buildit_ui1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/buildit_ui1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mount_points_tab_widget.cpp moc_myviz.cpp moc_start_screen.cpp moc_start_screen_tab_widget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mount_points_tab_widget.cpp moc_myviz.cpp moc_start_screen.cpp moc_start_screen_tab_widget.cpp
moc_mount_points_tab_widget.cpp: include/buildit_ui/mount_points_tab_widget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) include/buildit_ui/mount_points_tab_widget.h -o moc_mount_points_tab_widget.cpp

moc_myviz.cpp: include/buildit_ui/myviz.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) include/buildit_ui/myviz.h -o moc_myviz.cpp

moc_start_screen.cpp: include/buildit_ui/start_screen.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) include/buildit_ui/start_screen.h -o moc_start_screen.cpp

moc_start_screen_tab_widget.cpp: include/buildit_ui/start_screen_tab_widget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) include/buildit_ui/start_screen_tab_widget.h -o moc_start_screen_tab_widget.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

buildit_config.o: src/buildit_config.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o buildit_config.o src/buildit_config.cpp

main.o: src/main.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o src/main.cpp

mount_points_tab_widget.o: src/mount_points_tab_widget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mount_points_tab_widget.o src/mount_points_tab_widget.cpp

myviz.o: src/myviz.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o myviz.o src/myviz.cpp

start_screen.o: src/start_screen.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o start_screen.o src/start_screen.cpp

start_screen_tab_widget.o: src/start_screen_tab_widget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o start_screen_tab_widget.o src/start_screen_tab_widget.cpp

moc_mount_points_tab_widget.o: moc_mount_points_tab_widget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mount_points_tab_widget.o moc_mount_points_tab_widget.cpp

moc_myviz.o: moc_myviz.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_myviz.o moc_myviz.cpp

moc_start_screen.o: moc_start_screen.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_start_screen.o moc_start_screen.cpp

moc_start_screen_tab_widget.o: moc_start_screen_tab_widget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_start_screen_tab_widget.o moc_start_screen_tab_widget.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

