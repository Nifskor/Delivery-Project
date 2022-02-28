#pragma once
#include "foodstore.h"
#ifndef _korea_fooda_
#define _korea_fooda_

using namespace std;

class korea_fooda : public foodstore
{
	
	

public:
	korea_fooda();
	~korea_fooda();
	void food_storemenu(); // 한식 식당 출력
	int  food_storelist(int store_num); //한식 메뉴 출력 
};

#endif
