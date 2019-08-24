CXX=g++
DIR=../../..
INC=$(DIR)/include
SRC=$(DIR)/apps/test-client
CFLAGS=-Wall
OBJS=$(SRC)/test.o
OUTDIR=$(DIR)/bin
FILENAME=test-client

all: $(OBJS)
	$(CXX) $(CFLAGS) -I$(INC) -L$(OUTDIR) -lnet -lutil -o $(OUTDIR)/$(FILENAME) $(OBJS)

$(SRC)/test.o: $(SRC)/test.cpp
	$(CXX) -I$(INC) $(DEBUG) $(CFLAGS) -c -o $(SRC)/test.o $(SRC)/test.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(FILENAME)
