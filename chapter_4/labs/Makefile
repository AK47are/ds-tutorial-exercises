MAKEFLAGS += --no-print-directory
SOURCES = $(wildcard *.cpp)
TARGETS = $(patsubst %.cpp, build/%.out, $(SOURCES))
LIB_DIR = "../../docs/lib/"
LIB = ../../docs/lib/libcontainers.a

all: build/ $(LIB) $(TARGETS)

build/:
	mkdir build/

build/%.out: %.cpp $(LIB) # 变量作为依赖项时不能有"" 。
	g++ -o $@ $< -l containers -L $(LIB_DIR)


$(LIB):
	@make -C ../../docs/lib/

.PHONY: clean
clean:
	rm -rf build/*
