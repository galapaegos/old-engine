CXX=g++
DIR=../../..
INC=-I$(DIR)/include -I/usr/X11R6/include
SRC=$(DIR)/apps/test-sceneloader
CFLAGS=-Wall -g
OBJS=$(SRC)/test.o
OUTDIR=$(DIR)/bin
FILENAME=test-sceneloader

all: $(OBJS)
	$(CXX) $(CFLAGS) -I$(INC) -L$(OUTDIR) -lgalapaegos -lutil -lgeom -lphyzics -limage -lwindow -o $(OUTDIR)/$(FILENAME) $(OBJS)

$(SRC)/test.o: $(SRC)/test.cpp
	$(CXX) $(INC) $(CFLAGS) -c -o $(SRC)/test.o $(SRC)/test.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(FILENAME)
