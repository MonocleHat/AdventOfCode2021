#include <iostream>
#include <fstream>
#include <string>
/*
Count number of times a depth measurement increases
from the previous measurement
Day 1 Challenge 2021
Written 12-03-2021
Author: Brandyn Pereira
*/
using namespace std;
int main() {
	int counter = 0;
	string next_val;
	string prev_val;
	ifstream readings;
	readings.open("input.txt");
	if (readings.is_open()) {
		getline(readings, prev_val);
		while (getline(readings, next_val)) {
			if (atoi(next_val.c_str()) > atoi(prev_val.c_str())) {
				counter++;
				prev_val = next_val;
			}
			if (atoi(next_val.c_str()) < atoi(prev_val.c_str())) {
				prev_val = next_val;
			}
	
			

		}
		readings.close();
	}
	cout << "The Highest Value is: " << prev_val << endl;
	cout << "The count is: " << counter << endl;


}