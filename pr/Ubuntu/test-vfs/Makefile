CXX=g++
DIR=../../..
INC=$(DIR)/include
SRC=$(DIR)/apps/test-vfs
CFLAGS=-Wall
OBJS=$(SRC)/test.o
OUTDIR=$(DIR)/bin
FILENAME=test-vfs

all: $(OBJS)
	$(CXX) $(CFLAGS) -I$(INC) -L$(OUTDIR) -lvfs -lutil -o $(OUTDIR)/$(FILENAME) $(OBJS)

$(SRC)/test.o: $(SRC)/test.cpp
	$(CXX) -I$(INC) $(DEBUG) $(CFLAGS) -c -o $(SRC)/test.o $(SRC)/test.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(FILENAME)
