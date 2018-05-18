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
string colNames[] = {"Date", "Time", "Delta Time", "Mouse Button", "userAcceleration.x", "userAcceleration.y", "userAcceleration.z",
	"gameObject.transform.position.x", "gameObject.transform.position.y", "gameObject.transform.position.z", "eulerAngles.x", "eulerAngles.y",
	"eulerAngles.z"};

void increasing(ifstream& input, int col, ofstream& output) {
	// declaring stringstream variables
	string line, word;

	// initializing lineNum
	int lineNum = 1;

	// initializing prev & bool (!increasing = decreasing)
	double prev = 0;
	bool increasing;
	bool pair = false;
	double start, end;
	vector<std::pair<int, int> > inc;
	vector<std::pair<int, int> > dec;


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
		double gyro_y;
		tt >> gyro_y;

		// converting from 360 to 180 so 359 --> 1 is now -1 --> 1
		// only for eulerangle columns
		if(col >= 9) {
			if((gyro_y > 180) || (gyro_y < -180)) {
				gyro_y -= 360;
			}
		}

		// whenever switches want to record the lines --> pair and push into a vector
		if(lineNum == 1) { 
			prev = gyro_y;
		} else if(lineNum == 2) {
			if(abs(gyro_y) >= prev) {
				increasing = true;
			} else {
				increasing = false;
			}
			start = lineNum-1;
		}
		else {
			if((gyro_y > 0)) {
				if(increasing && (gyro_y < prev)) {
					increasing = false;
					end = lineNum-1;
					pair = true;
				} else if(!increasing && (gyro_y > prev)) {
					increasing = true;
					end = lineNum-1;
					pair = true;
				}
			} else {
				// negative so if its increasing and then we have 
				// -0.2 instead of -0.5 then decreasing
				if(increasing && (gyro_y > prev)) {
					increasing = false;
					end = lineNum-1;
					pair = true;
				} else if(!increasing && (gyro_y < prev)) {
					increasing = true;
					end = lineNum-1;
					pair = true;
				}
			}
		}

		if(pair) {
			if(!increasing) {
				inc.push_back(make_pair(start, end));
			} else {
				dec.push_back(make_pair(start, end));
			}
			start = lineNum;
			pair = false;
		}
		prev = gyro_y;
		lineNum++;
	}

	// printing data to output
	output << "INCREASING / DECREASING" << endl;
	output << "Increasing: " << endl;
	vector<std::pair<int, int> >::iterator it;
	for(it = inc.begin(); it != inc.end(); it++) {
		output << it->first << " " << it->second << endl;
	}
	output << "Decreasing: " << endl;
	vector<std::pair<int, int> >::iterator it2;
	for(it2 = dec.begin(); it2 != dec.end(); it2++) {
		output << it2->first << " " << it2->second << endl;
	}
	output << endl;

}

// finds max/min magnitudes & line number
void absMaxMin(ifstream& input, int col, ofstream& output) {
	// declaring stringstream variables
	string line, word;

	// initializing the max/min/lineNum variables
	double max = 0;
	double min = 1000000;
	int lineNum = 1;
	int lineMax, lineMin;

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
		double gyro_y;
		tt >> gyro_y;

		// converting from 360 to 180 so 359 --> 1 is now -1 --> 1
		// only for eulerangle columns
		if(col >= 9) {
			if((gyro_y > 180) || (gyro_y < -180)) {
				gyro_y -= 360;
			}
		}

		// comparisons to reset max/min and line nums
		if(abs(gyro_y) > max) {
			max = abs(gyro_y);
			lineMax = lineNum;
		}
		if(abs(gyro_y) < min) {
			if(gyro_y > 0.00001) {
				min = abs(gyro_y);
				lineMin = lineNum;
			}
		}
		lineNum++;
	}

	// printing data to output
	output << "ABSOLUTE VALUE MAX/MIN" << endl;
	output << "Max: " << max << " line: " << lineMax << endl;
	output << "Min: " << min << " line: " << lineMin << endl;
	output << endl;
}

