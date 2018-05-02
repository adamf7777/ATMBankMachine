/**
* ATMBankMachine
*
* optional, long description, spanning
* several lines.
*
* @author Adam Fawcett <fawcett-a@ulster.ac.uk>
* @author Matthew Cordner <cordner-m1@ulster.ac.uk>
* @author Christopher Hull <faulkner-c5@ulster.ac.uk>
* @author Micheal Glass <glass-m@ulster.ac.uk>
* @license https://www.gnu.org/licenses/gpl-3.0.en.html
* @copyright Adam Fawcett 2018
* @copyright Matthew Cordner 2018
* @copyright Christopher Hull 2018
* @copyright Micheal Glass 2018
*
*/

#include <iostream>

#include "User.h"
#include "UserDatabase.h"
#include "Admin.h"
#include "Security.h"

#include <conio.h>
#include <string>
#include <ctime>
#include <algorithm>

//http://www.cplusplus.com/reference/vector/vector/push_back/
using namespace std;

int main(int argc, const char * argv[])
{
	int userInputIDNumber = 0;
	int userInputIDNumberLine = 0;
	int userInputPINCode = 0;
	int userInputOption = 0;
	char anotherService = 'Y';

	//while(differentUser = )
	system("cls");

	cout << "Welcome to Bank of Ulster" << endl << endl;
	cout << "Please enter your User ID Number " << endl << endl;
	cout << "User ID Number: ";

	cin >> userInputIDNumber;
	cout << endl;

	if (userInputIDNumber < 1000 || userInputIDNumber > 9999)
	{
		while (userInputIDNumber < 1000 || userInputIDNumber > 9999)
		{
			cout << "Invalid User ID, please re-enter a correct 4 digit User ID!" << endl;
			cout << "User ID Number: " << endl;
			cin >> userInputIDNumber;
			cout << endl;
		}
	}

	system("cls");
	
	//Find line for the user
	userInputIDNumberLine = (userInputIDNumber - 1000);

	//Find the correct user from the database
	UserDatabase userDatabase("User_database.txt");
	User currentUser = userDatabase.users.at(userInputIDNumberLine);
	
	//int mainPinCheck;

	Security security;

	
	//system("cls");
	if (security.pinCodeCheck(currentUser, userDatabase) == 0)
	{
		anotherService = 'N';
		cout << "The incorrect pin has been entered more than 3 times. " << endl;
	}

	else
	{
		anotherService = 'Y';
		cout << "correct pin" << endl;
	}

	while (anotherService == 'Y')
	{
		if (userInputIDNumber > 1000)
		{
			cout << "Please select one of the options below:" << endl << endl;

			cout << "[1] Cash Withdrawal " << endl;
			cout << "[2] Balance Enquiry " << endl;
			cout << "[3] Cash Lodgement " << endl;
			cout << "[4] Check Overdraft limit " << endl;
			cout << "[5] Change Pin Code" << endl;

			cin >> userInputOption;

			system("cls");

			switch (userInputOption) {
			case 1:

				currentUser.withdrawCash(userDatabase, userInputIDNumberLine);

				break;

			case 2: // Display onscreen balance

				currentUser.printBalance();

				break;

			case 3: // Allow for cash logdement 

				currentUser.lodgeCash(userDatabase, userInputIDNumberLine);

				break;

			case 4: // Overdraft Limit

				currentUser.printOverdraft();

				break;

			case 5: //Change Pin Code
				currentUser.resetPinCode(userDatabase, userInputIDNumberLine);
				break;

			case 0: // Admin menu
				//Admin admin;
				//admin.adminMenu(userDatabase);
				break;

			}//END OF FIRST SWITCH CASE

			 //Any further services required
			cout << "Do you require any further services? [Y/N] " << endl;
			cin >> anotherService;
			cout << "\n\n";
			system("cls");

		} //END OF USERID if
		else if (userInputIDNumber = 1000)
		{
			Admin admin;
			admin.adminMenu(userDatabase);
			break;
		}

	} //END OF ANOTHER SERVICE if

	system("cls");

	//if 'N' return card 

	cout << "Your card is now being returned\n";

	return 0;

}//END OF MAIN