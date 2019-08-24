DIR=../../..
INC=$(DIR)/include
SRC=$(DIR)/src/gsgeom
CFLAGS=-g -Wall -fPIC
OBJS=$(SRC)/gsbbox.o $(SRC)/gsbox.o $(SRC)/gscamera.o $(SRC)/gseffect.o $(SRC)/gsfrustum.o $(SRC)/gslight.o $(SRC)/gsocclusion.o $(SRC)/gsplane.o $(SRC)/gspolygon.o $(SRC)/gsscene.o $(SRC)/gssceneutil.o $(SRC)/gsshader.o $(SRC)/gsshadervariable.o $(SRC)/gsspline.o $(SRC)/gstriangulate.o
OUTDIR=$(DIR)/bin
MAJOR=1
MINOR=0.1
LIBGEOM=libgeom.so

all: $(OBJS)
	$(CXX) -shared -Wl,-export-dynamic -Wl,-soname,$(LIBGEOM).$(MAJOR) -o $(LIBGEOM).$(MAJOR).$(MINOR) $(OBJS) -lc
	ln -sf $(LIBGEOM).$(MAJOR).$(MINOR) $(LIBGEOM)
	ln -sf $(LIBGEOM).$(MAJOR).$(MINOR) $(LIBGEOM).$(MAJOR)
	mv $(LIBGEOM).$(MAJOR).$(MINOR) $(OUTDIR)
	mv $(LIBGEOM).$(MAJOR) $(OUTDIR)
	mv $(LIBGEOM) $(OUTDIR)

$(SRC)/gsbbox.o: $(SRC)/gsbbox.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsbbox.o $(SRC)/gsbbox.cpp

$(SRC)/gsbox.o: $(SRC)/gsbox.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsbox.o $(SRC)/gsbox.cpp

$(SRC)/gscamera.o: $(SRC)/gscamera.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gscamera.o $(SRC)/gscamera.cpp

$(SRC)/gseffect.o: $(SRC)/gseffect.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gseffect.o $(SRC)/gseffect.cpp

$(SRC)/gsfrustum.o: $(SRC)/gsfrustum.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsfrustum.o $(SRC)/gsfrustum.cpp

$(SRC)/gslight.o: $(SRC)/gslight.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gslight.o $(SRC)/gslight.cpp

$(SRC)/gsocclusion.o: $(SRC)/gsocclusion.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsocclusion.o $(SRC)/gsocclusion.cpp

$(SRC)/gsplane.o: $(SRC)/gsplane.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsplane.o $(SRC)/gsplane.cpp

$(SRC)/gspolygon.o: $(SRC)/gspolygon.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gspolygon.o $(SRC)/gspolygon.cpp

$(SRC)/gsscene.o: $(SRC)/gsscene.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsscene.o $(SRC)/gsscene.cpp

$(SRC)/gssceneutil.o: $(SRC)/gssceneutil.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gssceneutil.o $(SRC)/gssceneutil.cpp

$(SRC)/gsspline.o: $(SRC)/gsspline.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsspline.o $(SRC)/gsspline.cpp

$(SRC)/gsshader.o: $(SRC)/gsshader.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsshader.o $(SRC)/gsshader.cpp

$(SRC)/gsshadervariable.o: $(SRC)/gsshadervariable.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsshadervariable.o $(SRC)/gsshadervariable.cpp

$(SRC)/gstriangulate.o: $(SRC)/gstriangulate.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gstriangulate.o $(SRC)/gstriangulate.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(LIBGEOM) $(OUTDIR)/$(LIBGEOM).$(MAJOR) $(OUTDIR)/$(LIBGEOM).$(MAJOR).$(MINOR)