// finds max/min acceleration & line number
void signMaxMin(ifstream& input, int col, ofstream& output) {
	// declaring stringstream variables
	string line, word;

	// initializing the max/min/lineNum variables
	double max = 0;
	double min = 1000000;
	int lineNum = 1;
	int lineMax, lineMin;

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
		double gyro_y;
		tt >> gyro_y;

		// converting from 360 to 180 so 359 --> 1 is now -1 --> 1
		// only for eulerangle columns
		if(col >= 9) {
			if((gyro_y > 180) || (gyro_y < -180)) {
				gyro_y -= 360;
			}
		}

		// comparisons to reset max/min and line nums
		if(gyro_y >= max) {
			max = gyro_y;
			lineMax = lineNum;
		}
		if(gyro_y <= min) {
			if(gyro_y != 0) {
				min = gyro_y;
				lineMin = lineNum;
			}
		}
		lineNum++;
	}

	// printing data to output
	output << "NON ABSOLUTE VALUE MAX/MIN" << endl;
	output << "Max: " << max << " line: " << lineMax << endl;
	output << "Min: " << min << " line: " << lineMin << endl;
	output << endl;
}

void change(ifstream& input, int col, ofstream& output) {
	// declaring stringstream variables
	string line, word;

	// initializing max/min/lineNum variables
	double max = 0;
	double min = 1000000;
	int lineNum = 1;
	int lineMax, lineMin;

	// initializing prev (used to calc change)
	double prev = 0;

	// initializing avg and count (used to divide total by total count to get avg)
	double avg = 0;
	int count = 0;

	// takes in each line, reads garbage numbers up to column number
	// takes the column we want and calcs abs value change bc prev and curr num
	// if need be resets max/min change and line numbers and adds to total avg
	while(getline(input, line)) {
		stringstream ss;

		// discarding garbage variables
		for(int i=0; i<col; i++) {
			string temp;
			ss << line;
			ss >> temp;
		}

		// converting column string to number
		ss << line;
		ss >> word;
		stringstream tt;
		tt << word;
		double gyro_y;
		tt >> gyro_y;

		// converting from 360 to 180 so 359 --> 1 is now -1 --> 1
		// only for eulerangle columns
		if(col >= 9) {
			if((gyro_y > 180) || (gyro_y < -180)) {
				gyro_y -= 360;
			}
		}

		// calculates abs change and manages avg variables
		// ignore first line bc starting point (prev is default 0)
		if(lineNum != 1) {
		double change = abs(abs(gyro_y) - prev);
		avg += change;
		count++;

			// resets max/min/line num if need be
			if(change > max) {
				max = change;
				lineMax = lineNum;
			}
			if(change < min) {
				if(change != 0) {
					min = change;
				}
				lineMin = lineNum;
			}
		}

		// resets prec
		prev = abs(gyro_y);
		lineNum++;
	}

	// calculates avg
	avg = avg/count;

	// outputs data
	output << "ABSOLUTE VALUE ONE STEP CHANGE" << endl;
	output << "Max change: " << max << " line: " << lineMax << endl;
	output << "Min change: " << min << " line: " << lineMin << endl;
	output << "Average change: " << avg << endl;
	output << endl;
}


int main(int argc, char* argv[]) {
	// checking inputs & printing desired format if incorrect num
	if(argc < 2) {
		cout << "EXEC COL" << endl;
	}

	// col number we want to start analysis at
	stringstream colNum;
	colNum << argv[1];
	int col;
	colNum >> col;


	// creating array of file names so when one thing is changed in .cpp
	// we can change all of the output files at once
	int SIZE = 20;
	string file[SIZE] = {"sitting.txt", "stepping.txt", "step1.txt", "step2.txt",
		"step3.txt", "step4.txt", "walking.txt", "looking.txt", "footL.txt", "footLU.txt",
		"footLD.txt", "footR.txt", "footRU.txt", "footRD.txt", "walk1.txt", "walk2.txt",
		"walk3.txt", "walk4.txt", "sit1.txt", "look1.txt"};

	// creates dynamic array of input and output file paths
	string* inputs = new string[SIZE];
	string* outputs = new string[SIZE];

	// fills in arrays with file paths
	for(int i=0; i<SIZE; i++) {
		string ipath = "./data/" + file[i];
		string opath = "./analysis/O" + file[i];
		inputs[i] = ipath;
		outputs[i] = opath;
	}

	// iterates through all files and performs the analysis
	for(int j=0; j<SIZE; j++) {
	// iterating through columns from col input --> final column
		ofstream output(outputs[j]);
		for(int i=col; i<13; i++) {
			output << "COL: " << colNames[i] << endl;
			ifstream input(inputs[j]);
			absMaxMin(input, i, output);

			ifstream input2(inputs[j]);
			signMaxMin(input2, i, output);

			ifstream input3(inputs[j]);
			change(input3, i, output);
			output << endl;

			ifstream input4(inputs[j]);
			increasing(input4, i, output);
			output << endl;
		}
	}

	// frees memory
	delete [] inputs;
	delete [] outputs;


	return 0;
}
