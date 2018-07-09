#include "Header.h"

//This function is like the one below it and is slightly more complicated
//It takes a tribute, determines their gender, and replaces the appropriate pronouns in an action
string pronounReplacer(string action, Tribute tribute, int count) {
	string himHer;
	string hisHer;
	string heShe;
	string himselfHerself;
	string rHimHer = "him/her" + to_string(count);
	string rHisHer = "his/her" + to_string(count);
	string rHeShe = "he/she" + to_string(count);
	string rHimselfHerself = "himself/herself" + to_string(count);
	if (tribute.gender == 'm')
	{
		himHer = "him";
		hisHer = "his";
		heShe = "he";
		himselfHerself = "himself";
	}
	else
	{
		himHer = "her";
		hisHer = "her";
		heShe = "she";
		himselfHerself = "herself";
	}
	//This while loop is almost identical to the nameReplacer function except that it looks for multiple different strings for all the pronouns
	while ((action.find(rHimHer) != string::npos) || (action.find(rHisHer) != string::npos) || (action.find(rHeShe) != string::npos) || (action.find(rHimselfHerself) != string::npos))
	{
		if (action.find(rHimHer) != string::npos) { action.replace(action.find(rHimHer), 8, himHer); }
		if (action.find(rHisHer) != string::npos) { action.replace(action.find(rHisHer), 8, hisHer); }
		if (action.find(rHeShe) != string::npos) { action.replace(action.find(rHeShe), 7, heShe); }
		if (action.find(rHimselfHerself) != string::npos) { action.replace(action.find(rHimselfHerself), 16, himselfHerself); }
	}
	return(action);
}

//This function takes a tribute and replaces the name of the number of tribute for i with the name of a tribute. Thus allowing a large amount of dayEvents to be
//written and applied to many different number of events with many different number of participating tributes
string nameReplacer(string action, int i, Tribute tribute)
{
	string toReplace = "Tribute";
	toReplace.append(to_string(i));
	action = pronounReplacer(action, tribute, i);
	while (action.find(toReplace) != string::npos)
		action.replace(action.find(toReplace), 8, tribute.name);
	return action;
}

//dayEvent STRUCTURE
int dayEventExample()
{
	//THIS FIRST IF STATEMENT IS USED TO CHECK IF THE dayEvent CALLED CAN EVEN BE RUN
	//DON'T FORGET THIS OR THE PROGRAM IS LIKELY TO RUN ITSELF INTO AN ENDLESS LOOP 
	//TRYING TO GET A TRIBUTE
	//The int number_of_tributes is likely to be hardcoded into each dayEvent since assigning it 
	// isn't really neccessary each time as each dayEvent is bound to have a different number
	int number_of_tributes = 0;
	if (number_of_tributes > usableTributes)
		return 0;
	//These two lines are getting a tribute pointer to point at a tribute
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	//Action is the string that determines the uniqueness of each dayEvent. You can make it whatever you want really
	string action = "";
	/************************************************
	Checks go here based on what the dayEvent is
	Checks can check anything from stats to inventory to injuries
	Take care to edit stats, inventory, injuries etc. based on what the dayEvent is
	Otherwise you're gonna get tributes with inventories and injuries and kills that don't match the output
	*************************************************/
	//Sending action to the nameReplacer function also sends it to the pronounReplacer function
	//This is purely for output, since tributes and their stuff will still be edited by the dayEvent
	//But forgetting to send the action to the function will print 'Tribute1' and whatnot all over the output to the screen
	action = nameReplacer(action, number_of_tributes, *tribute1);
	//Don't forget to mark the tribute as having done something today unless I guess your dayEvent doesn't fit the norm
	tribute1->usedToday = true;
	//These three lines are in charge of deleting the pointer to prdayEvent memory leaks
	//As well as removing the trubute from the list of usable tributes
	tribute1 = NULL;
	listOfUsableTributes.remove(true, tribute1->ID);
	delete tribute1;
	//Print what happened to the screen
	cout << action << "\n";
	//Return the number of tributes that the dayEvent used to the simulation function so it can update usable tributes there
	return number_of_tributes;
}

int dayEventOne()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 goes hunting";
	if (tribute1->endurance > 6)
	{
		action.append(" and successfully hunts a deer and gains a lot food.");
		tribute1->inventory.food = tribute1->inventory.food + 2;
	}
	else if (tribute1->endurance > 4)
	{
		action.append(" and successfully hunts a rabit and gains a little food.");
		tribute1->inventory.food++;
	}
	else
		action.append(" but was unsuccessful at hunting any game.");

	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventTwo()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "";
	if (tribute1->endurance < 5)
	{
		action.append("Tribute1 injures himself/herself1.");
		tribute1->injury++;
	}
	else
		action.append("Tribute1 takes a nasty looking fall but seems doesn't seem to take any serious injury.");

	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventThree()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 explores the arena.";
	tribute1->perception++;
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventFour()
{
	if (usableTributes < 2)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	Tribute *tribute2 = NULL;
	tribute2 = tribute2->getTribute(roster.size());
	while (tribute2->ID == tribute1->ID)
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(roster.size());
	}
	string action = "Tribute1 attempts to divert Tribute2's attention and run away,";
	if (tribute1->charisma > tribute2->perception)
		action.append(" and succeeds to escape.");
	else if (tribute2->perception > 6)
	{
		action.append(" but Tribute2 sees through the diversion and seriously maims him/her1.");
		tribute1->injury = tribute1->injury + 2;
	}
	else
	{
		action.append(" fortunately Tribute2 notices the distraction, just not soon enough, and only mildly injures Tribute1 as he/she1 escapes.");
		tribute1->injury++;
	}
	action = nameReplacer(action, 1, *tribute1);
	action = nameReplacer(action, 2, *tribute2);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute2->usedToday = true;
	listOfUsableTributes.remove(true, tribute2->ID);
	tribute1 = NULL;
	tribute2 = NULL;
	delete tribute1;
	delete tribute2;
	cout << action << "\n";
	return 2;
}

