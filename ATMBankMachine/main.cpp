#include "User.h"
#include "Admin.h"
#include "Security.h"
#include "Transaction.h"
#include <conio.h>
#include <fstream>
#include <string>


using namespace std;

int main(void);


int main(void)
{

	///User* fred = new User("Fred", "Jones", 123, 100.0);
	//User fred ("Fred" ,"Jones", 123, 100.0);
	User cecil(123);
	cout << cecil.getAccountNumber() << endl;

	//int userID;
	//int userInput;
	//int pinCode;
	//int mainLoop = 0;
	//char anotherService = 'Y';
	//float withdrawAmount;
	//float userBalance = 642;
	//float machineBalance = 10000;



	//cout << "Welcome to Bank of Ulster \n\n";

	//
	////Pincode area
	//cout << "Please enter you PIN code \n\n";
	//	cin >> pinCode;

	//// Stops the program if the user doesn't require any further services 
	//while (anotherService == 'Y'|| 'y') {
	//cout << "Please select one of the options below:\n";

	//cout << "[1] Cash Withdrawal\n";
	//cout << "[2] On-screen balance enquiry \n";
	//cout << "[3] Cash - lodgement \n";
	//cout << "[4] Admin Access \n";

	//cin >> userInput;
	//
	//

	//	switch (userInput) {
	//	case 1:
	//		cout << "Cash Withdrawl Menu\n\n";
	//		cout << "Please enter the amount of money you would like to withdraw: \n";
	//		cout << char(156);


	//		cin >> withdrawAmount;
	//		cout << "\n";

	//		if ((withdrawAmount <= machineBalance) && (withdrawAmount <= userBalance))
	//		{

	//			userBalance = userBalance - withdrawAmount;
	//			machineBalance = machineBalance - withdrawAmount;

	//			cout << "Transaction Approved\n\n";

	//			cout << "Counting your money\n\n";
	//			
	//			cout << "Please take your money\n\n";

	//			cout << "Your new balance is: " << char(156) << userBalance ;
	//			cout << "\n\n";
	//		}

	//		else if (withdrawAmount > userBalance)
	//		{
	//			cout << "Insufficient funds available in your account \n";
	//		}

	//		
	//		else if (withdrawAmount > machineBalance)
	//		{
	//			cout << "The machine has insufficient cash for this transaction\n";
	//			cout << "Please try again later \n";

	//		}

	//		break;

	//	case 2: // Display onscreen balance
	//		cout << "Your current balance is: " << char(156) << userBalance << endl;

	//		break;

	//	case 3: // Allow for cash logdement 
	//		cout << "Do nothing 3";

	//		break;

	//	case 4: // Admin access 
	//		cout << "The user balance is: "<< char(156) << userBalance << endl;
	//		cout << "The machine balance is: " << char(156) << machineBalance << endl;

	//	}

	//	// Any further services around 
	//	cout << "Would you like any further services? Y/N:\n";
	//	cin >> anotherService;
	//	cout << "\n\n";
	//	
	//	
	//	}

	//system("cls");

	//// If 'N' return card 
	//cout << "Your card is now being returned\n";
	}


