#pragma once
//////////////////////////////////////////////////////////////////
// Hunger Games Simulator Redux									//
// Inspired by http://brantsteele.net/hungergames/reaping.php	//
//																//
// Author: Tyler Tichler										//
// Date of last edit: June 18, 2018								//
//////////////////////////////////////////////////////////////////
// Roadmap									//
//											//
// Current Version: v 0.6					//
//											//
// In no particular order:					//
// 1. Relationships between Tributes	[]	//
// 2. Stats for Tributes				[X]	//
// 3. Arena Events						[]	//
// 4. Dynamic Death Rate				[]	//
// 5. Feast Event						[]	//
// 6. Inventory system for a tribute	[X]	//
// 7. Custom Arenas						[]	//
// 9. Save Rosters/Tributes				[X]	//
// 11. Injury system					[X]	//
// 12. District Names					[]	//
// 13. Quests							[]	//
// 15. GUI								[]	//
//////////////////////////////////////////////

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<limits>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<regex>
#include"LinkedList.h"
using namespace std;

struct Inventory {
	int shovel = 0;
	int bag = 0;
	int bow = 0;
	int arrow = 0;
	int knives = 0;
	int mace = 0;
	int canteen_of_water = 0;
	int food = 0;
	int sword = 0;
	int spear = 0;
	int grenade = 0;
	int first_aid_kit = 0;
	int sickle = 0;
	int rope = 0;
	int molotov = 0;
	int camping_equipment = 0;
	int trident = 0;
	int fishing_gear = 0;
	int shield = 0;
	int sais = 0;
	int hatchet = 0;
	int firewood = 0;
	int slingshot = 0;
	int ammo = 0;
	int pistol = 0;
	int rifle = 0;
	int axe = 0;

};

class Tribute {
public: int ID = 0;
		string name;
		bool alive;
		bool usedToday;
		int kills;
		char gender;
		int district;
		//40 Points to be distributed to the seven stats below
		int strength;
		int perception;
		int endurance;
		int charisma;
		int intelligence;
		int agility;
		int luck;

		Inventory inventory;

		int injury;
		Tribute();
		Tribute* getTribute(int vector_size);
};
//TYPEDEFS
//An array of function pointers is how the simulation handles executing code and simulating the games
typedef int(*func_ptr)();

//GLOBAL VARIABLES
extern vector <Tribute> roster;								//Source.cpp
extern vector <func_ptr> dayEvents;							//DayEvents.cpp
extern int livingTributes;									//Simulation.cpp && DayEvents.cpp
extern int usableTributes;									//Simulation.cpp && DayEvents.cpp
extern LinkedList<int> ListofUsableTributes;				//Simulation.cpp && Tribute.cpp

//SIMULATION FUNCTION
extern void simulation();

//MAIN MENU FUNCTIONS
extern void buildRoster();
extern void viewRoster(bool needsID);
extern void editRoster();