int dayEventFive()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 tries fishing ";
	if (tribute1->perception > 4)
	{
		action.append(" and successfully catches a big fish. he/she1 has food for the next day.");
		tribute1->inventory.food++;
	}
	else
		action.append(" but is unable to successfully catch any fish.");

	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventSix()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 attempts to sharpen a stick into a spear and ";

	if (tribute1->intelligence > 2)
	{
		action.append("succeeds.");
		tribute1->inventory.spear++;
	}
	else
		action.append("fails.");

	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventSeven()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 collects fruit from a tree.";
	tribute1->inventory.food++;
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventEight()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 searches for clean water and ";

	if (tribute1->perception > 6)
	{
		action.append("finds some.");
		tribute1->inventory.canteen_of_water++;
	}
	else
		action.append("doesn't find any.");

	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventNine()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 tries to sleep through the day to hunt at night.\n";
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action;
	return 1;
}

int dayEventTen()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 attempts to construct a makeshift tent out of dried grass and leaves";
	if (tribute1->intelligence > 5)
		action.append(" and succeeds to build shelter for the night.");
	else
		action.append(" but is unsuccessful and only manages to make a nice looking pile of flammable matieral.");

	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventEleven()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "";
	if (tribute1->inventory.arrow > 0 && tribute1->inventory.bow > 0)
	{
		action.append("Tribute1 practices his/her1 archery.");
		if (tribute1->perception < 5)
		{
			action.append(" Tribute1 finds that his/her1 skill with archery has improved.");
			tribute1->perception++;
			if (tribute1->inventory.arrow < 5)
				tribute1->inventory.arrow = 0;
			else
				tribute1->inventory.arrow = tribute1->inventory.arrow - 5;
		}
	}
	else
	{
		tribute1 = NULL;
		delete tribute1;
		return 0;
	}
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventTwelve()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 is pricked by thorns while picking berries. No serious harm is done.";
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventThirteen()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 tries to spear fish with a large stick";
	if (tribute1->inventory.spear == 0)
		action.append(" but he/she1 remembers that he/she1 doesn't have anything to spear the fish with.");
	else if (tribute1->agility > 7)
	{
		action.append(" and successfully spears a fish, but breaks the spear accidently in the process.");
		tribute1->inventory.food = tribute1->inventory.food + 1;
		tribute1->inventory.spear = tribute1->inventory.spear - 1;
	}
	else
	{
		action.append(" but is unsuccessful at spearing anything and breaks the spear in anger.");
		tribute1->inventory.spear = tribute1->inventory.spear - 1;
	}
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventFourteen()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 searches for firewood";
	if (tribute1->inventory.axe > 0)
	{
		action.append(" and using their axe is able to find logs to chop into firewood, allowing for a campfire tonight.");
		tribute1->inventory.camping_equipment = tribute1->inventory.camping_equipment + 1;
	}
	else if (tribute1->perception > 5 && tribute1->intelligence > 3)
	{
		action.append(" but instead finds some very straight sticks and uses them to make basic arrows.");
		tribute1->inventory.arrow = tribute1->inventory.arrow + 3;
	}
	else
		action.append(" but cannot find anything but some sticks to burn for a small fire.");
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventFifteen()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "";
	if (tribute1->intelligence > 6)
	{
		action.append("Tribute1 makes a slingshot");
		tribute1->inventory.slingshot = tribute1->inventory.slingshot + 1;
	}
	else
		action.append("Tribute1 attempted to make a slingshot but was unable to make one that didn't break upon first use.");
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventSixteen()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 travels to higher ground to view the arena";
	tribute1->perception++;
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventSeventeen()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 discovers a family of ducks";
	if (tribute1->intelligence > 2)
	{
		action.append(" and tries to not think about what he/she1 is doing as he/she1 kills and defeathers them for food.");
		tribute1->inventory.food = tribute1->inventory.food + 1;
	}
	else
		action.append(" and decides to follow them for the day.");
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventEighteen()
{
	if (usableTributes < 2)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 attempts to hunt for other tributes";
	if (tribute1->luck > 5)
	{
		if (tribute1->perception > 5)
		{
			action.append(" and begins following Tribute2's trail.");
			Tribute *tribute2 = NULL;
			tribute2 = tribute2->getTribute(roster.size());
			while (tribute2->ID == tribute1->ID)
			{
				tribute2 = NULL;
				delete tribute2;
				tribute2 = tribute2->getTribute(roster.size());
			}
			if (tribute1->endurance > tribute2->endurance)
			{
				action.append(" Tribute1 catches up to Tribute2 and the two begin to scuffle.\n");

				if (tribute1->strength > tribute2->strength)
				{
					action.append("\tTribute1 manages to pin Tribute2 down and by clamping his/her1 hands around Tribute2's throat, squeeze the life out of him/her2.");
					tribute2->alive = false;
					livingTributes--;
					action = nameReplacer(action, 1, *tribute1);
					action = nameReplacer(action, 2, *tribute2);
					tribute1->usedToday = true;
					listOfUsableTributes.remove(true, tribute1->ID);
					tribute2->usedToday = true;
					listOfUsableTributes.remove(true, tribute2->ID);
					tribute1 = NULL;
					tribute2 = NULL;
					delete tribute1;
					delete tribute2;
					cout << action << "\n";
					return 2;
				}
				else if (tribute1->strength < tribute2->strength)
				{
					action.append("\tTribute2 manages to pin Tribute1 down and using just his/her2 fists, bashes Tribute1's skull in, killing him/her1.");
					tribute1->alive = false;
					livingTributes--;
					action = nameReplacer(action, 1, *tribute1);
					action = nameReplacer(action, 2, *tribute2);
					tribute1->usedToday = true;
					listOfUsableTributes.remove(true, tribute1->ID);
					tribute2->usedToday = true;
					listOfUsableTributes.remove(true, tribute2->ID);
					tribute1 = NULL;
					tribute2 = NULL;
					delete tribute1;
					delete tribute2;
					cout << action << "\n";
					return 2;
				}
				else if (tribute1->strength == tribute2->strength)
				{
					action.append("\tThe two tributes break from their scuffle lasting several minutes, each having gotten some good hits in. Recognizing that they're an equal match, they shake on it and move on, allowing the other to live... for now.");
					action = nameReplacer(action, 1, *tribute1);
					action = nameReplacer(action, 2, *tribute2);
					tribute1->usedToday = true;
					listOfUsableTributes.remove(true, tribute1->ID);
					tribute2->usedToday = true;
					listOfUsableTributes.remove(true, tribute2->ID);
					tribute1 = NULL;
					tribute2 = NULL;
					delete tribute1;
					delete tribute2;
					cout << action << "\n";
					return 2;
				}
			}
			else
			{
				action.append(" but Tribute1 makes no progress on Tribute2 and spends all day tracking him/her2 but never actually catching up to him/her2.");
				action = nameReplacer(action, 1, *tribute1);
				action = nameReplacer(action, 2, *tribute2);
				tribute1->usedToday = true;
				listOfUsableTributes.remove(true, tribute1->ID);
				tribute1 = NULL;
				tribute2 = NULL;
				delete tribute1;
				delete tribute2;
				cout << action << "\n";
				return 1;
			}
		}
	}
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventNineteen()
{
	if (usableTributes < 2)
		return 0;
	Tribute *tribute1 = NULL;
	Tribute *tribute2 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	tribute2 = tribute2->getTribute(roster.size());
	while (tribute2->ID == tribute1->ID)
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(roster.size());
	}
	string action = "Tribute1 stalks Tribute2";
	if (tribute2->perception > tribute1->agility)
	{
		action.append(" but Tribute2 realizes that he/she1 is following him/her2 and domes Tribute1 with a rock before running off.");
		tribute1->injury++;
		action = nameReplacer(action, 1, *tribute1);
		action = nameReplacer(action, 2, *tribute2);
		tribute1->usedToday = true;
		listOfUsableTributes.remove(true, tribute1->ID);
		tribute1 = NULL;
		tribute2 = NULL;
		delete tribute1;
		delete tribute2;
		cout << action << "\n";
		return 1;
	}
	else if (tribute1->agility > tribute2->perception)
	{
		action.append(" and successfully catches Tribute2 in an ambush and manages to mildly injure him/her2 before he/she2 makes their escape.");
		tribute2->injury++;
		action = nameReplacer(action, 1, *tribute1);
		action = nameReplacer(action, 2, *tribute2);
		tribute1->usedToday = true;
		tribute2->usedToday = true;
		listOfUsableTributes.remove(true, tribute1->ID);
		listOfUsableTributes.remove(true, tribute2->ID);
		tribute1 = NULL;
		tribute2 = NULL;
		delete tribute1;
		delete tribute2;
		cout << action << "\n";
		return 2;
	}
	else
	{
		action.append(" but he/she1 decides against trying to ambush Tribute2 and watches him/her2 for the day to learn their daily routine and find a weakness to exploit later");
		action = nameReplacer(action, 1, *tribute1);
		action = nameReplacer(action, 2, *tribute2);
		tribute1->usedToday = true;
		listOfUsableTributes.remove(true, tribute1->ID);
		tribute1 = NULL;
		tribute2 = NULL;
		delete tribute1;
		delete tribute2;
		cout << action << "\n";
		return 1;
	}
}

