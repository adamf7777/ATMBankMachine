//#include "UserDatabase.h"
/**
* Controls the main functionality for a user.
*
* Provides the user with variables based on their account values
* which the user requires to be able to use the ATM.
*
* @author Adam Fawcett <fawcett-a@ulster.ac.uk>
* @license https://www.gnu.org/licenses/gpl-3.0.en.html
* @copyright Adam Fawcett 2018
*
*/

#ifndef User_H_
#define User_H_


#include <string>
#include <iostream>

// String stream function gathers data from the user database txt file
#include <sstream> 


//The user class works with the userdatabase class.
class UserDatabase;

class User
{

public:
	
	// Userfunctions to get user information
	User(std::string userInformation);
	User();

	// Defining functions to get parameters from private
	std::string getFirstName();
	std::string getLastName();
	std::string getName();
	int getAccountNumber();
	double getBalance();
	double getOverdraftLimit();
	int getPinCode();

	// Defining functions involving class parameters
	void printBalance();
	void printOverdraft();
	double getWithdrawalAmount(double withdrawalAmount);
	
	void setFirstName(std::string newFirstName);
	void setLastName(std::string newLastName);
	void setOverdraftLimit(double newOverdraftLimit);
	void setPinCode(int newPinCode);
	void setBalance(double newBalance);
	void setAccountNumber(int newAccountNumber);
	void resetPinCode(UserDatabase userDatabase, int userInputIDNumber);
	void withdrawCash(UserDatabase userDatabase, int userInputIDNumber, CashStatus cashStatus);
	void lodgeCash(UserDatabase userDatabase, int userInputIDNumber);
	

private:

	//Defining private variables 
	std::string firstName;
	std::string lastName;
	int accountNumber;
	double balance;
	double overdraftLimit;
	int pinCode;

}; // End User class

#endif 