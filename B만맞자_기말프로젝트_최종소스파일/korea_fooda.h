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
	void food_storemenu(); // �ѽ� �Ĵ� ���
	int  food_storelist(int store_num); //�ѽ� �޴� ��� 
};

#endif
