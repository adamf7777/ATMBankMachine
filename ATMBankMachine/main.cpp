#include <iostream>

#include "User.h"
#include "UserDatabase.h"

#include <conio.h>
#include <string>
#include <ctime>
#include <algorithm>

//http://www.cplusplus.com/reference/vector/vector/push_back/
using namespace std;
//Test comment for commit

int main(int argc, const char * argv[])
{


	int userInputIDNumber = 0;
	int userInputPINCode = 0;

	int userInputOption = 0;

	char anotherService = 'Y';


	//while(differentUser = )
	system("cls");


	cout << "Welcome to Bank of Ulster" << endl << endl;
	cout << "Please enter your user ID Number " << endl;



	cin >> userInputIDNumber;

	cout << endl;

	system("cls");
	cout << "Please enter your 4-digit Pin Code " << endl;
	cin >> userInputPINCode;
	cout << endl;

	//Find line for the user
	userInputIDNumber = (userInputIDNumber - 1000);



	//Find the correct user from the database
	UserDatabase userDatabase("User_database.txt");

	User currentUser = userDatabase.users.at(userInputIDNumber);


	//****Function to display number of users**********
	//****Do not delete **********************
	//cout << endl << endl;
	//cout << userDatabase.getAllUsers().size() << endl; //Displays the number of lines in the list
	//for (int i = 0; list.getAllUsers().size(); i++) {
	//	cout << list.getAllUsers().at(i).getFirstName() << endl;
	//}

	system("cls");

	while (anotherService == 'Y' || 'y')
	{

		cout << "Please select one of the options below:" << endl << endl;

		cout << "[1] Cash Withdrawal " << endl;
		cout << "[2] On-screen balance enquiry " << endl;
		cout << "[3] Cash - lodgement " << endl;
		cout << "[4] Check your overdraft limit " << endl;
		cout << "[5] Change your Pin Code" << endl;


		cin >> userInputOption;

		system("cls");


		switch (userInputOption) {
		case 1:
			int withdrawAmount;

			currentUser.printBalance();
			cout << endl;
			cout << "Please select the amount of money you would like to withdraw: \n";
			cout << char(156);
			cin >> withdrawAmount;

			break;

		case 2: // Display onscreen balance

			currentUser.printBalance();

			break;

		case 3: // Allow for cash logdement 

				//cout << "Do nothing 3";
				//UserDatabase.rewriteUserDatabase();
				//list.rewriteUserDatabase("User_database.txt");
			break;

		case 4: // Overdraft Limit

			currentUser.printOverdraft();

			break;

		case 5: //Change Pin Code


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
					cout << "Error - the pin must have 4 digits!" << endl;
				}

				else {
					currentUser.setPinCode(newPin);
					currentUser.setPinCode(newPin);
					userDatabase.allUsers->at(userInputIDNumber).setPinCode(newPin);
					userDatabase.rewriteUserDatabase();

					cout << "Your pincode has been successfully updated!" << endl;
				}
			}

			else {
				cout << "Error, the two pincodes do not match!" << endl;
			}

			break;

		case 0: // Admin access

			int adminInputOption;

			cout << "Admin Menu";
			cout << "Please select one of the options below:" << endl << endl;

			cout << "[1] Add User " << endl;
			cout << "[2] Remove User " << endl;
			cout << "[3] Edit User Data " << endl;
			cout << "[4] ATM Maintenance " << endl;
			//cout << "[5] Change  Pin Code" << endl;

			cin >> adminInputOption;

			break;

			system("cls");

			switch (adminInputOption) {
			case 1:

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

				break;

			case 2:

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

				break;

			case 3:

				int editUserID;

				cout << "Please enter the User ID of the user you would like to edit: \n" << endl;
				cout << "User ID:";
				cin >> editUserID;

				break;

			default:
				cout << "Error";


			}//END OF SECOND SWITCH CASE
		}//END OF FIRST SWITCH CASE

		 //Any further services required
		cout << "Would you like any further services? Y/N:\n";
		cin >> anotherService;
		cout << "\n\n";
		system("cls");

	}//END OF ANOTHER SERVICE

	system("cls");

	//if 'N' return card 

	cout << "Your card is now being returned\n";



	return 0;

}//END OF MAIN