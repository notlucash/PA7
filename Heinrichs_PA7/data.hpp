#pragma once 

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using std::string;
using std::stack;
using std::endl;
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::ostream;

class Data
{
private:
	// student data
	int record;
	int id;
	string name;
	string email;
	string units;
	string program;
	string level;
	int absences;
	stack<string> dateAbsences;
public:
	Data(int newRecord = 0, int newId = 0, string newName = "", string newEmail = "", string newUnits = "", string newProgram = "", string newLevel = "", int newAbsences = 0);

	~Data()
	{
		// commented out to avoid message being shown
		//cout << "inside data destructor" << endl;
	}

	Data(Data& d); // copy constructor
	
	// getters
	int getRecord()const;
	int getId()const;
	string getName()const;
	string getEmail()const;
	string getUnits()const;
	string getProgram()const;
	string getLevel()const;
	int getAbsences()const;
	stack<string>& getDateAbsences();

	// setters
	void setRecord(int newRecord);
	void setId(int newId);
	void setName(string newName);
	void setEmail(string newEmail);
	void setUnits(string newUnits);
	void setProgram(string newProgram);
	void setLevel(string newLevel);
	void setAbsences(int newabsences);
};