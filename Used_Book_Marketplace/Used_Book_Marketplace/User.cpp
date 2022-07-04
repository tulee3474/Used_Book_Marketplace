#include "User.h"

User::User(string id, string password, string name, string phoneNum, string email, bool activate) {
	this->id = id;
	this->password = password;
	this->name = name;
	this->phoneNum = phoneNum;
	this->email = email;
	this->activate = activate;

	power = true;
}

User::~User() {

}

string User::GetID()
{
	return id;
}

string User::GetPassword()
{
	return password;
}

string User::GetName() {
	return name;
}

string User::GetPhoneNum() {
	return phoneNum;
}

string User::GetEmail() {
	return email;
}

bool User::GetActivate() {
	return activate;
}

void User::ChangeAct() {
	if (activate)
		activate = false;
	else
		activate = true;
}


void User::UserUI() {

	if (BookList.empty())
		ReadBookList();		//책 목록 불러오기

	system("cls");
	cout << "###" << name << "- main  ###" << endl << endl;
	cout << "1. Book purchase" << endl;
	cout << "2. Book registration" << endl;
	cout << "3. Book management" << endl;
	cout << "0. Exit" << endl;
	cout << "Select Menu : ";

	cin >> menu;
	while (getchar() != '\n');

	switch (menu)
	{
	case 1:                 //책 구매

		BookPurchaseUI();	//책 구매 화면

		break;
	case 2:                 //책 등록

		BookRegistrationUI();		//책 등록 화면

		break;
	case 3:					//책 관리

		BookManageUI();		//책 관리 화면

		break;
	case 0:					//종료
		power = false;
		return;
	default:
		return;
	}
}

void User::BookPurchaseUI() {

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
		WriteBookList();
		return;
	default:

		return;
	}

	SearchBookUI(search);
	WriteBookList();

	return;

}

void User::BookRegistrationUI() {

	string  r_title, r_ISBN, r_author, r_publishHouse, r_publishYear, r_price, r_condition;
	int price = NULL;
	int condition = NULL;

	system("cls");
	cout << "### Book Registration ###" << endl << endl;
	while (1) {
		cout << "Title : ";
		getline(cin, r_title);;
		if (!r_title.empty())
			break;
	}
	cout << endl << "ISBN : ";
	getline(cin, r_ISBN);;
	cout << endl << "Publish House : ";
	getline(cin, r_publishHouse);;
	cout << endl << "Author : ";
	getline(cin, r_author);
	cout << endl << "Publish Year : ";
	getline(cin, r_publishYear);
	cout << endl << "Price : ";
	getline(cin, r_price);
	if (r_price.compare("") != 0)
		price = stoi(r_price);
	else
		price = -1;
	cout << endl << "Condition (1 - Excellent, 2 - Good, 3 - Fair) : ";
	getline(cin, r_condition);
	if (r_condition.compare("") != 0)
		condition = stoi(r_condition);

	Book book(id, r_title, r_ISBN, r_author, r_publishHouse, r_publishYear, email, price, condition);
	BookList.push_back(book);
	book.~Book();

	WriteBookList();

	cout << endl << "Registration Complete ";
	Sleep(2000);
}

void User::BookManageUI() {
	
	int a, menu2;
	vector<int> check;
	vector<int>::iterator iter;

	while (1) {

		system("cls");
		cout << "### My Books ###" << endl << endl;
		cout << "***************************************************************" << endl;

		for (int num = 0; num < BookList.size(); num++) {
			if (BookList.at(num).GetUserID().compare(id) == 0) {

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
					cout << "Excellent" << endl;
				else if (BookList.at(num).GetCondition() == 2)
					cout << "Good" << endl;
				else if (BookList.at(num).GetCondition() == 3)
					cout << "Fair" << endl;
				else
					cout << endl;
				cout << "|************|**********************************************" << endl;

				check.push_back(num);
			}
	}

	
		cout << endl;
		cout << "1. Modify book" << endl;
		cout << "2. Delete book" << endl;
		cout << "0. Save & Exit" << endl;
		cout << "Select menu : ";

		cin >> menu2;

		switch (menu2) {
		case 1:
			cout << endl << "Book to modify : ";
			cin >> a;

			iter = find(check.begin(), check.end(), a);

			if (iter != check.end()) {

				BookModifyUI(&BookList.at(a));
				cout << "Modify Complete";
				Sleep(2000);

				break;
			}
			else {
				cout << "Wrong book number";
				Sleep(2000);
			}
			break;

		case 2:
			cout << endl << "Book to delete : ";
			cin >> a;

			iter = find(check.begin(), check.end(), a); 
			
			if (iter != check.end()) {
				BookList.erase(BookList.begin() + a);
				cout << "Delete Complete";
				Sleep(2000);
				break;
			}
			else {
				cout << "Wrong book number";
				Sleep(2000);
			}

			break;

		case 0:
			WriteBookList();
			return;

		default:
			continue;
		}
		WriteBookList();
	}

}