int dayEventTwenty()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "";
	if (tribute1->luck > 6)
	{
		action = "Tribute1 receives an explosive from an unknown sponsor.";
		tribute1->inventory.grenade++;
	}
	else if (tribute1->luck == 1)
	{
		action = "Tribute1 receives an explosive from an unknown sponsor but it detonates upon landing killing Tribute1.";
		tribute1->alive = false;
		livingTributes--;
	}
	else
		action = "Tribute1 finds a secluded space to stare into the sky waiting for a care package from a sponsor that never comes.";
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventTwentyOne()
{
	if (usableTributes < 2)
		return 0;
	Tribute *tribute1 = NULL;
	Tribute *tribute2 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	tribute2 = tribute2->getTribute(roster.size());
	while (tribute2->ID == tribute1->ID)
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(roster.size());
	}
	string action = "";
	if (tribute1->perception < 3 && tribute2->perception < 3)
	{
		action = "Tribute1 and Tribute2 unknowingly build shelters within 100 yards of each other.";
		tribute1->inventory.camping_equipment++;
		tribute2->inventory.camping_equipment++;
	}
	else if (tribute1->perception > tribute2->perception)
	{
		action = "Whilst building his/her1 shelter, Tribute1 notices that Tribute2 is also building a shelter nearby";
		if (tribute1->agility > tribute2->perception)
			action.append(" and sets fire to his/her2 shelter when he/she2 takes a break, then Tribute1 leaves the area.");
		else
		{
			action.append(" but decides to live to fight another day and relocates somewhere else in the arena to make camp.");
			tribute2->inventory.camping_equipment++;
		}
	}
	else if (tribute1->perception < tribute2->perception)
	{
		action = "Whilst building his/her2 shelter, Tribute2 notices that Tribute1 is also building a shelter nearby";
		if (tribute2->agility > tribute1->perception)
			action.append(" and sets fire to his/her1 shelter when he/she1 takes a break, then Tribute2 leaves the area.");
		else
		{
			action.append(" but decides to live to fight another day and relocates somewhere else in the arena to make camp.");
			tribute1->inventory.camping_equipment++;
		}
	}
	else
	{
		action.append("Tribute1 and Tribute2 notice that they're building shelters within 100 yards of one another and begin fighting.\n");
		if (tribute1->strength > tribute2->strength)
		{
			action.append("\tArming himself/herself1 with materials they were using to build a shelter, Tribute1 lands a lucky blow on Tribute2 knocking him/her2 to the ground\n\tTribute1 proceeds to beat Tribute2's head in until it's just a mushy pile on the ground.");
			tribute2->alive = false;
			livingTributes--;
		}
		else if (tribute2->strength > tribute1->strength)
		{
			action.append("\tArming himself/herself2 with materials they were using to build a shelter, Tribute2 manages to knock down Tribute1 and jumps and stomps on Tribute1's ribcage, breaking their ribs\n\tWith Tribute2 standing on his/her1 chest, Tribute1 chokes on their blood and dies.");
			tribute1->alive = false;
			livingTributes--;
		}
		else
		{
			action.append("\tTribute1 fights valiantly against Tribute2 but is knocked unconcious during the fight\n\tWhen he/she1 wakes up, Tribute2 and his/her2 shelter are gone. Tribute1 picks himself/herself1 up and moves elsewhere in the arena to continue surviving.");
			tribute1->injury++;
			tribute2->injury++;
		}
	}
	action = nameReplacer(action, 1, *tribute1);
	action = nameReplacer(action, 2, *tribute2);
	tribute1->usedToday = true;
	tribute2->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	listOfUsableTributes.remove(true, tribute2->ID);
	tribute1 = NULL;
	tribute2 = NULL;
	delete tribute1;
	delete tribute2;
	cout << action << "\n";
	return 2;
}

