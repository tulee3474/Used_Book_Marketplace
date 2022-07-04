#include "Admin.h"

Admin::Admin() {
	power = true;
}

Admin::~Admin() {

}

void Admin::AdminUI() {

	if (UserList.empty()) {
		ReadUserList();		//유저 목록 불러오기
		ReadBookList();		//책 목록 불러오기

	}

	system("cls");
	cout << "###  Admin - main  ###" << endl << endl;
	cout << "1. User management" << endl;
	cout << "2. Book management" << endl;
	cout << "0. Exit" << endl;
	cout << "Select Menu : ";

	cin >> menu;
	//while (getchar() != '\n');

	switch (menu)
	{
	case 1:                 //사용자 관리

		UserManageUI();		//사용자 관리 화면
		
		break;
	case 2:					//책 관리
		
		BookManageUI();		//책 관리 화면

		break;
	case 0:					//종료
		power = false;
		return;
	default:
		return;
	}
}

void Admin::UserManageUI() {

	int user_manage_menu = -1;


	while (1) {

		int a;

		system("cls");
		cout << "### User management ###" << endl << endl;
		cout << "************************************************************" << endl;
		 
		for (int num = 0; num < UserList.size(); num++) {
			cout << num + 1 << ".";
			cout.width(10);
			cout.fill(' ');
			cout << UserList.at(num).GetName();
			cout.width(15);
			cout.fill(' ');
			cout << UserList.at(num).GetPhoneNum();
			cout.width(15);
			cout.fill(' ');
			cout << UserList.at(num).GetEmail();
			cout.width(12);
			cout.fill(' ');
			if (UserList.at(num).GetActivate())
				cout << "activated" << endl;
			else
				cout << "deactivated" << endl;
			cout << "|************|**********************************************" << endl;
		}

		cout << endl << "1. Change User's Act" << endl;
		cout << "2. Delete User" << endl;
		cout << "0. Save & Exit" << endl;
		cout << "Select Menu : ";

		cin >> user_manage_menu;
		//while (getchar() != '\n');

		switch (user_manage_menu) {
		case 1:
			cout << endl << "User to change act : " ;
			cin >> a;
			UserList.at(a - 1).ChangeAct();

			break;

		case 2:
			cout << endl << "User to delete : ";
			cin >> a;
			
			if (UserList.at(a - 1).GetActivate()) {

				for (int num = 0; num < BookList.size(); num++) {
					if (BookList.at(num).GetUserID().compare(UserList.at(a - 1).GetID()) == 0)
						BookList.erase(BookList.begin() + num);

				}
				
				UserList.erase(UserList.begin() + a - 1);

				
			}
			else {
				cout << "User's activate is activated";
				Sleep(2000);
			}


			break;

		case 0:
			WriteUserList();
			WriteBookList();
			return;
		default:
			continue;
		}
	}
}

void Admin::BookManageUI() {

	string search;

	system("cls");
	cout << "### Book management ###" << endl << endl;
	cout << "1. Title" << endl;
	cout << "2. ISBN" << endl;
	cout << "3. Author" << endl;
	cout << "4. Publish House" << endl;
	cout << "5. Publish Year" << endl;
	cout << "6. User ID" << endl;
	cout << "0. Save & Exit" << endl;
	cout << "Search by : ";

	cin >> menu;

	switch (menu)
	{
	case 1:                 

		cout << "Title : ";

		cin >> search;

		break;
	case 2:					

		cout << "ISBN : ";

		cin >> search;

		break;
	case 3:					

		cout << "Author : ";

		cin >> search;

		break;
	case 4:

		cout << "Publish House : ";

		cin >> search;

		break;
	case 5:

		cout << "Publish Year : ";

		cin >> search;

		break;
	case 6:					

		cout << "User ID : ";

		cin >> search;

		break;
	case 0:
		WriteUserList();
		WriteBookList();
		return;
	default:

		return;
	}

	SearchBookUI(search);
	WriteUserList();
	WriteBookList();

	return;

}


void Admin::ReadUserList() {

	int i = 0;
	string r_id, r_password, r_name, r_phoneNum, r_email, r_activate;
	bool activate;

	ifstream inFile("Users.txt");

	while (!inFile.eof()) {

		char inputLine[200] = { 0, };
		inFile.getline(inputLine, 200);

		if (inputLine[0] == NULL) { break; }

		if (i == 0) {				// 0은 관리자 정보
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

			User user(r_id, r_password, r_name, r_phoneNum, r_email, activate);
			UserList.push_back(user);
			user.~User();
		}

		i++;
	}

	inFile.close();
}

