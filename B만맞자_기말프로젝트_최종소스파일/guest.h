#pragma once
#include<string>
#include<iostream>
#include <windows.h>

#ifndef _guest_
#define _guest_
using namespace std;

class guest
{
	static string give_food_advice(); // ������ �޴� ��õ �Լ� 
	 static string guest_adress ; // �մ��� �ּ� 

public:
	//int today_food_advice; // ������ �޴� 
	static  string choice_menu; //���Բ��� ���� ���� �޴��� �����ϼ̳���?  
	static  string choice_stroe; // ���Բ��� ���� �������� �����ϼ̳���? 
	static string get_random() {  string a = give_food_advice();  return a; }
	static void set_address(string a) { guest_adress = a;  } // �մ� �ּ� �������°� 
	static string get_address() { return guest_adress; } // �ּ� �޾ƿ��°� 
	guest();
	~guest();
	 //void data_convert(string choice_menu2 , string choice_stroe2); // guest���ִ� ���� �������ִ°ɷν� ������ ��ȯ �뵵 

	 // ���� �״�� ��ü�����ͷ� �Ѱܼ� �װ� ���� �Լ����� ���� �Ѱ��ִ� Ÿ������ �����ϴ°� ������ 




};

#endif
