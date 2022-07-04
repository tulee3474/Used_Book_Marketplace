#include <iostream>
#include <fstream>
#include <Windows.h>

#include "Login.h"
#include "Admin.h"

using namespace std;

int main() {
	
	//로그인 화면

	Login login;
	int user = -1;			// 0 = 관리자, 1~ = 사용자

	while (1) {
		user = login.LoginUI();
		if (!login.CheckPower())
			break;
	}
	login.~Login();


	//메인 화면

	if (user == 0) {		//관리자 메인 화면
		Admin admin;

		while (1) {
			admin.AdminUI();
			if (!admin.CheckPower())
				break;
		}
		admin.~Admin();
	}
	else if (user > 0) {	//사용자 메인 화면
		int i = 0;
		string r_id, r_password, r_name, r_phoneNum, r_email, r_activate;
		bool activate;

		ifstream inFile("Users.txt");

		while (!inFile.eof()) {

			char inputLine[200] = { 0, };
			inFile.getline(inputLine, 200);

			if (inputLine[0] == NULL) { break; }

			if (i < user) {
				i++;
				continue;
			}
			else {
				r_id = strtok(inputLine, "/");
				r_password = strtok(NULL, "/");
				r_name = strtok(NULL, "/");
				r_phoneNum = strtok(NULL, "/");
				r_email = strtok(NULL, "/");
				r_activate = strtok(NULL, "/");

				if (r_activate.compare("true") == 0)
					activate = true;
				else
					activate = false;

				break;
			}
		}
		
		User user(r_id, r_password, r_name, r_phoneNum, r_email, activate);
		inFile.close();

		if (user.GetActivate()) {
			while (1) {
				user.UserUI();
				if (!user.CheckPower())
					break;
			}
			user.~User();
		}
		else {
			cout << "Your ID is deactivated";
			Sleep(2000);
			return 0;
		}

		

		//act가 비활성화이면 로그인 안됨!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}








	return 0;
}