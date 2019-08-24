DIR=../../..
INC=$(DIR)/include
SRC=$(DIR)/src/gsutil
DEBUG=-g
CFLAGS=-Wall -fPIC
LIBRARIES=-lpthread
OBJS=$(SRC)/gsXMLParser.o $(SRC)/gslogger.o $(SRC)/gsstring.o $(SRC)/gssystem.o $(SRC)/gstimer.o $(SRC)/gsthread.o
OUTDIR=$(DIR)/bin
MAJOR=1
MINOR=0.1
LIBUTIL=libutil.so

all: $(OBJS)
	$(CXX) $(LIBRARIES) -shared -Wl,-export-dynamic -Wl,-soname,$(LIBUTIL).$(MAJOR) -o $(LIBUTIL).$(MAJOR).$(MINOR) $(OBJS) -lc
	ln -sf $(LIBUTIL).$(MAJOR).$(MINOR) $(LIBUTIL)
	ln -sf $(LIBUTIL).$(MAJOR).$(MINOR) $(LIBUTIL).$(MAJOR)
	mv $(LIBUTIL).$(MAJOR).$(MINOR) $(OUTDIR)
	mv $(LIBUTIL).$(MAJOR) $(OUTDIR)
	mv $(LIBUTIL) $(OUTDIR)

$(SRC)/gsXMLParser.o: $(SRC)/gsXMLParser.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsXMLParser.o $(SRC)/gsXMLParser.cpp

$(SRC)/gslogger.o: $(SRC)/gslogger.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gslogger.o $(SRC)/gslogger.cpp

$(SRC)/gsstring.o: $(SRC)/gsstring.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsstring.o $(SRC)/gsstring.cpp

$(SRC)/gssystem.o: $(SRC)/gssystem.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gssystem.o $(SRC)/gssystem.cpp

$(SRC)/gstimer.o: $(SRC)/gstimer.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gstimer.o $(SRC)/gstimer.cpp

$(SRC)/gsthread.o: $(SRC)/gsthread.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsthread.o $(SRC)/gsthread.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(LIBUTIL) $(OUTDIR)/$(LIBUTIL).$(MAJOR) $(OUTDIR)/$(LIBUTIL).$(MAJOR).$(MINOR)
