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
	 int menu = mainmenu(); // 제일 먼저 메인 메뉴 실행 
	switch (menu)
	{
	case ADMIN : 
	default:
		break;
	}


	return 0;
}/* -> 배달 시스템 */

int deliver_console::mainmenu()
{
	int menu =0;
	std::cout << "초기 화면으로 이동중 ..." << endl;
	Sleep(1000);
	system("cls");
	std::cout << " ==================================" << endl;
	std::cout << " * 배달 관리시스템을 시작 합니다 * " << endl; 
	std::cout << " 진입하고자 하는 옵션을 선택해주세요 " << endl;
	std::cout << " ==================================" << endl;
	std::cout << "1 .관리자 2. 배달 주문 시작 3. 프로그램 종료 " << endl;
	std::cout << endl << " 메뉴입력 : ";
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
			std::cout << " * 관리자 페이지에 오신것을 환영합니다! " << endl;
			std::cout << " 관리자 비밀 번호를 입력해주세요 ! " << endl;
			std::cout << endl << " 메뉴입력 : ";
			cin >> admin_menu;
		}
		if (admin_menu == 1234) {
			std::cout << "관리자 페이지에 로그인 하셨습니다! " << endl;
			Sleep(100);
			system("cls");
			//std::cout << menu << endl;
			std::cout << " 관리자 페이지에서 사용하실 항목을 선택하세요! " << endl;
			std::cout << " ====================================================================" << endl;
			std::cout << " 1. 배달원 평점 2. 음식점 평점 3. 배달원 배달료 현황 4. 배달료 정산 5. 메인페이지로 나가기 " << endl;
			std::cout << " =======================================================================" << endl;
			std::cout << endl << " 메뉴입력 : ";
			cin >> menu;
			std::cout << menu;
			if (menu < 0) {
				std::cout << " 값을 잘못입력하셨습니다!  값을 똑바로 입력해주세요! ";
				system("cls");
				break;
			}
		//	std::cout << menu << endl;
			return menu;
		}
		else {
			std::cout << "비밀번호를 잘못입1력하셨습니다 다시 입력해주세요 " << endl;
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
	std::cout << " * 배달 주문에 오신것을 환영합니다 * " << endl;
	std::cout << " =======================================" << endl;
	std::cout << " 오늘은 " << guest::get_random() << "(랜덤) 메뉴를 추천합니다 " << endl;
	std::cout << "  드시고 싶은음식 종류를 선택 해주세요 " << endl;
	std::cout << "  1. 한식  2. 양식  3. 중식 " << endl;
	std::cout << " ========================================" << endl;
	std::cout << endl << " 메뉴입력 : ";
	cin >> menu;
	if (menu < 0) { std::cout << " 잘못된 값을 입력하셨습니다" << endl; Sleep(100); system("cls"); menu = 0; return 0; }
	if(menu >=4) { std::cout << " 잘못된 값을 입력하셨습니다" << endl; Sleep(100); system("cls"); menu = 0; return 0; }
	if (check_count == 0) {
		std::cout << " ======================================= " << endl;
		std::cout << " 배달 받으실 주소를 입력해주세요 ! " << endl;
		std::cout << " ======================================= " << endl;
		std::cout << " 주소입력 : "; cin.ignore();  getline(cin, address);  std::cout << endl;
		check_count++;
		guest::set_address(address);

	}
	return menu;
}

