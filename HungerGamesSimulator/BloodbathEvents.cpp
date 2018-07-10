#include "Header.h"

//returns the number of tributes with at least some amount of bloodbath points
//also inserts each tribte 
int numofTributeswithPoints(int minimum)
{
	listOfBBTributes.emptylist();
	for (int i = 0; i < roster.size(); i++)
		if (roster[i].BloodbathPoints + minimum <= BLOODBATHMAXPOINTS)
			listOfBBTributes.insert(i);
			
	return listOfBBTributes.size;
}

//bbEvent STRUCTURE
int bbEventExample()
{
	//THIS FIRST IF STATEMENT IS USED TO CHECK IF THE bbEvent CALLED CAN EVEN BE RUN
	//DON'T FORGET THIS OR THE PROGRAM IS LIKELY TO RUN ITSELF INTO AN ENDLESS LOOP 
	//TRYING TO GET A TRIBUTE
	int number_of_tributes = 1;
	if (number_of_tributes > usableTributes)
		return 0;
	//event value can vary depending of what happens in this event
	int eventvalue = 0;
	//This ensure that there exists a minimum number of tribute with a certain number of points remaining to participate in this event
	if (numofTributeswithPoints(eventvalue) < number_of_tributes)
		return 0;
	//These two lines are getting a tribute pointer to point at a tribute
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(true, roster.size());
	//the Tribute must have fewer points than their points plus the event value to not go over the maximum points.
	if ((tribute1->BloodbathPoints + eventvalue) > BLOODBATHMAXPOINTS)
	{
		tribute1 = NULL;
		delete tribute1;
		return 0;
	}
	//Action is the string that determines the uniqueness of each bbEvent. You can make it whatever you want really
	string action = "";
	/************************************************
	Checks go here based on what the bbEvent is
	Checks can check anything from stats to inventory to injuries
	Take care to edit stats, inventory, injuries etc. based on what the bbEvent is
	Otherwise you're gonna get tributes with inventories and injuries and kills that don't match the output
	*************************************************/
	//Sending action to the nameReplacer function also sends it to the pronounReplacer function
	//This is purely for output, since tributes and their stuff will still be edited by the bbEvent
	//But forgetting to send the action to the function will print 'Tribute1' and whatnot all over the output to the screen
	action = nameReplacer(action, number_of_tributes, *tribute1);
	//For each tribute the eventvalue should be added to their BloodBathPoints value
	//If this operation causes the tribute to reach BLOODBATHMAXPOINTS then the tribute should be considered used
	//The tribute then must be marked used and removed from the listOfUsableTributes
	tribute1->BloodbathPoints += eventvalue;
	if (tribute1->BloodbathPoints >= BLOODBATHMAXPOINTS)
	{
		tribute1->usedToday = true;
		usableTributes--;
		listOfUsableTributes.remove(true, tribute1->ID);
	}	
	//These three lines are in charge of deleting the pointer to prdayEvent memory leaks
	//As well as removing the trubute from the list of usable tributes
	tribute1 = NULL;
	delete tribute1;
	//Print what happened to the screen
	cout << action << "\n";
	//Return the value of the event multiplied by the number of tributes in this event.
	return (eventvalue * number_of_tributes);
}

int bbEventOne() 
{
	if (usableTributes < 1)
		return 0;
	int eventvalue = BLOODBATHMAXPOINTS;
	if (numofTributeswithPoints(eventvalue) < 1)
	{
		return 0;
	}
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(true, roster.size());
	if ((tribute1->BloodbathPoints + eventvalue) > BLOODBATHMAXPOINTS)
	{
		tribute1 = NULL;
		delete tribute1;
		return 0;
	}
	string action = "Tribute1 grabs a backpack full of supplies and runs off into the woods.";
	tribute1->inventory.food = tribute1->inventory.food + 5;
	tribute1->inventory.canteen_of_water = tribute1->inventory.canteen_of_water + 4;
	tribute1->inventory.knives++;
	tribute1->inventory.camping_equipment = tribute1->inventory.camping_equipment + 2;
	tribute1->inventory.rope++;
	tribute1->inventory.slingshot++;
	tribute1->inventory.rocks = tribute1->inventory.rocks + 10;
	action = nameReplacer(action, 1, *tribute1);
	tribute1->BloodbathPoints += eventvalue;
	if (tribute1->BloodbathPoints >= BLOODBATHMAXPOINTS)
	{
		tribute1->usedToday = true;
		usableTributes--;
		listOfUsableTributes.remove(true, tribute1->ID);
	}
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return (eventvalue * 1);
}

