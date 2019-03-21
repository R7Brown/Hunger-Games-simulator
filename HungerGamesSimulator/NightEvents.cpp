#include "Header.h"

int nightEventOne()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	string action = "Tribute1 wants to lie down for the night beneath a bush to hide and sleep ";
	if (tribute1->perception > 5)
	{
		action.append("and finds a good spot and isn't found all night.");
		tribute1->usedToday = true;
		listOfUsableTributes.remove(true, tribute1->ID);
	}
	else
		action.append("but isn't confindent in their hiding spot and relocates.");
	action = nameReplacer(action, 1, *tribute1);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int nightEventTwo()
{
	string action = "Tribute1 sets up camp for the night";
	return 0;
}

int nightEventThree()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	string action = "Tribute1 loses sight of where he/she1 is and wanders around all night.";
	tribute1->perception--;
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int nightEventFour()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	string action = "Tribute1 climbs a tree to rest";
	if (tribute1->agility > 5)
		action.append(" and spends the night up there.");
	else
	{
		action.append(" and falls back to the ground and is knocked unconcious for the night.");
		if (tribute1->luck < 6)
			tribute1->injury++;
	}
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int nightEventFive()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	string action = "Tribute1 goes to sleep for the night.";
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int nightEventSix()
{
	if (usableTributes < 2)
		return 0;
	Tribute *tribute1 = NULL;
	Tribute *tribute2 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	tribute2 = tribute2->getTribute(false, roster.size());
	while (tribute2->ID == tribute1->ID)
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(false, roster.size());
	}
	string action = "Tribute1 and Tribute2 tell stories about themselves to each other to pass the time.";
	tribute1->usedToday = true;
	tribute2->usedToday = true;
	action = nameReplacer(action, 1, *tribute1);
	action = nameReplacer(action, 2, *tribute2);
	listOfUsableTributes.remove(true, tribute1->ID);
	listOfUsableTributes.remove(true, tribute2->ID);
	tribute1 = NULL;
	tribute2 = NULL;
	delete tribute1;
	delete tribute2;
	cout << action << "\n";
	return 2;
}

int nightEventSeven()
{
	if (usableTributes < 4)
		return 0;
	Tribute *tribute1 = NULL;
	Tribute *tribute2 = NULL;
	Tribute *tribute3 = NULL;
	Tribute *tribute4 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	tribute2 = tribute2->getTribute(false, roster.size());
	while (tribute2->ID == tribute1->ID)
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(false, roster.size());
	}
	tribute3 = tribute3->getTribute(false, roster.size());
	while (tribute3->ID == tribute1->ID || tribute3->ID == tribute2->ID)
	{
		tribute3 = NULL;
		delete tribute3;
		tribute3 = tribute3->getTribute(false, roster.size());
	}
	tribute4 = tribute4->getTribute(false, roster.size());
	while (tribute4->ID == tribute1->ID || tribute4->ID == tribute2->ID || tribute4->ID == tribute3->ID)
	{
		tribute4 = NULL;
		delete tribute4;
		tribute4 = tribute4->getTribute(false, roster.size());
	}
	string action = "Tribute1, Tribute2, Tribute3, and Tribute4 sleep in shifts to avoid surprise attacks.";
	action = nameReplacer(action, 1, *tribute1);
	action = nameReplacer(action, 2, *tribute2);
	action = nameReplacer(action, 3, *tribute3);
	action = nameReplacer(action, 4, *tribute4);
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
	delete tribute1;
	delete tribute2;
	delete tribute3;
	delete tribute4;
	cout << action << "\n";
	return 4;
}

