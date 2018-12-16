CXX = g++
CXXFLAGS = -std=c++11 -Wall -W -Werror -pedantic

sspapp: sspapp.o graph.o minpriority.o
	$(CXX) -c sspapp sspapp.o graph.o minpriority.o

sspapp.o: sspapp.h sspapp.cpp graph.h minpriority.h

graph.o: graph.h graph.cpp

minpriority.o: minpriority.h minpriority.cpp

clean:
	rm -f *.o rbapp
