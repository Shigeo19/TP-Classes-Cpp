#include <iostream>
#include "User.h"
using namespace std;

User::User(string user,
		string pwd,
		string fname,
		string lname,
		string email,
		string addr,
		string session) {

	this->username = user;
	this->password = pwd;
	this->firstName = fname;
	this->lastName = lname;
	this->email = email;
	this->adress = addr;
	this->session = session;
}

string User::getEmail() {
	return this->email;
}

string User::getPassword() {
	return this->password;
}

string User::getHiddenEmail(){
	string hiddenEmail;
	string email = this->email;

	for (int i=0; i<email.size(); i++)
	{
		char c = email.at(i);
		if (i<4 || i >= email.size()-4)
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

		for (int i=0; i<password.size(); i++)
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


