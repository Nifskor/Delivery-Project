#include "delivery_system.h"
#include "korea_fooda.h"
#include "weston_fooda.h"
#include "chines_fooda.h"
#include "deliver_console.h"
#include "guest.h"
#include "delivery_manegement.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

delivery_system::delivery_system() {

	
}
delivery_system::~delivery_system()
{

}



void delivery_system::run() // 시작 메인 실행 처리함수 
{
	deliver_console::admin_menu = 0;
	int menu = 0 ,count =0;
	cout << " 배달 관리 시스템 v 1.0" << endl; 
	Sleep(1000);
	system("cls");
	do  {
		 menu = deliver_console::mainmenu();
		switch (menu) {
		case 1: admin_start(); break;
		case 2: deliver_start(); break;
		case 3: count = 0; break;
		default: cout << " 잘못된 값을 입력하셨습니다" << endl; Sleep(100); system("cls"); count = 1;
		}
		
	} while (count ==1);
	return;
}

void delivery_system::admin_start() // 관리자 페이지는 구현을 배달관리자 클래스에서  
{
	int menu = 0;
	Sleep(1000);
	system("cls");
	 menu = deliver_console::adminpage();
	// cout << menu;
	while (true) {
	//	cout << menu;
		Sleep(1000);
		switch (menu) {
		case 1: deliver_console::admin_deliver_star();  return admin_start();
		case 2: deliver_console::admin_store_star();    return admin_start();
		case 3: deliver_console::admin_deliver_paylist();  return admin_start();
		case 4: deliver_console::admin_deliver_totalsystem(); return admin_start();
		case 5: run(); break;

		default: cout << " 잘못된 값을 입력하셨습니다" << endl; Sleep(1000); system("cls"); menu = 0;  break;
		}
		return; //여기서 리턴하면 반복문 종료 	
	}
}
void delivery_system::deliver_start() // 여기서 손님 음식 어디로 갈찌 분류처리함 
{
	int menu2 = 0;
	 menu2 = deliver_console::food_optiona();
	int store, menu ,count =0;
	Sleep(1000);
	system("cls");
	while (count==0) {
		switch (menu2) {
		case 1:  food_korea(&store, &menu);  count++; return run();
		case 2:  food_weston(&store, &menu);  count++; return run();
		case 3:  food_chines(&store, &menu);   count++; return run();
		default: cout << " 잘못된 값을 입력하셨습니다" << endl; Sleep(1000); system("cls"); menu = 0;  break;
			
		}
		return;
	}
}
void  delivery_system::set_deliver_star(int a) // 총 배달원 / 음식점 평점은 지역변수로도 처리가 가능해   연산 
{
	cout << "함수 호출됨 ";
	string ab = "홍길동";
	if (delivery_manegement::get_deliver_name_check() == "홍길동") {
		cout << "함수 호출됨 ";
		int array_tim = 0, temp=0 , temp2=0; //배열 위치 
		/* 애는 별점 값 대입 */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[0] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0; // 초기 값이 1 근데 이러면 평점에 오류가 발생 0으로 초기화를 해서 다시 1로 저장하겠금 리셋 
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[0] = 1;// 한번 돌았음 
			cout << " 홍길동 " << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			/*         애는 카운트체크                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout << " 홍길동 " << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	else if (delivery_manegement::get_deliver_name_check() == "나경원") {
		int array_tim = 1, temp = 0, temp2 = 0; //배열 위치 
			/* 애는 별점 값 대입 */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[1] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0; // 초기 값이 1 근데 이러면 평점에 오류가 발생 0으로 초기화를 해서 다시 1로 저장하겠금 리셋 
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[1] = 1;// 한번 돌았음 
			cout << "나경원" << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			/*         애는 카운트체크                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout << "나경원" << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	else if (delivery_manegement::get_deliver_name_check() == "이문세") {
		int array_tim = 2, temp = 0, temp2 = 0; //배열 위치 
		/* 애는 별점 값 대입 */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[2] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0; // 초기 값이 1 근데 이러면 평점에 오류가 발생 0으로 초기화를 해서 다시 1로 저장하겠금 리셋 
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[2] = 1;// 한번 돌았음 
			cout << "이문세" << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			/*         애는 카운트체크                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout << "이문세" << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	else if (delivery_manegement::get_deliver_name_check() == "김문자") {
		int array_tim = 3, temp = 0, temp2 = 0; //배열 위치 
		/* 애는 별점 값 대입 */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[3] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0; // 초기 값이 1 근데 이러면 평점에 오류가 발생 0으로 초기화를 해서 다시 1로 저장하겠금 리셋 
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[3] = 1;// 한번 돌았음 
			cout << "김문자" << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			/*         애는 카운트체크                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout << "김문자" << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	else if (delivery_manegement::get_deliver_name_check() == "소공") {
		int array_tim = 4, temp = 0, temp2 = 0; //배열 위치 
		/* 애는 별점 값 대입 */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[4] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0; // 초기 값이 1 근데 이러면 평점에 오류가 발생 0으로 초기화를 해서 다시 1로 저장하겠금 리셋 
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[4] = 1;// 한번 돌았음 
			cout << "소공" << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			/*         애는 카운트체크                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout << "소공" << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	else if (delivery_manegement::get_deliver_name_check() == "B만 가자") {
		int array_tim = 5, temp = 0, temp2 = 0; //배열 위치 
			/* 애는 별점 값 대입 */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[5] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0; // 초기 값이 1 근데 이러면 평점에 오류가 발생 0으로 초기화를 해서 다시 1로 저장하겠금 리셋 
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[5] = 1;// 한번 돌았음 
			cout << "B만 가자" << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			/*         애는 카운트체크                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout <<"B만 가자" << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	else if (delivery_manegement::get_deliver_name_check() == "제발 B라도") {
		int array_tim = 6, temp = 0, temp2 = 0; //배열 위치 
		/* 애는 별점 값 대입 */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[6] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0; // 초기 값이 1 근데 이러면 평점에 오류가 발생 0으로 초기화를 해서 다시 1로 저장하겠금 리셋 
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[6] = 1;// 한번 돌았음 
			cout << "제발 B라도" << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			/*         애는 카운트체크                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout << "제발 B라도" << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	else if (delivery_manegement::get_deliver_name_check() == "김우주") {
		int array_tim = 7, temp = 0, temp2 = 0; //배열 위치 
		/* 애는 별점 값 대입 */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[7] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0; // 초기 값이 1 근데 이러면 평점에 오류가 발생 0으로 초기화를 해서 다시 1로 저장하겠금 리셋 
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[7] = 1;// 한번 돌았음 
			cout << "김우주" << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			/*         애는 카운트체크                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout << "김우주" << get_total_deliver_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	
}


void delivery_system::set_food_star(int a) // 음식점 별점 처리 함수  배열 처리순서 : 한식 -> 양식 -> 중식 순으로 배열 처리 
{
	/* 한식 */
	
	if (guest::choice_stroe  == "한마음식당(찌게집)") {
		int array_tim = 0, temp = 0, temp2 = 0; //배열 위치 
		/* 애는 별점 값 대입 */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[8] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0;
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[8] = 1;// 한번 돌았음 
			cout << endl;
			cout << " 한마음식당(찌게집)" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << " 한마음식당(찌게집)" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	else if (guest::choice_stroe == "한식이먹고싶다(볶음집)") {
		int array_tim = 1, temp = 0, temp2 = 0; //배열 위치 
		/* 애는 별점 값 대입 */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[9] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0;
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[9] = 1;// 한번 돌았음 
			cout << endl;
			cout << "한식이먹고싶다(볶음집)" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << "한식이먹고싶다(볶음집)" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	else if (guest::choice_stroe == "한식이좋아") {
		int array_tim = 2, temp = 0, temp2 = 0; //배열 위치 
		/* 애는 별점 값 대입 */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[10] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0;
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[10] = 1;// 한번 돌았음 
			cout << endl;
			cout << "한식이좋아" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << "한식이좋아" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	else if (guest::choice_stroe == "오늘은 한식") {
		int array_tim = 3, temp = 0, temp2 = 0; //배열 위치 
		/* 애는 별점 값 대입 */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[11] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0;
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[11] = 1;// 한번 돌았음 
			cout << endl;
			cout <<"오늘은 한식" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << "오늘은 한식" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	  /*  양식   */
	else if (guest::choice_stroe == "파스타집 ") {
		int array_tim = 4, temp = 0, temp2 = 0; //배열 위치 
			/* 애는 별점 값 대입 */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[12] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0;
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[12] = 1;// 한번 돌았음 
			cout << endl;
			cout << "파스타집 " << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << "파스타집 " << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	else if (guest::choice_stroe == " 돈까스집") {
		int array_tim = 5, temp = 0, temp2 = 0; //배열 위치 
		/* 애는 별점 값 대입 */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[13] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0;
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[13] = 1;// 한번 돌았음 
			cout << endl;
			cout << " 돈까스집" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << " 돈까스집" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	else if (guest::choice_stroe == "샐러드집 ") {
		int array_tim = 6, temp = 0, temp2 = 0; //배열 위치 
		/* 애는 별점 값 대입 */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[14] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0;
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[14] = 1;// 한번 돌았음 
			cout << endl;
			cout << "샐러드집 " << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << "샐러드집 " << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	/* 중식 */
	else if (guest::choice_stroe == "화룡각 ") {
		int array_tim = 7, temp = 0, temp2 = 0; //배열 위치 
		/* 애는 별점 값 대입 */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         애는 카운트체크                      */
		if (first_run_count[15] == 0) { // 초기 0에러 해결 함수 예외 조항문 
			temp2 = 0;
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[15] = 1;// 한번 돌았음 
			cout << endl;
			cout << "화룡각 " << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << "화룡각 " << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
		}
	}
	else if (guest::choice_stroe == " 지성원") {
	int array_tim = 8, temp = 0, temp2 = 0; //배열 위치 
	/* 애는 별점 값 대입 */
	temp = foodstore_star[array_tim];
	temp = temp + a;
	foodstore_star[array_tim] = temp;
	/*         애는 카운트체크                      */
	if (first_run_count[16] == 0) { // 초기 0에러 해결 함수 예외 조항문 
		temp2 = 0;
		temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
		foodstore_star_count[array_tim] = temp2;
		first_run_count[16] = 1;// 한번 돌았음 
		cout << endl;
		cout << " 지성원" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
	}
	else {
		temp2 = foodstore_star_count[array_tim];
		temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
		foodstore_star_count[array_tim] = temp2;
		cout << endl;
		cout << " 지성원" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
	}
	}
	else if (guest::choice_stroe == "맛나짜장면집") {
	int array_tim = 9, temp = 0, temp2 = 0; //배열 위치 
	/* 애는 별점 값 대입 */
	temp = foodstore_star[array_tim];
	temp = temp + a;
	foodstore_star[array_tim] = temp;
	/*         애는 카운트체크                      */
	if (first_run_count[17] == 0) { // 초기 0에러 해결 함수 예외 조항문 
		temp2 = 0;
		temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
		foodstore_star_count[array_tim] = temp2;
		first_run_count[17] = 1;// 한번 돌았음 
		cout << endl;
		cout << "맛나짜장면집" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
	}
	else {
		temp2 = foodstore_star_count[array_tim];
		temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
		foodstore_star_count[array_tim] = temp2;
		cout << endl;
		cout << "맛나짜장면집" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
	}
	}

	else if (guest::choice_stroe == "아이좋아 짜장면") {
	int array_tim = 10, temp = 0, temp2 = 0; //배열 위치 
	/* 애는 별점 값 대입 */
	temp = foodstore_star[array_tim];
	temp = temp + a;
	foodstore_star[array_tim] = temp;
	/*         애는 카운트체크                      */
	if (first_run_count[18] == 0) { // 초기 0에러 해결 함수 예외 조항문 
		temp2 = 0;
		temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
		foodstore_star_count[array_tim] = temp2;
		first_run_count[18] = 1;// 한번 돌았음 
		cout << endl;
		cout << "아이좋아 짜장면" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
	}
	else {
		temp2 = foodstore_star_count[array_tim];
		temp2 = temp2 + 1; // 한번 돌았기때문에 반복할때마다 1씩 증가 
		foodstore_star_count[array_tim] = temp2;
		cout << endl;
		cout << "아이좋아 짜장면" << get_total_food_star(array_tim) << "별점 책정 완료 " << endl;
	}
	}
}


void delivery_system::food_korea(int *store ,int *menu) // 리턴없이 guest 쪽에 주문한 음식 메뉴 , 음식점 값 넘겨주는거 
{
	
	korea_fooda p;
	 deliver_console::food_korean(store,menu); // 인터페이스 호출  
	 /*    여기서 부터가 구현부 */
	if (*store == 1) { // 음식 메뉴 나 음식점 입력받은걸 해당 guest 에다가 값을 넣어 주는 역활
	//	a.choice_menu = p.food_list[*menu-1];
	//	a.choice_stroe = p.stor_menu[*store-1];
		guest::choice_menu = p.food_list[*menu - 1];
		guest::choice_stroe = p.stor_menu[*store - 1];
		deliver_console::food_order_finish(guest::choice_menu, guest::choice_stroe);
	}
	else if (*store == 2) {
	//	a.choice_menu = p.food_list[*menu+4 ]; // 메뉴에서 들어온값이 1이라고하면 거기서 배열 처리를 위해서 4씩 감소 했는데 여기서 4씩 더해주면 그위치가 나오는거지
	//	a.choice_stroe = p.stor_menu[*store-1];
	//	cout << a.choice_menu;
	//	cout << a.choice_stroe;
		guest::choice_menu = p.food_list[*menu +4];
		guest::choice_stroe = p.stor_menu[*store - 1];
		deliver_console::food_order_finish(guest::choice_menu, guest::choice_stroe);
	}
	else if (*store == 3) {
	//	a.choice_menu = p.food_list[*menu+8 ];
	//	a.choice_stroe = p.stor_menu[*store-1];
	//	cout << a.choice_menu;
	//	cout << a.choice_stroe;
		guest::choice_menu = p.food_list[*menu +8];
		guest::choice_stroe = p.stor_menu[*store - 1];
		deliver_console::food_order_finish(guest::choice_menu, guest::choice_stroe);

	}
	else if (*store == 4) {
		//choice_menu = p.food_list[*menu+5 ];
		//a.choice_stroe = p.stor_menu[*store-1];
	//	cout << a.choice_menu;
	//	cout << a.choice_stroe;
		guest::choice_menu = p.food_list[*menu +5];
		guest::choice_stroe = p.stor_menu[*store - 1];
		deliver_console::food_order_finish(guest::choice_menu, guest::choice_stroe);
	}
	// 여기에 다음으로 이동할 페이지 적어야함 static으로 이동해야함 
	deliver_console::food_store_start();
	
}

void delivery_system::food_weston(int* store, int* menu)
{
	weston_fooda p;
	deliver_console::food_weston(store, menu); // 인터페이스 호출  
	/*    여기서 부터가 구현부 */
	if (*store == 1) { // 음식 메뉴 나 음식점 입력받은걸 해당 guest 에다가 값을 넣어 주는 역활
	//	a.choice_menu = p.food_list[*menu-1];
		//a.choice_stroe = p.stor_menu[*store - 1];
	//	deliver_console::food_order_finish();
		guest::choice_menu = p.food_list[*menu -1];
		guest::choice_stroe = p.stor_menu[*store - 1];
		deliver_console::food_order_finish(guest::choice_menu, guest::choice_stroe);
	}
	else if (*store == 2) {
	//	a.choice_menu = p.food_list[*menu + 5]; // 메뉴에서 들어온값이 1이라고하면 거기서 배열 처리를 위해서 4씩 감소 했는데 여기서 4씩 더해주면 그위치가 나오는거지
	//	a.choice_stroe = p.stor_menu[*store - 1];
	//	deliver_console::food_order_finish();
		guest::choice_menu = p.food_list[*menu +5];
		guest::choice_stroe = p.stor_menu[*store - 1];
		deliver_console::food_order_finish(guest::choice_menu, guest::choice_stroe);
	}
	else if (*store == 3) {
	//	a.choice_menu = p.food_list[*menu + 9];
	//	a.choice_stroe = p.stor_menu[*store - 1];
	//	deliver_console::food_order_finish();
		guest::choice_menu = p.food_list[*menu +9];
		guest::choice_stroe = p.stor_menu[*store - 1];
		deliver_console::food_order_finish(guest::choice_menu, guest::choice_stroe);

	}
	// 여기에 다음으로 이동할 페이지 적어야함 static으로 이동해야함 
	deliver_console::food_store_start();
}

void delivery_system::food_chines(int* store, int* menu) // 중국 옵션 처리 
{
	
	chines_fooda p;
	deliver_console::food_chines(store, menu); // 인터페이스 호출  
	/*    여기서 부터가 구현부 */
	if (*store == 1) { // 음식 메뉴 나 음식점 입력받은걸 해당 guest 에다가 값을 넣어 주는 역활
		int calc_num = 0;
		//  = p.food_list[*menu - 1];
		//a.choice_stroe2 = p.stor_menu[*store - 1];
	//	cout <<a.choice_menu;
		//deliver_console::food_order_finish();
		guest::choice_menu = p.food_list[*menu -1];
		guest::choice_stroe = p.stor_menu[*store - 1];
		deliver_console::food_order_finish(guest::choice_menu, guest::choice_stroe);
	}
	else if (*store == 2) {
		guest::choice_menu = p.food_list[*menu + 11];
		guest::choice_stroe = p.stor_menu[*store - 1];
		deliver_console::food_order_finish(guest::choice_menu, guest::choice_stroe);
	}
	else if (*store == 3) {
		int calc_num = 0;
	//	a.choice_menu = p.food_list[*menu + 5];
	//	a.choice_stroe = p.stor_menu[*store - 1];
	//	deliver_console::food_order_finish();
		guest::choice_menu = p.food_list[*menu + 5];
		guest::choice_stroe = p.stor_menu[*store - 1];
		deliver_console::food_order_finish(guest::choice_menu, guest::choice_stroe);

	}
	else if (*store == 4) {
		int calc_num = 0;
	//	a.choice_menu = p.food_list[*menu + 2];
	//	a.choice_stroe = p.stor_menu[*store - 1];
	//	deliver_console::food_order_finish();
		guest::choice_menu = p.food_list[*menu + 2];
		guest::choice_stroe = p.stor_menu[*store - 1];
		deliver_console::food_order_finish(guest::choice_menu, guest::choice_stroe);
	}
	// 여기에 다음으로 이동할 페이지 적어야함 static으로 이동해야함 
	deliver_console::food_store_start();
}

int delivery_system::dliever_star_count[50] = {}; // 전체 호출 횟수 초기화 
int delivery_system::deliver_star[50] = {}; // 배달원 별점 
int delivery_system::foodstore_star[50] = {};
int delivery_system::foodstore_star_count[50] = {};
int delivery_system::first_run_count[20] = {};

