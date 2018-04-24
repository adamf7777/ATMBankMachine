#ifndef UserDatabase_H_
#define UserDatabase_H_

/**
* Used to read and write information from UserDatabase.
*
* optional, long description, spanning
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

class UserDatabase
{
public:
	UserDatabase(std::string filePath);

	void rewriteUserDatabase();

	std::vector<User> getPinCode;
	std::vector<User> users;


	std::vector<User> getAllUsers();

	void addUser(User user);


	std::vector<User>* allUsers = new std::vector<User>();

private:
	std::string filePath;
	
};


#endif