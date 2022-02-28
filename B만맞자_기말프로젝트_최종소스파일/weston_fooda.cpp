#include "weston_fooda.h"
#include "chines_fooda.h"
#include  "deliver_console.h"
#include "delivery_system.h"
#include <iostream>
#include <string>
using namespace std;

enum {food_name =3 };
enum{ first_sto=0  , sec_stor=6 , three_stor=10 };
weston_fooda::weston_fooda() {

	
	string foodna[] = { "파스타집 ", " 돈까스집" , "샐러드집 " }; // 음식점 이름 
     // 첫번째 파스타집, 돈까스집, 샐러드집 
	string  foodname[] = { "스테이크" , "파스타", "로제파스타" ,"오일파스타","토마토파스타","크림파스타" ,"등심돈까스","안심돈까스","치즈돈까스","고구마돈까스","야채샐러드","등심샐러드","삼겹살샐러드","김치샐러드" }; // 음식 메뉴 

	  /* 값 복사 구문 */
	for (int j = 0; j < 3; j++) {
		stor_menu[j] = foodna[j];
	}


	for (int i = 0; i < 14; i++) {
		food_list[i] = foodname[i];
	}
	/* 출력 테스트 용 */
	/*for (int i = 0; i < 13; i++) {
		cout << food_list[i] << endl;
	}*/
	
	

}

weston_fooda::~weston_fooda()
{
}

void weston_fooda::food_storemenu() // 양식 음식점 이름 출력 함수 
{
	for (int i = 0; i < food_name; i++) {
		cout << i + 1 << " ." << stor_menu[i] << "  ";
	}
}

int  weston_fooda::food_storelist(int store_num)  // 양식 음식점 메뉴 출력 함수 
{
	if (store_num == 1) { // 한마음식당 처리구문 
		for (int i = first_sto; i < 6; i++) {
			cout << i + 1 << " ." << food_list[i] << "  ";

		}
	}
	else if (store_num == 2) { // 한식이 먹고싶다 처리구문 

		for (int i = sec_stor; i < 10; i++) { // 디스플레이 처리를 위해 -4씩 처리함 
			cout << i - 5 << " ." << food_list[i] << "  ";

		}

	}
	else if (store_num == 3) {// 한식이 좋아 처리 

		for (int i = three_stor; i < 14; i++) { // 디스플레이 처리를 위해 -8씩 처리함 
			cout << i - 9 << " ." << food_list[i] << "  ";

		}

	}

	else cout << "잘못된 값이 store_num 에 입력 되었습니다 " << endl;
	return 0;
}

