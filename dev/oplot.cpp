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

void swap(vector<double>& v, int x, int y);

void quicksort(vector<double> &vec, int L, int R) {
    int i, j, mid; 
    double piv;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    piv = vec[mid];

    while (i<R || j>L) {
        while (vec[i] < piv)
            i++;
        while (vec[j] > piv)
            j--;

        if (i <= j) {
            swap(vec, i, j); //error=swap function doesnt take 3 arguments
            i++;
            j--;
        }
        else {
            if (i < R)
                quicksort(vec, i, R);
            if (j > L)
                quicksort(vec, L, j);
            return;
        }
    }
}

void swap(vector<double>& v, int x, int y) {
    double temp = v[x];
    v[x] = v[y];
    v[y] = temp;

}

vector<double> twenty(vector<double>& v) {
	vector<double> final;
	int range = v.size()-1-20;
	if(v.size()-1 < 20) {
		range = 0;
	}
	for(unsigned int i=range; i<v.size(); i++) {
		final.push_back(v[i]);
	}
	return final;
}


int main(int argc, char* argv[]) {
	if(argc < 2) {
		cout << "ERROR" << endl;
		return -1;
	}

	bool oculus = false;
	string path = "./gdata/";
	int xcol = 4;
	int ycol = 5;
	int zcol = 6;
	unsigned int SIZE = 0;
	vector<string> file;
	string arg = argv[1];

	if (arg == "oculus") {
		oculus = true;
	}
	if(oculus) {
		SIZE = 30;
		string oculus[SIZE] = {"owalk101.txt", "owalk102.txt", "owalk103.txt", "owalk104.txt"
						,"owalks7.txt", "owalks17.txt", "owalks27.txt", "ohKneeS.txt",
						"ohKneeF.txt", "oNormM.txt", "oNormS.txt", "oShuffM.txt",
						"oVarL.txt", "oVar201.txt", "oVar202.txt", "oVar203.txt",
						"ohkneeM.txt", "oStand.txt", "oLook.txt", "oVarHK201.txt",
						"oVarHK202.txt", "oVarHK203.txt", "oVarHK181.txt", "oVarHK16.txt", "oVarHK101.txt",
						"oVarHK17.txt", "oVarHK131.txt", "oVarHK171.txt",
						"oVarHK121.txt", "oVar161.txt"};
		for(unsigned int i=0; i<SIZE; i++) {
			file.push_back(oculus[i]);
		}
		path = "./odata/";
		xcol = 8;
		ycol = 9;
		zcol = 10;
	} else {
		SIZE = 4;
		string gear[SIZE] = {"ghKneeF.txt", "ghKneeS.txt", "ghKneeM.txt", "ghVar201.txt"};
		for(unsigned int i=0; i<SIZE; i++) {
			file.push_back(gear[i]);
		}
	}

	// creating array of file names so when one thing is changed in .cpp
	// we can change all of the output files at once


	// CHANGE SO AUTOMATICALLY SWITCHES FOR GEAR AND USE COLUMN TWO FOR THE TIME STEP!!



	// creates dynamic array of input and output file paths
	string* inputs = new string[SIZE];
	string* outputs = new string[SIZE];

	// fills in arrays with file paths
	for(unsigned int i=0; i<file.size(); i++) {
		// string ipath = "./odata/" + file[i];
		// string opath = "./panalysis/P" + file[i];
		string ipath = path + file[i];
		string opath = "./panalysis/P" + file[i];
		inputs[i] = ipath;
		outputs[i] = opath;
	}



	// iterates through all files and performs the analysis
	for(unsigned int j=0; j<SIZE; j++) {
	// iterating through columns from col input --> final column
		vector<double> times;
		vector<double> sums;
		vector<double> ys;
		vector<double> xs;
		vector<double> zs;

		ofstream output(outputs[j]);

		ifstream input(inputs[j]);
		cout << "HEREEEEEEE" << endl;
		if(oculus) {
			time(input, sums, times);
		} else {
			gtime(input, sums, times);
		}

		ifstream input1(inputs[j]);
		y(input1, ys, ycol);

		ifstream input2(inputs[j]);
		y(input2, xs, xcol);

		ifstream input3(inputs[j]);
		y(input3, zs, zcol);

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

		output << "DERIVATIVE" << endl;
		output << "t = ";
		format(output, sums);

		output << "y = ";
		vector<double> d = derivative(ys);
		format(output, d);

		output << "SECOND DERIVATIVE" << endl;
		output << "t = ";
		format(output, sums);

		output << "y = ";
		vector<double> sd = derivative(d);
		format(output, sd);

		output << "BASELINE SUBTRACTION" << endl;
		output << "t = ";
		format(output, sums);

		output << "y = ";
		baseline(ys);
		format(output, ys);

		// quicksort y
	}

	// frees memory
	delete [] inputs;
	delete [] outputs;

	return 0;
}