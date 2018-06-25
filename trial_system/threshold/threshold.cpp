#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>

#include "thresh.h"


using namespace std;

void gtime(ifstream& input, vector<Thresh>& v) {

	// declaring stringstream variables
	string line, word;
	double prev;
	double sum = 0;
	int count = 0;

	// takes in each line, reads garbage numbers up to column number
	// takes the column we want and compares to prev max/min and resets
	// if need be
	while(getline(input, line)) {
		stringstream ss;

		// discarding garbage values
		for(int i=0; i<2; i++) {
			string temp;
			ss << line;
			ss >> temp;
		}

		// converting column string to double
		ss << line;
		ss >> word;
		stringstream tt;
		tt << word;
		double val;
		tt >> val;
		double diff;

		diff = val-prev;
		prev = val;
		sum += diff;

		v[count].time = sum;
		count++;
	}
	
}

void time(ifstream& input, vector<Thresh>& v) {

	// declaring stringstream variables
	string line, word;
	double prev;
	int count = 0;
	double sum = 0;

	// takes in each line, reads garbage numbers up to column number
	// takes the column we want and compares to prev max/min and resets
	// if need be
	while(getline(input, line)) {
		stringstream ss;

		// discarding garbage values
		for(int i=0; i<1; i++) {
			string temp;
			ss << line;
			ss >> temp;
		}

		// converting column string to double
		ss << line;
		ss >> word;
		stringstream tt;
		tt << word;
		string val;
		tt >> val;

		stringstream rr;
		rr << val;
		char temp;
		rr >> temp;
		int h = 0;
		while((temp != ':') || (h != 2)) {
			rr >> temp;
			if(temp == ':') {
				h++;
			}
		}

		double curr;
		rr >> curr;

		double diff;

		if(count == 0) {
			prev = curr;
			diff = 0;
		} else {
			diff = curr-prev;
			sum += diff;
			prev=curr;
		}

		v[count].time = sum;
		count++;
	}
	
}

void y(ifstream& input, vector<Thresh>& y, int col) {
	// declaring stringstream variables
	string line, word;

	// takes in each line, reads garbage numbers up to column number
	// takes the column we want and compares to prev max/min and resets
	// if need be
	while(getline(input, line)) {
		stringstream ss;

		// discarding garbage values
		for(int i=0; i<col; i++) {
			string temp;
			ss << line;
			ss >> temp;
		}

		// converting column string to double
		ss << line;
		ss >> word;
		stringstream tt;
		tt << word;
		double val;
		tt >> val;

		Thresh v(val);

		y.push_back(v);
	}
}

void derivative(vector<Thresh>& v) {
	v[0].derivative = 0;

	double prev = v[0].y;
	for(unsigned int i=1; i<v.size(); i++) {
		double curr = v[i].y;
		double diff = curr - prev;
		prev = curr;
		v[i].derivative = diff;
	}
}


void swap(vector<Thresh>& v, int x, int z);

void quicksortY(vector<Thresh> &vec, int L, int R) {
    int i, j, mid; 
    double piv;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    piv = abs(vec[mid].y);

    while (i<R || j>L) {
        while (abs(vec[i].y) < piv)
            i++;
        while (abs(vec[j].y) > piv)
            j--;

        if (i <= j) {
            swap(vec, i, j); //error=swap function doesnt take 3 arguments
            i++;
            j--;
        }
        else {
            if (i < R)
                quicksortY(vec, i, R);
            if (j > L)
                quicksortY(vec, L, j);
            return;
        }
    }
}

void swap(vector<Thresh>& v, int x, int z) {
    double ty = v[x].y;
    double tt = v[x].time;
    double td = v[x].derivative;
    v[x].y = v[z].y;
    v[x].time = v[z].time;
    v[x].derivative = v[z].derivative;
    v[z].y = ty;
    v[z].time = tt;
    v[z].derivative = td;

}

// I KNOW I COULD MAKE A COMPARATOR AND PASS IN DIFF COMPARATORS BUT THIS IS TRULY EASIER

