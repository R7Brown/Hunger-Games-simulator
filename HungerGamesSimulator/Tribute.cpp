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
	BloodbathPoints = 0;
	hypothermiaPoints = 0;
}

//TODO: add bool to check if bloodbath event or regular event
Tribute* Tribute::getTribute(bool bloodbath, int vector_size) {
	if (roster.size() <= 0)
	{
		//If there is no roster, then a blank slate of a tribute is returned
		Tribute tribute;
		return &tribute;
	}

	int temp, temp2;

	//This checks to see if the tribute is being retreived for a bloodbath event.
	//This will pull a tribute from a separate list meant just for the bloodbath.
	//Every other type of event will go through the normal listOfUsableTributes.
	if (bloodbath)
	{
		//produces a random number from 0 to the last index of the list.
		temp = rand() % listOfBBTributes.size;
		//gets the id from the list
		temp2 = listOfBBTributes[temp];
	}
	else
	{
		//produces a random number from 0 to the last index of the list.
		temp = rand() % listOfUsableTributes.size;
		//gets the id from the list
		temp2 = listOfUsableTributes[temp];
	}

	
	//returns the tribute
	return &roster[temp2];
}