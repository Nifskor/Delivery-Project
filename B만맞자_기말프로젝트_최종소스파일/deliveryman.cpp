#include "deliveryman.h"
#include "guest.h"
#include <iostream>
#include <string>
#include "delivery_manegement.h"
#include "time.h"

using namespace std;

int deliveryman::random_deliver_pay()
{
	int temp =0 , num =0 ;
	srand(time(NULL));
	temp = rand() % 6;
	num = get_deliver_pay_list(&temp);
	return num;
}

string deliveryman::random_deliverman_name()
{
	int temp = 0;
	string num;
	srand(time(NULL));
	temp = rand() % 8;
	num = get_deliver_man_list(&temp);
	return num;
}

int deliveryman::give_deliver_time()
{
	return 0;
}


deliveryman::deliveryman() // �ִ� ��ü�� ������ �ؾ��ϰ� �׸��� �����Ѵ� ���� �̷��Ÿ� statitc ���� 

{  


	
}

deliveryman::~deliveryman()
{
	delete[] deliver_pay_list;
	delete[] deliverman_list;
}
