#ifndef UserDatabase_H_
#define UserDatabase_H_

/**
* one line description of class or file
*
* optional, long description, spanning
* several lines.
*
* @author Nathan Fawectt <fawcett-a@ulster.ac.uk>
* @license (url of your license)
* @copyright Adam Fawcett 2018
*
*/


#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "User.h"

class UserDatabase
{
public:
	UserDatabase(std::string filePath);

	void rewriteUserDatabase(std::string filePath);
	
	std::vector<User> getPinCode;
	std::vector<User> users;


	std::vector<User> getAllUsers();
	void addUser(User user);
private: 
	//create & initialise dynamic array to hold users 
	std::vector<User>* allUsers = new std::vector<User>();

};






#endif