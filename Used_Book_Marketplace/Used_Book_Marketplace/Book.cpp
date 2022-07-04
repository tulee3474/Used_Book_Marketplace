#include "Book.h"

Book::Book(string userID, string title, string ISBN, string author, string publishHouse, string publishYear, string email, int price, int condition){
	Set_and_Modify(userID, title, ISBN, author, publishHouse, publishYear, email, price, condition);
}

Book::~Book() {

} 

void Book::Set_and_Modify(string userID, string title, string ISBN, string author, string publishHouse, string publishYear, string email, int price, int condition) {
	this->userID = userID;
	this->title = title;
	this->ISBN = ISBN;
	this->author = author;
	this->publishHouse = publishHouse;
	this->publishYear = publishYear;
	this->email = email;
	this->price = price;
	this->condition = condition;
}

string Book::GetUserID() {
	return userID;
}

string Book::GetTitle() {
	return title;
}

string Book::GetISBN() {
	return ISBN;
}

string Book::GetAuthor() {
	return author;
}

string Book::GetPublishHouse() {
	return publishHouse;
}

string Book::GetPublishYear() {
	return publishYear;
}

string Book::GetEmail() {
	return email;
}

int Book::GetPrice() {
	return price;
}

int Book::GetCondition() {
	return condition;
}