#pragma once
#include <string>
#include "deliveryman.h"
#ifndef _delivery_manegement_
#define _delivery_manegement_
using namespace std;
class delivery_manegement
{
	static int deliverman_pay[100] ; // ��޿� ��޷� ���� ���� 
	static string deliver_name; // ��޿� �̸� 

public:
	static int store_cooktime; // ���� �ֹ� �ð�
	static int total_deliver_plus_time; // �߰� �ֹ� �ҿ� �ð� �ջ��Ͽ� ��ü ��� �ҿ� �ð� ���� ���� 
	void arr_reset() {
		for (int i = 0; i <= 99; i++) {
			deliverman_pay[i] = 0;
		}
	}
	int get_deliverman_pay(int a) { return deliverman_pay[a]; }  // ���� ó���Ҷ� ������ ���� �� �ְ� �ް� ���� �� ���� ó���ض� 
	void get_deliverman_pay(int a, string b);// ��޿� �̸� ��޷Ḧ �޾Ƽ� �װ� ��� 
	static void  total_last_deliver_pay(); // ���� ��޷� ���� �Լ� 
	static int get_total_deliver_time(); // �� ��ü ��� �ҿ�ð� ��� �Լ� �ҿ�ð� ����Ʈ +20 �� 
	static string get_deliver_name_check() { return deliver_name; }
	delivery_manegement();
	~delivery_manegement();

};

#endif

