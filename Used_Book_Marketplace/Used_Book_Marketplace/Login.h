#pragma once
#pragma warning (disable:4996)

#include <iostream>
#include <fstream>
#include <Windows.h>


using namespace std;

class Login {
private:
	int menu = -1;
	int user = -1;

	bool power = false;
public:
	Login();
	~Login();
	
	int LoginUI();

	int CheckUser(string id, string password);

	void SignUp(string id, string password, string name, string phoneNum, string email);

	bool CheckPower();

};
