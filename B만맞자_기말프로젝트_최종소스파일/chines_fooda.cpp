#include "chines_fooda.h"
#include "weston_fooda.h"
#include <iostream>
#include <string>
using namespace std; 

enum { food_name = 4 };
enum { first_sto = 0, sec_stor = 12, three_stor = 6, four = 3 };
chines_fooda::chines_fooda() {

	string foodna[] = { "화룡각 ", " 지성원" , "맛나짜장면집" ,"아이좋아 짜장면" }; // 음식점 이름
	 //화룡각 , 지성원 , 맛나 짜장면집 , 아이좋아 짜장면
	string  foodname[30] = { "짜장면","짬뽕","간짜장","우동","울면","삼선우동","홍합짬뽕","고추짬뽕","삼선울면","해물쟁반짜장","짜장밥", "짬뽕밥","볶음밥","새우볶음밥","삼선볶음밥","잡채밥","잡탕밥","탕수육","찹쌀탕수육","사천탕수육","깐풍기","깐풍육","군만두" }; // 음식 메뉴

	  /* 값 복사 구문 */ // 음식점 이름 
	  for (int j = 0; j < 4; j++) {
		  stor_menu[j] = foodna[j];
	  }

	  /* 음식 이름 */
	  for (int i = 0; i < 24; i++) {
		  food_list[i] = foodname[i];
	  }
	  /* 출력 테스트 용 */
	  /*for (int i = 0; i < 24; i++) {
		  cout << food_list[i] << endl;
	  }*/
	  
	 
}

chines_fooda::~chines_fooda() {}

void chines_fooda::food_storemenu() // 중식집 음식점 이름 출력 함수 
{
	for (int i = 0; i < food_name; i++) {  // 4
		cout << i + 1 << " ." << stor_menu[i] << "  ";
	}
}

int  chines_fooda::food_storelist(int store_num)  // 중식 음식점 메뉴 출력 함수 
{
	if (store_num == 1) { // 한마음식당 처리구문 
		for (int i = first_sto; i < 12; i++) { // 0
			cout << i + 1 << " ." << food_list[i] << "  ";

		}
	}
	else if (store_num == 2) { // 한식이 먹고싶다 처리구문 

		for (int i = sec_stor; i < 18; i++) { // 디스플레이 처리를 위해 -4씩 처리함   // 5 
			cout << i - 11 << " ." << food_list[i] << "  ";

		}

	}
	else if (store_num == 3) {// 한식이 좋아 처리 

		for (int i = three_stor; i < 23; i++) { // 디스플레이 처리를 위해 -8씩 처리함  //9 
			cout << i - 5 << " ." << food_list[i] << "  ";

		}

	}

	else if (store_num == 4) {// 오늘은 한식 처리  

		for (int i = four; i < 18; i++) { // 디스플레이 처리를 위해 -5씩 처리함  // 6
			cout << i - 2 << " ." << food_list[i] << "  ";

		}

	}
	else cout << "잘못된 값이 store_num 에 입력 되었습니다 " << endl;
	return 0;
}