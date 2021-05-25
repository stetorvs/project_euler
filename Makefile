SRCS:=$(wildcard *.cpp)
EXES:=$(patsubst %.cpp,%.out,$(SRCS))

CXXFLAGS:=-std=c++17 -g -lgmp -lgmpxx -O2

all: $(EXES)

%.out: %.cpp
	$(CXX) -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(EXES)

.PHONY: all clean
