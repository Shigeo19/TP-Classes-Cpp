#include <iostream>
#include <stdlib.h>
#include <string>
#include "UserDetails.h"
using namespace std;


UserDetails::UserDetails() {

}

string UserDetails::encryptPassword(string password, int key) {
    string encryptedPassword = password;

    for (size_t i = 0; i < password.length(); i++)
    {
        encryptedPassword[i] += key;
    }
    return encryptedPassword;
}

string UserDetails::decryptPassword(string encrypted, int key){
	string decryptedPassword = encrypted;

	for (size_t i = 0; i < decryptedPassword.length(); i++)
	    {
			decryptedPassword[i] -= key;
	    }
	    return decryptedPassword;
}