int deliver_console::check_count = 0; // 전역 으로 배달 주소 1번만 최초 입력 하도록 하는 변수 재정의 
void deliver_console::food_korean(int *store , int *menu)
{
	*store = 0;  *menu = 0;
	korea_fooda p;
	guest a;
	system("cls");
	std::cout << " * 한식 종목에 오신것을 환영합니다! " << endl;
	std::cout << " ========================================" << endl;
	std::cout << " 다음중 한식 식당을 선택해주세요! " << endl; 	std::cout << endl;
	p.food_storemenu(); std::cout << endl; 
	std::cout << endl << " 메뉴입력 : ";
	cin >> *store;
		if (*store < 0) { std::cout << " 잘못된 값을 입력하셨습니다" << endl; Sleep(100); system("cls"); menu = 0; return; }
		if (*store > 18) { std::cout << " 잘못된 값을 입력하셨습니다" << endl; Sleep(100); system("cls"); menu = 0; return; }
	std::cout << endl; 
	std::cout << p.stor_menu[*store -1]<<" 음식 메뉴를 선택해주세요 ! " << endl; std::cout << endl;
	p.food_storelist(*store); std::cout << endl;
	std::cout << endl << " 메뉴입력 : ";
	cin >> *menu;
	if (*menu < 0) { std::cout << " 잘못된 값을 입력하셨습니다" << endl; Sleep(100); system("cls"); menu = 0; return; }
	if (*menu > 18) { std::cout << " 잘못된 값을 입력하셨습니다" << endl; Sleep(100); system("cls"); menu = 0; return; }
	std::cout << endl;
	
}

void  deliver_console::food_weston(int* store, int* menu)
{
	*store = 0;  *menu = 0;
	weston_fooda p;
	guest a;
	system("cls");
	std::cout << " * 양식 종목에 오신것을 환영합니다! " << endl;
	std::cout << " ========================================" << endl;
	std::cout << " 다음중 양식 식당을 선택해주세요! " << endl; 	std::cout << endl;
	p.food_storemenu(); std::cout << endl;
	std::cout << endl << " 메뉴입력 : ";
	cin >> *store;
	if (*store < 0) { std::cout << " 값을 잘못입력하셨습니다!  값을 똑바로 입력해주세요! "; return ; }
	if (*store > 18) { std::cout << " 잘못된 값을 입력하셨습니다" << endl; Sleep(100); system("cls"); menu = 0; return; }
	std::cout << endl;
	std::cout << p.stor_menu[*store - 1] << " 음식 메뉴를 선택해주세요 ! " << endl;
	p.food_storelist(*store); std::cout << endl;
	std::cout << endl << " 메뉴입력 : ";
	cin >> *menu;
	if (*menu < 0) { std::cout << " 값을 잘못입력하셨습니다!  값을 똑바로 입력해주세요! "; return ; }
	if (*menu > 18) { std::cout << " 잘못된 값을 입력하셨습니다" << endl; Sleep(100); system("cls"); menu = 0; return; }
	std::cout << endl;
	
	
	
}

void  deliver_console::food_chines(int* store, int* menu)
{
	*store = 0;  *menu = 0;
	chines_fooda p;
	guest a;
	system("cls");
	std::cout << " * 중식 종목에 오신것을 환영합니다! " << endl;
	std::cout << " ========================================" << endl;
	std::cout << " 다음중 중식 식당을 선택해주세요! " << endl; 	std::cout << endl;
	p.food_storemenu(); std::cout << endl;
	std::cout << endl << " 메뉴입력 : ";
	cin >> *store;
	if (*store < 0) { std::cout << " 값을 잘못입력하셨습니다!  값을 똑바로 입력해주세요! "; return ; }
	if (*store > 18) { std::cout << " 잘못된 값을 입력하셨습니다" << endl; Sleep(100); system("cls"); menu = 0; return; }
	std::cout << endl;
	std::cout << p.stor_menu[*store - 1] << " 음식 메뉴를 선택해주세요 ! " << endl;
	p.food_storelist(*store); std::cout << endl;
	std::cout << endl << " 메뉴입력 : ";
	cin >> *menu;
	if (*menu < 0) { std::cout << " 값을 잘못입력하셨습니다!  값을 똑바로 입력해주세요! "; return;}
	if (*menu > 18) { std::cout << " 잘못된 값을 입력하셨습니다" << endl; Sleep(100); system("cls"); menu = 0; return; }
	std::cout << endl;

}

void deliver_console::food_order_finish(string menu, string store)
{
	guest a;
	system("cls");
	std::cout << " ================================================" << endl;
	std::cout << "주문하신 "  << store << "음식점에서 " << endl;
	std::cout << "주문음식 : " << menu << "  " << endl;
	std::cout << "주문주소 : " << a.get_address() << endl;
	std::cout << "정상 주문 완료 되었습니다! " << endl;
	std::cout << " ===============================================" << endl;
	Sleep(1000);
}

