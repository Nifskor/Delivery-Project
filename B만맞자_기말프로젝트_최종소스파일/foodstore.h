#pragma once
#ifndef _foodstore_
#define _foodstore_
using namespace std;

#include<string>

class foodstore
{
	
public:
	foodstore(); //생성자 
	~foodstore();
	  string stor_menu[100]; // 음식점 명단 
	  string food_list[100]; // 음식 명단

};

#endif

