#include <iostream>

#include "User.h"
#include "UserDatabase.h"
#include "Admin.h"

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

	while (anotherService == 'Y')
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
			
			currentUser.withdrawCash(userDatabase, userInputIDNumber);

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
			currentUser.resetPinCode(userDatabase, userInputIDNumber);
			break;

		case 0: // Admin access

			int adminInputOption;
			Admin admin;

			cout << "Admin Menu";
			cout << "Please select one of the options below:" << endl << endl;

			cout << "[1] Add User " << endl;
			cout << "[2] Remove User " << endl;
			cout << "[3] Edit User Data " << endl;
			cout << "[4] ATM Maintenance " << endl;
			cout << "[5] Change  Pin Code" << endl;

			cin >> adminInputOption;
			cout << "Debug: " << adminInputOption << endl;

			system("cls");

			switch (adminInputOption) {
			case 1:

				//cout << "Debug: Option 1" << endl;
				admin.addUser();

				break;

			case 2:

				admin.removeUser();

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
		break;
			}//END OF SECOND SWITCH CASE
		}//END OF FIRST SWITCH CASE


		 //Any further services required
		cout << "Do you require any further services? Y/N:\n";
		cin >> anotherService;
		cout << "\n\n";
		system("cls");

		} //END OF ANOTHER SERVICE if

	

	system("cls");

	//if 'N' return card 

	cout << "Your card is now being returned\n";



	return 0;

}//END OF MAIN