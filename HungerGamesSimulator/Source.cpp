//everyday multiply chance of arena event to deem if happening. Baseline = 15% will go down from there. Every day # 10 one will happen if it hasn't already
#include "Header.h"
#include <Windows.h>
#include <algorithm>

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#undef max
#undef min


//Maximum value any stat can have
const int MAX_STAT_VALUE = 10;
//This number +7 is how many total stat points are available to tributes during their creation
int STAT_POINTS = 33;

//insantiates the usable list;
LinkedList<int> ListofUsableTributes = LinkedList<int>();
vector <Tribute> roster(0);

BOOL CtrlHandler(DWORD fdwCtrlType)
{
	cout << endl;
	return true;
}

int main() {
	int choice = 0;

	SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, true);

	cout << "Hello and Welcome to the Hunger Games Simulator Redux\n";
	cout << "This simulator is currently in Beta\n";
	cout << "v 0.65\n";

	srand((unsigned int)time(NULL));

	while (true) 
	{
		cout.clear();
		cout << "-------------------------------------------------------------\n";
		cout << "Please select what you would to do:\n";

		cout << "1. Begin Simulation\n";
		cout << "2. Build Roster from file\n";
		cout << "3. View Roster\n";
		cout << "4. Edit Roster\n";
		cout << "5. Clear Roster\n";
		cout << "6. Exit\n";
		cout << "-------------------------------------------------------------\n";

		//This while loop ensures that only an integer value can be input. It also prevents a crash if anything other than an integer value is entered
		//Credit to jRaskell from cplusplus.com as he's the author of the loop
		while (!(cin >> choice)) 
		{
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}

		cout << endl;
		//Switch statement to determine which function to call next
		switch (choice) 
		{
		case 1:
			system("CLS");
			simulation();
			break;
		case 2:
			system("CLS");
			buildRoster();
			break;
		case 3:
			system("CLS");
			viewRoster(false);
			break;
		case 4:
			system("CLS");
			editRoster();
			break;
		case 5:
			roster.resize(0);
			system("CLS");
			cout << "Roster cleared!" << endl << endl;
			break;
		case 6:
			return 0;
			break;
		case 7:
			break;
		default:
			system("CLS");
			cout << "Invalid Input. Try again:\n\n";
		}
		choice = 0;
	}
	return 0;
}

