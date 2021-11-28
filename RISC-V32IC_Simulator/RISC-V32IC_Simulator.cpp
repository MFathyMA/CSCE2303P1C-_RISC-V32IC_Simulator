// RISC-V32IC_Simulator.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

void cnum(int n, short s)
{
	if (s == 1)
		cout << bitset<8 * sizeof(n)>(n);
	else
		cout << n;
}

int getreg(string r)
{

	return -1;
}

int main()
{
	int x[32] = {0}; // Array holds the 32 registers, all its elements are initialized to 0.
	int pc;
	do {
		cout << "Enter the address where your first assembly instruction should be placed in the memory.\n";
		cin >> pc;
	} while (pc < 0);
	string fileName;
	ifstream file;
	do {
		cout << "Enter the file path or name including the extension.\n";
		cin >> fileName;
		file.open(fileName);
	} while (!file.is_open());
	short numberingSystem;
	do {
		cout << "Press 1 for showing numbers in binary, 2 for octal, 3 for dicimal, or 4 for hexadicimal.\n";
		cin >> numberingSystem;
	} while (numberingSystem<1 || numberingSystem>4);
	if (numberingSystem == 2)
		cout << oct;
	else if (numberingSystem == 4)
		cout << hex;
	string line;
	map<string, int> labels;
	while (getline(file, line))
	{
		pc += 4;
		int pos = line.find(":");
		if (pos != string::npos)
		{
			if (line.length() == pos + 1)	pc-=4;
			continue;
		}
		labels.insert(pair<string, int>(line.substr(0, pos), pc - 4));
			}

	file.close();
}
