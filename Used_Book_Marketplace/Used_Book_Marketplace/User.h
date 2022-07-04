#pragma once
#pragma warning (disable:4996)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

#include "Book.h"


using namespace std;

class User {
private:
	string id;
	string password;
	string name;
	string phoneNum;
	string email;
	bool activate;

	int menu = -1;

	vector<Book> BookList;

	bool power = false;
public:
	User(string id, string password, string name, string phoneNum, string email, bool activate);
	~User();

	string GetID();

	string GetPassword();

	string GetName();

	string GetPhoneNum();

	string GetEmail();

	bool GetActivate();

	void ChangeAct();

	void UserUI();

	void BookPurchaseUI();

	void BookRegistrationUI();

	void BookManageUI();

	void BookModifyUI(Book *book);

	void SearchBookUI(string search);

	void ReadBookList();

	void WriteBookList();

	bool CheckPower();


};
