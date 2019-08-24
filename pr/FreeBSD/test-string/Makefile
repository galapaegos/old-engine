CXX=g++
DIR=../../..
INC=$(DIR)/include
SRC=$(DIR)/apps/test-string
CFLAGS=-Wall
OBJS=$(SRC)/main.o
OUTDIR=$(DIR)/bin
FILENAME=test-string

all: $(OBJS)
	$(CXX) $(CFLAGS) -I$(INC) -L$(OUTDIR) -lutil -o $(OUTDIR)/$(FILENAME) $(OBJS)

$(SRC)/main.o: $(SRC)/main.cpp
	$(CXX) -I$(INC) $(DEBUG) $(CFLAGS) -c -o $(SRC)/main.o $(SRC)/main.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(FILENAME)