int bbEventTwo()
{
	if (usableTributes < 1)
		return 0;
	int eventvalue = BLOODBATHMAXPOINTS;
	if (numofTributeswithPoints(eventvalue) < 1)
	{
		return 0;
	}
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(true, roster.size());
	if ((tribute1->BloodbathPoints + eventvalue) > BLOODBATHMAXPOINTS)
	{
		tribute1 = NULL;
		delete tribute1;
		return 0;
	}
	string action = "Tribute1 grabs a backpack full of supplies and runs off into the woods.";
	tribute1->inventory.fishing_gear++;
	tribute1->inventory.spear++;
	tribute1->inventory.trident++;
	tribute1->inventory.firewood = tribute1->inventory.firewood + 3;
	tribute1->inventory.food = tribute1->inventory.food + 3;
	tribute1->inventory.canteen_of_water = tribute1->inventory.canteen_of_water + 3;
	tribute1->inventory.bait++;
	tribute1->inventory.net++;
	action = nameReplacer(action, 1, *tribute1);
	tribute1->BloodbathPoints += eventvalue;
	if (tribute1->BloodbathPoints >= BLOODBATHMAXPOINTS)
	{
		tribute1->usedToday = true;
		usableTributes--;
		listOfUsableTributes.remove(true, tribute1->ID);
	}
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return (eventvalue * 1);
}

int bbEventThree()
{
	if (usableTributes < 1)
		return 0;
	int eventvalue = BLOODBATHMAXPOINTS;
	if (numofTributeswithPoints(eventvalue) < 1)
	{
		return 0;
	}
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(true, roster.size());
	if ((tribute1->BloodbathPoints + eventvalue) > BLOODBATHMAXPOINTS)
	{
		tribute1 = NULL;
		delete tribute1;
		return 0;
	}
	string action = "Tribute1 grabs a backpack full of supplies and runs off into the woods.";
	tribute1->inventory.arrow = tribute1->inventory.arrow + 15;
	tribute1->inventory.bow++;
	tribute1->inventory.first_aid_kit = tribute1->inventory.first_aid_kit + 3;
	tribute1->inventory.firewood++;
	tribute1->inventory.rope++;
	tribute1->inventory.spear++;
	tribute1->inventory.poison++;
	action = nameReplacer(action, 1, *tribute1);
	tribute1->BloodbathPoints += eventvalue;
	if (tribute1->BloodbathPoints >= BLOODBATHMAXPOINTS)
	{
		tribute1->usedToday = true;
		usableTributes--;
		listOfUsableTributes.remove(true, tribute1->ID);
	}
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return (eventvalue * 1);
}

int bbEventFour()
{
	if (usableTributes < 1)
		return 0;
	int eventvalue = BLOODBATHMAXPOINTS;
	if (numofTributeswithPoints(eventvalue) < 1)
	{
		return 0;
	}
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(true, roster.size());
	if ((tribute1->BloodbathPoints + eventvalue) > BLOODBATHMAXPOINTS)
	{
		tribute1 = NULL;
		delete tribute1;
		return 0;
	}
	string action = "Tribute1 grabs a backpack full of supplies and runs off into the woods.";
	tribute1->inventory.spear++;
	tribute1->inventory.sword++;
	tribute1->inventory.mace++;
	tribute1->inventory.knives = tribute1->inventory.knives + 5;
	tribute1->inventory.helmet++;
	tribute1->inventory.chestplate++;
	action = nameReplacer(action, 1, *tribute1);
	tribute1->BloodbathPoints += eventvalue;
	if (tribute1->BloodbathPoints >= BLOODBATHMAXPOINTS)
	{
		tribute1->usedToday = true;
		usableTributes--;
		listOfUsableTributes.remove(true, tribute1->ID);
	}
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return (eventvalue * 1);
}

int bbEventFive()
{
	if (usableTributes < 1)
		return 0;
	int eventvalue = BLOODBATHMAXPOINTS;
	if (numofTributeswithPoints(eventvalue) < 1)
	{
		return 0;
	}
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(true, roster.size());
	if ((tribute1->BloodbathPoints + eventvalue) > BLOODBATHMAXPOINTS)
	{
		tribute1 = NULL;
		delete tribute1;
		return 0;
	}
	string action = "Tribute1 grabs a backpack full of supplies and runs off into the woods.";
	tribute1->inventory.ammo = tribute1->inventory.ammo + 10;
	tribute1->inventory.pistol++;
	tribute1->inventory.chestplate++;
	tribute1->inventory.flashlight++;
	tribute1->inventory.flares = tribute1->inventory.flares + 3;
	tribute1->inventory.flare_gun++;
	action = nameReplacer(action, 1, *tribute1);
	tribute1->BloodbathPoints += eventvalue;
	if (tribute1->BloodbathPoints >= BLOODBATHMAXPOINTS)
	{
		tribute1->usedToday = true;
		usableTributes--;
		listOfUsableTributes.remove(true, tribute1->ID);
	}
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return (eventvalue * 1);
}

