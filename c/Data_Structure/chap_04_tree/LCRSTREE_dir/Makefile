CFLAGS= -g -Wall -W -std=gnu99 -fPIC -I./ -I ./include $(EXT_CLFAGS) $(ADD_CFLAGS)
LDFLAGS= $(EXT_LDFLAGS)
STATIC_LDFLAGS=

APP_OBJS= LCRSTree.o main.o

APP=examplecode

.SUFFIXES: .cpp .cxx .cc .C .c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<


all : $(APP)

$(APP) : $(APP_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(LIB_OBJ) $(APP_OBJS) $(LIB) $(APP)
leaks:
	valgrind --leak-check=yes ./$(APP_OBJS)

