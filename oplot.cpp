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


int main() {
	// creating array of file names so when one thing is changed in .cpp
	// we can change all of the output files at once
	int SIZE = 22;
	string file[SIZE] = {"owalk101.txt", "owalk102.txt", "owalk103.txt", "owalk104.txt"
						,"owalks7.txt", "owalks17.txt", "owalks27.txt", "ohKneeS.txt",
						"ohKneeF.txt", "oNormM.txt", "oNormS.txt", "oShuffM.txt",
						"oVarL.txt", "oVar201.txt", "oVar202.txt", "oVar203.txt",
						"ohkneeM.txt", "oStand.txt", "oLook.txt", "oVarHK201.txt",
						"oVarHK202.txt", "oVarHK203.txt"};

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
		y(input1, ys, 9);

		ifstream input2(inputs[j]);
		y(input2, xs, 8);

		ifstream input3(inputs[j]);
		y(input3, zs, 10);

		output << "t = ";
		format(output, sums);

		// output << "t = ";
		// format(output, times);

		output << "x = ";
		format(output, xs);


		output << "y = ";
		format(output, ys);


		output << "z = ";
		format(output, zs);

		output << "SMOOTH" << endl;
		output << "t = ";	
		format(output, sums);

		vector<double> xf = average(xs);
		output << "x = ";
		format(output, xf);

		vector<double> yf = average(ys);
		output << "y = ";
		format(output, yf);

		vector<double> zf = average(zs);
		output << "z = ";
		format(output, zf);
	}

	// frees memory
	delete [] inputs;
	delete [] outputs;

	return 0;
}