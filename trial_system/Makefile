BIN_DIR = bin
CXX = g++
CPPFLAGS = -g -Wall -Wextra -Wconversion --std=c++11

all: trial

thres.o: threshold/thresh.cpp threshold/thresh.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

trial: trial.cpp thres.o threshold/thresh.h threshold/functor.h threshold/qsort.h
	$(CXX) $(CPPFLAGS) trial.cpp threshold/thresh.cpp -o $@

.PHONY: clean
clean:
	rm -rf *.o trial