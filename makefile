CC=g++ 
CFLAGS=-c -Wall -std=c++98
LDFLAGS=
SOURCES=Connect4Demo.cpp GameplayStack.cpp Node.cpp LinkedList.cpp LStack.cpp
#SOURCES=Connect4DemoTemplate.cpp GameplayStack.h Node.h LinkedList.h LStack.h GamePiece.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=a2

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
