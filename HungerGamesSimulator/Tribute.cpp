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
	int temp = rand() % roster.size();
	if (usableTributes < 5)
		for (int i = 0; i < roster.size(); i++)
			if (roster[i].alive && !roster[i].usedToday)
				return &roster[i];
	//This while loop makes sure that the randomly chosen tribute hasn't already performed an action today
	while (roster[temp].alive && roster[temp].usedToday)
		temp = rand() % roster.size();
	roster[temp].usedToday = true;
	return &roster[temp];
}