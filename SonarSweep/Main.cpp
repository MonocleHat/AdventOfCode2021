#include <iostream>
#include <fstream>
#include <string>
/*
Count number of times a depth measurement increases
from the previous measurement
1. Read data from the file
2. store previous reading into variable;
3. read next reading
4. compare next with variable value
5. if larger, increment counter, store value in variable
6. if not larger, no increment, no storage

*/
using namespace std;
int main() {
	int counter = 0;
	int previous_val = 0;
	string next_val;
	string holder;
	ifstream readings;
	readings.open("input.txt");
	if (readings.is_open()) {
		getline(readings, holder);
		while (getline(readings, next_val)) {
			if (atoi(next_val.c_str()) > atoi(holder.c_str())) {
				counter++;
				holder = next_val;
			}
			if (atoi(next_val.c_str()) < atoi(holder.c_str())) {
				holder = next_val;
			}
	
			

		}
		readings.close();
	}
	cout << "The Highest Value is: " << holder << endl;
	cout << "The count is: " << counter << endl;


}