#pragma once
#include "foodstore.h"
#ifndef _weston_fooda_
#define _weston_fooda_
using namespace std;

class weston_fooda : public foodstore{
public:
	 weston_fooda();
	~weston_fooda();
	void food_storemenu(); // �ѽ� �Ĵ� ���
	int  food_storelist(int store_num); //�ѽ� �޴� ��� 
	
};

#endif

