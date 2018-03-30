#include "User.h"
#include "UserDatabase.h"
//#include <string>
//#include <ostream>
//#include <s>


using namespace std;

User::User(string userInformation)
{
	stringstream userStream(userInformation);
	userStream >> firstName;
	userStream >> lastName;
	userStream >> accountNumber;
	userStream >> initialBalance;
	userStream >> overdraftLimit;
	userStream >> pinCode;
}

string User::getFirstName()
{
	return firstName;
}

string User::getLastName()
{
	return lastName;
}

string User::getName()
{
	return firstName + " " + lastName;
}

int User::getAccountNumber()
{
	return accountNumber;
}

double User::getInitialBalance()
{
	return initialBalance;
}

double User::getOverdraftLimit()
{
	return overdraftLimit;
}

int User::getPinCode()
{
	return pinCode;
}

void User::setPinCode(int newPinCode) {
	pinCode = newPinCode;
}

void User::setPinCode(int newPinCode, std::vector<User> *allUsers)
{
	allUsers->at(accountNumber - 1000).setPinCode(newPinCode);

	cout << "in class " << allUsers->at(accountNumber - 1000).getPinCode();

	//update the database 
	//allUsers.at(accountNumber - 1000).setPinCode(newPinCode);
	
}


void User::printBalance() //Make print user balance
{
	cout << endl;
	cout << firstName << ", ";
	//cout << "Name: " << user.getName() << endl;
	//cout << "Account Number: " << user.getAccountNumber() << endl;
	cout << "your current balance is: " << char(156) << initialBalance << endl;
	cout << endl;
}

void User::printOverdraft()
{
	
	cout << firstName << ", ";
	cout << "your current maximum overdraft limit is: " << char(156) << overdraftLimit << endl << endl;
}

/*
void User::checkPinCode() 
{
	cout << "Please enter your - 4 digit Pin Code:" << endl;
	

}
*/


