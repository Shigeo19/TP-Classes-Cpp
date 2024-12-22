#include <iostream>
using namespace std;


class UserDetails {
	public:
		UserDetails();
		string encryptPassword(string password, int key);
		string decryptPassword(string encrypted, int key);


};

