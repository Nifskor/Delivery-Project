#pragma once
#include <string>
#include <iostream>
#ifndef _delivery_system_
#define _delivery_system_
using namespace std;
class guest;
class delivery_system
{
	static int deliver_star[50]; // 배달원 별점 
	static int foodstore_star[50]; // 음식점 별점  한식 -> 양식 ->중식 
	static int dliever_star_count[50]; // 총 몇번 호출되었는지 확인해서 평점 나누기할때 사용되는 변수 
	static int foodstore_star_count[50]; // 총 몇번 호출되었는지 확인해서 평점 나누기할때 사용되는 변수 
public:
	static int first_run_count[20]; // zero 에러 때문에 카운트 처리 함수 
	void run(); // 실행 함수 
	void food_korea(int* store, int* menu); // 한식 처리 구문 
	void food_weston(int* store, int* menu); // 양식 처리구문 
	void food_chines(int* store, int* menu); // 중식 처리구문 
	void admin_start(); // 관리자 운영 함수 
	void deliver_start(); // 배달 주문 시작 전용함수 
	/*          베달원 별점 처리 함수              */
	static void  set_deliver_star(int a); // 배달원 별점 반환   별점을 받아오는거 
	static int get_total_deliver_star(int a ) {// 별점 평점 구하는 함수 
		int  total = 0, c=0 ,b=0; // total 나눈거 저장 , b는 별점 받아오는거고 , c는 총 해당위치 반복횟수 
		    c   = dliever_star_count[a];
			 b = deliver_star[a];
			// cout << c << b; 
	          total  = b / c; 
			return total;
	} // 전체 배달원 평점 계산해서 반환 시키는애 

	         /*        음식점 별점 처리 함수          */
	static void set_food_star(int a);
	static int get_total_food_star(int a) {
		int  total = 0, c = 0, b = 0; // total 나눈거 저장 , b는 별점 받아오는거고 , c는 총 해당위치 반복횟수 
		c = foodstore_star_count[a];
		b = foodstore_star[a];
		total = b / c;
			// cout << c << b; 
		//cout << b << c; 
		return total;
	}


	void deliver_start_clear() {
		for (int i = 0; i <= 49; i++) {
				deliver_star[i] =0;
				dliever_star_count[i] = 1;
		}
	}
	 void foodstore_star_clear() { 
		for (int i = 0; i <= 49; i++) {
		      foodstore_star[i] = 0;
			  foodstore_star_count[i] = 1;
		}
	}

	delivery_system();
	~delivery_system();
};

#endif
