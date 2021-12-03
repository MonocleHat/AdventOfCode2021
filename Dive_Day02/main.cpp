#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*
-=-=-=-=-= Instructions =-=-=-=-=-=-
1. We read in a set of commands
2. Commands are in the format <ACTION> <VALUE>
3. We read in commands until a space, which acts as the delimiter. 
4. we process the command, then process the value that follows it
	4a. if command = forward { forward += value }
5. multiply horizontal position by vertical depth.
*/
int main() {
	string command;
	string value;
	int depth = 0;
	int horiz = 0;
	int counter = 0;
	ifstream input("input.txt");
	if (input.is_open()) {
		while (getline(input, command)) {
			counter++;
		}
		input.clear();
		input.seekg(0, std::ios::beg);
		for (int i = 0; i < counter; i++) {
			input >> command;
			input >> value;
			if (command == "forward") {
				horiz += atoi(value.c_str());
			}
			else if (command == "down") {
				depth += atoi(value.c_str());
			}
			else if (command == "up") {
				depth -= atoi(value.c_str());
			}
		}
		input.close();
	}
	cout << "POSITION OF SUBMARINE (PT1): " << depth * horiz << endl;
}