EXECUTABLE=bin/tn2_manager
SOURCES=src/main.cpp src/manager.cpp src/sandbox.cpp src/scheduler.cpp src/json/json.cpp
OBJECTS=$(SOURCES:.cpp=.o)
CPP=g++
FLAGS=-ansi -pedantic -Wall -s -O2
LDFLAGS=
DEBUG_FLAGS=-g -lm -DDEBUG

all: clean $(EXECUTABLE) $(EXECUTABLE)_dbg sb_test

$(EXECUTABLE):
	$(CPP) $(SOURCES) $(FLAGS) -o $@

$(EXECUTABLE)_dbg:
	$(CPP) $(SOURCES) $(FLAGS) $(DEBUG_FLAGS) -o $@

sb_test:
	$(CPP) src/sb_test.cpp $(FLAGS) -o bin/$@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) $(EXECUTABLE)_dbg
