#ifndef Admin_H_
#define Admin_H_

/**
* The admin class is the overseeing class for administration of user's and the machine itself
*
* optional, long description, spanning
* several lines.
*
* @author Matthew Cordner <cordner-m1@ulster.ac.uk>
* @license (url of your license)
* @copyright Matthew Cordner 2018
*
*/#pragma once

#include <string>
#include <iostream>
#include <sstream> //string stream function

//using namespace std;

class Admin
{

public:
	//constructors 

	User(std::string userInformation);

	std::string getFirstName();
	std::string getLastName();
	std::string getName();
	int getAccountNumber();
	double getInitialBalance();
	double getOverdraftLimit();
	int getPinCode();

	void printBalance();
	void printOverdraft();
	void setPinCode(int newPinCode);
	void getNewPinCode();
	void resetPinCode(UserDatabase userDatabase, int userInputIDNumber);

	//int getAccountNumber();

private:

	std::string firstName;
	std::string lastName;
	int accountNumber;
	double initialBalance;
	double overdraftLimit;
	int pinCode;

};

#endif 


/**
* The admin class is the overseeing class for administration of user's and the machine itself
* 
* Remove user, add user, adjust user info, adjust atm info / values, reciept amount counter
* view transactions,
*/#pragma once