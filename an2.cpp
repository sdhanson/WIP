#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>

#include "./threshold/thresh.h"

using namespace std;

string NAMES[12] = {"oh1", "oh2", "oh3", "oh4", "on1", "on2", "on3", "on4", "oc1", "oc2", "oc3", "oc4"};

/* FUNCTION TO CLEAN DATA AND SEND TO NEW SLOW FILE */
/* ********* ONLY WORKS FOR OCULUS RIGHT NOW ******** */
void clean(ifstream& input, ofstream& output) {
	// declaring stringstream variables
	string line;
	// takes in each line, reads garbage numbers up to column number
	// takes the column we want and compares to prev max/min and resets
	// if need be
	while(getline(input, line)) {
		stringstream ss;
		ss << line;
		bool select = false;
		char temp;

		// discarding garbage values
		while(ss >> temp) {
			string word;
			if(temp == 'A') {
				ss >> word;
				if(word == "CCELERATION_XYZ:") {
					select = true;
					break;
				}
			}
		}

		if(select) {
			output << line << endl;
		}	
	}
}

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
		if(diff < 0) {
			diff += 60;
		}
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
			if(diff < 0) {
				diff += 60;
			}
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

/* PYTHON fUNCTION TO MANAGE SETTING UP THE PYTHON FILE */
void python(bool oculus, int ycol, ofstream& output, ifstream& tinput, ifstream& input) {
	vector<double> times;
	vector<double> ys;

	if(oculus) {
		time(tinput, times);
	} else {
		gtime(tinput, times);
	}

	y(input, ys, ycol);

	output << "t = ";
	format(output, times);

	output << "y = ";
	format(output, ys);
}
/* *************************************************** */



/* THRESHOLD HELPER FUNCTIONS BEGIN HERE */

void gtimeT(ifstream& input, vector<Thresh>& v) {

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
		if(diff < 0) {
			diff += 60;
		}
		prev = val;
		sum += diff;

		v[count].time = sum;
		count++;
	}
	
}

void timeT(ifstream& input, vector<Thresh>& v) {
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
			if(diff < 0) {
				diff += 60;
			}
			sum += diff;
			prev=curr;
		}

		v[count].time = sum;
		count++;
	}	
}

