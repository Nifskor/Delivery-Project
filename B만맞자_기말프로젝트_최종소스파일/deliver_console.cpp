#include "korea_fooda.h"
#include "weston_fooda.h"
#include "chines_fooda.h"
#include "deliver_console.h"
#include "delivery_system.h"
#include "guest.h"
#include "deliveryman.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
//using namespace std;

deliver_console::deliver_console()
{

}

deliver_console::~deliver_console()
{
}


/* int deliver_console::run()
{
	 int menu = mainmenu(); // ���� ���� ���� �޴� ���� 
	switch (menu)
	{
	case ADMIN : 
	default:
		break;
	}


	return 0;
}/* -> ��� �ý��� */

int deliver_console::mainmenu()
{
	int menu =0;
	std::cout << "�ʱ� ȭ������ �̵��� ..." << endl;
	Sleep(1000);
	system("cls");
	std::cout << " ==================================" << endl;
	std::cout << " * ��� �����ý����� ���� �մϴ� * " << endl; 
	std::cout << " �����ϰ��� �ϴ� �ɼ��� �������ּ��� " << endl;
	std::cout << " ==================================" << endl;
	std::cout << "1 .������ 2. ��� �ֹ� ���� 3. ���α׷� ���� " << endl;
	std::cout << endl << " �޴��Է� : ";
	cin >> menu;
	return menu;
}

int deliver_console::adminpage()
{
	int menu = 0;
	system("cls");
	while (true) {
		//std::cout << menu;
	//	std::cout << admin_menu2 << endl; 
		if (admin_menu == 0) {
			std::cout << " * ������ �������� ���Ű��� ȯ���մϴ�! " << endl;
			std::cout << " ������ ��� ��ȣ�� �Է����ּ��� ! " << endl;
			std::cout << endl << " �޴��Է� : ";
			cin >> admin_menu;
		}
		if (admin_menu == 1234) {
			std::cout << "������ �������� �α��� �ϼ̽��ϴ�! " << endl;
			Sleep(100);
			system("cls");
			//std::cout << menu << endl;
			std::cout << " ������ ���������� ����Ͻ� �׸��� �����ϼ���! " << endl;
			std::cout << " ====================================================================" << endl;
			std::cout << " 1. ��޿� ���� 2. ������ ���� 3. ��޿� ��޷� ��Ȳ 4. ��޷� ���� 5. ������������ ������ " << endl;
			std::cout << " =======================================================================" << endl;
			std::cout << endl << " �޴��Է� : ";
			cin >> menu;
			std::cout << menu;
			if (menu < 0) {
				std::cout << " ���� �߸��Է��ϼ̽��ϴ�!  ���� �ȹٷ� �Է����ּ���! ";
				system("cls");
				break;
			}
		//	std::cout << menu << endl;
			return menu;
		}
		else {
			std::cout << "��й�ȣ�� �߸���1���ϼ̽��ϴ� �ٽ� �Է����ּ��� " << endl;
			Sleep(1000);
			system("cls");
			admin_menu = 0;
			adminpage();
		}

		
	}
}

int deliver_console::food_optiona()
{
	int menu=0 , count =0; 
	 string address;
	system("cls");
	std::cout << " * ��� �ֹ��� ���Ű��� ȯ���մϴ� * " << endl;
	std::cout << " =======================================" << endl;
	std::cout << " ������ " << guest::get_random() << "(����) �޴��� ��õ�մϴ� " << endl;
	std::cout << "  ��ð� �������� ������ ���� ���ּ��� " << endl;
	std::cout << "  1. �ѽ�  2. ���  3. �߽� " << endl;
	std::cout << " ========================================" << endl;
	std::cout << endl << " �޴��Է� : ";
	cin >> menu;
	if (menu < 0) { std::cout << " �߸��� ���� �Է��ϼ̽��ϴ�" << endl; Sleep(100); system("cls"); menu = 0; return 0; }
	if(menu >=4) { std::cout << " �߸��� ���� �Է��ϼ̽��ϴ�" << endl; Sleep(100); system("cls"); menu = 0; return 0; }
	if (check_count == 0) {
		std::cout << " ======================================= " << endl;
		std::cout << " ��� ������ �ּҸ� �Է����ּ��� ! " << endl;
		std::cout << " ======================================= " << endl;
		std::cout << " �ּ��Է� : "; cin.ignore();  getline(cin, address);  std::cout << endl;
		check_count++;
		guest::set_address(address);

	}
	return menu;
}

