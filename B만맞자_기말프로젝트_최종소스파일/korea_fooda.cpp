#include "korea_fooda.h"
#include  "deliver_console.h"
#include "delivery_system.h"
#include <iostream>
#include <string>
using namespace std;

enum { food_name = 4 };
enum { first_sto = 0, sec_stor = 5, three_stor = 9 ,four =6};
korea_fooda::korea_fooda()
{
	string foodna[10] = { "한마음식당(찌게집)","한식이먹고싶다(볶음집)","한식이좋아","오늘은 한식"}; // 음식점 이름 
	 // 화룡각 , 지성원 , 맛나 짜장면집 , 아이좋아 짜장면 
	string  foodname[30] = { "김치찌개","된장찌개","부대찌개","순두부찌개","청국장","낙지볶음","오징어볶음","제육볶음","돌솥비빔밥" ,"비빔밥","갈비탕","평양냉면","장터국밥","참치회비빔밥",
      "도토리 묵밥"}; // 음식 메뉴 

	  /* 값 복사 구문 */ // 음식점 이름 
	for (int j = 0; j < 5; j++) {
		stor_menu[j] = foodna[j];
	}

	/* 음식 이름 */
	for (int i = 0; i < 14; i++) {
		food_list[i] = foodname[i];
	}
	/* 출력 테스트 용 */
	/*for (int i = 0; i < 13; i++) {
		cout << food_list[i] << endl;
	}*/

}

korea_fooda::~korea_fooda()
{
}

void korea_fooda::food_storemenu() // 한식집 음식점 이름 출력 함수 
{
	for (int i = 0; i < food_name; i++) {  // 4
		cout   <<i+1 << " ."  << stor_menu[i] << "  "  ;
	}
}
 
int  korea_fooda::food_storelist(int store_num)  // 한식집 음식점 메뉴 출력 함수 
{
	if (store_num == 1) { // 한마음식당 처리구문 
		for (int i = first_sto; i < 5; i++) { // 0
			cout << i + 1 << " ." << food_list[i] << "  ";
			
		}
	}
	else if (store_num == 2) { // 한식이 먹고싶다 처리구문 

		for (int i = sec_stor; i < 9; i++) { // 디스플레이 처리를 위해 -4씩 처리함   // 5 
			cout << i - 4 << " ." << food_list[i] << "  ";
			
		}

	}
	else if (store_num == 3) {// 한식이 좋아 처리 

		for (int i = three_stor; i < 14; i++) { // 디스플레이 처리를 위해 -8씩 처리함  //9 
			cout << i - 8 << " ." << food_list[i] << "  ";
			
		}

	}

	else if (store_num == 4) {// 오늘은 한식 처리  

		for (int i = four; i < 10; i++) { // 디스플레이 처리를 위해 -5씩 처리함  // 6
			cout << i - 5 << " ." << food_list[i] << "  ";
			
		}

	}
	else cout << "잘못된 값이 store_num 에 입력 되었습니다 " << endl;
	return 0;
}


