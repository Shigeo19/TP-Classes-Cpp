#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>
#include "User.h"
#include "UserDetails.h"
#include "UserManagement.h"
using namespace std;


UserManagement::UserManagement() {

}

User UserManagement::addUser(User user) {
	string email = user.getEmail();
	string username = user.getUsername();

	for (User pointedUser : this->users)
	{
		if (pointedUser.getEmail() == email)
		{
			cout << "Cet email est deja utilise !" << endl;
			break;
		}

		else if(pointedUser.getUsername() == username)
		{
			cout << "Cet username est deja utilise!" << endl;
			break;
		}
	}

	string encryptedPassword = userDetails.encryptPassword(user.getPassword(), 7);
    user.setPassword(encryptedPassword);

    users.push_back(user);

    return user;
}


User UserManagement::deleteUser(User user){
	string username = user.getUsername();
	bool userFound = false;

	for (User pointedUser : this->users)
	{
		if (username == pointedUser.getUsername())
		{
			users.remove(pointedUser);
			userFound = true;
			break;
		}
	}

	if (!userFound) {
	        cout << "This username does not exist" << endl;
	    }

	return user;
}


void UserManagement::setNewPassword(string username, string oldPassword, string newPassword) {
	bool userFound = false;

	for (User& user : this->users)
	{
		if (user.getUsername() == username)
		{
			userFound = true;
			string encryptedOldPassword = userDetails.encryptPassword(oldPassword, 7);

			if (user.getPassword() == encryptedOldPassword)
			{
				string encryptedNewPassword = userDetails.encryptPassword(newPassword, 7);
				user.setPassword(encryptedNewPassword);
                cout << "Password successfully updated" << endl;
			}

			else
			{
				cout << "invalid old password" << endl;
			}
			break;
		}
	}

	if (!userFound)
	{
		cout << "User not found" << endl;
	}
}


void UserManagement::setNewUsername(string oldUsername, string newUsername, string password) {
	bool userFound = false;

	for (User& user : this->users)
	{
		if (user.getUsername() == oldUsername)
			{
				userFound = true;
				string encryptedPassword = userDetails.encryptPassword(password, 7);
				if (user.getPassword() == encryptedPassword)
				{
					user.setUsername(newUsername);
					cout << "Username successfully updated" << endl;
				}

				else
				{
					cout << "Invalid password" << endl;
				}
				break;
			}
	}
	if (!userFound) {
	        cout << "User not found" << endl;
	    }
}



User UserManagement::login(string username, string password) {
	bool userFound = false;
	string encryptedPassword = userDetails.encryptPassword(password, 7);
	User foundUser;

	for (User& user : this->users)
	{
		if (username == user.getUsername() && encryptedPassword == user.getPassword())
		{
			userFound = true;
			user.setSession(true);
			foundUser = user;
			cout << "Login successful" << endl;
			break;
		}
	}

	if (!userFound) {
	        cout << "invalid username or password" << endl;
	    }

	return foundUser;
}

User UserManagement::logout(string username) {
	bool userFound = false;
    User loggedOutUser;

	for (User& user : this->users)
	{
		if (username == user.getUsername())
		{
			userFound = true;
			if (user.getSession())
			{
				user.setSession(false);
			    loggedOutUser = user;
                cout << "Logout successful" << endl;
			}

			else
			{
                cout << "User is not logged in" << endl;
			}
			break;
		}
	}
	if (!userFound)
	{
		cout << "invalid username" << endl;
	}

	return loggedOutUser;
}