void buildRoster() {
	//This function asks the user for a file name and opens it, counts the lines, assigns the roster to be that size then moves through the file assigning 
	//values for the tributes appropriately
	string temp1;
	string temp2;
	int temp3;
	int numberOfLines = 0;

	cout << "Please enter the name of the file to open:\n";
	cin >> temp1;

	//ip is used to actually read the file and populate the roster
	ifstream ip(temp1);
	//tp is used below to count the lines in the file to determine how big to make the roster
	ifstream tp(temp1);

	if (!ip)
	{
		cout << "Error opening file!\n";
		return;
	}
	//This is the loop that determies number of competing tributes
	while (getline(tp, temp1))
		++numberOfLines;
	roster.resize(numberOfLines);

	//This for loop is really only necessary if the file is encoded in UTF-8
	//Doing so creates 3, what I believe are garbage characters, at the beginning of the file. So this is my fix for that for now until I can determine
	//how to know what a files' encoding is and dynamically run this loop or not
	for (int j = 0; j < 3; j++)
	{
		char c;
		ip.get(c);
	}
	//This loop runs until the end of the file assigning values in order of NAME,GENDER,DISTRICT#
	//If it's not in that order this will still assign but it'll very likely cause problems later on in simulation.
	int i = 0;
	cout << "Please wait, this may take a minute or two to read all tributes and assign their internal values...\n";
	while (!ip.eof())
	{
		//This chunk of code here grabs the data needed from the file
		roster[i].ID = i;
		getline(ip, roster[i].name, ',');
		getline(ip, temp1, ',');
		getline(ip, temp2, '\n');
		//This chunk of code takes the grabbed and assigns the gender and district appropriately
		roster[i].gender = temp1[0];
		roster[i].district = atoi(temp2.c_str());
		//This is the beginning of the randomizing of stats
		//Strap in, because this is where no value is for sure known lol
		//randomStat is going to be used to hold the randomly assigned value to determine which stat is about to get more point(s)
		int randomStat = 0;
		while (STAT_POINTS > 0)
		{
			randomStat = rand() % 7 + 1;
			switch (randomStat) {
			case 1:
				//These first if statements check if the current stat is at or above the maximum, and if it is, to break before performing
				//anything and changing the values
				if (roster[i].strength >= MAX_STAT_VALUE)
					break;
				//This line assigns temp3 the number of points to be added to a given stat
				//This is determined using first, the min() function which returns the smaller of two values passed to it
				//The first value is the maximum stat value subtracting what the value of the stat itself actually is
				//This is cone to ensure that no number greater than what space is remaining is available to be rolled
				//The other value passed to min() is obviously how many stat points are left
				temp3 = rand() % min(MAX_STAT_VALUE - roster[i].strength, STAT_POINTS) + 1;
				//This line adds the points to the current stat value
				roster[i].strength += temp3;
				//This line subtracts the points that were just added from the whole pool
				STAT_POINTS = STAT_POINTS - temp3;
				break;
			case 2:
				//These first if statements check if the current stat is at or above the maximum, and if it is, to break before performing
				//anything and changing the values
				if (roster[i].perception >= MAX_STAT_VALUE)
					break;
				//This line assigns temp3 the number of points to be added to a given stat
				//This is determined using first, the min() function which returns the smaller of two values passed to it
				//The first value is the maximum stat value subtracting what the value of the stat itself actually is
				//This is cone to ensure that no number greater than what space is remaining is available to be rolled
				//The other value passed to min() is obviously how many stat points are left
				temp3 = rand() % min(MAX_STAT_VALUE - roster[i].perception, STAT_POINTS) + 1;
				//This line adds the points to the current stat value
				roster[i].perception += temp3;
				//This line subtracts the points that were just added from the whole pool
				STAT_POINTS = STAT_POINTS - temp3;
				break;
			case 3:
				//These first if statements check if the current stat is at or above the maximum, and if it is, to break before performing
				//anything and changing the values
				if (roster[i].endurance >= MAX_STAT_VALUE)
					break;
				//This line assigns temp3 the number of points to be added to a given stat
				//This is determined using first, the min() function which returns the smaller of two values passed to it
				//The first value is the maximum stat value subtracting what the value of the stat itself actually is
				//This is cone to ensure that no number greater than what space is remaining is available to be rolled
				//The other value passed to min() is obviously how many stat points are left
				temp3 = rand() % min(MAX_STAT_VALUE - roster[i].endurance, STAT_POINTS) + 1;
				//This line adds the points to the current stat value
				roster[i].endurance += temp3;
				//This line subtracts the points that were just added from the whole pool
				STAT_POINTS = STAT_POINTS - temp3;
				break;
			case 4:
				//These first if statements check if the current stat is at or above the maximum, and if it is, to break before performing
				//anything and changing the values
				if (roster[i].charisma >= MAX_STAT_VALUE)
					break;
				//This line assigns temp3 the number of points to be added to a given stat
				//This is determined using first, the min() function which returns the smaller of two values passed to it
				//The first value is the maximum stat value subtracting what the value of the stat itself actually is
				//This is cone to ensure that no number greater than what space is remaining is available to be rolled
				//The other value passed to min() is obviously how many stat points are left
				temp3 = rand() % min(MAX_STAT_VALUE - roster[i].charisma, STAT_POINTS) + 1;
				//This line adds the points to the current stat value
				roster[i].charisma += temp3;
				//This line subtracts the points that were just added from the whole pool
				STAT_POINTS = STAT_POINTS - temp3;
				break;
			case 5:
				//These first if statements check if the current stat is at or above the maximum, and if it is, to break before performing
				//anything and changing the values
				if (roster[i].agility >= MAX_STAT_VALUE)
					break;
				//This line assigns temp3 the number of points to be added to a given stat
				//This is determined using first, the min() function which returns the smaller of two values passed to it
				//The first value is the maximum stat value subtracting what the value of the stat itself actually is
				//This is cone to ensure that no number greater than what space is remaining is available to be rolled
				//The other value passed to min() is obviously how many stat points are left
				temp3 = rand() % min(MAX_STAT_VALUE - roster[i].agility, STAT_POINTS) + 1;
				//This line adds the points to the current stat value
				roster[i].agility += temp3;
				//This line subtracts the points that were just added from the whole pool
				STAT_POINTS = STAT_POINTS - temp3;
				break;
			case 6:
				//These first if statements check if the current stat is at or above the maximum, and if it is, to break before performing
				//anything and changing the values
				if (roster[i].intelligence >= MAX_STAT_VALUE)
					break;
				//This line assigns temp3 the number of points to be added to a given stat
				//This is determined using first, the min() function which returns the smaller of two values passed to it
				//The first value is the maximum stat value subtracting what the value of the stat itself actually is
				//This is cone to ensure that no number greater than what space is remaining is available to be rolled
				//The other value passed to min() is obviously how many stat points are left
				temp3 = rand() % min(MAX_STAT_VALUE - roster[i].intelligence, STAT_POINTS) + 1;
				//This line adds the points to the current stat value
				roster[i].intelligence += temp3;
				//This line subtracts the points that were just added from the whole pool
				STAT_POINTS = STAT_POINTS - temp3;
				break;
			case 7:
				//These first if statements check if the current stat is at or above the maximum, and if it is, to break before performing
				//anything and changing the values
				if (roster[i].luck >= MAX_STAT_VALUE)
					break;
				//This line assigns temp3 the number of points to be added to a given stat
				//This is determined using first, the min() function which returns the smaller of two values passed to it
				//The first value is the maximum stat value subtracting what the value of the stat itself actually is
				//This is cone to ensure that no number greater than what space is remaining is available to be rolled
				//The other value passed to min() is obviously how many stat points are left
				temp3 = rand() % min(MAX_STAT_VALUE - roster[i].luck, STAT_POINTS) + 1;
				//This line adds the points to the current stat value
				roster[i].luck += temp3;
				//This line subtracts the points that were just added from the whole pool
				STAT_POINTS = STAT_POINTS - temp3;
				break;
			default:
				cout << "ERROR in stat assignment\n";
			}
		}
		//Resets the STAT_POINTS for the next tribute to be read in
		STAT_POINTS = 33;
		i++;
	}
}

