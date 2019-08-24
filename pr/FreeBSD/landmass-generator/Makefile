CXX=g++
DIR=../../..
INC=-I$(DIR)/include -I/usr/X11R6/include -I$(DIR)/apps/landmass-generator
SRC=$(DIR)/apps/landmass-generator
CFLAGS=-Wall -g
OBJS=$(SRC)/test.o
OUTDIR=$(DIR)/bin
FILENAME=landmass-generator

all: $(OBJS)
	$(CXX) $(CFLAGS) -I$(INC) -L$(OUTDIR) -lgalapaegos -lutil -lgeom -lphyzics -limage -o $(OUTDIR)/$(FILENAME) $(OBJS)

$(SRC)/test.o: $(SRC)/test.cpp
	$(CXX) $(INC) $(DEBUG) $(CFLAGS) -c -o $(SRC)/test.o $(SRC)/test.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(FILENAME)