int deliver_console::check_count = 0; // ���� ���� ��� �ּ� 1���� ���� �Է� �ϵ��� �ϴ� ���� ������ 
void deliver_console::food_korean(int *store , int *menu)
{
	*store = 0;  *menu = 0;
	korea_fooda p;
	guest a;
	system("cls");
	std::cout << " * �ѽ� ���� ���Ű��� ȯ���մϴ�! " << endl;
	std::cout << " ========================================" << endl;
	std::cout << " ������ �ѽ� �Ĵ��� �������ּ���! " << endl; 	std::cout << endl;
	p.food_storemenu(); std::cout << endl; 
	std::cout << endl << " �޴��Է� : ";
	cin >> *store;
		if (*store < 0) { std::cout << " �߸��� ���� �Է��ϼ̽��ϴ�" << endl; Sleep(100); system("cls"); menu = 0; return; }
		if (*store > 18) { std::cout << " �߸��� ���� �Է��ϼ̽��ϴ�" << endl; Sleep(100); system("cls"); menu = 0; return; }
	std::cout << endl; 
	std::cout << p.stor_menu[*store -1]<<" ���� �޴��� �������ּ��� ! " << endl; std::cout << endl;
	p.food_storelist(*store); std::cout << endl;
	std::cout << endl << " �޴��Է� : ";
	cin >> *menu;
	if (*menu < 0) { std::cout << " �߸��� ���� �Է��ϼ̽��ϴ�" << endl; Sleep(100); system("cls"); menu = 0; return; }
	if (*menu > 18) { std::cout << " �߸��� ���� �Է��ϼ̽��ϴ�" << endl; Sleep(100); system("cls"); menu = 0; return; }
	std::cout << endl;
	
}

void  deliver_console::food_weston(int* store, int* menu)
{
	*store = 0;  *menu = 0;
	weston_fooda p;
	guest a;
	system("cls");
	std::cout << " * ��� ���� ���Ű��� ȯ���մϴ�! " << endl;
	std::cout << " ========================================" << endl;
	std::cout << " ������ ��� �Ĵ��� �������ּ���! " << endl; 	std::cout << endl;
	p.food_storemenu(); std::cout << endl;
	std::cout << endl << " �޴��Է� : ";
	cin >> *store;
	if (*store < 0) { std::cout << " ���� �߸��Է��ϼ̽��ϴ�!  ���� �ȹٷ� �Է����ּ���! "; return ; }
	if (*store > 18) { std::cout << " �߸��� ���� �Է��ϼ̽��ϴ�" << endl; Sleep(100); system("cls"); menu = 0; return; }
	std::cout << endl;
	std::cout << p.stor_menu[*store - 1] << " ���� �޴��� �������ּ��� ! " << endl;
	p.food_storelist(*store); std::cout << endl;
	std::cout << endl << " �޴��Է� : ";
	cin >> *menu;
	if (*menu < 0) { std::cout << " ���� �߸��Է��ϼ̽��ϴ�!  ���� �ȹٷ� �Է����ּ���! "; return ; }
	if (*menu > 18) { std::cout << " �߸��� ���� �Է��ϼ̽��ϴ�" << endl; Sleep(100); system("cls"); menu = 0; return; }
	std::cout << endl;
	
	
	
}

void  deliver_console::food_chines(int* store, int* menu)
{
	*store = 0;  *menu = 0;
	chines_fooda p;
	guest a;
	system("cls");
	std::cout << " * �߽� ���� ���Ű��� ȯ���մϴ�! " << endl;
	std::cout << " ========================================" << endl;
	std::cout << " ������ �߽� �Ĵ��� �������ּ���! " << endl; 	std::cout << endl;
	p.food_storemenu(); std::cout << endl;
	std::cout << endl << " �޴��Է� : ";
	cin >> *store;
	if (*store < 0) { std::cout << " ���� �߸��Է��ϼ̽��ϴ�!  ���� �ȹٷ� �Է����ּ���! "; return ; }
	if (*store > 18) { std::cout << " �߸��� ���� �Է��ϼ̽��ϴ�" << endl; Sleep(100); system("cls"); menu = 0; return; }
	std::cout << endl;
	std::cout << p.stor_menu[*store - 1] << " ���� �޴��� �������ּ��� ! " << endl;
	p.food_storelist(*store); std::cout << endl;
	std::cout << endl << " �޴��Է� : ";
	cin >> *menu;
	if (*menu < 0) { std::cout << " ���� �߸��Է��ϼ̽��ϴ�!  ���� �ȹٷ� �Է����ּ���! "; return;}
	if (*menu > 18) { std::cout << " �߸��� ���� �Է��ϼ̽��ϴ�" << endl; Sleep(100); system("cls"); menu = 0; return; }
	std::cout << endl;

}

