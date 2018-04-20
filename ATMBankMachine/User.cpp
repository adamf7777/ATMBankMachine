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
	userStream >> balance;
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

double User::getBalance()
{
	return balance;
}


double User::getOverdraftLimit()
{
	return overdraftLimit;
}

int User::getPinCode()
{
	return pinCode;
}

void User::setPinCode(int newPinCode)
{
	pinCode = newPinCode;
}

void User::setBalance(double newBalance)
{
	balance = newBalance;
}

void User::printBalance() //Make print user balance
{

	cout << endl;
	cout << firstName << ", ";
	//cout << "Name: " << user.getName() << endl;
	//cout << "Account Number: " << user.getAccountNumber() << endl;
	cout << "your current balance is: " << char(156) << balance << endl;
	cout << endl;
}

void User::printOverdraft()
{

	cout << firstName << ", ";
	cout << "your current maximum overdraft limit is: " << char(156) << overdraftLimit << endl << endl;

}

void User::resetPinCode(UserDatabase userDatabase, int userInputIDNumber) {

	int newPin, newPin1, newPin2;
	cout << "Please enter new pincode: ";
	cin >> newPin1;

	system("cls");
	cout << "Please re enter your new pincode: ";
	cin >> newPin2;

	//currentUser.getNewPinCode();

	if (newPin1 == newPin2)
	{
		newPin = newPin1;

		if ((newPin < 1000) || (newPin > 9999))
		{
			cout << "Error - the pin code must have 4 digits!" << endl;
		}

		else {
			User::setPinCode(newPin);
			//User::setPinCode(newPin);
			userDatabase.allUsers->at(userInputIDNumber).setPinCode(newPin);
			userDatabase.rewriteUserDatabase();

			cout << "Your pincode has been successfully updated!" << endl;
		}
	}

	else {
		cout << "Error, the two pincodes do not match!" << endl;
		cout << "Please try again later" << endl;
	}

}

void User::withdrawCash(UserDatabase userDatabase, int userInputIDNumber) {
	double withdrawalOption, withdrawalAmount, withdrawalCheck, withdrawalBalance;

	//cout << "Cash Withdrawal Menu" << endl << endl;
	printBalance();

	cout << "Please select amount to be widthdrawn:" << endl << endl;
	cout << "[1] " << char(156) << "10" << "		" << "[2] " << char(156) << "20" << endl;
	cout << "[3] " << char(156) << "40" << "		" << "[4] " << char(156) << "50" << endl;
	cout << "[5] " << char(156) << "60" << "		" << "[6] " << char(156) << "80" << endl;
	cout << "[7] " << char(156) << "100" << "	" << "[8] " << "Other Amount " << endl;

	cin >> withdrawalOption;

	system("cls");

	if (withdrawalOption == 8)
	{
		cout << "Please note, this smallest available note value is " << char(156) << "5" << endl << endl;
		cout << "Please enter the amount you wish to widthdraw" << endl << endl;
		cout << char(156) << " ";
		cin >> withdrawalAmount;

		withdrawalCheck = (withdrawalAmount / 5);

		if (withdrawalCheck - (int)withdrawalCheck > 0.0)

		{
			cout << "Error - the number must be divisible by '5' " << endl;
		}

		else
		{
			withdrawalBalance = balance - withdrawalAmount;

			User::setBalance(withdrawalBalance);
			userDatabase.allUsers->at(userInputIDNumber).setBalance(withdrawalBalance);
			userDatabase.rewriteUserDatabase();

			system("cls");

			cout << "Please take your cash" << endl;
		}

			
		} 
			
	else 
	{
		
	}

}