void yT(ifstream& input, vector<Thresh>& y, int col) {
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

void formatT(ofstream& output, vector<Thresh>& v) {
	for(unsigned int i=0; i<v.size(); i++) {
		output << v[i].time << " - " << v[i].y << " - " << v[i].derivative << endl;
	}
}

/* *********** END OF THRESHOLD HELPER FUNCTIONS **************** */

vector<Thresh> test(vector<Thresh>& v) {
	bool low = false;
	double end = -100;
	double maxy = -100;
	double nend = 0;
	int maxi = 0;
	bool alert = false;
	bool high = false;
	bool valid = false;
	vector<Thresh> final;
	double ht = 2.8;
	double lt = -2.2;
	for(unsigned int i=0; i<v.size(); i++) {
		if(v[i].time > nend) {
		if(!alert) {
			if((v[i].y < lt) || (v[i].y > ht)) {
				alert = true;
				end = v[i].time + 0.25;
				if(v[i].y < lt) {
					low = true;
					high = false;	
				} else if(v[i].y > ht) {
					high = true;
					low = false;
				}
				maxy = v[i].y;
				maxi = i;
			}
		}
		else if(alert && (v[i].time < end)) {
			if(high && (v[i].y < lt)) {
					valid = true;
			}
			else if(low && (v[i].y > ht)) {
				valid = true;
			}
			if(v[i].y > maxy) {
				maxy = v[i].y;
				maxi = i;
			}
		} else if(alert && (v[i].time >= end)) {
			if(valid) {
				final.push_back(v[maxi]);
			}
			alert = false;
			low = false;
			high = false;
			nend = v[maxi].time + 0.25;
		}
	}
	}
	return final;
}

/* THRESHOLD FUNCTION TO DISCOVER THE THRESHOLD AFTER INPUTTING PEAK # */

void peaks(bool oculus, ofstream& output, ifstream& input, ifstream& tinput, int ycol, int i) {
		vector<Thresh> ys;
		string type = NAMES[i];

		yT(input, ys, ycol);

		if(oculus) {
			timeT(tinput, ys);
		} else {
			gtimeT(tinput, ys);
		}

		vector<Thresh> sm = test(ys);

		formatT(output, sm);
}
/* ******************************************************************* */



// basically will do the three S, M, F and put them in an array
// then will go through
// then will plot and can count and then will add the peak for that one and run the rest
// and then do plot for the next
// will always do slow, m, fast, so can output the 
int main(int argc, char* argv[]) {

	if(argc < 2) {
		cout << "ERROR: SPECIFICY 'OCULUS' OR 'GEAR'" << endl;
	}

/* DIFFERENCES BETWEEN OCULUS AND GEAR */
	string path;
	int ycol;
	string arg = argv[1];
	bool oculus = false;

	if(arg == "oculus") {
		path = "ofdata/";
		ycol = 9;
		oculus = true;
	} else {
		path = "gfdata/";
		ycol = 5;
		oculus = false;
	}
/* *********************************** */

/* CLEAN THE DATA */
	for(int i=0; i<12; i++) {
		string cipath = path + NAMES[i] + ".txt";
		string copath = NAMES[i] + ".txt";
		ifstream input(cipath);
		ofstream output(copath);
		clean(input, output);
	}

/* FILL ARRAY WITH TRIAL SLOW MEDIUM AND FAST FILE NAMES */
	unsigned int SIZE = 4;
	vector<string> file;
	// file.push_back("oh1.txt");
	// file.push_back("oh2.txt");
	// file.push_back("oh3.txt");
	// file.push_back("oh4.txt");
	// file.push_back("on1.txt");
	// file.push_back("on2.txt");
	// file.push_back("on3.txt");
	// file.push_back("on4.txt");
	file.push_back("oc1.txt");
	file.push_back("oc2.txt");
	file.push_back("oc3.txt");
	file.push_back("oc4.txt");
	// file.push_back("slow.txt");
	// file.push_back("med.txt");
	// file.push_back("fast.txt");
		// path = "dev/odata/";
		// unsigned int SIZE = 12;
		// string o[SIZE] = {"onidhi.txt",
		// 						};

		// for(unsigned int i=0; i<SIZE; i++) {
		// 	file.push_back(o[i]);
		// }
/* **************************************************** */

/* CREATE INPUT AND OUTPUT FILE PATHS */
	string* inputs = new string[SIZE];
	string* outputs = new string[SIZE];

	// fills in arrays with file paths
	for(unsigned int i=0; i<file.size(); i++) {
		 // string ipath = path + file[i];
		string ipath = file[i];
		string opath = "./other/" + file[i];
		inputs[i] = ipath;
		outputs[i] = opath;
	}
/* ********************************** */

/* RUN PYTHON SCRIPT AND GET THRESHOLDS FOR EACH */
for(unsigned int i=0; i<file.size(); i++) {
	ifstream pyin(inputs[i]);
	ifstream pytin(inputs[i]);

	string num;
	stringstream tt;
	tt << i;
	tt >> num;

	/* SEND STANDARD HEADER TEMPLATE TO PYTHON FILE */
	string ppath = "plot" + num;
	ppath += ".py";
	ofstream pyout(ppath);
	pyout << "import matplotlib.pyplot as plt" << endl;

	/* ******************************************** */

	/* PERFORM ANALYSIS ON THE FILE */
	python(oculus, ycol, pyout, pyin, pytin);


	/* SEND STANDARD FOOTER TEMPLATE TO PYTHON FILE */
	pyout << "plt.plot(t,y)" << endl;
	pyout << "plt.ylabel('acceleration')" << endl;

	pyout << "plt.savefig(\"" << NAMES[i] << num << "\")" << endl;
	pyout << "plt.show()" << endl;
	pyout << "plt.close()" << endl;

	/* ********************************************* */


	/* CALL THE PYTHON SCRIPT FROM HERE */ 
	string command = "python \"" + ppath + "\"";
	int res = system(command.c_str());
	if(res != 0) {
		cout << "ERROR: PYTHON SCRIPT EXITED W CODE " << res << endl;
	}
	/* ******************************** */

	/* THRESHOLD ANALYSIS - should write thresholds to a file */
	ofstream output(outputs[i]);
	ifstream input(inputs[i]);
	ifstream tinput(inputs[i]);

	// need to deal with fake peaks so if find something lower in time period then 
	// end is +0.25 from there
	// and if turns out to be a dud (well won't need to deal with that bc wouldve had something greater)
	peaks(oculus, output, input, tinput, ycol, i);
	/* ***************************************************** */
}

/* ******************** END FOR LOOP ************************ */

	// frees memory
	delete [] inputs;
	delete [] outputs;

	return 0;
}