void deliver_console::food_order_finish(string menu, string store)
{
	guest a;
	system("cls");
	std::cout << " ================================================" << endl;
	std::cout << "�ֹ��Ͻ� "  << store << "���������� " << endl;
	std::cout << "�ֹ����� : " << menu << "  " << endl;
	std::cout << "�ֹ��ּ� : " << a.get_address() << endl;
	std::cout << "���� �ֹ� �Ϸ� �Ǿ����ϴ�! " << endl;
	std::cout << " ===============================================" << endl;
	Sleep(1000);
}

int  deliver_console::food_store_start() { // �ִ� �ֹ����ͼ� Ȯ���ߴ��� �׸��� ���� ���� ���� �ð� �����ִ°� �׸��� �� 
	system("cls");
	string menu;
	int menu2 =0;
	Sleep(900);
	while (true) {
		//Beep(262, 500); Beep(294, 500); Beep(330, 500);
		PlaySound(TEXT("intro.wav"), NULL, SND_ASYNC);// �Ϲ� �Ҹ� ��� 
		system("color 5e");
		std::cout << " ========================================= " << endl;
		std::cout << " ( " << guest::choice_stroe << " ) " << " �������Դϴ�!."<<" �ֹ��� ���Խ��ϴ�!!!!!�ֹ��� Ȯ�����ּ���!!" << endl;
		std::cout << " ���� �޴� : " << guest::choice_menu << endl;
		std::cout << " ========================================= " << endl;
		std::cout << " �ֹ��� Ȯ���ϼ�����  y�� �Է� ���ּ���  : ";
		cin >> menu;
		if (menu == "y") {
			std::cout << " �ֹ��� Ȯ�� �ϼ̽��ϴ�! " << endl <<endl ; 
			PlaySound(TEXT("�����Ϸ�.wav"), NULL, SND_ASYNC);// �Ϲ� �Ҹ� ��� 
			Sleep(900);
			system("cls");
			std::cout << " ���� ���� ���� �ֹ��ð��� �Է����ּ���! (��)  :"; 
			cin >> delivery_manegement::store_cooktime; // ���� �ֹ� �ð� static ���� 
				system("color 0e");
				PlaySound(TEXT("��������.wav"), NULL, SND_ASYNC);// �Ϲ� �Ҹ� ��� 
				deliver_console::delivery_man_start(menu2); // ��� �ݷ� ���÷��� �� ó�� �ѱ�� ȣ�� �Լ� 
				Sleep(1000);
				break; // �ֶ����� ����ǰ����� ����! 
		}
		else { std::cout << " �ֹ��� Ȯ������ �����̽��ϴ�! �ֹ��� Ȯ�����ּ��� !! "; Sleep(900); system("cls");  }
		
	}
	return menu2;
}

