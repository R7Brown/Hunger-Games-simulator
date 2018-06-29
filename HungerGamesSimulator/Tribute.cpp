#include "Header.h"

Tribute::Tribute() {
	name = "";
	alive = true;
	usedToday = false;
	kills = 0;
	gender = '\0';
	district = 0;

	strength = 1;
	perception = 1;
	endurance = 1;
	charisma = 1;
	intelligence = 1;
	agility = 1;
	luck = 1;

	injury = 0;
}

Tribute* Tribute::getTribute(int vector_size) {
	if (roster.size() <= 0)
	{
		//If there is no roster, then a blank slate of a tribute is returned
		Tribute tribute;
		return &tribute;
	}

	//produces a random number from 0 to the last index of the list.
	int temp = rand() % ListofUsableTributes.size;
	//gets the id from the list
	int temp2 = ListofUsableTributes[temp];

	//returns the tribute
	return &roster[temp2];
}