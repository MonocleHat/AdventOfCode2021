#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
	cout << "EXEC: Part 2" << endl;
	//We need to do the same thing as the above but utilizing a sliding window algorithm
	//this is done by creating a subset of the array (a window) and adding the sums of the values together
	//we calculate the first value, then adjust it slowly by subtracting the previous value at position i - 1
	//and adding the next at i + 2
	counter = 0;
	std::vector<int> inputval;
	std::string reader;
	int newsum = 0;
	int prevsum = 0;
	ifstream file2("input.txt");
	if (file2.is_open()) { //while file open, load all values into vector, converting from string to integer
		while (getline(file2, reader)) {
			inputval.push_back(atoi(reader.c_str()));
		}
		file2.close();
	}
	newsum = (inputval[0] + inputval[1] + inputval[2]); //our first calculation, with the window from 0-2 (3)
	prevsum = newsum; // set previous sum to the new sum value
	for (int i = 1; i < inputval.size() - 2; i++){
		newsum -= inputval[i - 1]; //subtract 1 value from the array behind our subset
		newsum += inputval[i + 2]; //add the next value 2 position forward in our subset / the new window
		if (newsum > prevsum) {
			prevsum = newsum;
			counter++;
		}
		if (prevsum > newsum) {
			prevsum = newsum;
		}
	}
	cout << "PT 2 ANSWER: " << counter << endl;


}