SOURCES = $(wildcard *.cpp)
TARGETS = $(patsubst %.cpp, %.out, $(SOURCES))

all: build/ $(TARGETS)

%.out: %.cpp
	g++ -o build/$@ $<

.PHONY: clean
clean:
	rm -rf build/*