void quicksortT(vector<Thresh> &vec, int L, int R) {
    int i, j, mid; 
    double piv;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    piv = abs(vec[mid].time);

    while (i<R || j>L) {
        while (abs(vec[i].time) < piv)
            i++;
        while (abs(vec[j].time) > piv)
            j--;

        if (i <= j) {
            swap(vec, i, j); //error=swap function doesnt take 3 arguments
            i++;
            j--;
        }
        else {
            if (i < R)
                quicksortT(vec, i, R);
            if (j > L)
                quicksortT(vec, L, j);
            return;
        }
    }
}

void format(ofstream& output, vector<Thresh>& v) {
	for(unsigned int i=0; i<v.size(); i++) {
		output << v[i].time << " - " << v[i].y << " - " << v[i].derivative << endl;
	}
}


// ASSUMES AT LEAST 20 IN THE VECTOR
vector<Thresh> window(vector<Thresh>& v, double w, int peaks) {
	vector<Thresh> final;

	int count = static_cast<int>(v.size()-1);
	final.push_back(v[count--]);
	while((final.size() < peaks) && (count > 0)) {
		bool good = true;
		for(unsigned int i=0; i<final.size();i++) {
			if(abs(abs(v[count].time) - abs(final[i].time)) < w) {
				good = false;
			}
		}
		if(good) {
			final.push_back(v[count]);
			count--;
		} else {
			count--;
		}
	}
	return final;
}

double dist(vector<Thresh>& v) {
	double sum = 0;
	double prev = v[0].time;
	for(unsigned int i=1; i<v.size(); i++) {
		double diff = abs(prev-v[i].time);
		sum += diff;
		prev = v[i].time;
	}

	return sum/(static_cast<int>(v.size()-1));
}

void neg(vector<Thresh>& v) {
	vector<Thresh> final;
	for(unsigned int i=0; i<v.size(); i++) {
		if(v[i].y > 0) {
			final.push_back(v[i]);
		}
	}

	v = final;
}

double max(vector<Thresh>& v) {
	double max = 0;
	for(unsigned int i=1; i<v.size(); i++) {
		double step = v[i].time - v[i-1].time;
		if(step > max) {
			max = step;
		}
	}
	return max;
}

double min(vector<Thresh>& v) {
	double min = 10000000;
	for(unsigned int i=1; i<v.size(); i++) {
		double step = v[i].time - v[i-1].time;
		if(step < min) {
			min = step;
		}
	}
	return min;
	
}

double avg(vector<Thresh>& v) {
	double sum = 0;
	int count = 0;
	for(unsigned int i=1; i<v.size(); i++) {
		double step = v[i].time - v[i-1].time;
		sum += step;
		count++;
	}
	return sum/count;
}

double miny(vector<Thresh>& v) {
	double min = 10000000;
	for(unsigned int i=0; i<v.size(); i++) {
		if(v[i].y < min) {
			min = v[i].y;
		}
	}
	return min;
	
}


/* THIS IS TO FIND THE ThreshOLD THIS ALGO IS TO FIND THE ThreshOLD */

