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



void delivery_system::run() // ���� ���� ���� ó���Լ� 
{
	deliver_console::admin_menu = 0;
	int menu = 0 ,count =0;
	cout << " ��� ���� �ý��� v 1.0" << endl; 
	Sleep(1000);
	system("cls");
	do  {
		 menu = deliver_console::mainmenu();
		switch (menu) {
		case 1: admin_start(); break;
		case 2: deliver_start(); break;
		case 3: count = 0; break;
		default: cout << " �߸��� ���� �Է��ϼ̽��ϴ�" << endl; Sleep(100); system("cls"); count = 1;
		}
		
	} while (count ==1);
	return;
}

void delivery_system::admin_start() // ������ �������� ������ ��ް����� Ŭ��������  
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

		default: cout << " �߸��� ���� �Է��ϼ̽��ϴ�" << endl; Sleep(1000); system("cls"); menu = 0;  break;
		}
		return; //���⼭ �����ϸ� �ݺ��� ���� 	
	}
}
void delivery_system::deliver_start() // ���⼭ �մ� ���� ���� ���� �з�ó���� 
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
		default: cout << " �߸��� ���� �Է��ϼ̽��ϴ�" << endl; Sleep(1000); system("cls"); menu = 0;  break;
			
		}
		return;
	}
}
void  delivery_system::set_deliver_star(int a) // �� ��޿� / ������ ������ ���������ε� ó���� ������   ���� 
{
	cout << "�Լ� ȣ��� ";
	string ab = "ȫ�浿";
	if (delivery_manegement::get_deliver_name_check() == "ȫ�浿") {
		cout << "�Լ� ȣ��� ";
		int array_tim = 0, temp=0 , temp2=0; //�迭 ��ġ 
		/* �ִ� ���� �� ���� */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[0] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0; // �ʱ� ���� 1 �ٵ� �̷��� ������ ������ �߻� 0���� �ʱ�ȭ�� �ؼ� �ٽ� 1�� �����ϰڱ� ���� 
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[0] = 1;// �ѹ� ������ 
			cout << " ȫ�浿 " << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			/*         �ִ� ī��Ʈüũ                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout << " ȫ�浿 " << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	else if (delivery_manegement::get_deliver_name_check() == "�����") {
		int array_tim = 1, temp = 0, temp2 = 0; //�迭 ��ġ 
			/* �ִ� ���� �� ���� */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[1] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0; // �ʱ� ���� 1 �ٵ� �̷��� ������ ������ �߻� 0���� �ʱ�ȭ�� �ؼ� �ٽ� 1�� �����ϰڱ� ���� 
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[1] = 1;// �ѹ� ������ 
			cout << "�����" << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			/*         �ִ� ī��Ʈüũ                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout << "�����" << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	else if (delivery_manegement::get_deliver_name_check() == "�̹���") {
		int array_tim = 2, temp = 0, temp2 = 0; //�迭 ��ġ 
		/* �ִ� ���� �� ���� */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[2] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0; // �ʱ� ���� 1 �ٵ� �̷��� ������ ������ �߻� 0���� �ʱ�ȭ�� �ؼ� �ٽ� 1�� �����ϰڱ� ���� 
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[2] = 1;// �ѹ� ������ 
			cout << "�̹���" << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			/*         �ִ� ī��Ʈüũ                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout << "�̹���" << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	else if (delivery_manegement::get_deliver_name_check() == "�蹮��") {
		int array_tim = 3, temp = 0, temp2 = 0; //�迭 ��ġ 
		/* �ִ� ���� �� ���� */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[3] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0; // �ʱ� ���� 1 �ٵ� �̷��� ������ ������ �߻� 0���� �ʱ�ȭ�� �ؼ� �ٽ� 1�� �����ϰڱ� ���� 
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[3] = 1;// �ѹ� ������ 
			cout << "�蹮��" << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			/*         �ִ� ī��Ʈüũ                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout << "�蹮��" << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	else if (delivery_manegement::get_deliver_name_check() == "�Ұ�") {
		int array_tim = 4, temp = 0, temp2 = 0; //�迭 ��ġ 
		/* �ִ� ���� �� ���� */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[4] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0; // �ʱ� ���� 1 �ٵ� �̷��� ������ ������ �߻� 0���� �ʱ�ȭ�� �ؼ� �ٽ� 1�� �����ϰڱ� ���� 
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[4] = 1;// �ѹ� ������ 
			cout << "�Ұ�" << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			/*         �ִ� ī��Ʈüũ                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout << "�Ұ�" << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	else if (delivery_manegement::get_deliver_name_check() == "B�� ����") {
		int array_tim = 5, temp = 0, temp2 = 0; //�迭 ��ġ 
			/* �ִ� ���� �� ���� */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[5] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0; // �ʱ� ���� 1 �ٵ� �̷��� ������ ������ �߻� 0���� �ʱ�ȭ�� �ؼ� �ٽ� 1�� �����ϰڱ� ���� 
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[5] = 1;// �ѹ� ������ 
			cout << "B�� ����" << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			/*         �ִ� ī��Ʈüũ                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout <<"B�� ����" << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	else if (delivery_manegement::get_deliver_name_check() == "���� B��") {
		int array_tim = 6, temp = 0, temp2 = 0; //�迭 ��ġ 
		/* �ִ� ���� �� ���� */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[6] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0; // �ʱ� ���� 1 �ٵ� �̷��� ������ ������ �߻� 0���� �ʱ�ȭ�� �ؼ� �ٽ� 1�� �����ϰڱ� ���� 
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[6] = 1;// �ѹ� ������ 
			cout << "���� B��" << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			/*         �ִ� ī��Ʈüũ                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout << "���� B��" << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	else if (delivery_manegement::get_deliver_name_check() == "�����") {
		int array_tim = 7, temp = 0, temp2 = 0; //�迭 ��ġ 
		/* �ִ� ���� �� ���� */
		temp = deliver_star[array_tim];
		temp = temp + a;
		deliver_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[7] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0; // �ʱ� ���� 1 �ٵ� �̷��� ������ ������ �߻� 0���� �ʱ�ȭ�� �ؼ� �ٽ� 1�� �����ϰڱ� ���� 
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			first_run_count[7] = 1;// �ѹ� ������ 
			cout << "�����" << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			/*         �ִ� ī��Ʈüũ                      */
			temp2 = dliever_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			dliever_star_count[array_tim] = temp2;
			cout << endl;
			cout << "�����" << get_total_deliver_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	
}


void delivery_system::set_food_star(int a) // ������ ���� ó�� �Լ�  �迭 ó������ : �ѽ� -> ��� -> �߽� ������ �迭 ó�� 
{
	/* �ѽ� */
	
	if (guest::choice_stroe  == "�Ѹ����Ĵ�(�����)") {
		int array_tim = 0, temp = 0, temp2 = 0; //�迭 ��ġ 
		/* �ִ� ���� �� ���� */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[8] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0;
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[8] = 1;// �ѹ� ������ 
			cout << endl;
			cout << " �Ѹ����Ĵ�(�����)" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << " �Ѹ����Ĵ�(�����)" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	else if (guest::choice_stroe == "�ѽ��̸԰�ʹ�(������)") {
		int array_tim = 1, temp = 0, temp2 = 0; //�迭 ��ġ 
		/* �ִ� ���� �� ���� */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[9] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0;
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[9] = 1;// �ѹ� ������ 
			cout << endl;
			cout << "�ѽ��̸԰�ʹ�(������)" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << "�ѽ��̸԰�ʹ�(������)" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	else if (guest::choice_stroe == "�ѽ�������") {
		int array_tim = 2, temp = 0, temp2 = 0; //�迭 ��ġ 
		/* �ִ� ���� �� ���� */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[10] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0;
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[10] = 1;// �ѹ� ������ 
			cout << endl;
			cout << "�ѽ�������" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << "�ѽ�������" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	else if (guest::choice_stroe == "������ �ѽ�") {
		int array_tim = 3, temp = 0, temp2 = 0; //�迭 ��ġ 
		/* �ִ� ���� �� ���� */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[11] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0;
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[11] = 1;// �ѹ� ������ 
			cout << endl;
			cout <<"������ �ѽ�" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << "������ �ѽ�" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	  /*  ���   */
	else if (guest::choice_stroe == "�Ľ�Ÿ�� ") {
		int array_tim = 4, temp = 0, temp2 = 0; //�迭 ��ġ 
			/* �ִ� ���� �� ���� */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[12] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0;
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[12] = 1;// �ѹ� ������ 
			cout << endl;
			cout << "�Ľ�Ÿ�� " << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << "�Ľ�Ÿ�� " << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	else if (guest::choice_stroe == " �����") {
		int array_tim = 5, temp = 0, temp2 = 0; //�迭 ��ġ 
		/* �ִ� ���� �� ���� */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[13] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0;
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[13] = 1;// �ѹ� ������ 
			cout << endl;
			cout << " �����" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << " �����" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	else if (guest::choice_stroe == "�������� ") {
		int array_tim = 6, temp = 0, temp2 = 0; //�迭 ��ġ 
		/* �ִ� ���� �� ���� */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[14] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0;
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[14] = 1;// �ѹ� ������ 
			cout << endl;
			cout << "�������� " << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << "�������� " << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	/* �߽� */
	else if (guest::choice_stroe == "ȭ�氢 ") {
		int array_tim = 7, temp = 0, temp2 = 0; //�迭 ��ġ 
		/* �ִ� ���� �� ���� */
		temp = foodstore_star[array_tim];
		temp = temp + a;
		foodstore_star[array_tim] = temp;
		/*         �ִ� ī��Ʈüũ                      */
		if (first_run_count[15] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
			temp2 = 0;
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			first_run_count[15] = 1;// �ѹ� ������ 
			cout << endl;
			cout << "ȭ�氢 " << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
		else {
			temp2 = foodstore_star_count[array_tim];
			temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
			foodstore_star_count[array_tim] = temp2;
			cout << endl;
			cout << "ȭ�氢 " << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
		}
	}
	else if (guest::choice_stroe == " ������") {
	int array_tim = 8, temp = 0, temp2 = 0; //�迭 ��ġ 
	/* �ִ� ���� �� ���� */
	temp = foodstore_star[array_tim];
	temp = temp + a;
	foodstore_star[array_tim] = temp;
	/*         �ִ� ī��Ʈüũ                      */
	if (first_run_count[16] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
		temp2 = 0;
		temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
		foodstore_star_count[array_tim] = temp2;
		first_run_count[16] = 1;// �ѹ� ������ 
		cout << endl;
		cout << " ������" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
	}
	else {
		temp2 = foodstore_star_count[array_tim];
		temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
		foodstore_star_count[array_tim] = temp2;
		cout << endl;
		cout << " ������" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
	}
	}
	else if (guest::choice_stroe == "����¥�����") {
	int array_tim = 9, temp = 0, temp2 = 0; //�迭 ��ġ 
	/* �ִ� ���� �� ���� */
	temp = foodstore_star[array_tim];
	temp = temp + a;
	foodstore_star[array_tim] = temp;
	/*         �ִ� ī��Ʈüũ                      */
	if (first_run_count[17] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
		temp2 = 0;
		temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
		foodstore_star_count[array_tim] = temp2;
		first_run_count[17] = 1;// �ѹ� ������ 
		cout << endl;
		cout << "����¥�����" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
	}
	else {
		temp2 = foodstore_star_count[array_tim];
		temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
		foodstore_star_count[array_tim] = temp2;
		cout << endl;
		cout << "����¥�����" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
	}
	}

	else if (guest::choice_stroe == "�������� ¥���") {
	int array_tim = 10, temp = 0, temp2 = 0; //�迭 ��ġ 
	/* �ִ� ���� �� ���� */
	temp = foodstore_star[array_tim];
	temp = temp + a;
	foodstore_star[array_tim] = temp;
	/*         �ִ� ī��Ʈüũ                      */
	if (first_run_count[18] == 0) { // �ʱ� 0���� �ذ� �Լ� ���� ���׹� 
		temp2 = 0;
		temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
		foodstore_star_count[array_tim] = temp2;
		first_run_count[18] = 1;// �ѹ� ������ 
		cout << endl;
		cout << "�������� ¥���" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
	}
	else {
		temp2 = foodstore_star_count[array_tim];
		temp2 = temp2 + 1; // �ѹ� ���ұ⶧���� �ݺ��Ҷ����� 1�� ���� 
		foodstore_star_count[array_tim] = temp2;
		cout << endl;
		cout << "�������� ¥���" << get_total_food_star(array_tim) << "���� å�� �Ϸ� " << endl;
	}
	}
}


void delivery_system::food_korea(int *store ,int *menu) // ���Ͼ��� guest �ʿ� �ֹ��� ���� �޴� , ������ �� �Ѱ��ִ°� 
{
	
	korea_fooda p;
	 deliver_console::food_korean(store,menu); // �������̽� ȣ��  
	 /*    ���⼭ ���Ͱ� ������ */
	if (*store == 1) { // ���� �޴� �� ������ �Է¹����� �ش� guest ���ٰ� ���� �־� �ִ� ��Ȱ
	//	a.choice_menu = p.food_list[*menu-1];
	//	a.choice_stroe = p.stor_menu[*store-1];
		guest::choice_menu = p.food_list[*menu - 1];
		guest::choice_stroe = p.stor_menu[*store - 1];
		deliver_console::food_order_finish(guest::choice_menu, guest::choice_stroe);
	}
	else if (*store == 2) {
	//	a.choice_menu = p.food_list[*menu+4 ]; // �޴����� ���°��� 1�̶���ϸ� �ű⼭ �迭 ó���� ���ؼ� 4�� ���� �ߴµ� ���⼭ 4�� �����ָ� ����ġ�� �����°���
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
	// ���⿡ �������� �̵��� ������ ������� static���� �̵��ؾ��� 
	deliver_console::food_store_start();
	
}

void delivery_system::food_weston(int* store, int* menu)
{
	weston_fooda p;
	deliver_console::food_weston(store, menu); // �������̽� ȣ��  
	/*    ���⼭ ���Ͱ� ������ */
	if (*store == 1) { // ���� �޴� �� ������ �Է¹����� �ش� guest ���ٰ� ���� �־� �ִ� ��Ȱ
	//	a.choice_menu = p.food_list[*menu-1];
		//a.choice_stroe = p.stor_menu[*store - 1];
	//	deliver_console::food_order_finish();
		guest::choice_menu = p.food_list[*menu -1];
		guest::choice_stroe = p.stor_menu[*store - 1];
		deliver_console::food_order_finish(guest::choice_menu, guest::choice_stroe);
	}
	else if (*store == 2) {
	//	a.choice_menu = p.food_list[*menu + 5]; // �޴����� ���°��� 1�̶���ϸ� �ű⼭ �迭 ó���� ���ؼ� 4�� ���� �ߴµ� ���⼭ 4�� �����ָ� ����ġ�� �����°���
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
	// ���⿡ �������� �̵��� ������ ������� static���� �̵��ؾ��� 
	deliver_console::food_store_start();
}

void delivery_system::food_chines(int* store, int* menu) // �߱� �ɼ� ó�� 
{
	
	chines_fooda p;
	deliver_console::food_chines(store, menu); // �������̽� ȣ��  
	/*    ���⼭ ���Ͱ� ������ */
	if (*store == 1) { // ���� �޴� �� ������ �Է¹����� �ش� guest ���ٰ� ���� �־� �ִ� ��Ȱ
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
	// ���⿡ �������� �̵��� ������ ������� static���� �̵��ؾ��� 
	deliver_console::food_store_start();
}

int delivery_system::dliever_star_count[50] = {}; // ��ü ȣ�� Ƚ�� �ʱ�ȭ 
int delivery_system::deliver_star[50] = {}; // ��޿� ���� 
int delivery_system::foodstore_star[50] = {};
int delivery_system::foodstore_star_count[50] = {};
int delivery_system::first_run_count[20] = {};

