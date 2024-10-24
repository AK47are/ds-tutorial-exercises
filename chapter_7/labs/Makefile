SOURCES = $(wildcard *.cpp)
TARGETS = $(patsubst %.cpp, build/%.out, $(SOURCES))

all: build/ $(TARGETS)

build/:
	mkdir build/

build/%.out: %.cpp
	g++ -o $@ $<

.PHONY: clean
clean:
	rm -rf build/*