int bbEventSix()
{
	if (usableTributes < 2)
		return 0;
	int eventvalue = BLOODBATHMAXPOINTS;
	if (numofTributeswithPoints(eventvalue) < 2)
	{
		return 0;
	}
	Tribute *tribute1 = NULL;
	Tribute *tribute2 = NULL;
	tribute1 = tribute1->getTribute(true, roster.size());
	if ((tribute1->BloodbathPoints + eventvalue) > BLOODBATHMAXPOINTS)
	{
		tribute1 = NULL;
		delete tribute1;
		return 0;
	}
	tribute2 = tribute2->getTribute(true, roster.size());
	while ((tribute2->ID == tribute1->ID) || ((tribute1->BloodbathPoints + eventvalue) > BLOODBATHMAXPOINTS))
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(true, roster.size());
	}
	string action = "Tribute1 and Tribute2 fight over a backpack of supplies";
	if (tribute1->strength > tribute2->strength)
	{
		action.append(" and Tribute1 overpowers Tribute2 to take the bag.");
		tribute1->BloodbathPoints += eventvalue;
		if (tribute1->BloodbathPoints >= BLOODBATHMAXPOINTS)
		{
			tribute1->usedToday = true;
			usableTributes--;
			listOfUsableTributes.remove(true, tribute1->ID);
		}
	}
	else if (tribute2->strength < tribute1->strength)
	{
		action.append(" and Tribute2 overpowers Tribute1 to take the bag.");
		tribute2->BloodbathPoints += eventvalue;
		if (tribute2->BloodbathPoints >= BLOODBATHMAXPOINTS)
		{
			tribute2->usedToday = true;
			usableTributes--;
			listOfUsableTributes.remove(true, tribute2->ID);
		}
	}
	else
	{
		tribute1->BloodbathPoints += eventvalue;
		if (tribute1->BloodbathPoints >= BLOODBATHMAXPOINTS)
		{
			tribute1->usedToday = true;
			usableTributes--;
			listOfUsableTributes.remove(true, tribute1->ID);
		}
		tribute2->BloodbathPoints += eventvalue;
		if (tribute2->BloodbathPoints >= BLOODBATHMAXPOINTS)
		{
			tribute2->usedToday = true;
			usableTributes--;
			listOfUsableTributes.remove(true, tribute2->ID);
		}
		action.append(" and the bag gets taken while they fight each other.");
	}
	action = nameReplacer(action, 1, *tribute1);
	action = nameReplacer(action, 2, *tribute2);
	tribute1 = NULL;
	tribute2 = NULL;
	delete tribute2;
	delete tribute1;
	cout << action << "\n";
	return (eventvalue * 2);
}

int bbEventSeven()
{
	if (usableTributes < 1)
		return 0;

	int eventvalue = 1;
	if (numofTributeswithPoints(eventvalue) < 1)
	{
		return 0;
	}
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(true, roster.size());
	if ((tribute1->BloodbathPoints + eventvalue) > BLOODBATHMAXPOINTS)
	{
		tribute1 = NULL;
		delete tribute1;
		return 0;
	}
	string action = "Tribute1 takes a handful of throwing knives.";
	tribute1->inventory.knives = tribute1->inventory.knives + 5;
	tribute1->BloodbathPoints += eventvalue;
	if (tribute1->BloodbathPoints >= BLOODBATHMAXPOINTS)
	{
		tribute1->usedToday = true;
		usableTributes--;
		listOfUsableTributes.remove(true, tribute1->ID);
	}
	action = nameReplacer(action, 1, *tribute1);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return (eventvalue * 1);
}

int bbEventEight()
{
	string action = "Tribute1 rips a mace out of Tribute2's hands";
	return 0;
}

int bbEventNine()
{
	if (usableTributes < 1)
		return 0;

	int eventvalue = 1;
	if (numofTributeswithPoints(eventvalue) < 1)
	{
		return 0;
	}
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(true, roster.size());
	if ((tribute1->BloodbathPoints + eventvalue) > BLOODBATHMAXPOINTS)
	{
		tribute1 = NULL;
		delete tribute1;
		return 0;
	}
	string action = "Tribute1 finds a canteen full of water"; 
	tribute1->inventory.knives++;
	tribute1->BloodbathPoints += eventvalue;
	if (tribute1->BloodbathPoints >= BLOODBATHMAXPOINTS)
	{
		tribute1->usedToday = true;
		usableTributes--;
		listOfUsableTributes.remove(true, tribute1->ID);
	}
	action = nameReplacer(action, 1, *tribute1);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return (eventvalue * 1);
}