int  deliver_console::food_store_start() { // 애는 주문들어와서 확인했는지 그리고 예상 음식 조리 시간 보여주는거 그리고 끝 
	system("cls");
	string menu;
	int menu2 =0;
	Sleep(900);
	while (true) {
		//Beep(262, 500); Beep(294, 500); Beep(330, 500);
		PlaySound(TEXT("intro.wav"), NULL, SND_ASYNC);// 일반 소리 재생 
		system("color 5e");
		std::cout << " ========================================= " << endl;
		std::cout << " ( " << guest::choice_stroe << " ) " << " 음식점입니다!."<<" 주문이 들어왔습니다!!!!!주문을 확인해주세요!!" << endl;
		std::cout << " 음식 메뉴 : " << guest::choice_menu << endl;
		std::cout << " ========================================= " << endl;
		std::cout << " 주문을 확인하셨으면  y를 입력 해주세요  : ";
		cin >> menu;
		if (menu == "y") {
			std::cout << " 주문을 확인 하셨습니다! " << endl <<endl ; 
			PlaySound(TEXT("접수완료.wav"), NULL, SND_ASYNC);// 일반 소리 재생 
			Sleep(900);
			system("cls");
			std::cout << " 예상 음식 조리 주문시간을 입력해주세요! (분)  :"; 
			cin >> delivery_manegement::store_cooktime; // 정적 주문 시간 static 접근 
				system("color 0e");
				PlaySound(TEXT("조리시작.wav"), NULL, SND_ASYNC);// 일반 소리 재생 
				deliver_console::delivery_man_start(menu2); // 배달 콜로 디스플레이 값 처리 넘기는 호출 함수 
				Sleep(1000);
				break; // 애때문에 종료되고있음 유의! 
		}
		else { std::cout << " 주문을 확인하지 않으셨습니다! 주문을 확인해주세요 !! "; Sleep(900); system("cls");  }
		
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
		system("color 5f"); // 여기서 누구누구님 배달 콜이 도착했습니다로 수정해야할듯  그리고 랜덤으로 배달요금 나오는것도 추가해야할듯 
		PlaySound(TEXT("배달콜.wav"), NULL, SND_ASYNC);// 일반 소리 재생 
		std::cout << " =============================================" << endl;
		std::cout << "   - 배달 콜이 도착하였습니다!!!  확인해주세요!-     " << endl;
		std::cout << "배달원 : " <<temp_name <<"  님  배달을 확인해주세요 !! " << endl; // 여기서 랜덤으로 배달원 이름 호출 해야함 
		std::cout << "배달 주소 : " << guest::get_address() << endl;
		std::cout << "배달 음식 : " << guest::choice_menu << endl;
		std::cout << "배달 수수료 (원) : " <<temp_pay  <<endl; // 배달 수수료 랜덤 호출 
		std::cout << "남은 배달 소요 시간 : " << delivery_manegement::get_total_deliver_time()  << "분 남았습니다. "<< endl;
		std::cout << "================================================" << endl;
		//Beep(269, 500); Beep(294, 500); Beep(450, 500);
		std::cout << " 콜을 잡으실려면 y를 입력해주세요 :  ";
		cin >> menu;
		if (menu == "y") { // 배달 콜을 잡으면 해당 배달원에게 랜덤 호출 이름 뽑아오는애 1개랑 배달원 이름 저장하고 있을애 2개가 필요할듯 
			// 하나는 리스트 , 1개는 지역 변수로 받아서 보여줄애 (랜덤)  , 1개는 콜을 잡으면 개를 배달료 적립시킬 변수 총 안에서 3개가 필요할듯  -> 배달 사람이름 
			// 배달료 저장 하는 배열도 여기서 값을 넣어줘야하네  -> 그사람한테 배달료 넣어 줘야하니까 랜덤 가져오는거 한개 , 애는 총 2개 변수 배달료 가지고와서 디스플레이 , 배달료 적립시킬애하나
			std::cout << " 배달 콜을 잡으셨습니다 !  " << endl << endl;
			std::cout << " 잠시만 기다려 주세요 ..... "; // ->   창 순서가 ->  -> 음식점 픽업 완료 -> 
			bs.get_deliverman_pay(temp_pay,temp_name);
			Sleep(900);
			system("color 0e");
			food_store_cook_finish();
			break;
		}
		else {
			std::cout << " 배달 콜을 잡지 않으셨습니다 ....... 콜 대기 화면 으로 이동 합니다... ";  Sleep(1000); system("cls"); 
			std::cout << "콜 대기중 ";
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
		std::cout << guest::choice_stroe << " 음식점 님 " << guest::choice_menu << "음식 조리가 완료 되었습니까 ?" << endl;
		std::cout << "================================================" << endl;

		std::cout << " 조리를 완료 하셨다면 y 를 입력해주세요 : ";
		cin >> menu;
		if (menu == "y") { 
			system(" cls");
			std::cout << "주문 조리가 완료 되었습니다!! " << endl;
			Sleep(1000);
			deliver_man_pickup();
			break;
		}
		else {
			system("cls");
			std::cout << " =============================================" << endl;
			std::cout << "추가 조리 시간이 더 필요 하십니까 ?? " <<  endl;
			std::cout << "================================================" << endl;
			std::cout << " 필요하시다면  y 를 입력해주세요 : "; cin >> menu;
			if (menu == "y") {
				std::cout << " 얼마나 추가 소요 시간이 필요하십니까?  " << endl << " 추가 소요시간을 입력 해주세요 :  "; 
				cin >> menu2;
				delivery_manegement::total_deliver_plus_time = delivery_manegement::total_deliver_plus_time +  menu2;
				system("cls");
				std::cout << " 총 : " << delivery_manegement::total_deliver_plus_time << " (분) 남았습니다 주문을 서둘러 주세요 ! " << endl; 
				
			}
			else {
				std::cout << delivery_manegement::total_deliver_plus_time << " ( 분) 남았습니다 " << endl <<"조리가 완료 되지 않았습니다... 서둘러 주세요 !! " << endl; Sleep(1000); system("cls");
			}
			
		}
	}
}

void deliver_console::deliver_man_pickup() {
	while (true) {
		string menu;
		system("cls");
		std::cout << " =============================================" << endl;
		std::cout << delivery_manegement::get_deliver_name_check() << " 배달원님 음식조리가 완료 되었습니다! 음식을 픽업 해주세요 !! " << endl;
		std::cout << "================================================" << endl;
		std::cout << " 음식을 픽업  하셨다면 y 를 입력해주세요 : ";
		cin >> menu;
		if (menu == "y") {
			system(" cls");
			std::cout << delivery_manegement::get_deliver_name_check() << " 배달원님의 픽업이 완료되었습니다! " << endl;
			Sleep(1000);
			food_store_pickup();
			break;
		}
		else {
			system("cls");
			std::cout << delivery_manegement::get_deliver_name_check() << " 픽업은 미룰수가 없습니다 픽업을 진행 하여 주세요 !! " << endl;
			Sleep(1000);

			}
	}
}
void deliver_console::food_store_pickup() {
	while (true) {
		string menu;
		system("cls");
		std::cout << " =============================================" << endl;
		std::cout << guest::choice_stroe << " 음식점 님 " << guest::choice_menu << "메뉴를 "  << endl;
		std::cout << " 배달 기사가 음식 픽업을 완료 하였습니다! " << endl;
		std::cout << "================================================" << endl;
		std::cout << " 픽업을 확인하셨다면  y 를 입력해주세요 : ";
		cin >> menu;
		if (menu == "y") {
			system(" cls");
			std::cout << " 배달원님의 픽업이 확인 되었습니다 !  " << endl;
			Sleep(1000);
			deliver_finish();
			break;
		}
		else {
			system("cls");
			std::cout << " 배달원 이름 : " << delivery_manegement::get_deliver_name_check() << " 배달원을 호출 합니다! " << endl;
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
		std::cout << delivery_manegement::get_deliver_name_check() << "배달 기사님!  음식 배달을 완료 하셨나요?? " << endl;
		std::cout << "배달 소요시간이 : "<< delivery_manegement::total_deliver_plus_time  << " (분) 남았습니다! "<< endl;
		std::cout << "================================================" << endl;
		std::cout << " 배달을 완료 하셨다면  y 를 입력해주세요 : ";
		cin >> menu;
		if (menu == "y") {
			system(" cls");
			std::cout << " 배달이 완료 되었습니다 !  " << endl;
			Sleep(1000);
			food_store_finishcall();
			break;
		}
		else {
			system("cls");
			std::cout << delivery_manegement::get_deliver_name_check() <<" 배달원님!!  " << "  배달을 서둘러 주세요 !  " << endl;
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
		std::cout << guest::choice_stroe << "음식점님 ! " << endl << guest::choice_menu << "음식 배달이 완료 되었습니다 ! " << endl;
		std::cout << "================================================" << endl;
		std::cout << " 확인 하셨다면  y 를 입력해주세요 : ";
		cin >> menu;
		if (menu == "y") {
			system(" cls");
			std::cout << " 배달처리가  완료 되었습니다 !  " << endl;
			PlaySound(TEXT("배달완료.wav"), NULL, SND_ASYNC);// 일반 소리 재생 
			Sleep(1000);
			total_star_finish();
			break;
		}
		else {
			system("cls");
			std::cout << guest::choice_stroe << " 음식점님! 배달 민원 발생시 고객센터로 통화 부탁드립니다!    " << endl << " TEL : 080 -0000 -0000  입니다 . 감사합니다! " << endl;
			Sleep(1300);
		}
	}
}
void deliver_console::total_star_finish() {
	while (true) {
		int menu;
		system("cls");
		std::cout << " =============================================" << endl;
		std::cout << guest::choice_stroe << " 음식점에서  " << guest::choice_menu << " 음식 메뉴를 주문하신 고객님!! " << endl;
		std::cout << " 배달이 완료 되었습니다!!  간단한 아래 만족도조사를 해주세요! " << endl;
		std::cout << "================================================" << endl;
		std::cout << "     - 별점은 1 ~ 5점 만점입니다 ! -  " << endl;
		std::cout << guest::choice_stroe << "음식점에 대한 만족도는 어떠 셨습니까? ";
		cin >> menu;
		delivery_system::set_food_star(menu);
		std::cout << " 배달원에 대한 만족도는 어떠 셨습니까 ? ";
		cin >> menu;
		delivery_system::set_deliver_star(menu);
		Sleep(1600);
		std::cout << " 만족도 참여도에 참여해주셔서 감사합니다 ! ";
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
		std::cout << " 배달원 평점 페이지입니다  아래는 현재까지 배달원의 누적 평점 현황 입니다. " << endl;
		std::cout << " 배달원의 평점에 따라 배달 수수료가 차등 지급 됩니다 !  " << endl;
		std::cout << "================================================" << endl;
		std::cout << "  배달원  평점 현황  " << endl;
		for (int te1 = 0; te1 <= 7; te1++) {
		std::cout << " " << hi.get_deliver_man_list(&te1) <<  "  " ;
		}
		std::cout << endl << endl;
		std::cout << "       배달원  평점 현황 단위 : (점)  " << endl<<endl;
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
		std::cout << " 음식점 평점 페이지입니다  아래는 현재까지 음식점의 누적 평점 현황 입니다. " << endl;
		std::cout << "================================================" << endl;
		std::cout << "  음식점   평점 현황  " << endl;
		std::cout << endl;
		std::cout << "               -  한식집  - " << endl;
		std::cout << endl; 
		for (int te = 0; te <= 7; te++) {
			std::cout << "   "<< test.stor_menu[te] << "      ";
		}
		std::cout << endl << endl;
		for (int te2 = 0; te2 <= 3; te2++) {
			std::cout << "       " << delivery_system::get_total_food_star(te2)<< "                  ";
		}
		std::cout << endl;
		std::cout << "               -  양식집  - " << endl;
		std::cout << endl;
		for (int te3 = 0; te3 <= 2; te3++) {
			std::cout << "   " << wesa.stor_menu[te3] << "         ";
		}
		std::cout << endl << endl<<endl;
		for (int te4 = 4; te4 <= 6; te4++) {
			std::cout << "       " << delivery_system::get_total_food_star(te4) << "                ";
		}
		std::cout << endl << endl << endl;
		std::cout << "               -  중식집  - " << endl;
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
	deliveryman ta[3];// 객체 배열 
	deliveryman* tes;// 객체 포인터
	deliveryman hi;
	delivery_manegement fd;
	tes = ta; // 객체 포인터 초기화 
	while (true) {
		int menu;
		system("cls");
		std::cout << " =============================================" << endl;
		std::cout << " 배달원 배달료 페이지입니다  아래는 현재까지 배달원의 누적 배달료 현황 입니다. " << endl;
		std::cout << " 배달원의 평점에 따라 배달 수수료가 차등 지급 됩니다 !  " << endl;
		std::cout << "================================================" << endl;
		std::cout << "  배달원  배달료 현황  " << endl;
		for (int te1 = 0; te1 <= 7; te1++) { // 배달원 이름 호출 
			std::cout << " " << tes->get_deliver_man_list(&te1) << "  "; // 객체 포인터를 통한 호출 
			// 안되면 이거 제거 
		}
		std::cout << endl << endl;
		for (int te2 = 0; te2 <= 7; te2++) {
			std::cout << "   " << fd.get_deliverman_pay(te2) << "     ";
		}
		std::cout << "       배달원  배달료 현황 단위 : (원)  " << endl << endl;
		Sleep(3000);
		std::cout << endl << endl;
		std::cout << "       배달원  평점 현황 단위 : (점)  " << endl << endl;
		for (int te2 = 0; te2 <= 7; te2++) {
			std::cout << "   " << delivery_system::get_total_deliver_star(te2) << "      ";
		}
		Sleep(3000);
		break;
	}

}

void deliver_console::admin_deliver_totalsystem() { // 최종 지급 페이지 
	deliveryman hi;
	delivery_manegement fd;
	delivery_system a;
	delivery_manegement b;
	while (true) {
		int menu;
		system("cls");
		std::cout << " =============================================" << endl;
		std::cout << " 배달원 배달료 지급 페이지입니다  아래는 현재까지 배달원의 누적 배달료 현황 입니다. " << endl;
		std::cout << " 배달원의 평점에 따라 배달 수수료가 차등 지급 됩니다 !  " << endl;
		std::cout << "================================================" << endl;
		std::cout << "                        배달원  배달료 현황  " << endl;
		for (int te1 = 0; te1 <= 7; te1++) { // 배달원 리스트 
			std::cout << " " << hi.get_deliver_man_list(&te1) << "  ";
		}
		std::cout << endl << endl;
		for (int te2 = 0; te2 <= 7; te2++) {
			std::cout << "   " << fd.get_deliverman_pay(te2) << "     ";
		}
		std::cout << endl << endl;
		std::cout << "                      최종  배달원 (평점 반영)  배달료 지급 완료 금액 ! : (원)  " << endl << endl;
		delivery_manegement::total_last_deliver_pay();
		Sleep(6500);
		cout << "                           최종 지급이 완료 되었습니다!!!!            " << endl  << endl ;
		cout <<  "  (주의) : !!    지급이 완료 되었으므로   전체 배달료 와 평점이  초기화 됩니다  !! " << endl << endl;
		b.arr_reset();// 배달료 초기화 
		a.deliver_start_clear();
		a.foodstore_star_clear();
		for (int i = 0; i <= 18; i++) { // 에러 코드 관련 메인 초기 화 
			a.first_run_count[i] = 0;
		}
		Sleep(1500);
		break;
	}

}
int deliver_console::admin_menu = 0;



