#include <iostream>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// global variable for column names 
string colNames[] = {"Date", "Time", "Delta Time", "Mouse Button", "userAcceleration.x", "userAcceleration.y", "userAcceleration.z",
	"gameObject.transform.position.x", "gameObject.transform.position.y", "gameObject.transform.position.z", "eulerAngles.x", "eulerAngles.y",
	"eulerAngles.z"};


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
	if(argc != 4) {
		cout << "EXEC INPUT COL OUTPUT" << endl;
	}

	// initializing output and col number we want to start 
	// out analysis at
	ofstream output(argv[3]);
	stringstream colNum;
	colNum << argv[2];
	int col;
	colNum >> col;

	// iterating through columns from col input --> final column
	for(int i=col; i<13; i++) {
		output << "COL: " << colNames[col] << endl;
		ifstream input(argv[1]);
		absMaxMin(input, col, output);

		ifstream input2(argv[1]);
		signMaxMin(input2, i, output);

		ifstream input3(argv[1]);
		change(input3, i, output);
		output << endl;
	}
	return 0;
}
