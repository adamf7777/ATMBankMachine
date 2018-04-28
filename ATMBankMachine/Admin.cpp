#include "Admin.h"
#include "User.h"
#include "UserDatabase.h"

//#include <string>
//#include <ostream>
//#include <s>

using namespace std;

void Admin::adminMenu(UserDatabase userDatabase)
{
	int adminInputOption;

	//userDatabase.getAllUsers().size();

	cout << "Admin Menu" << endl << endl;
	cout << "Please select one of the options below:" << endl << endl;

	cout << "[1] Add User " << endl;
	cout << "[2] Remove User " << endl;
	cout << "[3] Edit User Data " << endl;
	cout << "[4] ATM Maintenance " << endl;
	cout << "[5] Change Pin Code" << endl << endl;
	cout << "Option: ";

	cin >> adminInputOption;

	system("cls");

	switch (adminInputOption) {
	case 1:

		addUser(userDatabase);

		break;

	case 2:

		//removeUser();

		break;

	case 3:

		int editUserID;

		cout << "Please enter the User ID of the user you would like to edit: \n" << endl;
		cout << "User ID:";
		cin >> editUserID;

		break;

	case 4:

		cout << "ATM Maintenance\n" << endl;
		cout << "Please select one of the options below:" << endl << endl;

		cout << "[1] Update ATM Balance " << endl;
		cout << "[2] Update Receipt Amount " << endl;
		cout << "[3] View Transaction History " << endl;

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
	//int newUserIDNumber;
	//string newUserInfo;

	addUserDatabaseSize = (userDatabase.getAllUsers().size()) + 1;
	//cout << newUserDatabaseSize << endl << endl;

	addUserAccountNumber = addUserDatabaseSize + 1000;
	//cout << "The ID number for the new user is: " << addUserAccountNumber << endl;
	
	cout << "Admin Menu: Add User" << endl << endl;
	cout << "Please enter the details of the user you would like to add: " << endl << endl;
	cout << "New user account number: " << addUserAccountNumber << endl;
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

	cout << "Database Updated!" << endl;

}

//
//void Admin::removeUser()
//{
//	std::string addUserFirstName;
//	std::string addUserLastName;
//	int addUserAccountNumber;
//	double addUserAccountBalance;
//	double addUserOverdraftLimit;
//	int addUserPincode;
//	int newUserDatabaseSize;
//	int newUserIDNumber;
//	string newUserInfo;
//
//	std::string removeUserFirstName;
//	std::string removeUserLastname;
//	int removeUserAccountNumber;
//	double removeUserAccountBalance;
//	double removeUserOverdraftLimit;
//	int removeUserPincode;
//	int removeUserDatabaseSize;
//	int removeUserIDNumber;
//	string removeUserIDNumber;
//
//	cout << "Please enter the details of the user you would like to add: \n" << endl;
//	cout << "First Name: \n";
//	cin >> removeUserFirstName;
//	cout << endl;
//	cout << "Surname: \n";
//	cin >> removeUserLastname;
//	cout << endl;
//	cout << "User ID: \n";
//	cin >> removeUserID;
//	cout << endl;
//	cout << "Initial Account Balance: \n";
//	cin >> removeUserAccountBalance;
//	cout << endl;
//	cout << "Inital Overdraft Limit: \n";
//	cin >> removeUserOverdraft;
//	cout << endl;
//	cout << "Setup Pincode: \n";
//	cin >> removeUserPincode;
//	cout << endl;
//}

