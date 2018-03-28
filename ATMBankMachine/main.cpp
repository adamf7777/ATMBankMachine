#include <iostream>

#include "User.h"
#include "UserDatabase.h"

#include <conio.h>
#include <string>


using namespace std;

void printBalance(User user) //Make print user balance
{

	cout << endl;
	cout << "Hello " << user.getFirstName() << "! " << endl << endl;
	//cout << "Name: " << user.getName() << endl;
	//cout << "Account Number: " << user.getAccountNumber() << endl;
	cout << "Your current balance is: " << char(156) << user.getInitialBalance() << endl;
	cout << endl;
}

int main(int argc, const char * argv[])
{

	int userInputIDNumber;
	int userInputPINCode;

	int userInputOption;
	char anotherService = 'Y';

	cout << "Welcome to Bank of Ulster" << endl << endl ;
	cout << "Please enter your user ID Number " << endl;
	
	cin >> userInputIDNumber;
	cout << endl;

	cout << "Please enter your 4-digit Pin Code " << endl;
	cin >> userInputPINCode;
	cout << endl;

	//Find line for the user
	userInputIDNumber = (userInputIDNumber - 1000);


	//Find the correct user from the database
	UserDatabase list("User_database.txt");
		
	User currentUser = list.users.at(userInputIDNumber);

	
	cout << "Please select one of the options below:\n";

	cout << "[1] Cash Withdrawal " << endl;
	cout << "[2] On-screen balance enquiry "<< endl;
	cout << "[3] Cash - lodgement " << endl;
	cout << "[4] Check your overdraft limit " << endl;
	//cout << "[5] Admin Access" << endl;
	
	cout << "Please select one of the options below:\n";
	cin >> userInputOption;

	// Stops the program if the user doesn't require any further services 
	while (anotherService == 'Y' || 'y') {


		switch (userInputOption) {
		case 1:
			cout << "Cash Withdrawl Menu\n\n";
			cout << "Please enter the amount of money you would like to withdraw: \n";
			cout << char(156);
			break;

		case 2: // Display onscreen balance

			currentUser.printBalance();

			break;

		case 3: // Allow for cash logdement 

			cout << "Do nothing 3";

			break;

		case 4: // Overdraft Limit

			currentUser.printOverdraft();

			break;

		case 0: // Admin access
			cout << "Admin menu";

			break;

		default:
			cout << "Error";


		}

		//Any further services required
		cout << "Would you like any further services? Y/N:\n";
		cin >> anotherService;
		cout << "\n\n";

	}
//if 'N' return card 
//	system("cls");
cout << "Your card is now being returned\n";
	
	

	return 0;

}

/*
int main(void)
{


	

	int userID;
	int userInput;
	int pinCode;
	int mainLoop = 0;
	char anotherService = 'Y';
	float withdrawAmount;
	float userBalance = 642;
	float machineBalance = 10000;



	cout << "Welcome to Bank of Ulster \n\n";

	
	//Pincode area
	cout << "Please enter you PIN code \n\n";
		cin >> pinCode;

	// Stops the program if the user doesn't require any further services 
	while (anotherService == 'Y'|| 'y') {
	cout << "Please select one of the options below:\n";

	cout << "[1] Cash Withdrawal\n";
	cout << "[2] On-screen balance enquiry \n";
	cout << "[3] Cash - lodgement \n";
	cout << "[4] Admin Access \n";

	cin >> userInput;
	
	

		switch (userInput) {
		case 1:
			cout << "Cash Withdrawl Menu\n\n";
			cout << "Please enter the amount of money you would like to withdraw: \n";
			cout << char(156);


			cin >> withdrawAmount;
			cout << "\n";

			if ((withdrawAmount <= machineBalance) && (withdrawAmount <= userBalance))
			{

				userBalance = userBalance - withdrawAmount;
				machineBalance = machineBalance - withdrawAmount;

				cout << "Transaction Approved\n\n";

				cout << "Counting your money\n\n";
				
				cout << "Please take your money\n\n";

				cout << "Your new balance is: " << char(156) << userBalance ;
				cout << "\n\n";
			}

			else if (withdrawAmount > userBalance)
			{
				cout << "Insufficient funds available in your account \n";
			}

			
			else if (withdrawAmount > machineBalance)
			{
				cout << "The machine has insufficient cash for this transaction\n";
				cout << "Please try again later \n";

			}

			break;

		case 2: // Display onscreen balance
			cout << "Your current balance is: " << char(156) << userBalance << endl;

			break;

		case 3: // Allow for cash logdement 
			cout << "Do nothing 3";

			break;

		case 4: // Admin access 
			cout << "The user balance is: "<< char(156) << userBalance << endl;
			cout << "The machine balance is: " << char(156) << machineBalance << endl;

		}

		// Any further services around 
		cout << "Would you like any further services? Y/N:\n";
		cin >> anotherService;
		cout << "\n\n";
		
		
		}

	system("cls");

	// If 'N' return card 
	cout << "Your card is now being returned\n";
	}

	*/
