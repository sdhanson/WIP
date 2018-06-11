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



// global variable for column names 
string colNames[] = {"Date", "Time", "Rand1", "Rand2", "letter", "Unity", "colon",
	"Acceleration marker", "accel.x", "accel.y", "accel.z", "Euler marker",
	"euler.x", "euler.y", "euler.z"};

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
vector<Thresh> window(vector<Thresh>& v, double w) {
	vector<Thresh> final;

	int count = static_cast<int>(v.size()-1);
	final.push_back(v[count--]);
	while((final.size() < 20) && (count > 0)) {
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


/* THIS IS TO FIND THE ThreshOLD THIS ALGO IS TO FIND THE ThreshOLD */

int main(int argc, char* argv[]) {
	if(argc < 2) {
		cout << "ERROR" << endl;
		return -1;
	}

	bool oculus = false;
	string path = "../gdata/";

	int ycol = 5;

	unsigned int SIZE = 0;
	vector<string> file;
	string arg = argv[1];

	if (arg == "oculus") {
		oculus = true;
	}
	if(oculus) {
		SIZE = 22;
		string oculus[SIZE] = {"owalk101.txt", "owalk102.txt", "owalk103.txt", "owalk104.txt"
						,"owalks7.txt", "owalks17.txt", "owalks27.txt", "ohKneeS.txt",
						"ohKneeF.txt", "oNormM.txt", "oNormS.txt", "oShuffM.txt",
						"oVarL.txt", "oVar201.txt", "oVar202.txt", "oVar203.txt",
						"ohkneeM.txt", "oStand.txt", "oLook.txt", "oVarHK201.txt",
						"oVarHK202.txt", "oVarHK203.txt"};
		for(unsigned int i=0; i<SIZE; i++) {
			file.push_back(oculus[i]);
		}
		path = "../odata/";

		ycol = 9;

	} else {
		SIZE = 4;
		string gear[SIZE] = {"ghKneeF.txt", "ghKneeS.txt", "ghKneeM.txt", "ghVar201.txt"};
		for(unsigned int i=0; i<SIZE; i++) {
			file.push_back(gear[i]);
		}
	}

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

		derivative(ys);

		quicksortY(ys, 0, static_cast<int>(ys.size()-1));

		// format(output, ys);

		vector<Thresh> sm = window(ys, 0.2);

		quicksortT(sm, 0, static_cast<int>(sm.size()-1));

		cout << dist(ys) << endl;

		// for any that are under the average time different (or some percentage of it) then remove those and if
		// the size of the new vector is below whatever we want it to be then add back the most recent ones

		vector<Thresh> xs = window(sm, static_cast<double>(dist(sm)));

		format(output, xs);

		// quicksort y
	}

	// frees memory
	delete [] inputs;
	delete [] outputs;

	return 0;
}