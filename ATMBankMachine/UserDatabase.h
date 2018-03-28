#ifndef UserDatabase_H_
#define UserDatabase_H_

/**
* one line description of class or file
*
* optional, long description, spanning
* several lines.
*
* @author Adam Fawectt <fawcett-a@ulster.ac.uk>
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

	User getUserBalance();
	std::vector<User> getHonorRollUsers();
	std::vector<User> getFailingUsers();

//private: 
	std::vector<User> users;

};






#endif