CXX=g++
DIR=../../..
INC=$(DIR)/include
SRC=$(DIR)/apps/test-server
CFLAGS=-Wall
OBJS=$(SRC)/test.o
OUTDIR=$(DIR)/bin
FILENAME=test-server

all: $(OBJS)
	$(CXX) $(CFLAGS) -I$(INC) -L$(OUTDIR) -lnet -lutil -o $(OUTDIR)/$(FILENAME) $(OBJS)

$(SRC)/test.o: $(SRC)/test.cpp
	$(CXX) -I$(INC) $(DEBUG) $(CFLAGS) -c -o $(SRC)/test.o $(SRC)/test.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(FILENAME)
