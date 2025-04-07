#include "menu.hpp"

#include <conio.h>

using std::to_string; // convert date to string

Menu::Menu()
{
	// open files when menu is constructed
	classList.open("classList.csv", ios::in);
	masterIn.open("master.csv", ios::in);
	masterOut.open("master.csv", ios::out);
}

Menu::~Menu()
{
	cout << "inside menu destructor, closing open files" << endl;

	// close files for menu destructor
	if (classList.is_open())
	{
		classList.close();
	}
	if (masterIn.is_open())
	{
		masterIn.close();
	}
	if (masterOut.is_open())
	{
		masterOut.close();
	}
}

void Menu::runMenu(void)
{
	int choice = 0;
	do
	{
		// print menu
		cout << "attendance menu" << endl << endl
			<< "1. import course list" << endl
			<< "2. load master list" << endl
			<< "3. store master list" << endl
			<< "4. mark absences" << endl
			<< "5. generate report" << endl
			<< "6. exit" << endl;

		choice = _getch() - '0';
		system("cls");

		switch (choice)
		{
		case 1:
		{
			masterList.destroyList(); // first destroy the master list
			char line[100];
			classList.getline(line, 100); // read the first line to discard
			while (classList) // while there is data in the file
			{
				Data* newData = new Data(); // create memory for data

				if (classList >> *newData) // if there is data being read in from the file to the data
				{
					masterList.insert(newData); // insert the data into the list
				}
			}
		}
		cout << "press any key to return to menu";
		_getch(); // wait for input before returning to the menu
		system("cls");
		break;
		case 2:
		{
			char line[100];
			classList.getline(line, 100);
			while (masterIn)
			{
				Data* newData = new Data();

				if (masterIn >> *newData)
				{
					masterList.insert(newData);
				}
			}
		}
		cout << "press any key to return to menu";
		_getch();
		system("cls");
		break;
		case 3:
			masterOut << masterList; // print data in the master list to the master file

			cout << "press any key to return to menu";
			_getch();
			system("cls");
			break;
		case 4:
		{
			Node<Data>* pCur = masterList.getHeadPtr();

			while (pCur != nullptr) // while there are still nodes in the list
			{

				cout << pCur->getData()->getName() << endl; // print name of the student
				cout << "press 1 if absent, 0 if present" << endl;

				int attendance = 0;
				do
				{
					attendance = _getch() - '0';

					switch (attendance)
					{
					case 1: // if the student is absent
					{
						int numAbsences = pCur->getData()->getAbsences(); // read the amount of absences the student has
						++numAbsences; // increment by one
						pCur->getData()->setAbsences(numAbsences); // set the absences to the new value (+1)

						// get current date
						time_t t = time(0);
						struct tm* now = localtime(&t);
						string line = to_string(now->tm_year + 1900) + '-' + to_string(now->tm_mon + 1) + '-' + to_string(now->tm_mday); // save the date as a string

						pCur->getData()->getDateAbsences().push(line); // push the date string to the date absences stack
					}
					break;
					case 0: // do nothing if the student isn't absent
						break;
					default:
						cout << endl << "invalid choice";
						break;
					}
				} while (attendance > 1); // while the input isn't valid

				system("cls"); // clear the screen
				pCur = pCur->getNextPtr(); // go to the next node
			}
		}
		cout << "end of student list" << endl << "press any key to return to menu";
		_getch();
		system("cls");
		break;
		case 5:
		{
			int report = 0;
			cout << "1. generate report for all students" << endl <<
				"2. generate report for students with 3 or more absences" << endl;
			do
			{
				report = _getch() - '0';
				system("cls");
				switch (report)
				{
				case 1: // report for all students
				{
					Node<Data>* pCur = masterList.getHeadPtr();

					while (pCur != nullptr)
					{
						if (pCur->getData()->getDateAbsences().empty())
						{
							cout << pCur->getData()->getId() << " " << pCur->getData()->getName() << " " << "no absences" << endl; // print no absences for studets with no absences
						}
						else
						{
							cout << pCur->getData()->getId() << " " << pCur->getData()->getName() << " " << pCur->getData()->getDateAbsences().top() << endl; // print the most recent absence
						}
						pCur = pCur->getNextPtr();
					}
				}
				break;
				case 2: // report for students with 3 or more absences
				{
					Node<Data>* pCur = masterList.getHeadPtr();

					if (pCur->getData()->getAbsences() >= 3) // if the absences is 3 or more
					{
						cout << pCur->getData()->getId() << " " << pCur->getData()->getName() << " " << pCur->getData()->getAbsences() << " absences" << endl; // print students and amount of absences they have
					}
				}
				break;
				default:
					cout << endl << "invalid choice";
					break;
				}
			} while (report > 2);
			cout << endl << "press any key to return to menu";
			_getch();
			system("cls");
		}
		break;
		case 6:
			system("cls");
			masterList.destroyList(); // destroy the list upon exiting
			break;
		default:
			cout << "invalid choice" << endl << endl << "press any key to return to menu";
			_getch();
			system("cls");
			break;
		}
	} while (choice != 6);
}

ifstream& operator>>(ifstream& input, Data& rhs)
{
	char line[100] = "";

	// read lines from file and set it to the corresponding data
	input.getline(line, 100, ',');
	rhs.setRecord(atoi(line));
	input.getline(line, 100, ',');
	rhs.setId(atoi(line));
	input.getline(line, 100, '\"'); // read quotation and discard
	input.getline(line, 100, '\"');
	rhs.setName(line);
	input.getline(line, 100, ','); // read comma and discard
	input.getline(line, 100, ',');
	rhs.setEmail(line);
	input.getline(line, 100, ',');
	rhs.setUnits(line);
	input.getline(line, 100, ',');
	rhs.setProgram(line);
	input.getline(line, 100);
	rhs.setLevel(line);

	return input;
}

ofstream& operator<<(ofstream& output, List<Data>& rhs)
{
	Node<Data>* pCur = rhs.getHeadPtr();
	while (pCur != nullptr) // while there is data in the list
	{
		// write data from list to the file in the original format
		output << pCur->getData()->getRecord() << ',' << pCur->getData()->getId() << ',' << '\"' << pCur->getData()->getName() << '\"' << ',' << pCur->getData()->getEmail() <<
			',' << pCur->getData()->getUnits() << ',' << pCur->getData()->getProgram() << ',' << pCur->getData()->getLevel() << endl;
		pCur = pCur->getNextPtr();
	}

	return output;
}