int dayEventTwentyTwo()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 spends his/her1 day trying to find a way out of the arena.";
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventTwentyThree()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 wonders how long the game would take if he/she1 hid and waited for the other tributes to starve";
	if (tribute1->intelligence > 4)
	{
		action.append(" and realizes how stupid of an idea this is and decides to actually do something with his/her1 day.");
		action = nameReplacer(action, 1, *tribute1);
		tribute1 = NULL;
		delete tribute1;
		cout << action << "\n";
		return 0;
	}
	else
		action.append(" and spends the entire day thinking about it, doing nothing productive to his/her1 survival.");
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventTwentyFour()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 falls down a small cliff and is knocked out for the day";
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	if (tribute1->luck < 4)
		tribute1->injury++;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventTwentyFive()
{
	if (usableTributes < 3)
		return 0;
	Tribute *tribute1 = NULL;
	Tribute *tribute2 = NULL;
	Tribute *tribute3 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	tribute2 = tribute2->getTribute(roster.size());
	while (tribute2->ID == tribute1->ID)
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(roster.size());
	}
	tribute3 = tribute3->getTribute(roster.size());
	while (tribute3->ID == tribute1->ID  || tribute3->ID == tribute2->ID)
	{
		tribute3 = NULL;
		delete tribute3;
		tribute3 = tribute3->getTribute(roster.size());
	}
	string action = "After some discussion, Tribute1, Tribute2, and Tribute3 work together for the day to find edible food and clean water";
	int temp = tribute1->perception + tribute2->perception + tribute3->perception;
	if (temp <= 15)
		action.append(" but none are able to find anything.");
	else if (temp > 15 && temp <= 20) 
	{
		action.append(" and split what they find.");
		tribute1->inventory.food++;
		tribute1->inventory.canteen_of_water++;
		tribute2->inventory.food++;
		tribute2->inventory.canteen_of_water++;
		tribute3->inventory.food++;
		tribute3->inventory.canteen_of_water++;
	}
	else if (temp > 20 && temp <= 25)
	{
		action.append(" and split what they find.");
		tribute1->inventory.food = tribute1->inventory.food + 2;
		tribute1->inventory.canteen_of_water = tribute1->inventory.canteen_of_water + 2;
		tribute2->inventory.food = tribute2->inventory.food + 2;
		tribute2->inventory.canteen_of_water = tribute2->inventory.canteen_of_water + 2;
		tribute3->inventory.food = tribute3->inventory.food + 2;
		tribute3->inventory.canteen_of_water = tribute3->inventory.canteen_of_water + 2;
	}
	else if (temp > 25)
	{
		action.append(" and split what they find.");
		tribute1->inventory.food = tribute1->inventory.food + 3;
		tribute1->inventory.canteen_of_water = tribute1->inventory.canteen_of_water + 3;
		tribute2->inventory.food = tribute2->inventory.food + 3;
		tribute2->inventory.canteen_of_water = tribute2->inventory.canteen_of_water + 3;
		tribute3->inventory.food = tribute3->inventory.food + 3;
		tribute3->inventory.canteen_of_water = tribute3->inventory.canteen_of_water + 3;
	}
	action = nameReplacer(action, 1, *tribute1);
	action = nameReplacer(action, 2, *tribute2);
	action = nameReplacer(action, 3, *tribute3);
	tribute1->usedToday = true;
	tribute2->usedToday = true;
	tribute3->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	listOfUsableTributes.remove(true, tribute2->ID);
	listOfUsableTributes.remove(true, tribute3->ID);
	tribute1 = NULL;
	tribute2 = NULL;
	tribute3 = NULL;
	delete tribute1;
	delete tribute2;
	delete tribute3;
	cout << action << "\n";
	return 3;
}

