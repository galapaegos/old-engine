DIR=../../..
INC=-I$(DIR)/include -I/usr/X11R6/include
SRC=$(DIR)/src/gsgfx/gl
CFLAGS=-Wall -fPIC -DGL_GLEXT_LEGACY
OBJS=$(SRC)/dllmain.o $(SRC)/gsext.o $(SRC)/gsgl.o
OUTDIR=$(DIR)/bin
MAJOR=1
MINOR=0.1
LIBGL=libgl.so

$(OUTDIR)/$(LIBGL): $(OBJS)
	$(CXX) -shared -Wl,-soname,$(LIBGL).$(MAJOR) -o $(LIBGL).$(MAJOR).$(MINOR) $(OBJS) -L/usr/X11R6/lib -lc -lGL -lGLw
	ln -sf $(LIBGL).$(MAJOR).$(MINOR) $(LIBGL)
	ln -sf $(LIBGL).$(MAJOR).$(MINOR) $(LIBGL).$(MAJOR)
	mv $(LIBGL).$(MAJOR).$(MINOR) $(OUTDIR)
	mv $(LIBGL).$(MAJOR) $(OUTDIR)
	mv $(LIBGL) $(OUTDIR)

$(SRC)/dllmain.o: $(SRC)/dllmain.cpp
	$(CXX) $(DEBUG) $(INC) $(CFLAGS) -c -o $(SRC)/dllmain.o $(SRC)/dllmain.cpp

$(SRC)/gsext.o: $(SRC)/gsext.cpp
	$(CXX) $(DEBUG) $(INC) $(CFLAGS) -c -o $(SRC)/gsext.o $(SRC)/gsext.cpp

$(SRC)/gsgl.o: $(SRC)/gsgl.cpp
	$(CXX) $(DEBUG) $(INC) $(CFLAGS) -c -o $(SRC)/gsgl.o $(SRC)/gsgl.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(LIBGL) $(OUTDIR)/$(LIBGL).$(MAJOR) $(OUTDIR)/$(LIBGL).$(MAJOR).$(MINOR)
