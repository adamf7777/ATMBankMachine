#include "Admin.h"
//#include <string>
//#include <ostream>
//#include <s>

using namespace std;

void Admin::addUser()
{
	int addUserFirstName;
	int addUserSurname;
	int addUserID;
	int addUserAccountBalance;
	int addUserOverdraft;
	int addUserPincode;

	cout << "Please enter the details of the user you would like to add: \n" << endl;
	cout << "First Name: \n";
	cin >> addUserFirstName;
	cout << endl;
	cout << "Surname: \n";
	cin >> addUserSurname;
	cout << endl;
	cout << "User ID: \n";
	cin >> addUserID;
	cout << endl;
	cout << "Initial Account Balance: \n";
	cin >> addUserAccountBalance;
	cout << endl;
	cout << "Inital Overdraft Limit: \n";
	cin >> addUserOverdraft;
	cout << endl;
	cout << "Setup Pincode: \n";
	cin >> addUserPincode;
	cout << endl;

}

void Admin::removeUser()
{
	int removeUserFirstName;
	int removeUserSurname;
	int removeUserID;
	int removeUserAccountBalance;
	int removeUserOverdraft;
	int removeUserPincode;

	cout << "Please enter the details of the user you would like to add: \n" << endl;
	cout << "First Name: \n";
	cin >> removeUserFirstName;
	cout << endl;
	cout << "Surname: \n";
	cin >> removeUserSurname;
	cout << endl;
	cout << "User ID: \n";
	cin >> removeUserID;
	cout << endl;
	cout << "Initial Account Balance: \n";
	cin >> removeUserAccountBalance;
	cout << endl;
	cout << "Inital Overdraft Limit: \n";
	cin >> removeUserOverdraft;
	cout << endl;
	cout << "Setup Pincode: \n";
	cin >> removeUserPincode;
	cout << endl;
}