// putting everything in one file

// - Extract from file into another file names slow.txt, med.txt, fast.txt then run rest of program using slow med fast
//     - Rest of program can be that it plots it 
//     - Then it pauses and waits for input on the peak number 
//     - Then after giving the peak numbers it runs the rest and tells you the window tdiff and threshold

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

/* HELPERS FOR PYTHON FUNCTION */
void gtime(ifstream& input, vector<double>& sums) {

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

		sums.push_back(sum);
	}
}

void time(ifstream& input, vector<double>& sums) {

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
/* ************** PYTHON HELPERS END ***************** */

void python(bool oculus, int ycol, ofstream& output, ifstream& input) {
	vector<double> times;
	vector<double> ys;

	if(oculus) {
		time(input, times);
	} else {
		gtime(input, times);
	}

	y(input, ys, ycol);

	output << "t = ";
	format(output, times);

	output << "y = ";
	format(output, ys);

}

// basically will do the three S, M, F and put them in an array
// then will go through
// then will plot and can count and then will add the peak for that one and run the rest
// and then do plot for the next
// will always do slow, m, fast, so can output the 
int main(int argc, char* argv[]) {

/* DIFFERENCES BETWEEN OCULUS AND GEAR */
	string path;
	int ycol;
	string arg = argv[1];
	bool oculus = false;

	if(arg == "oculus") {
		path = "../odata/";
		ycol = 9;
		oculus = true;
	} else {
		path = "../gdata/";
		ycol = 5;
		oculus = false;
	}
/* *********************************** */

/* FILL ARRAY WITH TRIAL SLOW MEDIUM AND FAST FILE NAMES */
	unsigned int SIZE = 3;
	vector<string> file;
	file.push_back("slow.txt");
	file.push_back("med.txt");
	file.push_back("fast.txt");
/* **************************************************** */

/* CREATE INPUT AND OUTPUT FILE PATHS */
	string* inputs = new string[SIZE];
	string* outputs = new string[SIZE];

	// fills in arrays with file paths
	for(unsigned int i=0; i<file.size(); i++) {
		string ipath = path + file[i];
		string opath = "../testing/" + file[i];
		inputs[i] = ipath;
		outputs[i] = opath;
	}
/* ********************************** */


// FIRST THING WE NEED TO DO IS CLEAN THE DATA AND PLOT IT
	// MAYBE DO THIS IN ANOTHER PROGRAM THAT SPITS IT OUT IN ODATA GSATA SLOW MEDIUM FAST

// CREATE AND CALL PYTHON SCRIPT TO PLOT THE DATA

// IN A LOOP ???
	ifstream pyin(inputs[i]);

/* SEND STANDARD HEADER TEMPLATE TO PYTHON FILE */
	string ppath = "plot" + i + ".py";
	ofstream pyout(ppath);
	pyout << "import matplotlib.pyplot as plt" << endl;

/* ******************************************** */

/* PERFORM ANALYSIS ON THE FILE */
	python(oculus, ycol, pyout, pyin);


/* SEND STANDARD FOOTER TEMPLATE TO PYTHON FILE */
	pyout << "plt.plot(t,y)" << endl;
	pyout << "plt.ylabel('acceleration')" << endl;

	pyout << "plt.savefig(" << file[i] << ")" << endl;
	pyout << "plt.show()" << endl;
	pyout << "plt.close()" << endl;

/* ********************************************* */


/* CALL THE PYTHON SCRIPT FROM HERE */
	string command = "python \"" + pplot + "\"";
	system(command);
/* ******************************** */

/* ASK USER FOR NUMBER OF PEAKS AND USE AS NUM */






/* ******************************************* */


/* THRESHOLD ANALYSIS - should write thresholds to a file */
	ofstream output(outputs[i]);
	ifstream input(inputs[i]);

	threshold(oculus, output, input);
	// DO ALL OF THIS ALL OF THIS ALL OF THIS AND PUT IT IN A LOOP


/* ****************** */




	// iterates through all files and performs the analysis
	for(unsigned int j=0; j<SIZE; j++) {
	// iterating through columns from col input --> final column
		vector<Thresh> ys;

		ofstream output(outputs[j]);

		ifstream input(inputs[j]);


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