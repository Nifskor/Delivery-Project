#pragma once
#include<string>
#include<iostream>
#include <windows.h>

#ifndef _guest_
#define _guest_
using namespace std;

class guest
{
	static string give_food_advice(); // 오늘의 메뉴 추천 함수 
	 static string guest_adress ; // 손님의 주소 

public:
	//int today_food_advice; // 오늘의 메뉴 
	static  string choice_menu; //고객님께서 무슨 음식 메뉴를 선택하셨나요?  
	static  string choice_stroe; // 고객님께서 무슨 음식점을 선택하셨나요? 
	static string get_random() {  string a = give_food_advice();  return a; }
	static void set_address(string a) { guest_adress = a;  } // 손님 주소 가져오는거 
	static string get_address() { return guest_adress; } // 주소 받아오는거 
	guest();
	~guest();
	 //void data_convert(string choice_menu2 , string choice_stroe2); // guest에있는 값을 대입해주는걸로써 데이터 교환 용도 

	 // 값을 그대로 객체포인터로 넘겨서 그걸 여기 함수에서 값을 넘겨주는 타입으로 결정하는게 나을듯 




};

#endif
