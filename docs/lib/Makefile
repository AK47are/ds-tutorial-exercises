SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, build/%.o, $(SOURCES))
STATIC_LIB = libcontainers.a

$(STATIC_LIB): $(OBJECTS)
	ar -rc $@ $^

build/%.o: src/%.cpp
	g++ -c $< -o $@

.PHONY: clean
clean:
	rm -rf build/*.o $(STATIC_LIB)
