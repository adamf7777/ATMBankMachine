#include "Admin.h"
#include "User.h"
#include "UserDatabase.h"

//#include <string>
//#include <ostream>
//#include <s>

using namespace std;

void Admin::adminMenu(UserDatabase userDatabase)
{
	int adminMenuInputOption;

	cout << "Admin Menu" << endl << endl;
	cout << "Please select one of the options below:" << endl << endl;

	cout << "[1] Add User " << endl;
	cout << "[2] Remove User " << endl;
	cout << "[3] Edit User Data " << endl;
	cout << "[4] ATM Maintenance " << endl;
	cout << "[5] Change Pin Code" << endl << endl;
	cout << "Option: ";

	cin >> adminMenuInputOption;

	system("cls");

	switch (adminMenuInputOption) {
	case 1:

		addUser(userDatabase);

		break;

	case 2:

		removeUser(userDatabase);

		break;

	case 3:

		editUser(userDatabase);

		break;

	case 4:

		atmMaintenance();

		break;

	default:

		cout << "Error";

		break;
	}
}

void Admin::addUser(UserDatabase userDatabase)
{
	std::string addUserFirstName;
	std::string addUserLastName;
	int addUserAccountNumber;
	double addUserAccountBalance;
	double addUserOverdraftLimit;
	int addUserPincode;
	int addUserDatabaseSize;
	std::string returnOption;

	addUserDatabaseSize = (userDatabase.getAllUsers().size()) + 1;
	//cout << newUserDatabaseSize << endl << endl;

	addUserAccountNumber = addUserDatabaseSize + 1000;
	//cout << "The ID number for the new user is: " << addUserAccountNumber << endl;
	
	cout << "Admin Menu: Add User" << endl << endl;
	cout << "Please enter the details of the user you would like to add: " << endl << endl;
	cout << "New User Account Number:	" << addUserAccountNumber << endl;
	cout << "First Name:			";
	cin >> addUserFirstName;
	cout << "Last Name:			";
	cin >> addUserLastName;
	cout << "Initial Account Balance:	";
	cin >> addUserAccountBalance;
	cout << "Inital Overdraft Limit:		";
	cin >> addUserOverdraftLimit;
	cout << "Setup Pincode:			";
	cin >> addUserPincode;

	User* tempUser = new User();
	tempUser->setFirstName(addUserFirstName);
	tempUser->setLastName(addUserLastName);
	tempUser->setAccountNumber(addUserAccountNumber);
	tempUser->setBalance(addUserAccountBalance);
	tempUser->setOverdraftLimit(addUserOverdraftLimit);
	tempUser->setPinCode(addUserPincode);

	userDatabase.addUser(tempUser);

	cout << "\nDatabase Updated!" << endl << endl;

	cout << "Would you like to return to the Admin menu? (Y/N): ";
	cin >> returnOption;

	system("cls");

	if (returnOption == "Y")
	{
		adminMenu(userDatabase);
	}
	else
	{
		cout << "\n\n\n		Thanks for using this service, please press 'X' to exit!" << endl;
		cin >> returnOption;
	}

}

void Admin::removeUser(UserDatabase userDatabase)
{
	std::string removeUserFirstname;
	std::string removeUserLastname;
	int removeUserAccountNumber;
	double removeUserAccountBalance;
	double removeUserOverdraftLimit;
	int removeUserPincode;
	//int removeUserDatabaseSize;
	//int removeUserIDNumber;
	//string removeUserIDNumber;

	cout << "Admin Menu: Remove User" << endl << endl;
	cout << "Please enter the Account Number of the user you would like to remove: " << endl << endl;
	cout << "Account Number: ";
	cin >> removeUserAccountNumber;

	//userDatabase.removeUser(tempUser);

	removeUserFirstname = "REMOVED";
	removeUserLastname = "REMOVED";
	removeUserAccountBalance = 0;
	removeUserOverdraftLimit = 0;
	removeUserPincode = 0;

	User* tempUser = new User();
	tempUser->setFirstName(removeUserFirstname);
	tempUser->setLastName(removeUserLastname);
	tempUser->setAccountNumber(removeUserAccountBalance);
	tempUser->setBalance(removeUserAccountBalance);
	tempUser->setOverdraftLimit(removeUserOverdraftLimit);
	tempUser->setPinCode(removeUserPincode);
}

void Admin::editUser(UserDatabase userDatabase)
{
	std::string editUserFirstName;
	std::string editUserLastName;
	int editUserAccountNumber;
	double editUserAccountBalance;
	double editUserOverdraftLimit;
	int editUserPincode;

	cout << "Admin Menu: Edit User" << endl << endl;
	cout << "Please enter the Account Number of the user you would like to edit: " << endl << endl;
	cout << "Account Number: ";
	cin >> editUserAccountNumber;

	//User* tempUser = new User();
	//tempUser->setFirstName(editUserFirstName);
	//tempUser->setLastName(editUserLastName);
	//tempUser->setAccountNumber(editUserAccountNumber);
	//tempUser->setBalance(editUserAccountBalance);
	//tempUser->setOverdraftLimit(editUserOverdraftLimit);
	//tempUser->setPinCode(editUserPincode);

	//userDatabase.editUser(tempUser);

	cout << "Database Updated!" << endl;

}

void Admin::atmMaintenance()
{
	int adminMaintenanceOption;

	cout << "Admin Menu: ATM Maintenance\n" << endl;
	cout << "Please select one of the options below:" << endl << endl;

	cout << "[1] Update ATM Balance " << endl;
	cout << "[2] Update Receipt Amount " << endl;
	cout << "[3] View Transaction History " << endl << endl;
	cout << "Option: ";

	cin >> adminMaintenanceOption;

	system("cls");

	switch (adminMaintenanceOption) {
	case 1:

		updateATMBalance();

		break;

	case 2:

		updateReceiptAmount();

		break;

	case 3:

		viewTransactionHistory();

		break;
	}
}

void Admin::updateATMBalance()
{
	int newATMBalance;
	int newATMBalanceFive;
	int newATMBalanceTen;
	int newATMBalanceTwenty;
	int totalNotes;

	cout << "Admin Menu: ATM Maintenance: Update ATM Balance" << endl << endl;
	cout << "Please enter the amount of money being added to the ATM: " << endl << endl;
	cout << "Amount of money being added: ";
	cin >> newATMBalance;

	cout << endl << "Please enter the amount of FIVE(5) pound notes being added to the ATM: " << endl << endl;
	cout << "Amount of notes being added: ";
	cin >> newATMBalanceFive;

	cout << endl << "Please enter the amount of TEN(10) pound notes being added to the ATM: " << endl << endl;
	cout << "Amount of notes being added: ";
	cin >> newATMBalanceTen;

	cout << endl << "Please enter the amount of TWENTY(20) pound notes being added to the ATM: " << endl << endl;
	cout << "Amount of notes being added: ";
	cin >> newATMBalanceTwenty;

	totalNotes = ((newATMBalanceFive * 5) + (newATMBalanceTen * 10) + (newATMBalanceTwenty * 20));

	if (totalNotes != newATMBalance)
	{
		cout << endl << "ERROR! Incorrect the current amounts of notes do not total the amount" << endl << endl;
	}
}
void Admin::updateReceiptAmount()
{

}
void Admin::viewTransactionHistory()
{

}