int main(int argc, char* argv[]) {
	if(argc < 5) {
		cout << "ERROR: prog oculus slow 11 file" << endl;
		return -1;
	}

	bool oculus = false;
	string path = "../gdata/";

	int ycol = 5;

	unsigned int SIZE = 0;
	vector<string> file;
	string arg1 = argv[1];
	string arg2 = argv[2];


	double win;
	string speaks = argv[3];
	stringstream ss;
	ss << speaks;
	int peaks;
	ss >> peaks;

	if (arg1 == "oculus") {
		oculus = true;
	}

	if(arg2 == "slow") {
		win = 0.4;
	} else if(arg2 == "med") {
		win = 0.3;
	} else {
		win = 0.2;
	}

	if(oculus) {
		// SIZE = 3;
		// string oculus[SIZE] = {"ohKneeS.txt", "ohkneeM.txt", "ohKneeF.txt"};
		// for(unsigned int i=0; i<SIZE; i++) {
		// 	file.push_back(oculus[i]);
		// }
		path = "../odata/";

		ycol = 9;

	} else {
		// SIZE = 3;
		// string gear[SIZE] = {"ghKneeS.txt", "ghKneeM.txt", "ghKneeF.txt"};
		// for(unsigned int i=0; i<SIZE; i++) {
		// 	file.push_back(gear[i]);
		// }
	}

	SIZE = 1;
	string fname = argv[4];
	file.push_back(fname);

	// creates dynamic array of input and output file paths
	string* inputs = new string[SIZE];
	string* outputs = new string[SIZE];

	// fills in arrays with file paths
	for(unsigned int i=0; i<file.size(); i++) {
		// string ipath = "./odata/" + file[i];
		// string opath = "./panalysis/P" + file[i];
		string ipath = path + file[i];
		string opath = "../Ranalysis/R" + file[i];
		inputs[i] = ipath;
		outputs[i] = opath;
	}


	// HAVE TO LOOK AT THE GRAPH AND COUNT THE PEAKS IN ORDER TO SET
	// NUMBER OF HOW MANY PEAKS TO LOOK FOR

	// iterates through all files and performs the analysis
	for(unsigned int j=0; j<SIZE; j++) {
	// iterating through columns from col input --> final column
		vector<Thresh> ys;

		ofstream output(outputs[j]);

		ifstream input(inputs[j]);
		cout << "HEREEEEEEE" << endl;


		ifstream input1(inputs[j]);
		y(input1, ys, ycol);

		if(oculus) {
			time(input, ys);
		} else {
			gtime(input, ys);
		}

		neg(ys);

		// derivative(ys);
		// cout << "d: " << dist(ys) << endl;


		quicksortY(ys, 0, static_cast<int>(ys.size()-1));


		// use diff window thresholds for the slow, medium, fast
		vector<Thresh> sm = window(ys, win, peaks);

		quicksortT(sm, 0, static_cast<int>(sm.size()-1));
		cout << "small: " << dist(sm) << endl;

		for(unsigned int i=0; i<sm.size(); i++) {
			cout << sm[i].time << endl;
		}

		cout << "MAX: " << max(sm) << endl;
		cout << "MIN: " << min(sm) << endl;
		cout << "AVG: " << avg(sm) << endl;

		cout << miny(sm) << endl;

		// threshold for time should be min time - .06 for error
		// so this would be 0.58 for slow
		
		// or look at avg of the bottom half% and then subtract for error
		// NEED MORE SLOW MEDIUM FAST DATA TO TEST THIS ON


		vector<Thresh> final = sm;
		// int len = static_cast<int>(final.size());
		// double start = 0.2;
		// double end = static_cast<double>(dist(final));


		// int SIZE = 10;
		// int count = 0;
		// vector<Thresh> temp;

		// while ((len != SIZE) && count < 100) {

		// 	double distance = (end-start)/2 + start;

		// 	temp = window(final, static_cast<double>(dist(final)));
		// 	len = static_cast<int>(temp.size());

		// 	if(len > SIZE) {
		// 		start = distance;
		// 	} else {
		// 		end = distance;
		// 	}
		// 	count++;
		// }

		// cout << count << endl;
		// final = temp;

		// for any that are under the average time different (or some percentage of it) then remove those and if
		// the size of the new vector is below whatever we want it to be then add back the most recent ones

		// vector<Thresh> xs = window(sm, static_cast<double>(dist(sm)));

		// create temp vector and assign 

		cout << "Time before considering " << arg2 << " threshold: " << min(sm) - 0.02 << endl;
		cout << "Acceleration threshold for " << arg2 << ": " << miny(sm) - 0.3 << endl;
		format(output, final);

		// quicksort y
	}

	// frees memory
	delete [] inputs;
	delete [] outputs;

	return 0;
}