#include "Header.h"

//HOW THE SIMULAITON WILL WORK
//1. Get a number for how many tributes will compete
//	1.1 Determine if there are enough tributes available to do something that day still that can participate in an event
//2. Randomly get those tributes using getTribute()
//	2.1 Make sure the tributes returned from getTribute have not already done something that day
//3. Call the event randomly and execute code
//	3.1 Stat checks
//	3.2 Depending on event, check for injuries or what's in inventory
//	3.3 Change values of tributes -- usedToday and alive specifically
//	3.4 Update inventory if applicable
//4. Return here to simulation and repeat until day/night ends
//	4.1 Once day/night has ended, mark each tribute that is still alive as usedToday = false


int livingTributes;
int usableTributes;

void simulation() 
{
	if (roster.size() == 0)
	{
		cout << "Error: There are no tributes in the roster to compete. Please build a roster and then try again\n";
		return;
	}
	//Variables needed during the entirerty of the simulation with values that will be changed frequently
	int dayNum = 1;
	livingTributes = roster.size();
	usableTributes = roster.size();

	while (livingTributes > 1)
	{
		cout << "Day: " << dayNum << "\n";
		while (usableTributes > 0)
		{
			usableTributes = usableTributes - (dayEvents[rand() % dayEvents.size()]());
		}

		while (usableTributes > 0)
		{

		}
	}
}