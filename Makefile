BIN_DIR = bin
CXX = g++
CPPFLAGS = -g -Wall -Wextra -Wconversion --std=c++11

all: change ochange

# comp.o: comp.cpp comp.h bitstr.h
# 	$(CXX) $(CPPFLAGS) -c $< -o $@

change: change.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

ochange: ochange.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf *.o change