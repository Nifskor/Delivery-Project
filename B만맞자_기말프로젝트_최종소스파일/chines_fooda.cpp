#include "chines_fooda.h"
#include "weston_fooda.h"
#include <iostream>
#include <string>
using namespace std; 

enum { food_name = 4 };
enum { first_sto = 0, sec_stor = 12, three_stor = 6, four = 3 };
chines_fooda::chines_fooda() {

	string foodna[] = { "ȭ�氢 ", " ������" , "����¥�����" ,"�������� ¥���" }; // ������ �̸�
	 //ȭ�氢 , ������ , ���� ¥����� , �������� ¥���
	string  foodname[30] = { "¥���","«��","��¥��","�쵿","���","�Ｑ�쵿","ȫ��«��","����«��","�Ｑ���","�ع����¥��","¥���", "«�͹�","������","���캺����","�Ｑ������","��ä��","������","������","����������","��õ������","��ǳ��","��ǳ��","������" }; // ���� �޴�

	  /* �� ���� ���� */ // ������ �̸� 
	  for (int j = 0; j < 4; j++) {
		  stor_menu[j] = foodna[j];
	  }

	  /* ���� �̸� */
	  for (int i = 0; i < 24; i++) {
		  food_list[i] = foodname[i];
	  }
	  /* ��� �׽�Ʈ �� */
	  /*for (int i = 0; i < 24; i++) {
		  cout << food_list[i] << endl;
	  }*/
	  
	 
}

chines_fooda::~chines_fooda() {}

void chines_fooda::food_storemenu() // �߽��� ������ �̸� ��� �Լ� 
{
	for (int i = 0; i < food_name; i++) {  // 4
		cout << i + 1 << " ." << stor_menu[i] << "  ";
	}
}

int  chines_fooda::food_storelist(int store_num)  // �߽� ������ �޴� ��� �Լ� 
{
	if (store_num == 1) { // �Ѹ����Ĵ� ó������ 
		for (int i = first_sto; i < 12; i++) { // 0
			cout << i + 1 << " ." << food_list[i] << "  ";

		}
	}
	else if (store_num == 2) { // �ѽ��� �԰�ʹ� ó������ 

		for (int i = sec_stor; i < 18; i++) { // ���÷��� ó���� ���� -4�� ó����   // 5 
			cout << i - 11 << " ." << food_list[i] << "  ";

		}

	}
	else if (store_num == 3) {// �ѽ��� ���� ó�� 

		for (int i = three_stor; i < 23; i++) { // ���÷��� ó���� ���� -8�� ó����  //9 
			cout << i - 5 << " ." << food_list[i] << "  ";

		}

	}

	else if (store_num == 4) {// ������ �ѽ� ó��  

		for (int i = four; i < 18; i++) { // ���÷��� ó���� ���� -5�� ó����  // 6
			cout << i - 2 << " ." << food_list[i] << "  ";

		}

	}
	else cout << "�߸��� ���� store_num �� �Է� �Ǿ����ϴ� " << endl;
	return 0;
}