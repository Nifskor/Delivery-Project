#include "delivery_manegement.h"
#include "deliveryman.h"
#include "delivery_system.h"
#include <iostream>
#include <string>
using namespace std;

void delivery_manegement::get_deliverman_pay(int  a  , string b  ) // ���⼭ �ش� �迭 �̸��� ���� �� ������ġ ������ ���⼭ ����� if  int a Ÿ���� �ݾ� , string Ÿ���� ��޿� �̸� 
{  //  deliveryman b;
	// int n = b.get_deliver_pay_list(&a);  -> �̱����� �������� �߻��� ���Ѽ� ��Ų ���� �޾Ƽ� �־� �ֱ⸸ �ϸ�Ǵ°ž� 
	       deliver_name = b;  // ��޿� �̸� �־��ִ°� 
		// deliverman_pay[a] = n;
		if (b == "ȫ�浿") {
			cout << a << b << endl;
			int array_tim = 0, temp ; //�迭 ��ġ 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " ȫ�浿 " << deliverman_pay[0] << "��ޱݾ� å�� �Ϸ� ";
		}
		else if (b == "�����") {
			cout << a << b << endl;
			int array_tim = 1, temp = 0; //�迭 ��ġ 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " ����� " << deliverman_pay[array_tim] << "��ޱݾ� å�� �Ϸ� ";
		}
		else if (b == "�̹���") {
			cout << a << b << endl;
			int array_tim = 2, temp = 0; //�迭 ��ġ 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " �̹��� " << deliverman_pay[array_tim] << "��ޱݾ� å�� �Ϸ� ";
		}
		else if (b == "�蹮��") {
			cout << a << b << endl;
			int array_tim = 3, temp = 0; //�迭 ��ġ 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " �蹮�� " << deliverman_pay[array_tim] << "��ޱݾ� å�� �Ϸ� ";
		}
		else if (b == "�Ұ�") {
			cout << a << b << endl;
			int array_tim = 4, temp = 0; //�迭 ��ġ 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " �Ұ� " << deliverman_pay[array_tim] << "��ޱݾ� å�� �Ϸ� ";
		}
		else if (b == "B�� ����") {
			cout << a << b << endl;
			int array_tim = 5, temp = 0; //�迭 ��ġ 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " B�� ���� " << deliverman_pay[array_tim] << "��ޱݾ� å�� �Ϸ� ";
		}
		else if (b == "���� B��") {
			cout << a << b << endl;
			int array_tim = 6, temp = 0; //�迭 ��ġ 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " ���� B�� " << deliverman_pay[array_tim] << "��ޱݾ� å�� �Ϸ� ";
		}
		else if (b == "�����") {
			cout << a << b << endl;
			int array_tim = 7, temp = 0; //�迭 ��ġ 
			temp = deliverman_pay[array_tim];
			temp = temp + a;
			deliverman_pay[array_tim] = temp;
			cout << endl;
			cout << " ����� " << deliverman_pay[array_tim] << "��ޱݾ� å�� �Ϸ� ";
		}
	

}