int bbEventTen()
{
	if (usableTributes < 1)
		return 0;
	int eventvalue = 5;
	if (numofTributeswithPoints(eventvalue) < 1)
	{
		return 0;
	}
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(true, roster.size());
	if ((tribute1->BloodbathPoints + eventvalue) > BLOODBATHMAXPOINTS)
	{
		tribute1 = NULL;
		delete tribute1;
		return 0;
	}
	string action = "Tribute1 hides in the cornucopia for resources once the others leave";
	tribute1->inventory.club++;
	tribute1->inventory.torch++;
	tribute1->inventory.smoke_grenade++;
	tribute1->inventory.map++;
	tribute1->inventory.matches++;
	tribute1->BloodbathPoints += eventvalue;
	if (tribute1->BloodbathPoints >= BLOODBATHMAXPOINTS)
	{
		tribute1->usedToday = true;
		usableTributes--;
		listOfUsableTributes.remove(true, tribute1->ID);
	}
	action = nameReplacer(action, 1, *tribute1);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return (eventvalue * 1);
}

int bbEventEleven()
{
	if (usableTributes < 1)
		return 0;

	int eventvalue = 1;
	if (numofTributeswithPoints(eventvalue) < 1)
	{
		return 0;
	}
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(true, roster.size());
	if ((tribute1->BloodbathPoints + eventvalue) > BLOODBATHMAXPOINTS)
	{
		tribute1 = NULL;
		delete tribute1;
		return 0;
	}
	string action = "Tribute1 gathers as much food as he/she1 can";
	tribute1->inventory.food = tribute1->inventory.food + 5;
	tribute1->BloodbathPoints += eventvalue;
	if (tribute1->BloodbathPoints >= BLOODBATHMAXPOINTS)
	{
		tribute1->usedToday = true;
		usableTributes--;
		listOfUsableTributes.remove(true, tribute1->ID);
	}
	action = nameReplacer(action, 1, *tribute1);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return (eventvalue * 1);
}

int bbEventTwelve()
{
	string action = "Tribute1 grabs a sword";
	return 0;
}

int bbEventThirteen()
{
	string action = "Tribute1 takes a spear from the cornucopia";
	return 0;
}

int bbEventFourteen()
{
	string action = "Tribute1 finds a bag of exsplosives";
	return 0;
}

int bbEventFifteen()
{
	string action = "Tribute1 grabs a first aid kit";
	return 0;
}

int bbEventSixteen()
{
	string action = "Tribute1 takes a sickle from inside the cornucopia";
	return 0;
}

int bbEventSeventeen()
{
	string action = "Tribute1, Tribute2, and Tribute3 work together to gather as many supplies as possible";
	return 0;
}

int bbEventEighteen()
{
	string action = "Tribute1 runs away with a lighter and some rope";
	return 0;
}

int bbEventNineteen()
{
	string action = "Tribute1 grabs a bottle of alcohol and a rag";
	return 0;
}

int bbEventTwenty()
{
	string action = "Tribute1 grabs a backpack full of camping supplies";
	return 0;
}

int bbEventTwentyOne()
{
	string action = "Tribute1 grabs a backpack not realizing it's empty";
	return 0;
}

int bbEventTwentyTwo()
{
	string action = "Tribute1 breaks Tribute2's nose for a basket of bread";
	return 0;
}

int bbEventTwentyThree()
{
	string action = "Tribute1, Tribute2, Tribute3, and Tribute4 share everything they gathered before running";
	return 0;
}

int bbEventTwentyFour()
{
	string action = "Tribute1 grabs a trident from inside the cornucopia";
	return 0;
}

int bbEventTwentyFive()
{
	string action = "Tribute1 grabs fishing bait while Tribute2 grabs fishing gear";
	return 0;
}

int bbEventTwentySix()
{
	string action = "Tribute1 scares Tribute2 away from the cornucopia";
	return 0;
}

int bbEventTwentySeven()
{
	string action = "Tribute1 grabs a shotgun leaning against the cornucopia";
	return 0;
}

int bbEventTwentyEight()
{
	string action = "Tribute1 snatches a ";
	return 0;
}




vector <func_ptr> bbEvents = {	bbEventOne,			bbEventTwo,				bbEventThree,			bbEventFour,		bbEventFive,
								bbEventSix,			bbEventSeven,			bbEventEight,			bbEventNine,		bbEventTen,
								bbEventEleven,		bbEventTwelve,			bbEventThirteen,		bbEventFourteen,	bbEventFifteen,
								bbEventSixteen,		bbEventSeventeen,		bbEventEighteen,		bbEventNineteen,	bbEventTwenty,
								bbEventTwentyOne,	bbEventTwentyTwo,		bbEventTwentyThree,		bbEventTwentyFour,	bbEventTwentyFive,
								bbEventTwentySix,	bbEventTwentySeven,		bbEventTwentyEight};