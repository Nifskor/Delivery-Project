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

	
	string foodna[] = { "�Ľ�Ÿ�� ", " �����" , "�������� " }; // ������ �̸� 
     // ù��° �Ľ�Ÿ��, �����, �������� 
	string  foodname[] = { "������ũ" , "�Ľ�Ÿ", "�����Ľ�Ÿ" ,"�����Ľ�Ÿ","�丶���Ľ�Ÿ","ũ���Ľ�Ÿ" ,"��ɵ��","�Ƚɵ��","ġ��","�������","��ä������","��ɻ�����","���������","��ġ������" }; // ���� �޴� 

	  /* �� ���� ���� */
	for (int j = 0; j < 3; j++) {
		stor_menu[j] = foodna[j];
	}


	for (int i = 0; i < 14; i++) {
		food_list[i] = foodname[i];
	}
	/* ��� �׽�Ʈ �� */
	/*for (int i = 0; i < 13; i++) {
		cout << food_list[i] << endl;
	}*/
	
	

}

weston_fooda::~weston_fooda()
{
}

void weston_fooda::food_storemenu() // ��� ������ �̸� ��� �Լ� 
{
	for (int i = 0; i < food_name; i++) {
		cout << i + 1 << " ." << stor_menu[i] << "  ";
	}
}

int  weston_fooda::food_storelist(int store_num)  // ��� ������ �޴� ��� �Լ� 
{
	if (store_num == 1) { // �Ѹ����Ĵ� ó������ 
		for (int i = first_sto; i < 6; i++) {
			cout << i + 1 << " ." << food_list[i] << "  ";

		}
	}
	else if (store_num == 2) { // �ѽ��� �԰�ʹ� ó������ 

		for (int i = sec_stor; i < 10; i++) { // ���÷��� ó���� ���� -4�� ó���� 
			cout << i - 5 << " ." << food_list[i] << "  ";

		}

	}
	else if (store_num == 3) {// �ѽ��� ���� ó�� 

		for (int i = three_stor; i < 14; i++) { // ���÷��� ó���� ���� -8�� ó���� 
			cout << i - 9 << " ." << food_list[i] << "  ";

		}

	}

	else cout << "�߸��� ���� store_num �� �Է� �Ǿ����ϴ� " << endl;
	return 0;
}

