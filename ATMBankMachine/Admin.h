/**
* The admin class is the overseeing class for administration of user's
*
* @author Matthew Cordner <cordner-m1@ulster.ac.uk>
* @license https://www.gnu.org/licenses/gpl-3.0.en.html
* @copyright Matthew Cordner 2018
*
*/

#ifndef Admin_H_
#define Admin_H_

#pragma once

#include <string>
#include <iostream>
#include <sstream> // String Stream function, gathers data from the user database .txt file
#include "UserDatabase.h"

// The admin class works with the UserDatabase & User Classes
class UserDatabase;
class User;

class Admin
{

public:

	// Defining public functions involving class parameters
	void adminMenu(UserDatabase userDatabase);
	void atmMaintenanceMenu(UserDatabase userDatabase);
	void returnToAdminMenu(UserDatabase userDatabase);
	void returnToATMMaintenanceMenu(UserDatabase userDatabase);

private:

	// Defining private functions involving class parameters
	void addUser(UserDatabase userDatabase);
	void removeUser(UserDatabase userDatabase);
	void editUser(UserDatabase userDatabase);	
	void updateATMBalance(UserDatabase userDatabase);
	void updateReceiptAmount(UserDatabase userDatabase);

};
#endif