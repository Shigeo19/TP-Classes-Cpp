#include <iostream>
using namespace std;
#include "User.h"
#include "UserDetails.h"

int main() {

	User uti = User("shiqeo", "anas", "chakrone", "chak.0019@email.ma", "pergola");

	cout << uti.getEmail() << endl;
	cout << uti.getHiddenEmail() << endl;

	uti.setPassword("Anas.0019");

	cout << "Your password is: " << uti.getPassword() << endl;

	UserDetails UserDetails;
	string password = uti.getPassword();
	int key = 5;

	string encrypted = UserDetails.encryptPassword(password, key);
	cout << "Encrypted password: " << encrypted << endl;

	string decrypted = UserDetails.decryptPassword(encrypted, key);
	cout << "Decrypted Password: " << decrypted;


	return 0;
}
