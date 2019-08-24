#include ../Makefile.common

DIR=../../..
INC=$(DIR)/include -I/usr/X11R6/include
SRC=$(DIR)/src/gs
CFLAGS=-g -Wall -fPIC
OBJS=$(SRC)/gsconsole.o $(SRC)/gsevent.o $(SRC)/gskernel.o $(SRC)/gslibrary.o $(SRC)/gsresourcemgr.o $(SRC)/gssceneloader.o $(SRC)/gsscript.o $(SRC)/gsscriptexecute.o $(SRC)/gsscriptobject.o $(SRC)/gsscriptparser.o $(SRC)/gstask.o
OUTDIR=$(DIR)/bin
MAJOR=1
MINOR=0.1
LIBGS=libgalapaegos.so

all: $(OBJS)
	$(CXX) -shared -Wl,-soname,$(LIBGS).$(MAJOR) -o $(LIBGS).$(MAJOR).$(MINOR) $(OBJS) -L$(OUTDIR) -L/usr/X11R6/lib -lc -lutil -lphyzics -lgeom -limage
	ln -sf $(LIBGS).$(MAJOR).$(MINOR) $(LIBGS)
	ln -sf $(LIBGS).$(MAJOR).$(MINOR) $(LIBGS).$(MAJOR)
	mv $(LIBGS).$(MAJOR).$(MINOR) $(OUTDIR)
	mv $(LIBGS).$(MAJOR) $(OUTDIR)
	mv $(LIBGS) $(OUTDIR)

$(SRC)/gsconsole.o: $(SRC)/gsconsole.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsconsole.o $(SRC)/gsconsole.cpp

$(SRC)/gsevent.o: $(SRC)/gsevent.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsevent.o $(SRC)/gsevent.cpp

$(SRC)/gskernel.o: $(SRC)/gskernel.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gskernel.o $(SRC)/gskernel.cpp

$(SRC)/gslibrary.o: $(SRC)/gslibrary.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gslibrary.o $(SRC)/gslibrary.cpp

$(SRC)/gsresourcemgr.o: $(SRC)/gsresourcemgr.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsresourcemgr.o $(SRC)/gsresourcemgr.cpp

$(SRC)/gssceneloader.o: $(SRC)/gssceneloader.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gssceneloader.o $(SRC)/gssceneloader.cpp

$(SRC)/gsscript.o: $(SRC)/gsscript.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsscript.o $(SRC)/gsscript.cpp

$(SRC)/gsscriptexecute.o: $(SRC)/gsscriptexecute.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsscriptexecute.o $(SRC)/gsscriptexecute.cpp

$(SRC)/gsscriptobject.o: $(SRC)/gsscriptobject.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsscriptobject.o $(SRC)/gsscriptobject.cpp

$(SRC)/gsscriptparser.o: $(SRC)/gsscriptparser.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsscriptparser.o $(SRC)/gsscriptparser.cpp

$(SRC)/gstask.o: $(SRC)/gstask.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gstask.o $(SRC)/gstask.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(LIBGS) $(OUTDIR)/$(LIBGS).$(MAJOR) $(OUTDIR)/$(LIBGS).$(MAJOR).$(MINOR)
