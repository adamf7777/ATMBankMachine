#include "Admin.h"
#include "User.h"
#include "UserDatabase.h"


//#include <string>
//#include <ostream>
//#include <s>

using namespace std;

void Admin::setNewUserFirstname(string newUserFirstName)
{
	addUserFirstName = newUserFirstName;
}



void Admin::adminMenu()
{
	int adminInputOption;
	//Admin admin;
	UserDatabase userDatabase("User_database.txt");
	userDatabase.getAllUsers().size();

	//int newUserLine = (userDatabase.getAllUsers().size()) + 1;

	//ser newUser = userDatabase.users.at(newUserLine);

	cout << "Admin Menu";
	cout << "Please select one of the options below:" << endl << endl;

	cout << "[1] Add User " << endl;
	cout << "[2] Remove User " << endl;
	cout << "[3] Edit User Data " << endl;
	cout << "[4] ATM Maintenance " << endl;
	cout << "[5] Change Pin Code" << endl;

	cin >> adminInputOption;
	//cout << "Debug: " << adminInputOption << endl;

	system("cls");

	switch (adminInputOption) {
	case 1:

		//cout << "Debug: Option 1" << endl;
	
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
	//int addUserID;
	double addUserAccountBalance;
	double addUserOverdraftLimit;
	int addUserPincode;
	int newUserDatabaseSize;
	int newUserIDNumber;

	cout << "Please enter the details of the user you would like to add: \n" << endl;
	cout << "First Name: \n";
	cin >> addUserFirstName;
	cout << endl;
	cout << "Last Name: \n";
	cin >> addUserLastName;
	cout << endl;
	//cout << "User ID: \n";
	//cin >> addUserID;
	//cout << endl;
	cout << "Initial Account Balance: \n";
	cin >> addUserAccountBalance;
	cout << endl;
	cout << "Inital Overdraft Limit: \n";
	cin >> addUserOverdraftLimit;
	cout << endl;
	cout << "Setup Pincode: \n";
	cin >> addUserPincode;
	cout << endl;

	/*UserDatabase userDatabase("User_database.txt");
	
	userDatabase.getAllUsers().size();*/
	
	newUserDatabaseSize = (userDatabase.getAllUsers().size()) + 1;
	cout << newUserDatabaseSize << endl << endl;

	newUserIDNumber = newUserDatabaseSize + 1000;
	cout << "The ID number for the new user is: " << newUserIDNumber << endl;

	Admin::setNewUserFirstname(addUserFirstName);
	/*newUser.setLastName(addUserLastName);
	newUser.setBalance(addUserAccountBalance);
	newUser.setOverdraftLimit(addUserOverdraftLimit);
	newUser.setPinCode(addUserPincode);*/

	userDatabase.allUsers->at(newUserIDNumber).setFirstName(addUserFirstName);
	/*userDatabase.allUsers->at(newUserIDNumber).setLastName(addUserLastName);
	userDatabase.allUsers->at(newUserIDNumber).setBalance(addUserAccountBalance);
	userDatabase.allUsers->at(newUserIDNumber).setOverdraftLimit(addUserOverdraftLimit);
	userDatabase.allUsers->at(newUserIDNumber).setPinCode(addUserPincode);*/
	userDatabase.rewriteUserDatabaseNewUser();
	cout << "Database Updated!" << endl;

}

//
//void Admin::removeUser()
//{
//	int removeUserFirstName;
//	int removeUserSurname;
//	int removeUserID;
//	int removeUserAccountBalance;
//	int removeUserOverdraft;
//	int removeUserPincode;
//
//	cout << "Please enter the details of the user you would like to add: \n" << endl;
//	cout << "First Name: \n";
//	cin >> removeUserFirstName;
//	cout << endl;
//	cout << "Surname: \n";
//	cin >> removeUserSurname;
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

