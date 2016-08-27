SOURCES=weiner_index.cpp Graph.cpp
EXECUTABLE=weiner_index
CC=g++
CFLAGS=-Wall -std=c++11 -O2
LDFLAGS=-pthread
OBJECTS=$(SOURCES:.cpp=.o)

all:$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
	rm -rf *~
