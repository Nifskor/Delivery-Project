#pragma once
#include <string>
#include "korea_fooda.h"
#include "weston_fooda.h"
#include "chines_fooda.h"
#include "delivery_system.h"
#ifndef _deliver_console_
#define _deliver_console_
using namespace std;
class delivery_system;
class deliver_console
{
private :


public:
	static int admin_menu; // ������ �޴� 
	static int check_count ; // �ּ� �ι� �Է� ���ް� ī��Ʈ�ϴ°� 
	static int  mainmenu(); // ���οɼ� ����Լ� 
	static int  adminpage(); // ������ ������ 
	static int  food_optiona(); //  �մ� �ѽ�, ��� ,�߽� ���� ������ 
	/*        ������ �� �޴�                                */
	static void  food_korean(int* store, int* menu); // �ѽ��������� ������ 
	static void  food_weston(int* store, int* menu); // ����������� ������
	static void  food_chines(int* store, int* menu); // �߽��������� ������ 
	static void  food_order_finish(string menu , string store); // �ֹ�����Ϸ� ��������� 
	static int food_store_start(); // ���������� �ֹ����°� ó���ϰ� �ν��ϴ� ���� 
	static void  delivery_man_start(int check); // ��޿� �������̽� ó�� ���� �κ� 
	static void food_store_cook_finish(); // ���������� ������ �Ϸ� �Ͽ����� Ȯ�� 
	static void deliver_man_pickup(); // ��޿� �Ⱦ� Ȯ�� �Լ� 
	static void food_store_pickup(); // ������ �Ⱦ� Ȯ�� �Լ� 
	static void deliver_finish(); // ���� ��� �Ϸ� �Լ� 
	static void food_store_finishcall(); // ������ ��� �Ϸ� �ȳ� �Լ� 
	static void total_star_finish(); // ���� ������ ȭ�� ���� �ο� ������ 
	static void admin_deliver_star(); // ������ ������ ��޿� ���� ����Լ� 
	static void admin_store_star(); // ������ ������ ������ ���� ��� �Լ� 
	static void admin_deliver_paylist(); // ������ ��޷� ���� ��� �Լ� 
	static void admin_deliver_totalsystem(); // ���� ������ ���� ������ 

	deliver_console();
	~deliver_console();




};

#endif