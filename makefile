OS=$(shell uname)

ifeq ($(OS),Darwin)
CC=g++
LL=g++
OUTPUT=-o ichor
CFLAGS=-c -Wall -Ilib/osx/SDL2.framework/Headers
LFLAGS=-Wall -Flib/osx/ -framework SDL2 -framework OpenGL -framework SDL2_image lib/osx/libGLEW.1.12.0.dylib
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

ichor: $(OBJECTS)
	$(LL) $(LFLAGS) $(OUTPUT) $(OBJECTS)

$(OBJECTS) : build/%.o: src/%.cpp
	$(CC) $(CFLAGS) $(OFLAG)$@ $< 

clean:
	rm /build/*o