void deliver_console::delivery_man_start(int check) {
	string menu;
	int temp_pay = 0, count = 0;
	while(true){
		deliveryman a;
		delivery_manegement bs;
		
		string temp_name;
		temp_name = a.random_deliverman_name();
		temp_pay = a.random_deliver_pay();
		system("cls");
		system("color 5f"); // ���⼭ ���������� ��� ���� �����߽��ϴٷ� �����ؾ��ҵ�  �׸��� �������� ��޿�� �����°͵� �߰��ؾ��ҵ� 
		PlaySound(TEXT("�����.wav"), NULL, SND_ASYNC);// �Ϲ� �Ҹ� ��� 
		std::cout << " =============================================" << endl;
		std::cout << "   - ��� ���� �����Ͽ����ϴ�!!!  Ȯ�����ּ���!-     " << endl;
		std::cout << "��޿� : " <<temp_name <<"  ��  ����� Ȯ�����ּ��� !! " << endl; // ���⼭ �������� ��޿� �̸� ȣ�� �ؾ��� 
		std::cout << "��� �ּ� : " << guest::get_address() << endl;
		std::cout << "��� ���� : " << guest::choice_menu << endl;
		std::cout << "��� ������ (��) : " <<temp_pay  <<endl; // ��� ������ ���� ȣ�� 
		std::cout << "���� ��� �ҿ� �ð� : " << delivery_manegement::get_total_deliver_time()  << "�� ���ҽ��ϴ�. "<< endl;
		std::cout << "================================================" << endl;
		//Beep(269, 500); Beep(294, 500); Beep(450, 500);
		std::cout << " ���� �����Ƿ��� y�� �Է����ּ��� :  ";
		cin >> menu;
		if (menu == "y") { // ��� ���� ������ �ش� ��޿����� ���� ȣ�� �̸� �̾ƿ��¾� 1���� ��޿� �̸� �����ϰ� ������ 2���� �ʿ��ҵ� 
			// �ϳ��� ����Ʈ , 1���� ���� ������ �޾Ƽ� �����پ� (����)  , 1���� ���� ������ ���� ��޷� ������ų ���� �� �ȿ��� 3���� �ʿ��ҵ�  -> ��� ����̸� 
			// ��޷� ���� �ϴ� �迭�� ���⼭ ���� �־�����ϳ�  -> �׻������ ��޷� �־� ����ϴϱ� ���� �������°� �Ѱ� , �ִ� �� 2�� ���� ��޷� ������ͼ� ���÷��� , ��޷� ������ų���ϳ�
			std::cout << " ��� ���� �����̽��ϴ� !  " << endl << endl;
			std::cout << " ��ø� ��ٷ� �ּ��� ..... "; // ->   â ������ ->  -> ������ �Ⱦ� �Ϸ� -> 
			bs.get_deliverman_pay(temp_pay,temp_name);
			Sleep(900);
			system("color 0e");
			food_store_cook_finish();
			break;
		}
		else {
			std::cout << " ��� ���� ���� �����̽��ϴ� ....... �� ��� ȭ�� ���� �̵� �մϴ�... ";  Sleep(1000); system("cls"); 
			std::cout << "�� ����� ";
			for (int i = 0; i < 10; i++) {
				std::cout << " .";
				Sleep(500);
			}
			Sleep(1900);
			count = 1;
		}
	}
	return;
}

void deliver_console::food_store_cook_finish()
{
	string menu;
	int menu2;
	system("cls");
	system("color 5f"); 
	while (true) {
		std::cout << " =============================================" << endl;
		std::cout << guest::choice_stroe << " ������ �� " << guest::choice_menu << "���� ������ �Ϸ� �Ǿ����ϱ� ?" << endl;
		std::cout << "================================================" << endl;

		std::cout << " ������ �Ϸ� �ϼ̴ٸ� y �� �Է����ּ��� : ";
		cin >> menu;
		if (menu == "y") { 
			system(" cls");
			std::cout << "�ֹ� ������ �Ϸ� �Ǿ����ϴ�!! " << endl;
			Sleep(1000);
			deliver_man_pickup();
			break;
		}
		else {
			system("cls");
			std::cout << " =============================================" << endl;
			std::cout << "�߰� ���� �ð��� �� �ʿ� �Ͻʴϱ� ?? " <<  endl;
			std::cout << "================================================" << endl;
			std::cout << " �ʿ��Ͻôٸ�  y �� �Է����ּ��� : "; cin >> menu;
			if (menu == "y") {
				std::cout << " �󸶳� �߰� �ҿ� �ð��� �ʿ��Ͻʴϱ�?  " << endl << " �߰� �ҿ�ð��� �Է� ���ּ��� :  "; 
				cin >> menu2;
				delivery_manegement::total_deliver_plus_time = delivery_manegement::total_deliver_plus_time +  menu2;
				system("cls");
				std::cout << " �� : " << delivery_manegement::total_deliver_plus_time << " (��) ���ҽ��ϴ� �ֹ��� ���ѷ� �ּ��� ! " << endl; 
				
			}
			else {
				std::cout << delivery_manegement::total_deliver_plus_time << " ( ��) ���ҽ��ϴ� " << endl <<"������ �Ϸ� ���� �ʾҽ��ϴ�... ���ѷ� �ּ��� !! " << endl; Sleep(1000); system("cls");
			}
			
		}
	}
}