void User::BookModifyUI(Book *book) {

	int menu2 = -1, input2 = 0;
	string input;

	system("cls");
	cout << "### Book Modify - "<< book->GetTitle() << " ###" << endl << endl;
	cout << "1. Title" << endl;
	cout << "2. ISBN" << endl;
	cout << "3. Author" << endl;
	cout << "4. Publish House" << endl;
	cout << "5. Publish Year" << endl;
	cout << "6. Price" << endl;
	cout << "7. Condition" << endl;
	cout << "0. Save & Exit" << endl;
	cout << "Modify by : ";

	cin >> menu2;
	while (getchar() != '\n');

	switch (menu2)
	{
	case 1:
		while (1) {
			cout << "Title : ";
			getline(cin, input);;
			if (!input.empty())
				break;
		}

		book->Set_and_Modify(id, input, book->GetISBN(), book->GetAuthor(), book->GetPublishHouse(), book->GetPublishYear(), email, book->GetPrice(), book->GetCondition());

		break;
	case 2:

		cout << endl << "ISBN : ";
		getline(cin, input);;
		
		

		book->Set_and_Modify(id, book->GetTitle(), input, book->GetAuthor(), book->GetPublishHouse(), book->GetPublishYear(), email, book->GetPrice(), book->GetCondition());


		break;
	case 3:

		cout << "Author : ";
		getline(cin, input);;

		book->Set_and_Modify(id, book->GetTitle(), book->GetISBN(), input, book->GetPublishHouse(), book->GetPublishYear(), email, book->GetPrice(), book->GetCondition());


		break;
	case 4:

		cout << "Publish House : ";
		getline(cin, input);;


		book->Set_and_Modify(id, book->GetTitle(), book->GetISBN(), book->GetAuthor(), input, book->GetPublishYear(), email, book->GetPrice(), book->GetCondition());


		break;
	case 5:

		cout << "Publish Year : ";
		getline(cin, input);;


		book->Set_and_Modify(id, book->GetTitle(), book->GetISBN(), book->GetAuthor(), book->GetPublishHouse(), input, email, book->GetPrice(), book->GetCondition());


		break;
	case 6:

		cout << "Price : ";

		getline(cin, input);
		if (input.compare("") != 0)
			input2 = stoi(input);
		else
			input2 = -1;

		book->Set_and_Modify(id, book->GetTitle(), book->GetISBN(), book->GetAuthor(), book->GetPublishHouse(), book->GetPublishYear(), email, input2, book->GetCondition());


		break;
	case 7:

		cout << "Condition (1 - Excellent, 2 - Good, 3 - Fair) : ";

		getline(cin, input);
		if (input.compare("") != 0)
			input2 = stoi(input);

		book->Set_and_Modify(id, book->GetTitle(), book->GetISBN(), book->GetAuthor(), book->GetPublishHouse(), book->GetPublishYear(), email, book->GetPrice(), input2);


		break;
	case 0:
		WriteBookList();
		return;
	default:

		return;
	}
	WriteBookList();

	return;

}

void User::SearchBookUI(string search) {

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

	while (1) {
		cout << endl << "Book to purchase : ";
		cin >> a;

		iter = find(check.begin(), check.end(), a);

		if (iter != check.end()) {
			cout << endl << "Your mail has been sent." << endl << "from. " << this->email << endl << "to. " << BookList.at(a).GetEmail() << endl;
			Sleep(3000);
			break;
		}
		else {
			cout << "Wrong book number";
		}
	}

	return;
}

void User::ReadBookList() {

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

void User::WriteBookList() {
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

bool User::CheckPower() {
	return power;
}