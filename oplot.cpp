#include <iostream>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <utility>
#include <vector>


using namespace std;

// global variable for column names 
string colNames[] = {"Date", "Time", "Rand1", "Rand2", "letter", "Unity", "colon",
	"Acceleration marker", "accel.x", "accel.y", "accel.z", "Euler marker",
	"euler.x", "euler.y", "euler.z"};


void time(ifstream& input, vector<double>& t) {

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
			count++;
		} else {
			diff = curr-prev;
			sum += diff;
			prev=curr;
		}

		t.push_back(sum);
	}
	
}

void y(ifstream& input, vector<double>& y, int col) {
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

		y.push_back(val);
	}
}

void format(ofstream& output, vector<double>& v) {
	output << "Length: " << v.size() << endl;
	output << "[";
	for(unsigned int i=0; i<v.size(); i++) {
		if(i == v.size()-1) {
			output << v[i] << "]" << endl;
		} else {
			output << v[i] << ", ";
		}
	}
}


int main() {
	// creating array of file names so when one thing is changed in .cpp
	// we can change all of the output files at once
	// int SIZE = 11;
	int SIZE = 1;
	string file[SIZE] = {"owalk4.txt"};
	// string file[SIZE] = {"oevery.txt", "osit1.txt", "osit2.txt", "osit3.txt", "osit4.txt", 
	// 					"owalk1.txt", "owalk2.txt", "owalk3.txt", "owalk4.txt", "oud.txt", "olr.txt"};

	// creates dynamic array of input and output file paths
	string* inputs = new string[SIZE];
	string* outputs = new string[SIZE];

	// fills in arrays with file paths
	for(int i=0; i<SIZE; i++) {
		string ipath = "./odata/" + file[i];
		string opath = "./panalysis/P" + file[i];
		inputs[i] = ipath;
		outputs[i] = opath;
	}

	vector<double> times;
	vector<double> ys;
	vector<double> xs;
	vector<double> zs;

	// iterates through all files and performs the analysis
	for(int j=0; j<SIZE; j++) {
	// iterating through columns from col input --> final column
		ofstream output(outputs[j]);

		ifstream input(inputs[j]);
		cout << "HEREEEEEEE" << endl;
		time(input, times);

		ifstream input1(inputs[j]);
		y(input1, ys, 9);

		ifstream input2(inputs[j]);
		y(input2, xs, 8);

		ifstream input3(inputs[j]);
		y(input3, zs, 10);

		output << "TIME VECTOR" << endl;
		format(output, times);

		output << "X VECTOR" << endl;
		format(output, xs);

		output << "Y VECTOR" << endl;
		format(output, ys);

		output << "Z VECTOR" << endl;
		format(output, zs);
	}

	// frees memory
	delete [] inputs;
	delete [] outputs;

	return 0;
}