EXECUTABLE=bin/tn2_manager
SOURCES=src/main.cpp src/dbmanager.cpp
OBJECTS=$(SOURCES:.cpp=.o)
CPP=g++
FLAGS=-ansi -pedantic -Wall -s -O2 -Werror
LDFLAGS=
DEBUG_FLAGS=-g -lm -Wall -DDEBUG

all: clean $(EXECUTABLE) $(EXECUTABLE)_dbg

$(EXECUTABLE):
	$(CPP) $(SOURCES) $(FLAGS) -o $@

$(EXECUTABLE)_dbg:
	$(CPP) $(SOURCES) $(FLAGS) $(DEBUG_FLAGS) -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) $(EXECUTABLE)_dbg
