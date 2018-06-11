#ifndef QSORT_H
#define QSORT_H

#include <vector>

// swaps values - from class notes
template <class T>
void swap(T& p1, T& p2) {
	T p3(p2);
	p2 = p1;
	p1 = p3;
}

// returns the index of the median of the start, end, and mid values of myArray
// uses selection sort to sort the subArray and then returns median (middle) index
template <class T, class Comparator>
int median_of_three(std::vector<T> &myArray, Comparator comp, int start, int end) {
	int mid = (end+start)/2;

	std::vector<int> subArray;
	subArray.push_back(start);
	subArray.push_back(mid);
	subArray.push_back(end);

	// selection sort - from class notes
	for(unsigned int j=0; j<subArray.size()-1;j++) {
			int min = j;
		for(unsigned int i=j+1; i<subArray.size(); i++) {
			if(comp(myArray[subArray[i]], myArray[subArray[min]])) {
				min = i;
			}
		}
		swap(subArray[j], subArray[min]);
	}
	
	return subArray[1];
}


// uses pivot to sort all values "<" pivot to left and ">" to right
template <class T, class Comparator>
int partition(std::vector<T> &myArray, Comparator comp, int start, int end) {
	// get pivot index and set pivot to pivot value
	int p = median_of_three(myArray, comp, start, end);
	T pivot = myArray[p];

	// move pivot out of the way
	swap(myArray[p], myArray[end]);
	int left = start;
	int right = end-1;

	// move up indexes until need to be swapped and then swap
	while(left < right) {
		while(!comp(pivot, myArray[left]) && left < right) {
			left++;
		}
		while( !comp(myArray[right], pivot) && left < right) {
			right--;
		}
		if(left < right) {
			swap(myArray[left], myArray[right]);
		}
	}

	// if remaining needs to be swapped, swap and return index
	if(comp(myArray[end], myArray[right])) {
		swap(myArray[right], myArray[end]);
		return right;
	}

	return end;
}

// recursive quicksort calling itself on partition sides until all sorted
template <class T, class Comparator>
void QuickSort_helper(std::vector<T> &myArray, Comparator comp, int start, int end) {
	if(start >= end) {
		return;
	}
	int pos = partition(myArray, comp, start, end);
	QuickSort_helper(myArray, comp, start, pos-1);
	QuickSort_helper(myArray, comp, pos+1, end);

};

// quicksort function to calls helper
template <class T, class Comparator>
void QuickSort (std::vector<T> &myArray, Comparator comp) {
	if(myArray.size() == 0) {
		return;
	}
	int size = static_cast<int>(myArray.size()-1);
	QuickSort_helper(myArray, comp, 0, size);
}

#endif