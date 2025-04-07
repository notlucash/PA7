#include "data.hpp"

Data::Data(int newRecord, int newId, string newName, string newEmail, string newUnits, string newProgram, string newLevel, int newAbsences)
{
	// set data from passed values
	this->record = newRecord;
	this->id = newId;
	this->name = newName;
	this->email = newEmail;
	this->units = newUnits;
	this->program = newProgram;
	this->level = newLevel;
	this->absences = newAbsences;
}

Data::Data(Data& d)
{
	// set data from d to data that called operation
	this->record = d.getRecord();
	this->id = d.getId();
	this->name = d.getName();
	this->email = d.getEmail();
	this->units = d.getUnits();
	this->program = d.getProgram();
	this->level = d.getLevel();
	this->absences = d.getAbsences();
	this->dateAbsences = d.getDateAbsences();
}

// return values from data
int Data::getRecord() const
{
	return this->record;
}

int Data::getId() const
{
	return this->id;
}

string Data::getName() const
{
	return this->name;
}

string Data::getEmail() const
{
	return this->email;
}

string Data::getUnits() const
{
	return this->units;
}

string Data::getProgram() const
{
	return this->program;
}

string Data::getLevel() const
{
	return this->level;
}

int Data::getAbsences() const
{
	return this->absences;
}

stack<string>& Data::getDateAbsences()
{
	return this->dateAbsences;
}

// set data from passed value to data that called operation
void Data::setRecord(int newRecord)
{
	this->record = newRecord;
}

void Data::setId(int newId)
{
	this->id = newId;
}

void Data::setName(string newName)
{
	this->name = newName;
}

void Data::setEmail(string newEmail)
{
	this->email = newEmail;
}

void Data::setUnits(string newUnits)
{
	this->units = newUnits;
}

void Data::setProgram(string newProgram)
{
	this->program = newProgram;
}

void Data::setLevel(string newLevel)
{
	this->level = newLevel;
}

void Data::setAbsences(int newAbsences)
{
	this->absences = newAbsences;
}