#include "delivery_manegement.h"
#include "deliveryman.h"
#include "delivery_system.h"
#include <iostream>
#include <string>
using namespace std;

void delivery_manegement::get_deliverman_pay(int  a  , string b  ) // 여기서 해당 배열 이름에 따른 값 저장위치 지정을 여기서 해줘야 if  int a 타입은 금액 , string 타입은 배달원 이름 
{  //  deliveryman b;
	// int n = b.get_deliver_pay_list(&a);  -> 이구문은 랜덤으로 발생을 시켜서 시킨 값을 받아서 넣어 주기만 하면되는거야 
	       deliver_name = b;  // 배달원 이름 넣어주는거 
		// deliverman_pay[a] = n;
		if (b == "홍길동") {
			cout << a << b << endl;
			int array_tim = 0, temp ; //배열 위치 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " 홍길동 " << deliverman_pay[0] << "배달금액 책정 완료 ";
		}
		else if (b == "나경원") {
			cout << a << b << endl;
			int array_tim = 1, temp = 0; //배열 위치 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " 나경원 " << deliverman_pay[array_tim] << "배달금액 책정 완료 ";
		}
		else if (b == "이문세") {
			cout << a << b << endl;
			int array_tim = 2, temp = 0; //배열 위치 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " 이문세 " << deliverman_pay[array_tim] << "배달금액 책정 완료 ";
		}
		else if (b == "김문자") {
			cout << a << b << endl;
			int array_tim = 3, temp = 0; //배열 위치 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " 김문자 " << deliverman_pay[array_tim] << "배달금액 책정 완료 ";
		}
		else if (b == "소공") {
			cout << a << b << endl;
			int array_tim = 4, temp = 0; //배열 위치 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " 소공 " << deliverman_pay[array_tim] << "배달금액 책정 완료 ";
		}
		else if (b == "B만 가자") {
			cout << a << b << endl;
			int array_tim = 5, temp = 0; //배열 위치 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " B만 가자 " << deliverman_pay[array_tim] << "배달금액 책정 완료 ";
		}
		else if (b == "제발 B라도") {
			cout << a << b << endl;
			int array_tim = 6, temp = 0; //배열 위치 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " 제발 B라도 " << deliverman_pay[array_tim] << "배달금액 책정 완료 ";
		}
		else if (b == "김우주") {
			cout << a << b << endl;
			int array_tim = 7, temp = 0; //배열 위치 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " 김우주 " << deliverman_pay[array_tim] << "배달금액 책정 완료 ";
		}
	

}

