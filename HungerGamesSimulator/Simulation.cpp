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

void resetUsable();
void endOfDayChecks();

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
		dayNum++;
		cout << "Day: " << dayNum << "\n";
		resetUsable();
		while (usableTributes > 0)
		{
			usableTributes = usableTributes - (dayEvents[rand() % dayEvents.size()]());
		}
		//Note to self: Mention to brady about dumping internal values to file if running in real time
		endOfDayChecks();

		while (usableTributes > 0)
		{

		}
	}
}

//This function determines at the end of the day if the tributes have food, water, shelter, and medkits
//If they don't, they have a 15% chance of receiving an injury for it
void endOfDayChecks()
{
	for (int i = 0; i < roster.size(); i++)
	{
		if (roster[i].alive)
		{
			if (roster[i].inventory.camping_equipment > 0)
				roster[i].inventory.camping_equipment--;
			else
			{
				int temp = rand() % 100 + 1;
				if (temp <= 5)
					roster[i].injury++;
			}
			if (roster[i].inventory.canteen_of_water > 0)
				roster[i].inventory.canteen_of_water--;
			else
			{
				int temp = rand() % 100 + 1;
				if (temp <= 5)
					roster[i].injury++;
			}
			if (roster[i].inventory.food > 0)
				roster[i].inventory.food--;
			else
			{
				int temp = rand() % 100 + 1;
				if (temp <= 5)
					roster[i].injury++;
			}
			if (roster[i].inventory.first_aid_kit > 0)
			{
				roster[i].inventory.first_aid_kit--;
				roster[i].injury--;
			}

			if (roster[i].injury >= 5)
			{
				roster[i].alive = false;
				livingTributes--;
				cout << roster[i].name << " succumbs to their wounds and dies.\n";
			}
		}
	}
}

//this method will reset the usable list each new day with the id number of each tribute that is alive.
//is also resets the number of usableTributes each day, which will also be the same as alive tributes.
void resetUsable()
{	
	usableTributes = 0;
	for (int i = 0; i < roster.size(); i++)
	{
		if (roster[i].alive)
		{
			roster[i].usedToday = false;
			usable.insert(i);
			usableTributes++;
		}
	}
}