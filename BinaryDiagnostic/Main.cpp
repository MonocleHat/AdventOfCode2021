/*
Day 1 Goal: Calculate "Power Consumption" by multiplying gamma and epsilon rates of a set of binary numbers
The columns of each set of binary are parsed through
The most common bit among each column makes up the start of our numbers
We can isolate a single bit using <string>.c_str()[index] 
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main() {
	fstream input("input.txt");
	int one_count = 0;
	int zero_count = 0;
	int linecount = 0;
	string line;
	string gamma;
	string epsilon;
	vector<string> inArray;
	if (input.is_open()) {
		while (getline(input, line)) {
			linecount++;
			inArray.push_back(line);
		}
		
		input.close();
		for (int x = 0; x < inArray[0].length(); x++) {
			for (int y = 0; y < linecount; y++) {
				if (inArray[y].c_str()[x] == '1') {
					one_count++;
				}
				else if (inArray[y].c_str()[x] == '0') {
					zero_count++;
				}
				else {
					cout << "Err in if" << endl;
				}
			}
			if (zero_count > one_count) {
				gamma.append("0");
				epsilon.append("1");
			}
			else {
				gamma.append("1");
				epsilon.append("0");
			}
			zero_count = 0;
			one_count = 0;
		}
		cout << gamma << endl;
		cout << epsilon << endl;
		cout << "Use converter to change these values" << endl;
		//solution was 3009600
	}
	
}