OS=$(shell uname)

ifeq ($(OS),Darwin)
CC=g++
LL=g++
OUTPUT=-o ichor
CFLAGS=-c -Wall -I/usr/local/include
LFLAGS=-Wall -L/usr/local/lib -lSDL2 -lSDL2_image -lGLEW -framework OpenGL
OFLAG=-o  
OBJECTS=$(patsubst src/%,build/%,$(SOURCES:.cpp=.o))
SOURCES=$(wildcard src/*.cpp)
else
ifeq ($(OS),Linux)
CC=g++
LL=g++
OUTPUT=-o ichor
CFLAGS=-c -Wall -I/usr/include -std=c++11
LFLAGS=-Wall -L/usr/lib -lSDL2 -lSDL2_image -lGLEW -lGL 
OFLAG=-o  
OBJECTS=$(patsubst src/%,build/%,$(SOURCES:.cpp=.o))
SOURCES=$(wildcard src/*.cpp)
else
CC=cl
LL=link
OUTPUT=/out:ichor.exe
CFLAGS=/Wall /I"lib\windows\include" /c
LFLAGS=/LIBPATH:"lib/windows/lib/x86" SDL2.lib SDL2main.lib SDL2_image.lib OpenGL32.lib glew32.lib /SUBSYSTEM:CONSOLE
OFLAG=/Fo
OBJECTS=$(patsubst src/%,build/%,$(SOURCES:.cpp=.o))
SOURCES=$(wildcard src/*.cpp)
endif
endif

ichor: $(OBJECTS)
	$(LL) $(OUTPUT) $(OBJECTS) $(LFLAGS)

$(OBJECTS) : build/%.o: src/%.cpp
	$(CC) $(CFLAGS) $(OFLAG)$@ $< 

clean:
	rm build/*.o
	rm ichor
