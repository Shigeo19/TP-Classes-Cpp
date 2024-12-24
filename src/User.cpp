#include <iostream>
#include <stdlib.h>
#include <string>
#include "User.h"
using namespace std;

User::User(string user,
		   string pwd,
		   string fname,
		   string lname,
		   string email,
		   string addr) {

	this->username = user;
	this->password = pwd;
	this->firstName = fname;
	this->lastName = lname;
	this->email = email;
	this->adress = addr;
}

User::User(string user,
		   string email,
		   string pwd) {

	this->username = user;
	this->password = pwd;
	this->email = email;
}

string User::getUsername(){
	return this->username;
}

void User::setUsername(string username){
	this->username = username;
}

string User::getEmail() {
	return this->email;
}

string User::getPassword() {
	return this->password;
}

void User::setSession(bool state) {
	this->session = state;
}

bool User::getSession() {
	return this->session;
}


virtual string User::getHiddenEmail(){
	string hiddenEmail;
	string email = this->email;

	for (size_t i=0; i < email.length(); i++)
	{
		char c = email.at(i);
		if (i<4 || i >= email.length()-4)
		{
			hiddenEmail.append(1,c);
		}

		else
		{
			hiddenEmail.append(1,'*');
		}
	}
	return hiddenEmail;
}


void User::setPassword(string password){
	if (password.size() >= 8)
	{
		int existMaj = 0;
		int existMin = 0;
		int existChif = 0;
		int existCaraSpec = 0;

		for (size_t i=0; i<password.length(); i++)
		{
			char c = password.at(i);
			if (c<=90 && c>=65) {
				existMaj = 1;
			} else if (c<=122 && c>=97) {
				existMin = 1;
			} else if (c<=57 && c>=48) {
				existChif = 1;
			} else {
				existCaraSpec = 1;
			}
		}
		if (existMaj ==1 && existMin ==1 && existCaraSpec ==1 && existChif ==1)
		{
			this->password = password;
		}
	}
}

virtual void User::setEmail(string email) {
	this->email = email;
}


virtual string User::printUserDetails() {
	return this->username + "\n" + this->firstName + " \n"  + this->lastName + " \n" + this->email + "\n" + this->adress;
}


