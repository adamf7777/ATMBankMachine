#ifndef Admin_H_
#define Admin_H_

/**
* The admin class is the overseeing class for administration of user's and the machine itself
*
* optional, long description, spanning
* several lines.
*
* @author Matthew Cordner <cordner-m1@ulster.ac.uk>
* @license https://www.gnu.org/licenses/gpl-3.0.en.html
* @copyright Matthew Cordner 2018
*
*/#pragma once

#include <string>
#include <iostream>
#include <sstream> //string stream function

//using namespace std;

class UserDatabase;
class User;

class Admin
{

public:
	void adminMenu();
	void addUser(UserDatabase userDatabase, User newUser);
	//void removeUser();
private:

};

#endif 


/**
* The admin class is the overseeing class for administration of user's and the machine itself
* 
* Remove user, add user, adjust user info, adjust atm info / values, reciept amount counter
* view transactions,
*/#pragma once