#ifndef User_H_
#define User_H_

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
#include <iostream>
#include <sstream> //string stream function

//using namespace std;

class User
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