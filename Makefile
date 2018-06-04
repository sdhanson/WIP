BIN_DIR = bin
CXX = g++
CPPFLAGS = -g -Wall -Wextra -Wconversion --std=c++11

all: change ochange oplot

# comp.o: comp.cpp comp.h bitstr.h
# 	$(CXX) $(CPPFLAGS) -c $< -o $@

change: change.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

ochange: ochange.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

oplot: oplot.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf *.o change