int dayEventTwentySix()
{
	if (usableTributes < 7)
		return 0;
	Tribute *tribute1 = NULL;
	Tribute *tribute2 = NULL;
	Tribute *tribute3 = NULL;
	Tribute *tribute4 = NULL;
	Tribute *tribute5 = NULL;
	Tribute *tribute6 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	tribute2 = tribute2->getTribute(roster.size());
	while (tribute2->ID == tribute1->ID)
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(roster.size());
	}
	tribute3 = tribute3->getTribute(roster.size());
	while (tribute3->ID == tribute1->ID || tribute3->ID == tribute2->ID)
	{
		tribute3 = NULL;
		delete tribute3;
		tribute3 = tribute3->getTribute(roster.size());
	}
	tribute4 = tribute4->getTribute(roster.size());
	while (tribute4->ID == tribute1->ID || tribute4->ID == tribute2->ID || tribute4->ID == tribute3->ID)
	{
		tribute4 = NULL;
		delete tribute4;
		tribute4 = tribute4->getTribute(roster.size());
	}
	tribute5 = tribute5->getTribute(roster.size());
	while (tribute5->ID == tribute1->ID || tribute5->ID == tribute2->ID || tribute5->ID == tribute3->ID || tribute5->ID == tribute4->ID)
	{
		tribute5 = NULL;
		delete tribute5;
		tribute5 = tribute5->getTribute(roster.size());
	}
	tribute6 = tribute6->getTribute(roster.size());
	while (tribute6->ID == tribute1->ID || tribute6->ID == tribute2->ID || tribute6->ID == tribute3->ID || tribute6->ID == tribute4->ID || tribute6->ID == tribute5->ID)
	{
		tribute6 = NULL;
		delete tribute6;
		tribute6 = tribute6->getTribute(roster.size());
	}
	string action = "Tribute1, Tribute2, Tribute3, Tribute4, Tribute6, and Tribute5 attempt to hunt for other tributes";
	int temp = tribute1->perception + tribute2->perception + tribute3->perception + tribute4->perception + tribute5->perception + tribute6->perception;
	if (temp > 30)
	{
		action.append(" and successfully find Tribute7 and surround him/her7.\n");
		Tribute *tribute7 = NULL;
		tribute7 = tribute7->getTribute(roster.size());
		while (tribute7->ID == tribute1->ID || tribute7->ID == tribute2->ID || tribute7->ID == tribute3->ID || tribute7->ID == tribute4->ID || tribute7->ID == tribute5->ID || tribute7->ID == tribute6->ID)
		{
			tribute7 = NULL;
			delete tribute7;
			tribute7 = tribute7->getTribute(roster.size());
		}
		temp = tribute1->strength + tribute2->strength + tribute3->strength + tribute4->strength + tribute5->strength + tribute6->strength;
		if (tribute7->strength > temp)
		{
			action.append("\tTribute7's fight or flight reflex kicks in and he/she7 begins to see everything in a blur.\n\tWhen he/she7 comes out of it, all 6 tributes lay dead around him/her7.");
			livingTributes = livingTributes - 6;
			tribute1->alive = false;
			tribute2->alive = false;
			tribute3->alive = false;
			tribute4->alive = false;
			tribute5->alive = false;
			tribute6->alive = false;
			action = nameReplacer(action, 1, *tribute1);
			action = nameReplacer(action, 2, *tribute2);
			action = nameReplacer(action, 3, *tribute3);
			action = nameReplacer(action, 4, *tribute4);
			action = nameReplacer(action, 5, *tribute5);
			action = nameReplacer(action, 6, *tribute6);
			action = nameReplacer(action, 7, *tribute7);
			tribute1->usedToday = true;
			tribute2->usedToday = true;
			tribute3->usedToday = true;
			tribute4->usedToday = true;
			tribute5->usedToday = true;
			tribute6->usedToday = true;
			tribute7->usedToday = true;
			listOfUsableTributes.remove(true, tribute1->ID);
			listOfUsableTributes.remove(true, tribute2->ID);
			listOfUsableTributes.remove(true, tribute3->ID);
			listOfUsableTributes.remove(true, tribute4->ID);
			listOfUsableTributes.remove(true, tribute5->ID);
			listOfUsableTributes.remove(true, tribute6->ID);
			listOfUsableTributes.remove(true, tribute7->ID);
			tribute1 = NULL;
			tribute2 = NULL;
			tribute3 = NULL;
			tribute4 = NULL;
			tribute5 = NULL;
			tribute6 = NULL;
			tribute7 = NULL;
			delete tribute1;
			delete tribute2;
			delete tribute3;
			delete tribute4;
			delete tribute5;
			delete tribute6;
			delete tribute7;
			cout << action << "\n";
			return 7;
		}
		else
		{
			action.append("\tTribute7's face is unrecognizable after the group beatdown, and he/she7 dies of the severity of the beating.");
			livingTributes--;
			tribute7->alive = false;
			action = nameReplacer(action, 1, *tribute1);
			action = nameReplacer(action, 2, *tribute2);
			action = nameReplacer(action, 3, *tribute3);
			action = nameReplacer(action, 4, *tribute4);
			action = nameReplacer(action, 5, *tribute5);
			action = nameReplacer(action, 6, *tribute6);
			action = nameReplacer(action, 7, *tribute7);
			tribute1->usedToday = true;
			tribute2->usedToday = true;
			tribute3->usedToday = true;
			tribute4->usedToday = true;
			tribute5->usedToday = true;
			tribute6->usedToday = true;
			tribute7->usedToday = true;
			listOfUsableTributes.remove(true, tribute1->ID);
			listOfUsableTributes.remove(true, tribute2->ID);
			listOfUsableTributes.remove(true, tribute3->ID);
			listOfUsableTributes.remove(true, tribute4->ID);
			listOfUsableTributes.remove(true, tribute5->ID);
			listOfUsableTributes.remove(true, tribute6->ID);
			listOfUsableTributes.remove(true, tribute7->ID);
			tribute1 = NULL;
			tribute2 = NULL;
			tribute3 = NULL;
			tribute4 = NULL;
			tribute5 = NULL;
			tribute6 = NULL;
			tribute7 = NULL;
			delete tribute1;
			delete tribute2;
			delete tribute3;
			delete tribute4;
			delete tribute5;
			delete tribute6;
			delete tribute7;
			cout << action << "\n";
			return 7;
		}
	} 
	else
		action.append(" but don't manage to find anyone.");
	action = nameReplacer(action, 1, *tribute1);
	action = nameReplacer(action, 2, *tribute2);
	action = nameReplacer(action, 3, *tribute3);
	action = nameReplacer(action, 4, *tribute4);
	action = nameReplacer(action, 5, *tribute5);
	action = nameReplacer(action, 6, *tribute6);
	tribute1->usedToday = true;
	tribute2->usedToday = true;
	tribute3->usedToday = true;
	tribute4->usedToday = true;
	tribute5->usedToday = true;
	tribute6->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	listOfUsableTributes.remove(true, tribute2->ID);
	listOfUsableTributes.remove(true, tribute3->ID);
	listOfUsableTributes.remove(true, tribute4->ID);
	listOfUsableTributes.remove(true, tribute5->ID);
	listOfUsableTributes.remove(true, tribute6->ID);
	tribute1 = NULL;
	tribute2 = NULL;
	tribute3 = NULL;
	tribute4 = NULL;
	tribute5 = NULL;
	tribute6 = NULL;
	delete tribute1;
	delete tribute2;
	delete tribute3;
	delete tribute4;
	delete tribute5;
	delete tribute6;
	cout << action << "\n";
	return 6;
}

int dayEventTwentySeven()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "";
	if (tribute1->intelligence > 6)
	{
		action.append("Tribute1 camoflagues himself/herself1 in the bushes and conceals himself/herself1 from other tributes for the day.");
		tribute1->usedToday = true;
		action = nameReplacer(action, 1, *tribute1);
		listOfUsableTributes.remove(true, tribute1->ID);
		tribute1 = NULL;
		delete tribute1;
		cout << action << "\n";
		return 1;
	}
	else
		action.append("Tribute1 attempts to camoflague himself/herself1 in the bushes but doesn't really hide himself/herself1 that well.");
	action = nameReplacer(action, 1, *tribute1);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 0;
}

