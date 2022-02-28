#pragma once
#include "guest.h"
#include "delivery_manegement.h"
#include <iostream>
#include <string >
#ifndef _deliveryman_
#define _deliveryman_
using namespace std;
class deliveryman
{
	int *deliver_pay_list = new int[6]{ 1000,2000,3000,4000,5000,6000 }; // 배달료 저장 공간 
	string *deliverman_list = new string[9] { "홍길동" ,"나경원","이문세","김문자","소공","B만 가자","제발 B라도","김우주"}; // 배달원 단순 리스트 
	
public:
	int get_deliver_pay_list(int* a) { int n = deliver_pay_list[*a];  return n; } // 배열 위치 값 그대로 가져가는거 
	string get_deliver_man_list(int *a) { string n = deliverman_list[*a]; return n; }
	int random_deliver_pay();
	string random_deliverman_name();
	int give_deliver_time(); // 배달 소요시간 함수 ) 배달원 
	
	deliveryman();
	~deliveryman();
	
};

#endif
