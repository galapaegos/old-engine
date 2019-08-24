DIR=../../..
INC=$(DIR)/include
SRC=$(DIR)/src/gsphyzics
CFLAGS=-Wall -fPIC
OBJS=$(SRC)/gscollision.o
OUTDIR=$(DIR)/bin
MAJOR=1.0
MINOR=1
LIBPHYZ=libphyzics.so

all: $(OBJS)
	$(CXX) -shared -Wl,-soname,$(LIBPHYZ).$(MAJOR) -o $(LIBPHYZ).$(MAJOR).$(MINOR) $(OBJS)
	ln -sf $(LIBPHYZ).$(MAJOR).$(MINOR) $(LIBPHYZ)
	ln -sf $(LIBPHYZ).$(MAJOR).$(MINOR) $(LIBPHYZ).$(MAJOR)
	mv $(LIBPHYZ).$(MAJOR).$(MINOR) $(OUTDIR)
	mv $(LIBPHYZ).$(MAJOR) $(OUTDIR)
	mv $(LIBPHYZ) $(OUTDIR)

$(SRC)/gscollision.o: $(SRC)/gscollision.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gscollision.o $(SRC)/gscollision.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(LIBPHYZ) $(OUTDIR)/$(LIBPHYZ).$(MAJOR) $(OUTDIR)/$(LIBPHYZ).$(MAJOR).$(MINOR)
