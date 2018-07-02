#include "Header.h"

int nightEventOne()
{
	string action = "Tribute1 starts a fire";
	return 0;
}

int nightEventTwo()
{
	string action = "Tribute1 sets up camp for the night";
	return 0;
}

vector <func_ptr> nightEvents = { nightEventOne, nightEventTwo };