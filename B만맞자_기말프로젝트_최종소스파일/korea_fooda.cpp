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
	string foodna[10] = { "�Ѹ����Ĵ�(�����)","�ѽ��̸԰�ʹ�(������)","�ѽ�������","������ �ѽ�"}; // ������ �̸� 
	 // ȭ�氢 , ������ , ���� ¥����� , �������� ¥��� 
	string  foodname[30] = { "��ġ�","�����","�δ��","���κ��","û����","��������","��¡���","��������","���ܺ����" ,"�����","������","���ø�","���ͱ���","��ġȸ�����",
      "���丮 ����"}; // ���� �޴� 

	  /* �� ���� ���� */ // ������ �̸� 
	for (int j = 0; j < 5; j++) {
		stor_menu[j] = foodna[j];
	}

	/* ���� �̸� */
	for (int i = 0; i < 14; i++) {
		food_list[i] = foodname[i];
	}
	/* ��� �׽�Ʈ �� */
	/*for (int i = 0; i < 13; i++) {
		cout << food_list[i] << endl;
	}*/

}

korea_fooda::~korea_fooda()
{
}

void korea_fooda::food_storemenu() // �ѽ��� ������ �̸� ��� �Լ� 
{
	for (int i = 0; i < food_name; i++) {  // 4
		cout   <<i+1 << " ."  << stor_menu[i] << "  "  ;
	}
}
 
int  korea_fooda::food_storelist(int store_num)  // �ѽ��� ������ �޴� ��� �Լ� 
{
	if (store_num == 1) { // �Ѹ����Ĵ� ó������ 
		for (int i = first_sto; i < 5; i++) { // 0
			cout << i + 1 << " ." << food_list[i] << "  ";
			
		}
	}
	else if (store_num == 2) { // �ѽ��� �԰�ʹ� ó������ 

		for (int i = sec_stor; i < 9; i++) { // ���÷��� ó���� ���� -4�� ó����   // 5 
			cout << i - 4 << " ." << food_list[i] << "  ";
			
		}

	}
	else if (store_num == 3) {// �ѽ��� ���� ó�� 

		for (int i = three_stor; i < 14; i++) { // ���÷��� ó���� ���� -8�� ó����  //9 
			cout << i - 8 << " ." << food_list[i] << "  ";
			
		}

	}

	else if (store_num == 4) {// ������ �ѽ� ó��  

		for (int i = four; i < 10; i++) { // ���÷��� ó���� ���� -5�� ó����  // 6
			cout << i - 5 << " ." << food_list[i] << "  ";
			
		}

	}
	else cout << "�߸��� ���� store_num �� �Է� �Ǿ����ϴ� " << endl;
	return 0;
}


