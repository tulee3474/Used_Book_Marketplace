#include "Login.h"

Login::Login() {
	power = true;
}

Login::~Login() {

}

int Login::LoginUI() {
	string id, password, name, phoneNum, email;
	

	system("cls");
	cout << "###  Used - Book MarketPlace  ###" << endl;
	cout << "###  Made by. 20184165 이태운 ###" << endl << endl;
	cout << "1. Login" << endl;
	cout << "2. Sign up" << endl;
	cout << "0. Exit" << endl;
	cout << "Select Menu : ";

	cin >> menu;
	//while (getchar() != '\n');

	switch (menu)
	{
	case 1:                 //로그인
		system("cls");
		cout << "### Login ###" << endl << endl;
		cout << "ID : ";
		cin >> id;
		cout << endl << "Password : ";
		cin >> password;
		user = CheckUser(id, password);
		power = false;
		return user;		//유저 정보 리턴하고 파워 끔
	case 2:					//사용자 등록(회원가입)
		system("cls");
		cout << "### Sign Up ###" << endl << endl;
		cout << "ID : ";
		cin >> id;
		cout << endl << "Password : ";
		cin >> password;
		cout << endl << "Name : ";
		cin >> name;
		cout << endl << "Phone Number : ";
		cin >> phoneNum;
		cout << endl << "E-Mail : ";
		cin >> email;
		SignUp(id, password, name, phoneNum, email);

		break;
	case 0:					//종료
		power = false;
		return -1;
	default:
		return -1;
	}

	


}

int Login::CheckUser(string id, string password) {
	
	if (id.compare("admin") == 0 && password.compare("nayana") == 0)
		return 0;

	int i = 0;
	string r_id, r_password;

	ifstream inFile("Users.txt");

	while (!inFile.eof()) {

		char inputLine[200] = { 0, };
		inFile.getline(inputLine, 200);

		if (inputLine[0] == NULL) { break; }
		r_id = strtok(inputLine, "/");
		r_password = strtok(NULL, "/");

		if (id.compare(r_id) == 0 && password.compare(r_password) == 0) {
			inFile.close();
			return i;
		}
			
		i++;
	}
	cout << "Login error. Exit Program...";
	Sleep(2000);

	inFile.close();
	exit(0);
}

void Login::SignUp(string id, string password, string name, string phoneNum, string email) {

	ofstream outFile("Users.txt", ios::app);
	outFile << id << "/" << password << "/" << name << "/" << phoneNum << "/" << email << "/" << "true" <<endl;
	outFile.close();
}


bool Login::CheckPower() {
	return power;
}