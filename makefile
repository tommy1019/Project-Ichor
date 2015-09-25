OS=$(shell uname)

ifeq ($(OS),Darwin)
CC=g++
LL=g++
OUTPUT=-o ichor
CFLAGS=-c -Wall -Isdl/osx/SDL2.framework/Headers
LFLAGS=-Wall -Fsdl/osx/ -framework SDL2 -framework OpenGL
OFLAG=-o  
OBJECTS=$(patsubst src/%,build/%,$(SOURCES:.cpp=.o))
SOURCES=$(wildcard src/*.cpp)
else
CC=cl
LL=link
OUTPUT=/out:ichor.exe
CFLAGS=/Wall /I"sdl\windows\include" /c
LFLAGS=/LIBPATH:"sdl/windows/lib/x86" SDL2.lib SDL2main.lib OpenGL32.lib /SUBSYSTEM:CONSOLE
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
