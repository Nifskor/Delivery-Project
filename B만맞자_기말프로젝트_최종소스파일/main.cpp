#include <iostream>
#include <string >
#include "weston_fooda.h"
#include "chines_fooda.h"
#include "korea_fooda.h"
#include "deliveryman.h"
#include "guest.h"
#include "deliver_console.h"
#include "delivery_system.h"
using namespace std; 


int main() {
	delivery_system a;
	delivery_manegement b;
	b.arr_reset();
	a.deliver_start_clear();
	a.foodstore_star_clear();
	for (int i = 0; i <= 18; i++) { // 에러 코드 관련 메인 초기 화 
		a.first_run_count[i] = 0;
	}
	a.run();
	
	//b.total_last_deliver_pay();
	//deliver_console::adminpage();
	/*for (int test = 0; test <= 10; test++) {
		a.set_food_star(3);
	}
	*/

}