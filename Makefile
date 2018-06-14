BIN_DIR = bin
CXX = g++
CPPFLAGS = -g -Wall -Wextra -Wconversion --std=c++11

all: change ochange oplot fast peak an

# comp.o: comp.cpp comp.h bitstr.h
# 	$(CXX) $(CPPFLAGS) -c $< -o $@

peak: peak.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

change: change.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

ochange: ochange.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

oplot: oplot.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

fast: fast.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

fast: fast.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

thres.o: threshold/thresh.cpp threshold/thresh.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

an: analysis.cpp thres.o threshold/thresh.h threshold/functor.h threshold/qsort.h
	$(CXX) $(CPPFLAGS) analysis.cpp threshold/thresh.cpp -o $@

.PHONY: clean
clean:
	rm -rf *.o change