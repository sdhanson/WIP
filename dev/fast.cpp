#include <iostream>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

// global variable for column names 
string colNames[] = {"Date", "Time", "Rand1", "Rand2", "letter", "Unity", "colon",
	"Acceleration marker", "accel.x", "accel.y", "accel.z", "Euler marker",
	"euler.x", "euler.y", "euler.z"};

void gtime(ifstream& input, vector<double>& sums, vector<double>& t) {

	// declaring stringstream variables
	string line, word;
	double prev;
	double sum = 0;

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

		t.push_back(diff);
		sums.push_back(sum);
	}
	
}

void time(ifstream& input, vector<double>& sums, vector<double>& t) {

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

		t.push_back(diff);
		sums.push_back(sum);
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
	output << "[";
	for(unsigned int i=0; i<v.size(); i++) {
		if(i == v.size()-1) {
			output << v[i] << "]" << endl;
		} else {
			output << v[i] << ", ";
		}
	}
}

vector<double> average(vector<double>& v) {
	vector<double> final;

	final.push_back(v[0]);
	// final.push_back(v[1]);
	// final.push_back(v[2]);

	for(unsigned int i=1; i<v.size()-1; i++) {
		double sum = v[i-1] + v[i] + v[i+1];
		double avg = sum/3.0;
		final.push_back(avg);
	}
	// final.push_back(v[v.size()-3]);
	// final.push_back(v[v.size()-2]);
	final.push_back(v[v.size()-1]);

	return final;
}

void step(vector<double>& t, vector<double>& v, double threshold) {
	vector<double> times;
	vector<double> vals;
	double pt = 0;
	for(unsigned int i=1; i<v.size(); i++) {
		if(v[i] > threshold && ((t[i]-pt) > 0.4)) {
			times.push_back(t[i]);
			vals.push_back(v[i]);
			pt=t[i];
		}
	}
	t = times;
	v = vals;
}

void format_step(ofstream& output, vector<double>& times, vector<double>& vals, double threshold) {
	output << "TIMES > " << threshold << endl;
	output << "TIME - VALUE" << endl;
	for(unsigned int i=0; i<vals.size(); i++) {
		output << times[i] << " - " << vals[i] << endl;
	}
}

vector<double> derivative(vector<double>& v) {
	vector<double> final;

	final.push_back(0);

	double prev = v[0];
	for(unsigned int i=1; i<v.size(); i++) {
		double curr = v[i];
		double diff = curr - prev;
		prev = curr;
		final.push_back(diff);
	}

	return final;
}

void baseline(vector<double>& v) {
	for(unsigned int i=0; i<v.size(); i++) {
		if(v[i] < 0.5) {
			v[i] = 0;
		}
	}
}


int main() {
	// creating array of file names so when one thing is changed in .cpp
	// we can change all of the output files at once
	// int SIZE = 22;
	// string file[SIZE] = {"owalk101.txt", "owalk102.txt", "owalk103.txt", "owalk104.txt"
	// 					,"owalks7.txt", "owalks17.txt", "owalks27.txt", "ohKneeS.txt",
	// 					"ohKneeF.txt", "oNormM.txt", "oNormS.txt", "oShuffM.txt",
	// 					"oVarL.txt", "oVar201.txt", "oVar202.txt", "oVar203.txt",
	// 					"ohkneeM.txt", "oStand.txt", "oLook.txt", "oVarHK201.txt",
	// 					"oVarHK202.txt", "oVarHK203.txt"};

	int SIZE = 1;
	string file[SIZE] = {"oVarHK16.txt"};
	int xcol = 8;
	int ycol = 9;
	int zcol = 10;

	// creates dynamic array of input and output file paths
	string* inputs = new string[SIZE];
	string* outputs = new string[SIZE];

	// fills in arrays with file paths
	for(int i=0; i<SIZE; i++) {
		// string ipath = "./odata/" + file[i];
		// string opath = "./tanalysis/Td" + file[i];
		string ipath = "./odata/" + file[i];
		string opath = "./tanalysis/Td" + file[i];
		inputs[i] = ipath;
		outputs[i] = opath;
	}



	// iterates through all files and performs the analysis
	for(int j=0; j<SIZE; j++) {
	// iterating through columns from col input --> final column
		vector<double> times;
		vector<double> sums;
		vector<double> ys;
		vector<double> xs;
		vector<double> zs;

		ofstream output(outputs[j]);

		ifstream input(inputs[j]);
		cout << "HEREEEEEEE" << endl;
		time(input, sums, times);

		ifstream input1(inputs[j]);
		// col for y in oculus is 9, gear is 5
		y(input1, ys, 9);
		vector<double> d = derivative(ys);
		vector<double> sd = derivative(d);

		double threshold = 0.6;

		step(sums, sd, threshold);
		format_step(output, sums, sd, threshold);

	}

	// frees memory
	delete [] inputs;
	delete [] outputs;

	return 0;
}