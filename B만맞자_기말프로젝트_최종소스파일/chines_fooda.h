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
	void food_storemenu(); // �ѽ� �Ĵ� ���
	int  food_storelist(int store_num); //�ѽ� �޴� ��� 
};

#endif