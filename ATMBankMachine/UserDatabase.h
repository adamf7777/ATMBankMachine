#ifndef UserDatabase_H_
#define UserDatabase_H_

/**
* Used to read and write information from UserDatabase.
*
* 
* several lines.
*
* @author	Adam Fawcett <fawcett-a@ulster.ac.uk>
* @license https://www.gnu.org/licenses/gpl-3.0.en.html
* @copyright Adam Fawcett 2018
*
*/


#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "User.h"
//#include "Admin.h"

//class Admin;

class UserDatabase
{
public:

	// declaring function to access the user database file path
	UserDatabase(std::string filePath);

	// declaring function to rewrite userdatabase vector array
	void rewriteUserDatabase();
	void rewriteUserDatabaseNewUser();

	// declaring function to get vector for user pincode and the user details
	std::vector<User> getPinCode;
	std::vector<User> users;

	// declaring function to get all user data and store in vector array
	std::vector<User> getAllUsers();

	// declaring function to 
	//void addUser(User* user);
	void addUser(User user);
	//Overriding with dynamic object
	void addUser(User* user);

	//Overriding with dynamic object
	//void removeUser(User* user);

	// declaring vector function for allusers
	std::vector<User>* allUsers = new std::vector<User>();

private:

	//declaring the filepath as a function only accessable in the class
	std::string filePath;
	
};


#endif