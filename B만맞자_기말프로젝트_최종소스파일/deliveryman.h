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
	int *deliver_pay_list = new int[6]{ 1000,2000,3000,4000,5000,6000 }; // ��޷� ���� ���� 
	string *deliverman_list = new string[9] { "ȫ�浿" ,"�����","�̹���","�蹮��","�Ұ�","B�� ����","���� B��","�����"}; // ��޿� �ܼ� ����Ʈ 
	
public:
	int get_deliver_pay_list(int* a) { int n = deliver_pay_list[*a];  return n; } // �迭 ��ġ �� �״�� �������°� 
	string get_deliver_man_list(int *a) { string n = deliverman_list[*a]; return n; }
	int random_deliver_pay();
	string random_deliverman_name();
	int give_deliver_time(); // ��� �ҿ�ð� �Լ� ) ��޿� 
	
	deliveryman();
	~deliveryman();
	
};

#endif