void deliver_console::deliver_man_pickup() {
	while (true) {
		string menu;
		system("cls");
		std::cout << " =============================================" << endl;
		std::cout << delivery_manegement::get_deliver_name_check() << " ��޿��� ���������� �Ϸ� �Ǿ����ϴ�! ������ �Ⱦ� ���ּ��� !! " << endl;
		std::cout << "================================================" << endl;
		std::cout << " ������ �Ⱦ�  �ϼ̴ٸ� y �� �Է����ּ��� : ";
		cin >> menu;
		if (menu == "y") {
			system(" cls");
			std::cout << delivery_manegement::get_deliver_name_check() << " ��޿����� �Ⱦ��� �Ϸ�Ǿ����ϴ�! " << endl;
			Sleep(1000);
			food_store_pickup();
			break;
		}
		else {
			system("cls");
			std::cout << delivery_manegement::get_deliver_name_check() << " �Ⱦ��� �̷���� �����ϴ� �Ⱦ��� ���� �Ͽ� �ּ��� !! " << endl;
			Sleep(1000);

			}
	}
}
void deliver_console::food_store_pickup() {
	while (true) {
		string menu;
		system("cls");
		std::cout << " =============================================" << endl;
		std::cout << guest::choice_stroe << " ������ �� " << guest::choice_menu << "�޴��� "  << endl;
		std::cout << " ��� ��簡 ���� �Ⱦ��� �Ϸ� �Ͽ����ϴ�! " << endl;
		std::cout << "================================================" << endl;
		std::cout << " �Ⱦ��� Ȯ���ϼ̴ٸ�  y �� �Է����ּ��� : ";
		cin >> menu;
		if (menu == "y") {
			system(" cls");
			std::cout << " ��޿����� �Ⱦ��� Ȯ�� �Ǿ����ϴ� !  " << endl;
			Sleep(1000);
			deliver_finish();
			break;
		}
		else {
			system("cls");
			std::cout << " ��޿� �̸� : " << delivery_manegement::get_deliver_name_check() << " ��޿��� ȣ�� �մϴ�! " << endl;
			Sleep(1000);
			return deliver_man_pickup();
			

		}
	}
}
void deliver_console::deliver_finish() {
	int  count = 0;
	while (true) {
		string menu;
		system("cls");
		if (count == 0) {
			delivery_manegement::total_deliver_plus_time = delivery_manegement::total_deliver_plus_time - delivery_manegement::store_cooktime;
		}
		std::cout << " =============================================" << endl;
		std::cout << delivery_manegement::get_deliver_name_check() << "��� ����!  ���� ����� �Ϸ� �ϼ̳���?? " << endl;
		std::cout << "��� �ҿ�ð��� : "<< delivery_manegement::total_deliver_plus_time  << " (��) ���ҽ��ϴ�! "<< endl;
		std::cout << "================================================" << endl;
		std::cout << " ����� �Ϸ� �ϼ̴ٸ�  y �� �Է����ּ��� : ";
		cin >> menu;
		if (menu == "y") {
			system(" cls");
			std::cout << " ����� �Ϸ� �Ǿ����ϴ� !  " << endl;
			Sleep(1000);
			food_store_finishcall();
			break;
		}
		else {
			system("cls");
			std::cout << delivery_manegement::get_deliver_name_check() <<" ��޿���!!  " << "  ����� ���ѷ� �ּ��� !  " << endl;
			count++;
			Sleep(1000);
		}
	}
}
void deliver_console::food_store_finishcall() {
	while (true) {
		string menu;
		system("cls");
		std::cout << " =============================================" << endl;
		std::cout << guest::choice_stroe << "�������� ! " << endl << guest::choice_menu << "���� ����� �Ϸ� �Ǿ����ϴ� ! " << endl;
		std::cout << "================================================" << endl;
		std::cout << " Ȯ�� �ϼ̴ٸ�  y �� �Է����ּ��� : ";
		cin >> menu;
		if (menu == "y") {
			system(" cls");
			std::cout << " ���ó����  �Ϸ� �Ǿ����ϴ� !  " << endl;
			PlaySound(TEXT("��޿Ϸ�.wav"), NULL, SND_ASYNC);// �Ϲ� �Ҹ� ��� 
			Sleep(1000);
			total_star_finish();
			break;
		}
		else {
			system("cls");
			std::cout << guest::choice_stroe << " ��������! ��� �ο� �߻��� �����ͷ� ��ȭ ��Ź�帳�ϴ�!    " << endl << " TEL : 080 -0000 -0000  �Դϴ� . �����մϴ�! " << endl;
			Sleep(1300);
		}
	}
}
void deliver_console::total_star_finish() {
	while (true) {
		int menu;
		system("cls");
		std::cout << " =============================================" << endl;
		std::cout << guest::choice_stroe << " ����������  " << guest::choice_menu << " ���� �޴��� �ֹ��Ͻ� ����!! " << endl;
		std::cout << " ����� �Ϸ� �Ǿ����ϴ�!!  ������ �Ʒ� ���������縦 ���ּ���! " << endl;
		std::cout << "================================================" << endl;
		std::cout << "     - ������ 1 ~ 5�� �����Դϴ� ! -  " << endl;
		std::cout << guest::choice_stroe << "�������� ���� �������� � �̽��ϱ�? ";
		cin >> menu;
		delivery_system::set_food_star(menu);
		std::cout << " ��޿��� ���� �������� � �̽��ϱ� ? ";
		cin >> menu;
		delivery_system::set_deliver_star(menu);
		Sleep(1600);
		std::cout << " ������ �������� �������ּż� �����մϴ� ! ";
		Sleep(1000);
		break;
	}

}
void deliver_console::admin_deliver_star() {
	deliveryman hi;
	while (true) {
		int menu;
		system("cls");
		std::cout << " =============================================" << endl;
		std::cout << " ��޿� ���� �������Դϴ�  �Ʒ��� ������� ��޿��� ���� ���� ��Ȳ �Դϴ�. " << endl;
		std::cout << " ��޿��� ������ ���� ��� �����ᰡ ���� ���� �˴ϴ� !  " << endl;
		std::cout << "================================================" << endl;
		std::cout << "  ��޿�  ���� ��Ȳ  " << endl;
		for (int te1 = 0; te1 <= 7; te1++) {
		std::cout << " " << hi.get_deliver_man_list(&te1) <<  "  " ;
		}
		std::cout << endl << endl;
		std::cout << "       ��޿�  ���� ��Ȳ ���� : (��)  " << endl<<endl;
		for (int te2 = 0; te2 <= 7; te2++) {
			std::cout << "   " << delivery_system::get_total_deliver_star(te2) << "     ";
		}
		Sleep(3000);
		break;
	}

}
void deliver_console::admin_store_star() {
	korea_fooda test;
	weston_fooda wesa;
	chines_fooda ci;

	while (true) {
		int menu;
		system("cls");
		std::cout << " =============================================" << endl;
		std::cout << " ������ ���� �������Դϴ�  �Ʒ��� ������� �������� ���� ���� ��Ȳ �Դϴ�. " << endl;
		std::cout << "================================================" << endl;
		std::cout << "  ������   ���� ��Ȳ  " << endl;
		std::cout << endl;
		std::cout << "               -  �ѽ���  - " << endl;
		std::cout << endl; 
		for (int te = 0; te <= 7; te++) {
			std::cout << "   "<< test.stor_menu[te] << "      ";
		}
		std::cout << endl << endl;
		for (int te2 = 0; te2 <= 3; te2++) {
			std::cout << "       " << delivery_system::get_total_food_star(te2)<< "                  ";
		}
		std::cout << endl;
		std::cout << "               -  �����  - " << endl;
		std::cout << endl;
		for (int te3 = 0; te3 <= 2; te3++) {
			std::cout << "   " << wesa.stor_menu[te3] << "         ";
		}
		std::cout << endl << endl<<endl;
		for (int te4 = 4; te4 <= 6; te4++) {
			std::cout << "       " << delivery_system::get_total_food_star(te4) << "                ";
		}
		std::cout << endl << endl << endl;
		std::cout << "               -  �߽���  - " << endl;
		std::cout << endl;
		for (int te5 = 0; te5 <= 3; te5++) {
			std::cout << "   " << ci.stor_menu[te5]<< "         ";
		}
		std::cout << endl << endl << endl;
		for (int te6 = 7; te6 <= 10; te6++) {
			std::cout << "       " << delivery_system::get_total_food_star(te6) << "                ";
		}
		Sleep(3000);
		break;
	}

}
void deliver_console::admin_deliver_paylist() {
	deliveryman ta[3];// ��ü �迭 
	deliveryman* tes;// ��ü ������
	deliveryman hi;
	delivery_manegement fd;
	tes = ta; // ��ü ������ �ʱ�ȭ 
	while (true) {
		int menu;
		system("cls");
		std::cout << " =============================================" << endl;
		std::cout << " ��޿� ��޷� �������Դϴ�  �Ʒ��� ������� ��޿��� ���� ��޷� ��Ȳ �Դϴ�. " << endl;
		std::cout << " ��޿��� ������ ���� ��� �����ᰡ ���� ���� �˴ϴ� !  " << endl;
		std::cout << "================================================" << endl;
		std::cout << "  ��޿�  ��޷� ��Ȳ  " << endl;
		for (int te1 = 0; te1 <= 7; te1++) { // ��޿� �̸� ȣ�� 
			std::cout << " " << tes->get_deliver_man_list(&te1) << "  "; // ��ü �����͸� ���� ȣ�� 
			// �ȵǸ� �̰� ���� 
		}
		std::cout << endl << endl;
		for (int te2 = 0; te2 <= 7; te2++) {
			std::cout << "   " << fd.get_deliverman_pay(te2) << "     ";
		}
		std::cout << "       ��޿�  ��޷� ��Ȳ ���� : (��)  " << endl << endl;
		Sleep(3000);
		std::cout << endl << endl;
		std::cout << "       ��޿�  ���� ��Ȳ ���� : (��)  " << endl << endl;
		for (int te2 = 0; te2 <= 7; te2++) {
			std::cout << "   " << delivery_system::get_total_deliver_star(te2) << "      ";
		}
		Sleep(3000);
		break;
	}

}

