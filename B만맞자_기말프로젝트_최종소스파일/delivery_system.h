#pragma once
#include <string>
#include <iostream>
#ifndef _delivery_system_
#define _delivery_system_
using namespace std;
class guest;
class delivery_system
{
	static int deliver_star[50]; // ��޿� ���� 
	static int foodstore_star[50]; // ������ ����  �ѽ� -> ��� ->�߽� 
	static int dliever_star_count[50]; // �� ��� ȣ��Ǿ����� Ȯ���ؼ� ���� �������Ҷ� ���Ǵ� ���� 
	static int foodstore_star_count[50]; // �� ��� ȣ��Ǿ����� Ȯ���ؼ� ���� �������Ҷ� ���Ǵ� ���� 
public:
	static int first_run_count[20]; // zero ���� ������ ī��Ʈ ó�� �Լ� 
	void run(); // ���� �Լ� 
	void food_korea(int* store, int* menu); // �ѽ� ó�� ���� 
	void food_weston(int* store, int* menu); // ��� ó������ 
	void food_chines(int* store, int* menu); // �߽� ó������ 
	void admin_start(); // ������ � �Լ� 
	void deliver_start(); // ��� �ֹ� ���� �����Լ� 
	/*          ���޿� ���� ó�� �Լ�              */
	static void  set_deliver_star(int a); // ��޿� ���� ��ȯ   ������ �޾ƿ��°� 
	static int get_total_deliver_star(int a ) {// ���� ���� ���ϴ� �Լ� 
		int  total = 0, c=0 ,b=0; // total ������ ���� , b�� ���� �޾ƿ��°Ű� , c�� �� �ش���ġ �ݺ�Ƚ�� 
		    c   = dliever_star_count[a];
			 b = deliver_star[a];
			// cout << c << b; 
	          total  = b / c; 
			return total;
	} // ��ü ��޿� ���� ����ؼ� ��ȯ ��Ű�¾� 

	         /*        ������ ���� ó�� �Լ�          */
	static void set_food_star(int a);
	static int get_total_food_star(int a) {
		int  total = 0, c = 0, b = 0; // total ������ ���� , b�� ���� �޾ƿ��°Ű� , c�� �� �ش���ġ �ݺ�Ƚ�� 
		c = foodstore_star_count[a];
		b = foodstore_star[a];
		total = b / c;
			// cout << c << b; 
		//cout << b << c; 
		return total;
	}


	void deliver_start_clear() {
		for (int i = 0; i <= 49; i++) {
				deliver_star[i] =0;
				dliever_star_count[i] = 1;
		}
	}
	 void foodstore_star_clear() { 
		for (int i = 0; i <= 49; i++) {
		      foodstore_star[i] = 0;
			  foodstore_star_count[i] = 1;
		}
	}

	delivery_system();
	~delivery_system();
};

#endif
