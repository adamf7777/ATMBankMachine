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
#include "UserDatabase.h"

//using namespace std;
class UserDatabase;

class User;

class Admin : public UserDatabase
{

public:

	Admin() : UserDatabase("User_database.txt") {};
	void adminMenu(UserDatabase userDatabase);
	void addUser(UserDatabase userDatabase);
	void removeUser(UserDatabase userDatabase);
	void editUser(UserDatabase userDatabase);
	void atmMaintenanceMenu(UserDatabase userDatabase);
	void updateATMBalance(UserDatabase userDatabase);
	void updateReceiptAmount(UserDatabase userDatabase);
	void viewTransactionHistory(UserDatabase userDatabase);
	void returnToAdminMenu(UserDatabase userDatabase);
	void returnToATMMaintenanceMenu(UserDatabase userDatabase);

private:

};

#endif 


/**
* The admin class is the overseeing class for administration of user's and the machine itself
* 
* Remove user, add user, adjust user info, adjust atm info / values, reciept amount counter
* view transactions,
*/#pragma once