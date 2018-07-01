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

int bbEventOne() 
{
	string action = "Tribute1 grabs a backpack full of supplies and runs off into the woods";
	return 0;
}

int bbEventTwo()
{
	string action = "Tribute1 grabs a backpack full of supplies and runs off into the woods";
	return 0;
}

int bbEventThree()
{
	string action = "Tribute1 grabs a backpack full of supplies and runs off into the woods";
	return 0;
}

int bbEventFour()
{
	string action = "Tribute1 grabs a backpack full of supplies and runs off into the woods";
	return 0;
}

int bbEventFive()
{
	string action = "Tribute1 grabs a backpack full of supplies and runs off into the woods";
	return 0;
}

int bbEventSix()
{
	string action = "Tribute1 and Tribute2 fight over a backpack of supplies";
	return 0;
}

int bbEventSeven()
{
	string action = "Tribute1 takes a handful of throwing knives";
	return 0;
}

int bbEventEight()
{
	string action = "Tribute1 rips a mace out of Tribute2's hands";
	return 0;
}

int bbEventNine()
{
	string action = "Tribute1 finds a canteen full of water";
	return 0;
}

int bbEventTen()
{
	string action = "Tribute1 hides in the cornucopia for resources once the others leave";
	return 0;
}

int bbEventEleven()
{
	string action = "Tribute1 gathers as much food as he/she1 can";
	return 0;
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
	string action = "Tribute1 grabs a shield leaning against the cornucopia";
	return 0;
}

int bbEventTwentyEight()
{
	string action = "Tribute1 snatches a pair of sais";
	return 0;
}




vector <func_ptr> bbEvents = {bbEventOne};