#include "guest.h"
#include "weston_fooda.h"
#include "korea_fooda.h"
#include "chines_fooda.h"
#include "delivery_system.h"
#include "deliver_console.h"
#include "delivery_system.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;


string guest::give_food_advice() // 오늘의 메뉴 추천 함수 
{
	// korea =0 , weston =1, chines =2 ;
	string name;
	srand(time(NULL));
	int randTemp = NULL ;
	randTemp = rand() % 3;
	if (randTemp == 0) {
		korea_fooda a;
		int randse = NULL;
		randse = rand() % 13;
		name  = a.food_list[randse];
	}
	else if(randTemp == 1) {
		weston_fooda a;
		int randse = NULL;
		randse = rand() % 13;
		name = a.food_list[randse];
	}
	else if (randTemp == 2) {
		chines_fooda a;
		int randse = NULL;
		randse = rand() % 22;
		name = a.food_list[randse];
	}
	
	return name;
}

string guest::choice_menu = " ";
string guest::choice_stroe = " ";
string guest::guest_adress = " ";

guest::guest() {
	
	//string choice_menu,  choice_store;
	//data_convert(choice_menu, choice_store);
//	cout << choice_menu << choice_stroe << endl;

}


guest::~guest()
{
}


/*void guest::data_convert(string  choice_menu2, string choice_stroe2)
{
	choice_menu = choice_menu2;
	choice_stroe = choice_stroe2;
	this->choice_menu = choice_menu;
	cout << choice_menu << choice_stroe << endl;
	cout << this->choice_menu << endl;
}
*/

