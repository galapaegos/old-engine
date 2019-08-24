CXX=g++
DIR=../../..
INC=$(DIR)/include -I/usr/X11R6/include
SRC=$(DIR)/apps/test-shadow
CFLAGS=-Wall
OBJS=$(SRC)/test.o
OUTDIR=$(DIR)/bin
FILENAME=test-shadow

all: $(OBJS)
	$(CXX) $(CFLAGS) -I$(INC) -L$(OUTDIR) -lgalapaegos -lutil -lgeom -lphyzics -lwindow -limage -o $(OUTDIR)/$(FILENAME) $(OBJS)

$(SRC)/test.o: $(SRC)/test.cpp
	$(CXX) -I$(INC) $(DEBUG) $(CFLAGS) -c -o $(SRC)/test.o $(SRC)/test.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(FILENAME)
