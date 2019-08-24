DIR=../../..
INC=$(DIR)/include
SRC=$(DIR)/src/gsnet
CFLAGS=-Wall -fPIC
OBJS=$(SRC)/gstcp.o $(SRC)/gsudp.o $(SRC)/gsclient.o $(SRC)/gsserver.o
OUTDIR=$(DIR)/bin
MAJOR=1
MINOR=0.1
LIBNET=libnet.so

all: $(OBJS)
	$(CXX) -shared -Wl,-export-dynamic -Wl,-soname,$(LIBNET).$(MAJOR) -o $(LIBNET).$(MAJOR).$(MINOR) $(OBJS) -lc
	ln -sf $(LIBNET).$(MAJOR).$(MINOR) $(LIBNET)
	ln -sf $(LIBNET).$(MAJOR).$(MINOR) $(LIBNET).$(MAJOR)
	mv $(LIBNET).$(MAJOR).$(MINOR) $(OUTDIR)
	mv $(LIBNET).$(MAJOR) $(OUTDIR)
	mv $(LIBNET) $(OUTDIR)

$(SRC)/gstcp.o: $(SRC)/gstcp.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gstcp.o $(SRC)/gstcp.cpp

$(SRC)/gsudp.o: $(SRC)/gsudp.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsudp.o $(SRC)/gsudp.cpp

$(SRC)/gsserver.o: $(SRC)/gsserver.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsserver.o $(SRC)/gsserver.cpp

$(SRC)/gsclient.o: $(SRC)/gsclient.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsclient.o $(SRC)/gsclient.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(LIBNET) $(OUTDIR)/$(LIBNET).$(MAJOR) $(OUTDIR)/$(LIBNET).$(MAJOR).$(MINOR)