int dayEventTwentyEight()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 discovers a cave to use as shelter for a few days.";
	tribute1->inventory.camping_equipment = tribute1->inventory.camping_equipment + 3;
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventTwentyNine()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "";
	if (tribute1->luck > 4)
	{
		action.append("Tribute1 receives a hatchet from an unknown sponsor.");
		tribute1->inventory.hatchet++;
	}
	else if (tribute1->luck == 1)
	{
		action.append("Tribute1 receives a hatchet from an unknown sponsor but as it falls to the arena it lands on Tribute1's foot, causing a severe gash.");
		tribute1->injury++;
	}
	else
		action.append("Tribute1 finds a secluded space to stare into the sky waiting for a care package from a sponsor that never comes.");
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventThirty()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = ""; 
	if (tribute1->luck > 4)
	{
		action.append("Tribute1 receives a clean water from an unknown sponsor.");
		tribute1->inventory.canteen_of_water++;
	}
	else
		action.append("Tribute1 finds a secluded space to stare into the sky waiting for a care package from a sponsor that never comes.");
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventThirtyOne()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "";
	if (tribute1->luck > 4)
	{
		action.append("Tribute1 receives a medical supplies from an unknown sponsor.");
		tribute1->inventory.first_aid_kit++;
	}
	else
		action.append("Tribute1 finds a secluded space to stare into the sky waiting for a care package from a sponsor that never comes.");
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventThirtyTwo()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "";
	if (tribute1->luck > 4)
	{
		action.append("Tribute1 receives a fresh food from an unknown sponsor.");
		tribute1->inventory.food++;
	}
	else if (tribute1->luck > 9)
	{
		action.append("Tribute1 receives a steak dinner without any silverware from an unknown sponsor.");
		tribute1->inventory.food = tribute1->inventory.food + 2;
	}
	else
		action.append("Tribute1 finds a secluded space to stare into the sky waiting for a care package from a sponsor that never comes.");
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventThirtyThree()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 searches for a water source";
	if (tribute1->luck > 5)
		action.append(" and finds a fresh water creek to drink from.");
	else
		action.append(" but doesn't find any fresh water to drink from.");
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventThirtyFour()
{
	if (usableTributes < 2)
		return 0;
	Tribute *tribute1 = NULL;
	Tribute *tribute2 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	tribute2 = tribute2->getTribute(roster.size());
	while (tribute2->ID == tribute1->ID)
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(roster.size());
	}
	string action = "Tribute1 and Tribute2 get into a fistfight";
	if (tribute1->strength > tribute2->strength)
	{
		if (tribute1->endurance >= tribute2->endurance)
		{
			action.append(" and Tribute1 lands a punch to Tribute2's jaw, knocking him/her2 unconcious.\n\tTribute1 takes the opportunity to execute Tribute2.");
			tribute2->alive = false;
			livingTributes--;
		}
		else if (tribute1->endurance < tribute2->endurance)
		{
			action.append(" and while Tribute1 swings as hard as he/she1 can, Tribute2 endures the hits until Tribute1 is too exhausted to fight anymore.\n\tTribute2 uses this opportunity to escape with only some minor injuries.");
			tribute2->injury++;
		}
	}
	else if (tribute1->strength < tribute2->strength)
	{
		if (tribute1->endurance <= tribute2->endurance)
		{
			action.append(" and Tribute2 lands a punch to Tribute1's jaw, knocking him/her1 unconcious.\n\tTribute2 takes the opportunity to execute Tribute1.");
			tribute1->alive = false;
			livingTributes--;
		}
		else if (tribute1->endurance > tribute2->endurance)
		{
			action.append(" and while Tribute2 swings as hard as he/she2 can, Tribute1 endures the hits until Tribute2 is too exhausted to fight anymore.\n\tTribute1 uses this opportunity to escape with only some minor injuries.");
			tribute1->injury++;
		}
	} 
	else
	{
		if (tribute1->endurance == tribute2->endurance)
		{
			action.append(" and both tributes are evenly matched against one another, giving each other some minor injuries.\n\tBoth tributes walk away from the experience alive");
			tribute1->injury++;
			tribute2->injury++;
		}
		else if (tribute1->endurance > tribute2->endurance)
		{
			action.append(" and while Tribute2 swings as hard as he/she2 can, Tribute1 endures the hits until Tribute2 is too exhausted to fight anymore.\n\tTribute1 uses this opportunity to escape with only some minor injuries.");
			tribute1->injury++;
		}
		else
		{
			action.append(" and while Tribute1 swings as hard as he/she1 can, Tribute2 endures the hits until Tribute1 is too exhausted to fight anymore.\n\tTribute2 uses this opportunity to escape with only some minor injuries.");
			tribute2->injury++;
		}
	}
	action = nameReplacer(action, 1, *tribute1);
	action = nameReplacer(action, 2, *tribute2);
	tribute1->usedToday = true;
	tribute2->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	listOfUsableTributes.remove(true, tribute2->ID);
	tribute1 = NULL;
	tribute2 = NULL;
	delete tribute1;
	delete tribute2;
	cout << action << "\n";
	return 2;
}

int dayEventThirtyFive()
{
	if (usableTributes < 5)
		return 0;
	Tribute *tribute1 = NULL;
	Tribute *tribute2 = NULL;
	Tribute *tribute3 = NULL;
	Tribute *tribute4 = NULL;
	Tribute *tribute5 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	tribute2 = tribute2->getTribute(roster.size());
	while (tribute2->ID == tribute1->ID)
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(roster.size());
	}
	tribute3 = tribute3->getTribute(roster.size());
	while (tribute3->ID == tribute1->ID || tribute3->ID == tribute2->ID)
	{
		tribute3 = NULL;
		delete tribute3;
		tribute3 = tribute3->getTribute(roster.size());
	}
	tribute4 = tribute4->getTribute(roster.size());
	while (tribute4->ID == tribute1->ID || tribute4->ID == tribute2->ID || tribute4->ID == tribute3->ID)
	{
		tribute4 = NULL;
		delete tribute4;
		tribute4 = tribute4->getTribute(roster.size());
	}
	tribute5 = tribute5->getTribute(roster.size());
	while (tribute5->ID == tribute1->ID || tribute5->ID == tribute2->ID || tribute5->ID == tribute3->ID || tribute5->ID == tribute4->ID)
	{
		tribute5 = NULL;
		delete tribute5;
		tribute5 = tribute5->getTribute(roster.size());
	}
	string action = "Tribute1, Tribute2, Tribute3, and Tribute4 raid Tribute5's camp to destroy his/her5 survival supplies while he/she5 is away.";
	if (tribute5->inventory.food > 0)
		tribute5->inventory.food--;
	else if (tribute5->inventory.canteen_of_water > 0)
		tribute5->inventory.canteen_of_water--;
	else if (tribute5->inventory.camping_equipment > 0)
		tribute5->inventory.camping_equipment--;
	action = nameReplacer(action, 1, *tribute1);
	action = nameReplacer(action, 2, *tribute2);
	action = nameReplacer(action, 3, *tribute3);
	action = nameReplacer(action, 4, *tribute4);
	action = nameReplacer(action, 5, *tribute5);
	tribute1->usedToday = true;
	tribute2->usedToday = true;
	tribute3->usedToday = true;
	tribute4->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	listOfUsableTributes.remove(true, tribute2->ID);
	listOfUsableTributes.remove(true, tribute3->ID);
	listOfUsableTributes.remove(true, tribute4->ID);
	tribute1 = NULL;
	tribute2 = NULL;
	tribute3 = NULL;
	tribute4 = NULL;
	tribute5 = NULL;
	delete tribute1;
	delete tribute2;
	delete tribute3;
	delete tribute4;
	delete tribute5;
	cout << action << "\n";
	return 4;
}