void delivery_manegement::total_last_deliver_pay() // ���� ��޿� ���� �ݿ��� ��޷� ���� ���� ó�� �Լ� 
{
	cout << " ���� ó�� �Լ� ���� " << endl;
	deliveryman hi;
	for (int i = 0; i <= 8; i++) {

		string name = hi.get_deliver_man_list(&i); //  ��޿� ��� 
		int total_star = delivery_system::get_total_deliver_star(i); // ���� ��޿� ���� 

		if (name == "ȫ�浿") {
			int array_tim = 0, temp; //�迭 ��ġ 

			if (total_star == 1) {// ������ �ſ� ���� 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // ������ ���Ƽ� 4õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // ������ ���Ƽ� 3õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // ������ ���Ƽ� 2õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // ������ 4���� ��� �谨�� ����  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // ������ 5���� ��� �μ�Ƽ�� 1000�� �߰��� 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // ������ ���Ƽ� 1õ�� ���ʽ�  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " ȫ�浿 " << deliverman_pay[0] << "��� ���� �ݾ� :  " << deliverman_pay[array_tim];
		}
		else if (name == "�����") {

			int array_tim = 1, temp = 0; //�迭 ��ġ 
			if (total_star == 1) {// ������ �ſ� ���� 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // ������ ���Ƽ� 4õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // ������ ���Ƽ� 3õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // ������ ���Ƽ� 2õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // ������ 4���� ��� �谨�� ����  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // ������ 5���� ��� �μ�Ƽ�� 1000�� �߰��� 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // ������ ���Ƽ� 1õ�� ���ʽ�  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " ȫ�浿 " << deliverman_pay[0] << "��� ���� �ݾ� :  " << deliverman_pay[array_tim];
		}
		else if (name == "�̹���") {

			int array_tim = 2, temp = 0; //�迭 ��ġ 
			if (total_star == 1) {// ������ �ſ� ���� 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // ������ ���Ƽ� 4õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // ������ ���Ƽ� 3õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // ������ ���Ƽ� 2õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // ������ 4���� ��� �谨�� ����  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // ������ 5���� ��� �μ�Ƽ�� 1000�� �߰��� 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // ������ ���Ƽ� 1õ�� ���ʽ�  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " ȫ�浿 " << deliverman_pay[0] << "��� ���� �ݾ� :  " << deliverman_pay[array_tim];
		}
		else if (name == "�蹮��") {
			int array_tim = 3, temp = 0; //�迭 ��ġ 
			if (total_star == 1) {// ������ �ſ� ���� 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // ������ ���Ƽ� 4õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // ������ ���Ƽ� 3õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // ������ ���Ƽ� 2õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // ������ 4���� ��� �谨�� ����  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // ������ 5���� ��� �μ�Ƽ�� 1000�� �߰��� 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // ������ ���Ƽ� 1õ�� ���ʽ�  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " ȫ�浿 " << deliverman_pay[0] << "��� ���� �ݾ� :  " << deliverman_pay[array_tim];
		}
		else if (name == "�Ұ�") {
			int array_tim = 4, temp = 0; //�迭 ��ġ 
			if (total_star == 1) {// ������ �ſ� ���� 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // ������ ���Ƽ� 4õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // ������ ���Ƽ� 3õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // ������ ���Ƽ� 2õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // ������ 4���� ��� �谨�� ����  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // ������ 5���� ��� �μ�Ƽ�� 1000�� �߰��� 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // ������ ���Ƽ� 1õ�� ���ʽ�  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " ȫ�浿 " << deliverman_pay[0] << "��� ���� �ݾ� :  " << deliverman_pay[array_tim];
		}
		else if (name == "B�� ����") {
			int array_tim = 5, temp = 0; //�迭 ��ġ 
			if (total_star == 1) {// ������ �ſ� ���� 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // ������ ���Ƽ� 4õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // ������ ���Ƽ� 3õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // ������ ���Ƽ� 2õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // ������ 4���� ��� �谨�� ����  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // ������ 5���� ��� �μ�Ƽ�� 1000�� �߰��� 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // ������ ���Ƽ� 1õ�� ���ʽ�  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " ȫ�浿 " << deliverman_pay[0] << "��� ���� �ݾ� :  " << deliverman_pay[array_tim];
		}
		else if (name == "���� B��") {
			int array_tim = 6, temp = 0; //�迭 ��ġ 
			if (total_star == 1) {// ������ �ſ� ���� 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // ������ ���Ƽ� 4õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // ������ ���Ƽ� 3õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // ������ ���Ƽ� 2õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // ������ 4���� ��� �谨�� ����  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // ������ 5���� ��� �μ�Ƽ�� 1000�� �߰��� 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // ������ ���Ƽ� 1õ�� ���ʽ�  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " ȫ�浿 " << deliverman_pay[0] << "��� ���� �ݾ� :  " << deliverman_pay[array_tim];
		}
		else if (name == "�����") {
			int array_tim = 7, temp = 0; //�迭 ��ġ 
			if (total_star == 1) {// ������ �ſ� ���� 
				temp = deliverman_pay[array_tim];
				temp = temp - 4000; // ������ ���Ƽ� 4õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 2) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 3000; // ������ ���Ƽ� 3õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 3) { // ������ 2���� ��� 
				temp = deliverman_pay[array_tim];
				temp = temp - 2000; // ������ ���Ƽ� 2õ�� �谨  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}
			else if (total_star == 4) { // ������ 4���� ��� �谨�� ����  
				temp = deliverman_pay[array_tim];

			}
			else if (total_star == 5) { // ������ 5���� ��� �μ�Ƽ�� 1000�� �߰��� 
				temp = deliverman_pay[array_tim];
				temp = temp + 1000; // ������ ���Ƽ� 1õ�� ���ʽ�  ���߿� - �Ǽ� ���� �߻��� ���ɼ��� �����ؾ��ҵ� �װſ� ���� ���ܹ��� �ʿ��Ҽ��� 
				deliverman_pay[array_tim] = temp;
			}

			//	cout << " ȫ�浿 " << deliverman_pay[0] << "��� ���� �ݾ� :  " << deliverman_pay[array_tim];
		}

	}
	for (int te2 = 0; te2 <= 8; te2++) {
		cout << "   " << hi.get_deliver_man_list(&te2)<< "     ";
	}
	cout << endl << endl;
	for (int te2 = 0; te2 <= 8; te2++) {
		cout << "   " << deliverman_pay[te2] << "         ";
	}
	cout << endl<< endl;;
	
}

delivery_manegement::delivery_manegement()
{


}

delivery_manegement::~delivery_manegement()
{
}

int delivery_manegement::get_total_deliver_time()
{
	
	 total_deliver_plus_time =  store_cooktime + 20;
	return total_deliver_plus_time;
}

int delivery_manegement::deliverman_pay[100] = { };
int delivery_manegement::store_cooktime = 0;
int delivery_manegement::total_deliver_plus_time = 0;
string delivery_manegement::deliver_name = "";