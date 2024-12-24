#include <iostream>
#include <list>
#include "User.h"
using namespace std;


class Admin : public User {
	public:
		Admin();
		string responsToComplaint(string complaint);

		void setEmail(string email) override {
			if (email.substr(0, 6) == "admin@")
			{
				this->email = email;
			}
			else
			{
				cout << "Error: Admin email must start with 'admin@'" << endl;
			}
		}


		string getHiddenEmail() override {
			return email;
		}

		string printUserDetails() override {
			return "Administrator Details:\nUsername: " + username +
			               "\nName: " + firstName + " " + lastName +
			               "\nEmail: " + getHiddenEmail();
		}
};