void delivery_manegement::total_last_deliver_pay() // 최종 배달원 평점 반영한 배달료 차감 최종 처리 함수 
{
	cout << " 최종 처리 함수 도착 " << endl;
	deliveryman hi;
	for (int i = 0; i <= 8; i++) {

		string name = hi.get_deliver_man_list(&i); //  배달원 명단 
		int total_star = delivery_system::get_total_deliver_star(i); // 총합 배달원 별점 

		if (name == "홍길동") {
			int array_tim = 0, temp; //배열 위치 

			if (total_star == 1) {// 별점이 매우 낮음 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // 별점이 낮아서 4천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // 별점이 낮아서 3천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // 별점이 낮아서 2천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // 별점이 4점일 경우 삭감이 없음  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // 별점이 5점인 경우 인센티브 1000원 추가함 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // 별점이 높아서 1천원 보너스  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " 홍길동 " << deliverman_pay[0] << "배달 최종 금액 :  " << deliverman_pay[array_tim];
		}
		else if (name == "나경원") {

			int array_tim = 1, temp = 0; //배열 위치 
			if (total_star == 1) {// 별점이 매우 낮음 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // 별점이 낮아서 4천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // 별점이 낮아서 3천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // 별점이 낮아서 2천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // 별점이 4점일 경우 삭감이 없음  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // 별점이 5점인 경우 인센티브 1000원 추가함 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // 별점이 높아서 1천원 보너스  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " 홍길동 " << deliverman_pay[0] << "배달 최종 금액 :  " << deliverman_pay[array_tim];
		}
		else if (name == "이문세") {

			int array_tim = 2, temp = 0; //배열 위치 
			if (total_star == 1) {// 별점이 매우 낮음 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // 별점이 낮아서 4천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // 별점이 낮아서 3천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // 별점이 낮아서 2천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // 별점이 4점일 경우 삭감이 없음  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // 별점이 5점인 경우 인센티브 1000원 추가함 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // 별점이 높아서 1천원 보너스  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " 홍길동 " << deliverman_pay[0] << "배달 최종 금액 :  " << deliverman_pay[array_tim];
		}
		else if (name == "김문자") {
			int array_tim = 3, temp = 0; //배열 위치 
			if (total_star == 1) {// 별점이 매우 낮음 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // 별점이 낮아서 4천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // 별점이 낮아서 3천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // 별점이 낮아서 2천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // 별점이 4점일 경우 삭감이 없음  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // 별점이 5점인 경우 인센티브 1000원 추가함 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // 별점이 높아서 1천원 보너스  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " 홍길동 " << deliverman_pay[0] << "배달 최종 금액 :  " << deliverman_pay[array_tim];
		}
		else if (name == "소공") {
			int array_tim = 4, temp = 0; //배열 위치 
			if (total_star == 1) {// 별점이 매우 낮음 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // 별점이 낮아서 4천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // 별점이 낮아서 3천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // 별점이 낮아서 2천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // 별점이 4점일 경우 삭감이 없음  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // 별점이 5점인 경우 인센티브 1000원 추가함 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // 별점이 높아서 1천원 보너스  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " 홍길동 " << deliverman_pay[0] << "배달 최종 금액 :  " << deliverman_pay[array_tim];
		}
		else if (name == "B만 가자") {
			int array_tim = 5, temp = 0; //배열 위치 
			if (total_star == 1) {// 별점이 매우 낮음 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // 별점이 낮아서 4천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // 별점이 낮아서 3천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // 별점이 낮아서 2천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // 별점이 4점일 경우 삭감이 없음  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // 별점이 5점인 경우 인센티브 1000원 추가함 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // 별점이 높아서 1천원 보너스  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " 홍길동 " << deliverman_pay[0] << "배달 최종 금액 :  " << deliverman_pay[array_tim];
		}
		else if (name == "제발 B라도") {
			int array_tim = 6, temp = 0; //배열 위치 
			if (total_star == 1) {// 별점이 매우 낮음 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // 별점이 낮아서 4천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // 별점이 낮아서 3천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // 별점이 낮아서 2천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // 별점이 4점일 경우 삭감이 없음  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // 별점이 5점인 경우 인센티브 1000원 추가함 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // 별점이 높아서 1천원 보너스  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " 홍길동 " << deliverman_pay[0] << "배달 최종 금액 :  " << deliverman_pay[array_tim];
		}
		else if (name == "김우주") {
			int array_tim = 7, temp = 0; //배열 위치 
			if (total_star == 1) {// 별점이 매우 낮음 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // 별점이 낮아서 4천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // 별점이 낮아서 3천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // 별점이 2점일 경우 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // 별점이 낮아서 2천원 삭감  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // 별점이 4점일 경우 삭감이 없음  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // 별점이 5점인 경우 인센티브 1000원 추가함 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // 별점이 높아서 1천원 보너스  나중에 - 되서 에러 발생할 가능성도 염두해야할듯 그거에 대한 예외문도 필요할수도 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " 홍길동 " << deliverman_pay[0] << "배달 최종 금액 :  " << deliverman_pay[array_tim];
		}

	}
	for (int te2 = 0; te2 <= 8; te2++) {
		cout << "   " << hi.get_deliver_man_list(&te2)<< "     ";
	}
	cout << endl << endl;
	for (int te2 = 0; te2 <= 8; te2++) {
		cout << "   " << deliverman_pay[te2] << "         ";
	}
	cout << endl<< endl;;
	
}

delivery_manegement::delivery_manegement()
{


}

delivery_manegement::~delivery_manegement()
{
}

int delivery_manegement::get_total_deliver_time()
{
	
	 total_deliver_plus_time =  store_cooktime + 20;
	return total_deliver_plus_time;
}

int delivery_manegement::deliverman_pay[100] = { };
int delivery_manegement::store_cooktime = 0;
int delivery_manegement::total_deliver_plus_time = 0;
string delivery_manegement::deliver_name = "";