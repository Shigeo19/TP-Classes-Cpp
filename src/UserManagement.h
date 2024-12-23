#include <iostream>
#include <list>
using namespace std;


class UserManagement {
	private:
		list<User> users;
		UserDetails userDetails;

	public:
		UserManagement();

		User addUser(User user);
		User deleteUser(User user);

		void setNewPassword(string username,
							string oldPassword,
							string newPassword);

		void setNewUsername(string password,
							string oldUsername,
							string newUsername);

		User login(string username, string password);
		User logout(string username);

		string printAllUsers();
};

