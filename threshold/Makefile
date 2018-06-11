BIN_DIR = bin
CXX = g++
CPPFLAGS = -g -Wall -Wextra -Wconversion --std=c++11

all: threshold thresh.o

# comp.o: comp.cpp comp.h bitstr.h
# 	$(CXX) $(CPPFLAGS) -c $< -o $@

thres.o: thresh.cpp thresh.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

threshold: threshold.cpp thres.o thresh.h functor.h qsort.h
	$(CXX) $(CPPFLAGS) threshold.cpp thresh.cpp -o $@


.PHONY: clean
clean:
	rm -rf *.o change