int nightEventEight()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	string action = "Tribute1 tends to his/her1 wounds";
	if (tribute1->inventory.first_aid_kit > 0)
	{
		tribute1->inventory.first_aid_kit--;
		tribute1->injury--;
		action.append(" and successfully treats some injuries.");
	}
	else
		action.append(" but spends all night not really improving his/her1 health.");
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int nightEventNine()
{
	if (usableTributes < 2)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	string action = "Tribute1 sees a fire, ";
	if (tribute1->charisma > 6)
	{
		action.append("and decides to investigate, finding Tribute2.");
		Tribute *tribute2 = NULL;
		tribute2 = tribute2->getTribute(false, roster.size());
		while (tribute2->ID == tribute1->ID)
		{
			tribute2 = NULL;
			delete tribute2;
			tribute2 = tribute2->getTribute(false, roster.size());
		}
		if (tribute2->charisma > tribute1->charisma)
		{
			action.append(" Tribute2 then convinces Tribute1 to truce for the night and shares his/her2 fire.");
		}
		else
		{
			action.append("\tTribute1 and Tribute2 begin to fight.\n\t");
			if (tribute1->strength > tribute2->strength)
			{
				action.append("Tribute1 manages to overpower Tribute2 and shoves him/her2 into the fire setting him/her2 ablaze. While he/she2 attempts to put himself/herself2 out, Tribute1 clubs at him/her2 with a thick tree branch until he/she2 stops moving.");
				action = nameReplacer(action, 1, *tribute1);
				action = nameReplacer(action, 2, *tribute2);
				tribute2->alive = false;
				livingTributes--;
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
				action.append("Tribute2 manages to overpower Tribute1 and holds his/her1 head down on the fire, preventing him/her1 from moving. Tribute1 quickly dies from the burns and inhalation.");
				action = nameReplacer(action, 1, *tribute1);
				action = nameReplacer(action, 2, *tribute2);
				tribute1->alive = false;
				livingTributes--;
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
		}
	}
	else
		action.append("but decides not to investigate and camp somewhere else for the night.");
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int nightEventTen()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	string action = "Tribute1 screams for help and eventually collapses of exhaustion from it.";
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int nightEventEleven()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	string action = "Tribute1 stays awake all night to watch for threats.";
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int nightEventTwelve()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	string action = "";
	if (tribute1->inventory.shovel > 1)
	{
		action = "Tribute1 digs himself/herself1 a small ditch to lie in for the night for safety.";
		action = nameReplacer(action, 1, *tribute1);
		tribute1->usedToday = true;
		listOfUsableTributes.remove(true, tribute1->ID);
		tribute1 = NULL;
		delete tribute1;
		cout << action << "\n";
		return 1;
	}
	tribute1 = NULL;
	delete tribute1;
	return 0;
}

int nightEventThirteen()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	string action = "";
	if (tribute1->inventory.food > 0)
	{
		action = "Tribute1 manages to use his/her1 food to make a good meal and feels a lot better after eating it.";
		tribute1->injury--;
		action = nameReplacer(action, 1, *tribute1);
		tribute1->usedToday = true;
		listOfUsableTributes.remove(true, tribute1->ID);
		tribute1 = NULL;
		delete tribute1;
		cout << action << "\n";
		return 1;
	}
	tribute1 = NULL;
	delete tribute1;
	return 0;
}

int nightEventFourteen()
{
	if (usableTributes < 2)
		return 0;
	Tribute *tribute1 = NULL;
	Tribute *tribute2 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	tribute2 = tribute2->getTribute(false, roster.size());
	while (tribute2->ID == tribute1->ID)
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(false, roster.size());
	}
	string action = "Tribute1 and Tribute2 decide to truce for the night and sleep in shifts to keep an eye out for other tributes.";
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

int nightEventFifteen()
{
	string action = "Tribute1 fends Tribute2, Tribute3, and Tribute4 away from his/her1 fire";
	return 0;
}

int nightEventSixteen()
{
	if (usableTributes < 3)
		return 0;
	Tribute *tribute1 = NULL;
	Tribute *tribute2 = NULL;
	Tribute *tribute3 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	tribute2 = tribute2->getTribute(false, roster.size());
	while (tribute2->ID == tribute1->ID)
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(false, roster.size());
	}
	tribute3 = tribute3->getTribute(false, roster.size());
	while (tribute3->ID == tribute1->ID || tribute2->ID == tribute3->ID)
	{
		tribute3 = NULL;
		delete tribute3;
		tribute3 = tribute3->getTribute(false, roster.size());
	}
	string action = "Tribute1, Tribute2, and Tribute3 discuss the game so far and what might happen in the morning.";
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