void deliver_console::admin_deliver_totalsystem() { // ���� ���� ������ 
	deliveryman hi;
	delivery_manegement fd;
	delivery_system a;
	delivery_manegement b;
	while (true) {
		int menu;
		system("cls");
		std::cout << " =============================================" << endl;
		std::cout << " ��޿� ��޷� ���� �������Դϴ�  �Ʒ��� ������� ��޿��� ���� ��޷� ��Ȳ �Դϴ�. " << endl;
		std::cout << " ��޿��� ������ ���� ��� �����ᰡ ���� ���� �˴ϴ� !  " << endl;
		std::cout << "================================================" << endl;
		std::cout << "                        ��޿�  ��޷� ��Ȳ  " << endl;
		for (int te1 = 0; te1 <= 7; te1++) { // ��޿� ����Ʈ 
			std::cout << " " << hi.get_deliver_man_list(&te1) << "  ";
		}
		std::cout << endl << endl;
		for (int te2 = 0; te2 <= 7; te2++) {
			std::cout << "   " << fd.get_deliverman_pay(te2) << "     ";
		}
		std::cout << endl << endl;
		std::cout << "                      ����  ��޿� (���� �ݿ�)  ��޷� ���� �Ϸ� �ݾ� ! : (��)  " << endl << endl;
		delivery_manegement::total_last_deliver_pay();
		Sleep(6500);
		cout << "                           ���� ������ �Ϸ� �Ǿ����ϴ�!!!!            " << endl  << endl ;
		cout <<  "  (����) : !!    ������ �Ϸ� �Ǿ����Ƿ�   ��ü ��޷� �� ������  �ʱ�ȭ �˴ϴ�  !! " << endl << endl;
		b.arr_reset();// ��޷� �ʱ�ȭ 
		a.deliver_start_clear();
		a.foodstore_star_clear();
		for (int i = 0; i <= 18; i++) { // ���� �ڵ� ���� ���� �ʱ� ȭ 
			a.first_run_count[i] = 0;
		}
		Sleep(1500);
		break;
	}

}
int deliver_console::admin_menu = 0;