void Admin::WriteUserList() {
	int i = 0;

	ofstream outFile("Users.txt");

	outFile << "admin/nayana/이태운/01032223474/tulee3474@naver.com/true" << endl;

	for (int i = 0; i < UserList.size(); i++) {
		outFile << UserList.at(i).GetID() << "/";
		outFile << UserList.at(i).GetPassword() << "/";
		outFile << UserList.at(i).GetName() << "/";
		outFile << UserList.at(i).GetPhoneNum() << "/";
		outFile << UserList.at(i).GetEmail() << "/";

		if (UserList.at(i).GetActivate())
			outFile << "true" << endl;
		else
			outFile << "false" << endl;
	}
	outFile.close();
}

void Admin::ReadBookList() {

	int i = 0;
	string r_userID, r_title, r_ISBN, r_author, r_publishHouse, r_publishYear, r_condition, r_email;
	int price, condition;

	ifstream inFile("Books.txt");

	while (!inFile.eof()) {

		char inputLine[200] = { 0, };
		inFile.getline(inputLine, 200);

		if (inputLine[0] == NULL) { break; }

		r_userID = strtok(inputLine, "/");
		r_title = strtok(NULL, "/");
		r_ISBN = strtok(NULL, "/");
		r_author = strtok(NULL, "/");
		r_publishHouse = strtok(NULL, "/");
		r_publishYear = strtok(NULL, "/");
		r_email = strtok(NULL, "/");
		price = atoi(strtok(NULL, "/"));
		condition = atoi(strtok(NULL, "/"));

		Book book(r_userID, r_title, r_ISBN, r_author, r_publishHouse, r_publishYear, r_email, price, condition);
		BookList.push_back(book);
		book.~Book();

		i++;
	}

	inFile.close();
}

void Admin::WriteBookList() {
	int i = 0;

	ofstream outFile("Books.txt");

	for (int i = 0; i < BookList.size(); i++) {
		outFile << BookList.at(i).GetUserID() << "/";
		outFile << BookList.at(i).GetTitle() << "/";
		if (BookList.at(i).GetISBN().compare("") == 0)
			outFile << " ";
		outFile << BookList.at(i).GetISBN() << "/";
		if (BookList.at(i).GetAuthor().compare("") == 0)
			outFile << " ";
		outFile << BookList.at(i).GetAuthor() << "/";
		if (BookList.at(i).GetPublishHouse().compare("") == 0)
			outFile << " ";
		outFile << BookList.at(i).GetPublishHouse() << "/";
		if (BookList.at(i).GetPublishYear().compare("") == 0)
			outFile << " ";
		outFile << BookList.at(i).GetPublishYear() << "/";
		outFile << BookList.at(i).GetEmail() << "/";
		outFile << BookList.at(i).GetPrice() << "/";
		outFile << BookList.at(i).GetCondition() << endl;
	}
	outFile.close();
}

void Admin::SearchBookUI(string search) {

	int a;
	vector<int> check;
	vector<int>::iterator iter;

	system("cls");
	cout << "### Search results ###" << endl << endl;
	cout << "***************************************************************" << endl;

	for (int num = 0; num < BookList.size(); num++) {
		if (!(BookList.at(num).GetTitle().find(search) == string::npos) && menu == 1) {
		}
		else if (!(BookList.at(num).GetISBN().find(search) == string::npos) && menu == 2) {
		}
		else if (!(BookList.at(num).GetAuthor().find(search) == string::npos) && menu == 3) {
		}
		else if (!(BookList.at(num).GetPublishHouse().find(search) == string::npos) && menu == 4) {
		}
		else if (!(BookList.at(num).GetPublishYear().find(search) == string::npos) && menu == 5) {
		}
		else if (!(BookList.at(num).GetUserID().find(search) == string::npos) && menu == 6) {
		}
		else
			continue;

		cout << num << ".";
		cout.width(10);
		cout.fill(' ');
		cout << BookList.at(num).GetTitle();
		cout.width(12);
		cout.fill(' ');
		cout << BookList.at(num).GetPublishHouse();
		cout.width(12);
		cout.fill(' ');
		cout << BookList.at(num).GetAuthor();
		cout.width(7);
		cout.fill(' ');
		cout << BookList.at(num).GetPublishYear();
		cout.width(7);
		cout.fill(' ');
		if (BookList.at(num).GetPrice() >= 0)
			cout << BookList.at(num).GetPrice();
		cout.width(11);
		cout.fill(' ');
		if (BookList.at(num).GetCondition() == 1)
			cout << "Excellent";
		else if (BookList.at(num).GetCondition() == 2)
			cout << "Good";
		else if (BookList.at(num).GetCondition() == 3)
			cout << "Fair";
		cout.width(20);
		cout.fill(' ');
		cout << BookList.at(num).GetISBN() << endl;
		cout << "|************|*************************************************" << endl;

		check.push_back(num);

	}

	while(1){
		cout << endl << "Book to delete : ";
		cin >> a;
		
		iter = find(check.begin(), check.end(), a);
	
		if (iter != check.end()) {
			BookList.erase(BookList.begin() + a);
			break;
		}
		else {
			cout << "Wrong book number";
		}
	}

	return;
}

bool Admin::CheckPower() {
	return power;
}