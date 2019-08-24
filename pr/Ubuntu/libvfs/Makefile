DIR=../../..
INC=$(DIR)/include
SRC=$(DIR)/src/gsvfs
CFLAGS=-Wall -fPIC
OBJS=$(SRC)/gsfilesystem.o $(SRC)/gsfile.o $(SRC)/gsdirectory.o
OUTDIR=$(DIR)/bin
MAJOR=1
MINOR=0.1
LIBVFS=libvfs.so

$(OUTDIR)/$(LIBVFS): $(OBJS)
	$(CXX) -shared -Wl,-export-dynamic -Wl,-soname,$(LIBVFS).$(MAJOR) -o $(LIBVFS).$(MAJOR).$(MINOR) $(OBJS) -lc
	ln -sf $(LIBVFS).$(MAJOR).$(MINOR) $(LIBVFS)
	ln -sf $(LIBVFS).$(MAJOR).$(MINOR) $(LIBVFS).$(MAJOR)
	mv $(LIBVFS).$(MAJOR).$(MINOR) $(OUTDIR)
	mv $(LIBVFS).$(MAJOR) $(OUTDIR)
	mv $(LIBVFS) $(OUTDIR)

$(SRC)/gsfilesystem.o: $(SRC)/gsfilesystem.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsfilesystem.o $(SRC)/gsfilesystem.cpp

$(SRC)/gsfile.o: $(SRC)/gsfile.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsfile.o $(SRC)/gsfile.cpp

$(SRC)/gsdirectory.o: $(SRC)/gsdirectory.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsdirectory.o $(SRC)/gsdirectory.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(LIBVFS) $(OUTDIR)/$(LIBVFS).$(MAJOR) $(OUTDIR)/$(LIBVFS).$(MAJOR).$(MINOR)
