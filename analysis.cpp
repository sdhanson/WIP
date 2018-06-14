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

/* PYTHON fUNCTION TO MANAGE SETTING UP THE PYTHON FILE */
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
/* *************************************************** */



/* THRESHOLD HELPER FUNCTIONS BEGIN HERE */
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
            swap(vec, i, j);
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
            swap(vec, i, j);
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

void formatT(ofstream& output, vector<Thresh>& v) {
	for(unsigned int i=0; i<v.size(); i++) {
		output << v[i].time << " - " << v[i].y << " - " << v[i].derivative << endl;
	}
}

/* *********** END OF THRESHOLD HELPER FUNCTIONS **************** */



/* THRESHOLD FUNCTION TO DISCOVER THE THRESHOLD AFTER INPUTTING PEAK # */
void threshold(bool oculus, ofstream& output, ifstream& input, ifstream& tinput, int peaks) {
		vector<Thresh> ys;

		if(oculus) {
			time(tinput, ys);
		} else {
			gtime(tinput, ys);
		}

		yT(input, ys, ycol);
		neg(ys);
		quicksortY(ys, 0, static_cast<int>(ys.size()-1));
		vector<Thresh> sm = window(ys, win, peaks);
		quicksortT(sm, 0, static_cast<int>(sm.size()-1));

		// output 
		output << "Time before considering " << arg2 << " threshold: " << min(sm) - 0.02 << endl;
		output << "Acceleration threshold for " << arg2 << ": " << miny(sm) - 0.3 << endl;
		formatT(output, sm);

}
/* ******************************************************************* */



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

for(unsigned int i=0; i<file.size(); i++) {
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
	cout << "Number of peaks? " << endl;
	string speaks;
	cin >> speaks;
	stringstream ss;
	ss << speaks;
	int peaks;
	ss >> peaks;
	/* ******************************************* */


	/* THRESHOLD ANALYSIS - should write thresholds to a file */
	ofstream output(outputs[i]);
	ifstream input(inputs[i]);
	ifstream tinput(inputs[i]);

	threshold(oculus, output, input, tinput, peaks);
	/* ***************************************************** */
}

	// frees memory
	delete [] inputs;
	delete [] outputs;

	return 0;
}