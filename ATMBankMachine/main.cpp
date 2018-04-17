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
			currentUser.resetPinCode(userDatabase, userInputIDNumber);

		case 0: // Admin access
			cout << "Admin menu";

			break;

		default:
			cout << "Error";


		}//END OF SWITCH CASE


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