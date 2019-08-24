DIR=../../..
INC=$(DIR)/include
SRC=$(DIR)/src/gsimage
CFLAGS=-Wall -fPIC
OBJS=$(SRC)/gsbmp.o $(SRC)/gspng.o $(SRC)/gsppm.o $(SRC)/gstga.o
OUTDIR=$(DIR)/bin
MAJOR=1
MINOR=0.1
LIBIMAGE=libimage.so

all: $(OBJS)
	$(CXX) -shared -Wl,-export-dynamic -Wl,-soname,$(LIBIMAGE).$(MAJOR) -o $(LIBIMAGE).$(MAJOR).$(MINOR) $(OBJS) -lc
	ln -sf $(LIBIMAGE).$(MAJOR).$(MINOR) $(LIBIMAGE)
	ln -sf $(LIBIMAGE).$(MAJOR).$(MINOR) $(LIBIMAGE).$(MAJOR)
	mv $(LIBIMAGE).$(MAJOR).$(MINOR) $(OUTDIR)
	mv $(LIBIMAGE).$(MAJOR) $(OUTDIR)
	mv $(LIBIMAGE) $(OUTDIR)

$(SRC)/gsbmp.o: $(SRC)/gsbmp.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsbmp.o $(SRC)/gsbmp.cpp

$(SRC)/gsjpeg.o: $(SRC)/gsjpeg.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsjpeg.o $(SRC)/gsjpeg.cpp

$(SRC)/gspng.o: $(SRC)/gspng.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gspng.o $(SRC)/gspng.cpp

$(SRC)/gsppm.o: $(SRC)/gsppm.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsppm.o $(SRC)/gsppm.cpp

$(SRC)/gstga.o: $(SRC)/gstga.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gstga.o $(SRC)/gstga.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(LIBIMAGE) $(OUTDIR)/$(LIBIMAGE).$(MAJOR) $(OUTDIR)/$(LIBIMAGE).$(MAJOR).$(MINOR)
