#include <iostream>
#include <list>
#include "User.h"
using namespace std;


class Customer : public User{
	private:
		double balance;
		int loyaltyPoints;


	public:
		Customer();
		Customer(double balance, int loyaltyPoints);

		Customer(string user,
				string pwd,
				string fname,
				string lname,
				string email,
	            string addr,
				double blnc,
				int points) : User(user, pwd, fname, lname, email, addr)
		{
			 this->balance = blnc;
			 this->loyaltyPoints = points;
		}


		void setEmail(string email) override {
			if (email.substr(0, 9) == "customer@")
			{
				this->email = email;
			}
			else
			{
				cout << "Error: Customer email must start with 'customer@'" << endl;
			}
		}

		string printUserDetails() override {
			return "Customer Details:\nUsername: " + username +
			               "\nName: " + firstName + " " + lastName +
			               "\nEmail: " + getHiddenEmail() +
			               "\nBalance: " + this->balance +
			               "\nLoyalty Points: " + to_string(loyaltyPoints);
		}
};

