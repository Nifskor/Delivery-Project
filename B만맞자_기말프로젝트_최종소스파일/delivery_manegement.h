#pragma once
#include <string>
#include "deliveryman.h"
#ifndef _delivery_manegement_
#define _delivery_manegement_
using namespace std;
class delivery_manegement
{
	static int deliverman_pay[100] ; // 배달원 배달료 저장 변수 
	static string deliver_name; // 배달원 이름 

public:
	static int store_cooktime; // 음식 주문 시간
	static int total_deliver_plus_time; // 추가 주문 소요 시간 합산하여 전체 배달 소요 시간 저장 변수 
	void arr_reset() {
		for (int i = 0; i <= 99; i++) {
			deliverman_pay[i] = 0;
		}
	}
	int get_deliverman_pay(int a) { return deliverman_pay[a]; }  // 페이 처리할때 포인터 관련 값 주고 받고 관련 잘 연산 처리해라 
	void get_deliverman_pay(int a, string b);// 배달원 이름 배달료를 받아서 그걸 기반 
	static void  total_last_deliver_pay(); // 최종 배달료 지급 함수 
	static int get_total_deliver_time(); // 총 전체 배달 소요시간 계산 함수 소요시간 디폴트 +20 분 
	static string get_deliver_name_check() { return deliver_name; }
	delivery_manegement();
	~delivery_manegement();

};

#endif

