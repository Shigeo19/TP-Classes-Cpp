#include <iostream>
using namespace std;

class User {
	private:
		string username;
		string password;
		string firstName;
		string lastName;
		string email;
		string adress;
		bool session;

	public:
		User();
		User(string user,
			 string pwd,
			 string fname,
			 string lname,
			 string email,
			 string addr);

		User(string user,
			 string fname,
			 string lname,
			 string email,
			 string addr);

		User(string user,
			 string email,
			 string pwd);

		string getUsername();
		void setUsername(string username);

		string getEmail();
		void setEmail(string email);

		string getHiddenEmail();

		void setPassword(string password);
		string getPassword();

		void setSession(bool state);
		bool getSession();

		string printUserDetails();



};


