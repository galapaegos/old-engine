DIR=../../..
INC=$(DIR)/include -I/usr/X11R6/include
SRC=$(DIR)/src/gswindow
CFLAGS=-Wall -fPIC
OBJS= $(SRC)/gsmenu.o \
$(SRC)/gsmain.o \
$(SRC)/gsmenuitem.o \
$(SRC)/gswidget.o \
$(SRC)/gswindow.o
OUTDIR=$(DIR)/bin
MAJOR=1
MINOR=0.1
LIBWINDOW=libwindow.so

$(OUTDIR)/$(LIBWINDOW): $(OBJS)
	$(CXX) -shared -Wl,-export-dynamic -Wl,-soname,$(LIBWINDOW).$(MAJOR) -o $(LIBWINDOW).$(MAJOR).$(MINOR) $(OBJS) -L$(OUTDIR) -L/usr/X11R6/lib -lc -lGLw -lGL -lXm -lXt -lX11 -limage
	ln -sf $(LIBWINDOW).$(MAJOR).$(MINOR) $(LIBWINDOW)
	ln -sf $(LIBWINDOW).$(MAJOR).$(MINOR) $(LIBWINDOW).$(MAJOR)
	mv $(LIBWINDOW).$(MAJOR).$(MINOR) $(OUTDIR)
	mv $(LIBWINDOW).$(MAJOR) $(OUTDIR)
	mv $(LIBWINDOW) $(OUTDIR)

$(SRC)/gsbutton.o: $(SRC)/gsbutton.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsbutton.o $(SRC)/gsbutton.cpp

$(SRC)/gscheckbox.o: $(SRC)/gscheckbox.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gscheckbox.o $(SRC)/gscheckbox.cpp

$(SRC)/gscombobox.o: $(SRC)/gscombobox.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gscombobox.o $(SRC)/gscombobox.cpp

$(SRC)/gsdescription.o: $(SRC)/gsdescription.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsdescription.o $(SRC)/gsdescription.cpp

$(SRC)/gsgroup.o: $(SRC)/gsgroup.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsgroup.o $(SRC)/gsgroup.cpp

$(SRC)/gslistbox.o: $(SRC)/gslistbox.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gslistbox.o $(SRC)/gslistbox.cpp

$(SRC)/gsmain.o: $(SRC)/gsmain.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsmain.o $(SRC)/gsmain.cpp

$(SRC)/gsmenu.o: $(SRC)/gsmenu.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsmenu.o $(SRC)/gsmenu.cpp

$(SRC)/gsmenuitem.o: $(SRC)/gsmenuitem.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsmenuitem.o $(SRC)/gsmenuitem.cpp

$(SRC)/gsradiobutton.o: $(SRC)/gsradiobutton.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsradiobutton.o $(SRC)/gsradiobutton.cpp

$(SRC)/gsradiogroup.o: $(SRC)/gsradiogroup.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gsradiogroup.o $(SRC)/gsradiogroup.cpp

$(SRC)/gstabctl.o: $(SRC)/gstabctl.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gstabctl.o $(SRC)/gstabctl.cpp

$(SRC)/gstabpanel.o: $(SRC)/gstabpanel.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gstabpanel.o $(SRC)/gstabpanel.cpp

$(SRC)/gstextbox.o: $(SRC)/gstextbox.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gstextbox.o $(SRC)/gstextbox.cpp

$(SRC)/gswidget.o: $(SRC)/gswidget.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gswidget.o $(SRC)/gswidget.cpp

$(SRC)/gswindow.o: $(SRC)/gswindow.cpp
	$(CXX) $(DEBUG) -I$(INC) $(CFLAGS) -c -o $(SRC)/gswindow.o $(SRC)/gswindow.cpp

clean:
	rm -rf $(OBJS) $(OUTDIR)/$(LIBWINDOW) $(OUTDIR)/$(LIBWINDOW).$(MAJOR) $(OUTDIR)/$(LIBWINDOW).$(MAJOR).$(MINOR)
