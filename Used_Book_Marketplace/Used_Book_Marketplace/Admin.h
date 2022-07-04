#pragma once
#pragma warning (disable:4996)

#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>

#include "User.h"
#include "Book.h"

using namespace std;

class Admin {
private:
	int menu = -1;
	
	vector<User> UserList;
	vector<Book> BookList;

	bool power = false;

public:
	Admin();
	~Admin();

	void AdminUI();

	void UserManageUI();

	void BookManageUI();

	void ReadUserList();

	void WriteUserList();

	void ReadBookList();

	void WriteBookList();

	void SearchBookUI(string search);

	bool CheckPower();
};
