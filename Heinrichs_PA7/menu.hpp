#pragma once

#include "list.hpp"

using std::ifstream;
using std::ofstream;
using std::ios;

class Menu
{
private:
	List<Data> masterList;

	// file streams
	ifstream classList;
	ifstream masterIn;
	ofstream masterOut;
public:
	Menu();
	~Menu();

	void runMenu(void);
};

// overloaded operators to read from file
ifstream& operator>> (ifstream& input, Data& rhs);
ofstream& operator<< (ofstream& output, List<Data>& rhs);