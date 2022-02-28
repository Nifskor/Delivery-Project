#pragma once
#include "foodstore.h"
#ifndef _chines_fooda_
#define _chines_fooda_
using namespace std;

class chines_fooda : public foodstore 

{
public:
	chines_fooda();
	~chines_fooda();
	void food_storemenu(); // 한식 식당 출력
	int  food_storelist(int store_num); //한식 메뉴 출력 
};

#endif