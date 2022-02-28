#pragma once
#include <string>
#include "korea_fooda.h"
#include "weston_fooda.h"
#include "chines_fooda.h"
#include "delivery_system.h"
#ifndef _deliver_console_
#define _deliver_console_
using namespace std;
class delivery_system;
class deliver_console
{
private :


public:
	static int admin_menu; // 관리자 메뉴 
	static int check_count ; // 주소 두번 입력 못받게 카운트하는거 
	static int  mainmenu(); // 메인옵션 출력함수 
	static int  adminpage(); // 관리자 페이지 
	static int  food_optiona(); //  손님 한식, 양식 ,중식 선택 페이지 
	/*        음식점 및 메뉴                                */
	static void  food_korean(int* store, int* menu); // 한식집에대한 페이지 
	static void  food_weston(int* store, int* menu); // 양식집에대한 페이지
	static void  food_chines(int* store, int* menu); // 중식집에대한 페이지 
	static void  food_order_finish(string menu , string store); // 주문정상완료 출력페이지 
	static int food_store_start(); // 음식점에서 주문들어온거 처리하고 인식하는 구문 
	static void  delivery_man_start(int check); // 배달원 인터페이스 처리 시작 부분 
	static void food_store_cook_finish(); // 음식접에서 조리를 완료 하였는지 확인 
	static void deliver_man_pickup(); // 배달원 픽업 확인 함수 
	static void food_store_pickup(); // 음식점 픽업 확인 함수 
	static void deliver_finish(); // 음식 배달 완료 함수 
	static void food_store_finishcall(); // 음식점 배달 완료 안내 함수 
	static void total_star_finish(); // 최종 마무리 화면 별점 부여 페이지 
	static void admin_deliver_star(); // 관리자 페이지 배달원 평점 출력함수 
	static void admin_store_star(); // 관리자 페이지 음식점 평점 출력 함수 
	static void admin_deliver_paylist(); // 관리자 배달료 종합 출력 함수 
	static void admin_deliver_totalsystem(); // 최종 관리자 지급 페이지 

	deliver_console();
	~deliver_console();




};

#endif