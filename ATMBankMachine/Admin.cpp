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

		atmMaintenanceMenu(userDatabase);

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

	returnToAdminMenu(userDatabase);

}

void Admin::removeUser(UserDatabase userDatabase)
{
	std::string removeUserFirstname;
	std::string removeUserLastname;
	int removeUserAccountNumber;
	double removeUserAccountBalance;
	double removeUserOverdraftLimit;
	int removeUserPincode;
	int removeUserLineNumber;

	cout << "Admin Menu: Remove User" << endl << endl;
	cout << "Please enter the Account Number of the user you would like to remove: " << endl << endl;
	cout << "Account Number: ";
	cin >> removeUserAccountNumber;

	removeUserLineNumber = removeUserAccountNumber - 1000;
	
	userDatabase.allUsers->at(removeUserLineNumber).setFirstName("Deleted");
	userDatabase.allUsers->at(removeUserLineNumber).setLastName("User");
	userDatabase.allUsers->at(removeUserLineNumber).setAccountNumber(removeUserAccountNumber);
	userDatabase.allUsers->at(removeUserLineNumber).setBalance(0);
	userDatabase.allUsers->at(removeUserLineNumber).setOverdraftLimit(0);
	userDatabase.allUsers->at(removeUserLineNumber).setPinCode(0000);
	
	

	userDatabase.rewriteUserDatabase();

	cout << "\nDatabase Updated!" << endl << endl;

	returnToAdminMenu(userDatabase);
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

	cout << "\nDatabase Updated!" << endl << endl;

	returnToAdminMenu(userDatabase);

}

void Admin::atmMaintenanceMenu(UserDatabase userDatabase)
{
	int adminMaintenanceOption;

	cout << "Admin Menu: ATM Maintenance\n" << endl;
	cout << "Please select one of the options below:" << endl << endl;

	cout << "[1] Update ATM Balance " << endl;
	cout << "[2] Update Receipt Amount " << endl;
	cout << "[3] View Transaction History " << endl;
	cout << "[4] Return to Admin Menu" << endl << endl;
	cout << "Option: ";

	cin >> adminMaintenanceOption;

	system("cls");

	switch (adminMaintenanceOption) {
	case 1:

		updateATMBalance(userDatabase);

		break;

	case 2:

		updateReceiptAmount(userDatabase);

		break;

	case 3:

		viewTransactionHistory(userDatabase);

		break;

	case 4:

		adminMenu(userDatabase);

		break;
	}
}

void Admin::updateATMBalance(UserDatabase userDatabase)
{
	int totalAdded;
	int newATMNotesFive;
	int newATMNotesTen;
	int newATMNotesTwenty;
	int totalNotes;
	std::string tryAgain;

	cout << "Admin Menu: ATM Maintenance: Update ATM Balance" << endl << endl;
	cout << "Please enter the total amount of money being added to the ATM: " << endl << endl;
	cout << "Total amount of money being added: ";
	cin >> totalAdded;

	cout << endl << "Please enter the amount of each note being added to the ATM: " << endl << endl;
	cout << "Amount of FIVE(5) pound notes being added:	";
	cin >> newATMNotesFive;
	cout << "Amount of TEN(10) pound notes being added:	";
	cin >> newATMNotesTen;
	cout << "Amount of TWENTY(20) pound notes being added:	";
	cin >> newATMNotesTwenty;

	totalNotes = ((newATMNotesFive * 5) + (newATMNotesTen * 10) + (newATMNotesTwenty * 20));

	if (totalNotes == totalAdded)
	{
		cout << endl << "ATM Balance Updated!" << endl << endl;
	}
	else
	{
		cout << endl << "ERROR! Incorrect amount of each note entered, amount does not match the total being added!" << endl;
		cout << "Would you like to re-enter? (Y/N): ";
		cin >> tryAgain;

		if (tryAgain == "Y")
		{
			cout << "\nTotal amount of money being added: ";
			cin >> totalAdded;
			cout << endl << "Please enter the amount of each note being added to the ATM: " << endl << endl;
			cout << "Amount of FIVE(5) pound notes being added:	";
			cin >> newATMNotesFive;
			cout << "Amount of TEN(10) pound notes being added:	";
			cin >> newATMNotesTen;
			cout << "Amount of TWENTY(20) pound notes being added:	";
			cin >> newATMNotesTwenty;

			totalNotes = ((newATMNotesFive * 5) + (newATMNotesTen * 10) + (newATMNotesTwenty * 20));

			if (totalNotes == totalAdded)
			{
				cout << endl << "ATM Balance Updated!" << endl << endl;
			}
			else
			{
				cout << endl << "There has been an error, please report the problem to service!" << endl << endl;
			}

		}
	}

	returnToATMMaintenanceMenu(userDatabase);

}

void Admin::updateReceiptAmount(UserDatabase userDatabase)
{

}

void Admin::viewTransactionHistory(UserDatabase userDatabase)
{

}

void Admin::returnToAdminMenu(UserDatabase userDatabase)
{
	std::string returnOption;

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

void Admin::returnToATMMaintenanceMenu(UserDatabase userDatabase)
{
	std::string returnOption;

	cout << "Would you like to return to the ATM Maintenance menu? (Y/N): ";
	cin >> returnOption;

	system("cls");

	if (returnOption == "Y")
	{
		atmMaintenanceMenu(userDatabase);
	}
	else
	{
		cout << "\n\n\n		Thanks for using this service, please press 'X' to exit!" << endl;
		cin >> returnOption;
	}
}