int dayEventThirtySix()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "";
	if (tribute1->intelligence > 5)
	{
		action.append("Tribute1 constructs a shack.");
		tribute1->inventory.camping_equipment = tribute1->inventory.camping_equipment + 2;
	}
	else
	{
		tribute1 = NULL;
		delete tribute1;
		return 0;
	}
		action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventThirtySeven()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 spends the day thinking about home.";
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	return 1;
}

int dayEventThirtyEight()
{
	if (usableTributes < 2)
		return 0;
	Tribute *tribute1 = NULL;
	Tribute *tribute2 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	tribute2 = tribute2->getTribute(roster.size());
	while (tribute2->ID == tribute1->ID)
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(roster.size());
	}
	string action = "Tribute1 and Tribute2 split up to search for resources";
	if ((tribute1->perception + tribute2->perception) > 10)
	{
		action.append(" and split what they find.");
		tribute1->inventory.food++;
		tribute1->inventory.canteen_of_water++;
		tribute2->inventory.food++;
		tribute2->inventory.canteen_of_water++;
	}
	else
	{
		action.append(" but spend the day looking without finding anything worthwhile.");
	}
	action = nameReplacer(action, 1, *tribute1);
	action = nameReplacer(action, 2, *tribute2);
	tribute1->usedToday = true;
	tribute2->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	listOfUsableTributes.remove(true, tribute2->ID);
	tribute1 = NULL;
	tribute2 = NULL;
	delete tribute1;
	delete tribute2;
	return 2;
}

int dayEventThirtyNine()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 picks flowers";
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int dayEventForty()
{
	//SWORD FIGHT EVENT
	if (usableTributes < 2)
		return 0;
	Tribute *tribute1 = NULL;
	Tribute *tribute2 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	tribute2 = tribute2->getTribute(roster.size());
	while (tribute2->ID == tribute1->ID)
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(roster.size());
	}
	string action = "Tribute1 and Tribute2 run into each other in the arena and begin to fight\n";
	if (tribute1->inventory.sword > 0 && tribute2->inventory.sword == 0)
	{
		action.append("\tTribute1 uses his/her1 sword and fatally stabs Tribute2 in the abdomen, spilling his/her2 intestines all over the ground, killing him/her2.");
		tribute2->alive = false;
		livingTributes--;
	}
	else if (tribute1->inventory.sword > 0 && tribute2->inventory.sword > 0)
	{
		action.append("\tTribute1 and Tribute2 use their swords and engage in a poorly executed swordfight");
		if (tribute1->agility > tribute2->agility)
		{
			action.append(" where Tribute2 is eventually decapitated, but not before deeply slashing Tribute1.");
			tribute2->alive = false;
			livingTributes--;
			tribute1->injury++;
		}
		else if (tribute2->agility > tribute1->agility)
		{
			action.append(" where Tribute1 loses his/her1 arm in the fight after gashing Tribute2 across his/her2 face.\n\the/she1 bleeds out on the ground as Tribute2 watches.");
			tribute1->alive = false;
			livingTributes--;
			tribute2->injury++;
		}
		else
		{
			action.append(" which ends in both tributes stabbing each fatally and dying on the ground forever looking into each others' eyes with hatred.");
			tribute1->alive = false;
			tribute2->alive = false;
			livingTributes = livingTributes - 2;
		}
	} 
	else
	{
		action.append("\tAs Tribute1 charges Tribute2, he/she2 pulls out his/her2 sword and thrusts it into Tribute1's charging shoulder knocking him/her1 to the ground.\n\tTribute2 uses this opportunity to plunge the sword into Tribute1's abdomen, killing him/her1.");
		tribute1->alive = false;
		livingTributes--;
	}
	action = nameReplacer(action, 1, *tribute1);
	action = nameReplacer(action, 2, *tribute2);
	tribute1->usedToday = true;
	tribute2->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	listOfUsableTributes.remove(true, tribute2->ID);
	tribute1 = NULL;
	tribute2 = NULL;
	delete tribute1;
	delete tribute2;
	cout << action << "\n";
	return 2;
}

int dayEventFortyOne()
{
	//Bow & Arrow Event
	return 0;
}

int dayEventFortyTwo()
{
	//Knives event
	return 0;
}

int dayEventFortyThree()
{
	//Mace event
	return 0;
}

int dayEventFortyFour()
{
	//Spear event
	return 0;
}

int dayEventFortyFive()
{
	//Sickle event
	return 0;
}

int dayEventFortySix()
{
	//Trident event
	return 0;
}

int dayEventFortySeven()
{
	//Sais event
	return 0;
}

int dayEventFortyEight()
{
	//Hatchet event
	return 0;
}

int dayEventFortyNine()
{
	//Slingshot event
	return 0;
}

int dayEventFifty()
{
	//Pistol event
	return 0;
}

int dayEventFiftyOne()
{
	//Rifle event
	return 0;
}

int dayEventFiftyTwo()
{
	//Axe event
	return 0;
}

int dayEventFiftyThree()
{
	string action = "Tribute1 catches Tribute2 off guard and kills him/her2";
	return 0;
}

int dayEventFiftyFour()
{
	string action = "Tribute1 throws a knife into Tribute2's head";
	return 0;
}

int dayEventFiftyFive()
{
	string action = "Tribute1 begs for Tribute2 to kill him/her1";
	return 0;
}

int dayEventFiftySix()
{
	string action = "Tribute1 and Tribute2 work together to drown Tribute3";
	return 0;
}

int dayEventFiftySeven()
{
	string action = "Tribute1 strangles Tribute2 after fistfight";
	return 0;
}

int dayEventFiftyEight()
{
	string action = "Tribute1 shoots an arrow into Tribute2's head";
	return 0;
}

int dayEventFiftyNine()
{
	string action = "Tribute1 cannot handle the circumstances and commits suicide";
	return 0;
}

int dayEventSixty()
{
	string action = "Tribute1 bashes Tribute2's head against a rock several times";
	return 0;
}