void viewRoster(bool needsID) {
	//This function first checks if there are *any* tributes and then iterates through the list
	//and prints it to the screen in a semi formatted fashion
	if (roster.size() == 0)
		cout << "No Roster to display\n";
	for (unsigned int i = 0; i < roster.size(); i++) {
		if (needsID)
			cout << roster[i].ID << "\t";

		cout << "Name: " << setw(10) << left << roster[i].name << "\t\tDistrict: " << roster[i].district << "\tGender: " << roster[i].gender;
		if (roster[i].alive)
			cout << "\tStatus: Alive\n";
		else
			cout << "\tStatus: Dead\n";
		cout << "S: " << roster[i].strength << "\t";
		cout << "P: " << roster[i].perception << "\t";
		cout << "E: " << roster[i].endurance << "\t";
		cout << "C: " << roster[i].charisma << "\t";
		cout << "I: " << roster[i].intelligence << "\t";
		cout << "A: " << roster[i].agility << "\t";
		cout << "L: " << roster[i].luck << "\n\n";
	}
}

void editRoster() {
	//This function first prints the roster to the screen and asks the user to identify which
	//tribute they would like edit the name and gender of based on that tributes unique ID
	//number.
	//Editing the District the tribute is in isn't currently possible but if the demand is
	//really there it can added.
	if (roster.size() == 0) {
		cout << "Error: Empty roster. Please build a roster before attempting to edit one.\n";
		return;
	}

	int editID = -1;
	viewRoster(true);


	cout << "Please type in the ID number of the Tribute you would like to edit:\n";
	//Sanitizing input
	while ((editID >= (signed int) roster.size()) || (editID <= 0)) 
	{
		if (!(cin >> editID))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again:\n";
			editID = -1;
		}
		else if ((editID >= (signed int) roster.size()) || (editID <= 0))
			cout << "Invalid input.  Try again:\n";
	}
	//Honestly I'll let you name the tribute anything you want
	cout << "Please enter the new name of this Tribute:\n";
	string temp;
	cin.ignore();
	getline(cin, temp);
	roster[editID].name = temp;

	cout << "Please enter " << roster[editID].name << "'s gender. The supported genders are M & F:\n";
	char c = '\0';

	while (c != 'm' && c != 'f' && c != 'M' && c != 'F') {
		if (!(cin >> c))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again:\n";
			c = '\0';
		}
		if (c != 'm' && c != 'f' && c != 'M' && c != 'F')
			cout << "Invalid input.  Try again:\n";
	}
	roster[editID].gender = tolower(c);
	cout << endl << endl;
}