int nightEventSeventeen()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	string action = "Tribute1 cries himself/herself1 to sleep";
	tribute1->charisma--;
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int nightEventEighteen()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	string action = "Tribute1 tries to treat his/her1 wounds";
	if (tribute1->inventory.first_aid_kit > 0)
	{
		tribute1->inventory.first_aid_kit--;
		tribute1->injury--;
		action.append(" and successfully treats some injuries.");
	}
	else
		action.append(" but spends all night not really improving his/her1 health.");
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int nightEventNineteen()
{
	if (usableTributes < 2)
		return 0;
	Tribute *tribute1 = NULL;
	Tribute *tribute2 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	tribute2 = tribute2->getTribute(false, roster.size());
	while (tribute2->ID == tribute1->ID)
	{
		tribute2 = NULL;
		delete tribute2;
		tribute2 = tribute2->getTribute(false, roster.size());
	}
	string action = "Tribute1 and Tribute2 talk about the tributes still alive before agreeing to truce for the night.";
	if (tribute1->luck == 1)
	{
		action.append("\n\tBut Tribute2 betrays the truce and smothers Tribute1 in his/her1 sleep.");
		action = nameReplacer(action, 1, *tribute1);
		action = nameReplacer(action, 2, *tribute2);
		livingTributes--;
		tribute1->alive = false;
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
	else if (tribute2->luck == 1)
	{
		action.append("\n\tBut Tribute1 betrays the truce and smothers Tribute2 in his/her2 sleep.");
		action = nameReplacer(action, 1, *tribute1);
		action = nameReplacer(action, 2, *tribute2);
		livingTributes--;
		tribute2->alive = false;
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

int nightEventTwenty()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	string action = "Tribute1 is awoken by nightmares and has difficulty sleeping for the rest of the night.";
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int nightEventTwentyOne()
{
	string action = "Tribute1 and Tribute2 huddle for warmth";
	return 0;
}

int nightEventTwentyTwo()
{
	string action = "Tribute1 thinks about winning";
	return 0;
}

int nightEventTwentyThree()
{
	string action = "Tribute1, Tribute2, Tribute3, Tribute4, and Tribute5 tell each other ghosts stories to lighten the mood";
	return 0;
}

int nightEventTwentyFour()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(false, roster.size());
	string action = "Tribute1 looks up at the night sky and learns a little bit about their surroundings by studying the constellations.";
	action = nameReplacer(action, 1, *tribute1);
	tribute1->perception++;
	tribute1->usedToday = true;
	listOfUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int nightEventTwentyFive()
{
	string action = "Tribute1 destroys Tribute2's supplies while he/she2 sleeps";
	return 0;
}

int nightEventTwentySix()
{
	string action = "Tribute1 lets Tribute2 into his/her1 shelter";
	return 0;
}

int nightEventTwentySeven()
{
	string action = "Tribute1 tries to sing himself/herself1 to sleep";
	return 0;
}

int nightEventTwentyEight()
{
	string action = "Tribute1 thinks about home";
	return 0;
}

int nightEventTwentyNine()
{
	string action = "Tribute1 tends to Tribute2's wounds";
	return 0;
}

int nightEventThirty()
{
	string action = "Tribute1 and others cheefully sing songs together";
	return 0;
}

int nightEventThirtyOne()
{
	string action = "Tribute1 and Tribute2 hold hands throughout the night";
	return 0;
}

int nightEventThirtyTwo()
{
	string action = "Tribute1 convinces Tribute2 to snuggle with him/her1";
	return 0;
}

int nightEventThirtyThree()
{
	string action = "Tribute1 questions his/her1 sanity";
	return 0;
}

vector <func_ptr> nightEvents = {	nightEventOne,		nightEventTwo,		nightEventThree,		nightEventFour,			nightEventFive,
									nightEventSix,		nightEventSeven,	nightEventEight,		nightEventNine,			nightEventTen,
									nightEventEleven,	nightEventTwelve,	nightEventThirteen,		nightEventFourteen,		nightEventFifteen };