int dayEventSixtyOne()
{
	string action = "Tribute1 unknowingly eats toxic berries";
	return 0;
}

int dayEventSixtyTwo()
{
	string action = "Tribute1 taints Tribute2's food, killing him/her2";
	return 0;
}

int dayEventSixtyThree()
{
	string action = "Tribute1 sets Tribute2 on fire with a molotov";
	return 0;
}

int dayEventSixtyFour()
{
	string action = "Tribute1 falls into a pit and dies";
	return 0;
}

int dayEventSixtyFive()
{
	string action = "Tribute1 stabs Tribute2 while his/her2 back is turned";
	return 0;
}

int dayEventSixtySix()
{
	string action = "Tribute1 severely injures Tribute2 and puts him/her2 out of his/her2 misery";
	//or leave to die
	return 0;
}

int dayEventSixtySeven()
{
	string action = "Tribute1 attempts to climb a tree but falls to his/her1 death";
	return 0;
}

int dayEventSixtyEight()
{
	string action = "Tribute1's trap kills Tribute2";
	return 0;
}

int dayEventSixtyNine()
{
	string action = "Tribute1 is unable to convince Tribute2 to spare him/her1";
	// success Only to kill trib1 himself/herself2
	return 0;
}

int dayEventSeventy()
{
	string action = "Tribute1 throws a knife into Tribute2's chest";
	return 0;
}

int dayEventSeventyOne()
{
	string action = "Tribute1 pushes Tribute2 off of a cliff";
	return 0;
}

int dayEventSeventyTwo()
{
	string action = "Tribute1, Tribute2 and Tribute3 but";
	//One runs away as the other two kill one
	return 0;
}

int dayEventSeventyThree()
{
	string action = "Tribute1 sets off an explosive killing";
	//Varying number of people
	return 0;
}

int dayEventSeventyFour()
{
	string action = "Tribute1 kills Tribute2 as he/she2 tries to run";
	return 0;
}

int dayEventSeventyFive()
{
	string action = "Tribute1 and Tribute2 threaten a double suicide but it fails and they die";
	return 0;
}

int dayEventSeventySix()
{
	string action = "Tribute1 dies of hypothermia";
	//may want to make night event
	return 0;
}

int dayEventSeventySeven()
{
	string action = "Tribute1 dies of hunger";
	//Or thirst
	return 0;
}

int dayEventSeventyEight()
{
	string action = "Tribute1 and Tribute2 team up to fight Tribute3 and Tribute4";
	return 0;
}

int dayEventSeventyNine()
{
	string action = "Tribute1 dies of dysentery";
	return 0;
}

int dayEventEighty()
{
	string action = "Tribute1 accidently detonates a land mine from the cornucopia";
	//Or arms it
	return 0;
}

int dayEventEightyOne()
{
	string action = "Tribute1 attacks Tribute2 but Tribute3 intervenes";
	return 0;
}

int dayEventEightyTwo()
{
	string action = "Tribute1 uses his/her1 rope to strangle Tribute2";
	return 0;
}

int dayEventEightyThree()
{
	string action = "Tribute1, Tribute2, and Tribute3 ambush Tribute4, Tribute5, and Tribute6";
	//chance to be unsuccessful
	return 0;
}

int dayEventEightyFour()
{
	string action = "Tribute1 stabs Tribute2 with a tree branch";
	return 0;
}

int dayEventEightyFive()
{
	string action = "Tribute1 forces Tribute2 to kill either Tribute3 or Tribute4";
	//pick one
	//or have trib1 kill trib2
	//or 3 team up
	return 0;
}

int dayEventEightySix()
{
	string action = "Tribute1 poisons Tribute2's drink";
	return 0;
}

int dayEventEightySeven()
{
	string action = "Tribute1, Tribute2, and Tribute3 get into a fight";
	return 0;
}

int dayEventEightyEight()
{
	string action = "Tribute1 attempts sniping other tributes from atop a tree atop a cliff";
	return 0;
}

vector <func_ptr> dayEvents = { dayEventOne,			dayEventTwo,			dayEventThree,			dayEventFour,			dayEventFive,
								dayEventSix,			dayEventSeven,			dayEventEight,			dayEventNine,			dayEventTen,
								dayEventEleven,			dayEventTwelve,			dayEventThirteen,		dayEventFourteen,		dayEventFifteen,
								dayEventSixteen,		dayEventSeventeen,		dayEventEighteen,		dayEventNineteen,		dayEventTwenty,
								dayEventTwentyOne,		dayEventTwentyTwo,		dayEventTwentyThree,	dayEventTwentyFour,		dayEventTwentyFive,
								dayEventTwentySix,		dayEventTwentySeven,	dayEventTwentyEight,	dayEventTwentyNine,		dayEventThirty,
								dayEventThirtyOne,		dayEventThirtyTwo,		dayEventThirtyThree,	dayEventThirtyFour,		dayEventThirtyFive,
								dayEventThirtySix,		dayEventThirtySeven,	dayEventThirtyEight,	dayEventThirtyNine,		dayEventForty,
								dayEventFortyOne,		dayEventFortyTwo,		dayEventFortyThree,		dayEventFortyFour,		dayEventFortyFive,
								dayEventFortySix,		dayEventFortySeven,		dayEventFortyEight,		dayEventFortyNine,		dayEventFifty,
								dayEventFiftyOne,		dayEventFiftyTwo,		dayEventFiftyThree,		dayEventFiftyFour,		dayEventFiftyFive,
								dayEventFiftySix,		dayEventFiftySeven,		dayEventFiftyEight,		dayEventFiftyNine,		dayEventSixty,
								dayEventSixtyOne,		dayEventSixtyTwo,		dayEventSixtyThree,		dayEventSixtyFour,		dayEventSixtyFive,
								dayEventSixtySix,		dayEventSixtySeven,		dayEventSixtyEight,		dayEventSixtyNine,		dayEventSeventy,
								dayEventSeventyOne,		dayEventSeventyTwo,		dayEventSeventyThree,	dayEventSeventyFour,	dayEventSeventyFive,
								dayEventSeventySix,		dayEventSeventySeven,	dayEventSeventyEight,	dayEventSeventyNine,	dayEventEighty,
								dayEventEightyOne,		dayEventEightyTwo,		dayEventEightyThree,	dayEventEightyFour,		dayEventEightyFive,
								dayEventEightySix,		dayEventEightySeven,	dayEventEightyEight};