#pragma once
#include <iostream>


using namespace std;

class Book {
private:
	string userID;
	string title;
	string ISBN;
	string author;
	string publishHouse;
	string publishYear;
	string email;
	int price;
	int condition;		//1 - Excellent, 2 - Good, 3 - Fair
public:
	Book(string userID, string title, string ISBN, string author, string publishHouse, string publishYear, string email, int price, int condition);
	~Book();

	void Set_and_Modify(string userID, string title, string ISBN, string author, string publishHouse, string publishYear, string email, int price, int condition);

	string GetUserID();

	string GetTitle();
	
	string GetISBN();

	string GetAuthor();

	string GetPublishHouse();

	string GetPublishYear();

	string GetEmail();

	int GetPrice();

	int GetCondition();



};
