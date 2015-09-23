CC=g++
CFLAGS=-c -Wall -Isdl/osx/SDL2.framework/Headers
LFLAGS=-Wall -Fsdl/osx/ -framework SDL2 -framework OpenGL
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(patsubst src/%,build/%,$(SOURCES:.cpp=.o))

ichor: $(OBJECTS)
	$(CC) $(LFLAGS) -o $@ $(OBJECTS)

$(OBJECTS) : build/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm /build/*o
