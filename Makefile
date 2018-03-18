CXXFLAGS = -g -std=c++11

all: b2 cm

b2: b2_test.o b2_update.o gfx.o world.o
	g++ $(CXXFLAGS) -o b2Test b2_test.o b2_update.o gfx.o world.o -lglut -lGL

cm: cm_test.o cm_update.o gfx.o world.o
	g++ $(CXXFLAGS) -o cmTest cm_test.o cm_update.o gfx.o world.o -lglut -lGL

b2_test.o:
	g++ $(CXXFLAGS) -c b2_test.cpp

b2_update.o: b2_update.h
	g++ $(CXXFLAGS) -c b2_update.cpp

cm_test.o:
	g++ $(CXXFLAGS) -c cm_test.cpp

cm_update.o: cm_update.h
	g++ $(CXXFLAGS) -c cm_update.cpp

world.o: world.h
	g++ $(CXXFLAGS) -c world.cpp

gfx.o: gfx.h
	g++ $(CXXFLAGS) -c gfx.cpp

clean:
	$(RM) b2Test cmTest *.o

