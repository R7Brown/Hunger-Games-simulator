#include "Header.h"

int nightEventOne()
{
	if (usableTributes < 1)
		return 0;
	Tribute *tribute1 = NULL;
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 wants to lie down for the night beneath a bush to hide and sleep ";
	if (tribute1->perception > 5)
	{
		action.append("and finds a good spot and isn't found all night.");
		tribute1->usedToday = true;
	}
	else
		action.append("but isn't confindent in their hiding spot and relocates.");
	action = nameReplacer(action, 1, *tribute1);
	ListofUsableTributes.remove(true, tribute1->ID);
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
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 loses sight of where he/she1 is";
	tribute1->perception--;
	action = nameReplacer(action, 1, *tribute1);
	ListofUsableTributes.remove(true, tribute1->ID);
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
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 climbs a tree to rest";
	if (tribute1->agility > 5)
		action.append(" and spends the night up there.");
	else
	{
		action.append(" and falls back to the ground and is knocked unconcious for the night.");
		if (tribute1->luck > 6)
			tribute1->injury++;
	}
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	ListofUsableTributes.remove(true, tribute1->ID);
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
	tribute1 = tribute1->getTribute(roster.size());
	string action = "Tribute1 goes to sleep for the night.";
	action = nameReplacer(action, 1, *tribute1);
	tribute1->usedToday = true;
	ListofUsableTributes.remove(true, tribute1->ID);
	tribute1 = NULL;
	delete tribute1;
	cout << action << "\n";
	return 1;
}

int nightEventSix()
{
	string action = "Tribute1 and Tribute2 tell stories about themselves to each other";
	return 0;
}

int nightEventSeven()
{
	string action = "Tribute1, Tribute2, Tribute3, and Tribute4 sleep in shifts";
	return 0;
}

int nightEventEight()
{
	string action = "Tribute1 tends to his/her1 wounds";
	return 0;
}

int nightEventNine()
{
	string action = "Tribute1 sees a fire, ";
	return 0;
}

int nightEventTen()
{
	string action = "Tribute1 screams for help";
	return 0;
}

int nightEventEleven()
{
	string action = "Tribute1 stays awake all night";
	return 0;
}

int nightEventTwelve()
{
	string action = "Tribute1 passes out from exhaustion";
	return 0;
}

int nightEventThirteen()
{
	string action = "Tribute1 cooks his/her1 food before putting his/her1 fire out";
	return 0;
}

int nightEventFourteen()
{
	string action = "Tribute1 and Tribute2 decide to truce for the night";
	return 0;
}

int nightEventFifteen()
{
	string action = "Tribute1 fends Tribute2, Tribute3, and Tribute4 away from his/her1 fire";
	return 0;
}

int nightEventSixteen()
{
	string action = "Tribute1, Tribute2, and Tribute3 discuss the games and what might happen in the morning";
	return 0;
}

int nightEventSeventeen()
{
	string action = "Tribute1 cries himself/herself1 to sleep";
	return 0;
}

int nightEventEighteen()
{
	string action = "Tribute1 tries to treat his/her1 wounds";
	return 0;
}

int nightEventNineteen()
{
	string action = "Tribute1 and Tribute2 talk about the tributes still alive";
	return 0;
}

int nightEventTwenty()
{
	string action = "Tribute1 is awoken by nightmares";
	return 0;
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
	string action = "Tribute1 looks up at the night sky";
	return 0;
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

vector <func_ptr> nightEvents = { nightEventOne, nightEventTwo };