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
	cout << "Your new pincode must contain four digits" << endl << endl;
	cout << "Please enter new pincode: ";
	cin >> newPin1;

	system("cls");
	cout << "Your new pincode must contain four digits" << endl << endl;
	cout << "Please re enter your new pincode: ";
	cin >> newPin2;

	
	// check that both of the pincodes entered match
	if (newPin1 == newPin2)
	{
		newPin = newPin1;

		// check if the 
		if ((newPin < 1000) || (newPin > 9999))
		{
			cout << "Error - the pin code must have 4 digits!" << endl;
		}

		else {
			User::setPinCode(newPin);
			
			userDatabase.allUsers->at(userInputIDNumber).setPinCode(newPin);
			userDatabase.rewriteUserDatabase();
			
			system("cls");
			cout << "Your pincode has been successfully updated!" << endl << endl;
		}
	}

	else {
		cout << "Error, the two pincodes do not match!" << endl;
		cout << "Please try again later" << endl;
	}

} // end of reset pincode

void User::withdrawCash(UserDatabase userDatabase, int userInputIDNumber) {
	double withdrawalAmount, withdrawalCheck=0, withdrawalBalance;
	int  withdrawalOption;
	char overdraftCheck;

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

		withdrawalCheck = (withdrawalAmount/5);

		if(withdrawalCheck - (int)withdrawalCheck > 0.0)
		{
			withdrawalCheck = 1;
		} // end of check divisible by 5

		else
		{
			withdrawalCheck = 0;
		}
		/*else // if divisible by 5
		{	
			// continue as value checked as correct

		} // end of if divisible by 5 */

		} // end of if withdrawal option = 8
			
	else // if the withdrawal option is not = 8
	{
		switch(withdrawalOption){
		
		case 1:
			withdrawalAmount = 10;
				break;
		case 2:
			withdrawalAmount = 20;
				break;
		case 3:
			withdrawalAmount = 40;
				break;
		case 4:
			withdrawalAmount = 50;
				break;
		case 5:
			withdrawalAmount = 60;
				break;
		case 6:
			withdrawalAmount = 80;
				break;
		case 7:
			withdrawalAmount = 100;
				break;

		default: 
			cout << "Error, incorrect value selected." << endl;
			cout << "Please try again later" << endl;
		} // end of switch case
	} // end of else  for option other than 8
	
	if (withdrawalCheck == 0) {

		if (withdrawalAmount <= balance)
		{
			withdrawalBalance = (balance - withdrawalAmount);

			User::setBalance(withdrawalBalance);
			userDatabase.allUsers->at(userInputIDNumber).setBalance(withdrawalBalance);
			userDatabase.rewriteUserDatabase();

			system("cls");

			cout << "Counting " << char(156) << withdrawalAmount << endl << endl;
			cout << "Please take your cash" << endl;
		} // end of high enough balance

		else //insufficient funds menu

			system("cls");
			cout << "You have insufficient funds for this transaction" << endl << endl;
		    printOverdraft();
			cout << endl;
			cout << "Would you like to use your overdraft for this transaction? [Y/N]" << endl;
			cin >> overdraftCheck;

			if (overdraftCheck == 'Y')
			{

				if (withdrawalAmount <= (balance + overdraftLimit))
				{
					// Overdraft limit

				}


				else
				{
					cout << "The overdraft limit is insufficient for this transaction" << endl;
				}


			} // end of insufficient funds


			else {
				cout << "Error, this machine cannot dispense the amount of money you have requested" << endl;
			}
		}
	}
//} // end of withdraw cash