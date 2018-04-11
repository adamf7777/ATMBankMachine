#include <iostream>

#include "User.h"
#include "UserDatabase.h"

#include <conio.h>
#include <string>
#include <ctime>

//comment1
//http://www.cplusplus.com/reference/vector/vector/push_back/
using namespace std;


int main(int argc, const char * argv[])
{
	

	int userInputIDNumber=0;
	int userInputPINCode=0;

	int userInputOption=0;
	
	char anotherService = 'Y';
	

		//while(differentUser = )
		system("cls");

		
		cout << "Welcome to Bank of Ulster" << endl << endl;
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
		// Stops the program if the user doesn't require any further services 
		
		cout << endl << endl;
		cout << list.getAllUsers().size() << endl;
		//for (int i = 0; list.getAllUsers().size(); i++) {
		//	cout << list.getAllUsers().at(i).getFirstName() << endl;
		//}
		cout << endl << endl;

		//system("cls");

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


			User newUser = User("Cecil Jones 1100 100.0 200.00 1234");


			switch (userInputOption) {
			case 1:
				cout << "Cash Withdrawl Menu\n\n";
				cout << "Please enter the amount of money you would like to withdraw: \n";
				cout << char('£');
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
<<<<<<< HEAD
				// Please re-enter your old pincode
				system("cls");

				
				int newPin1, newPin2;
				int newPin;
				cout << "Please enter new pincode: " << endl;
				cin >> newPin1;
					
				cout << "Please enter new pincode again: " << endl;
				cin >> newPin2;

				if (newPin1 == newPin2)
				{
					newPin1 = newPin; // test comment
=======
				cout << "Enter new pincode: ";
				int newPin;
				cin >> newPin;
				
				currentUser.setPinCode(newPin);
<<<<<<< HEAD
				cout << "Current user " << currentUser.getPinCode() << endl;
>>>>>>> parent of e1a5d14... Trying to implement Classes
=======
>>>>>>> parent of 1dd1df5... Rewrite pincode

				list.addUser(currentUser);
				for (int i = 0; i < list.getAllUsers().size(); i++) {
					if (list.getAllUsers().at(i).getAccountNumber() == currentUser.getAccountNumber()) {
						list.getAllUsers().at(i).setPinCode(newPin);
					}
				}

<<<<<<< HEAD
<<<<<<< HEAD
					cout << "Your pincode has been successfully changed" << endl;
				}
				//test comment
				else
				{
					cout << "Error: the two pincodes to not match,"
						<< "please try again" << endl;
				}

				//change the current users pincode
				//currentUser.setPinCode(newPin,userDatabase.getAllUsers());

				//currentUser.setPinCode(newPin, &userDatabase.getAllUsers());
=======
				cout << "array " << userDatabase.getAllUsers().at(userInputIDNumber).getPinCode() << endl; 
				
				userDatabase.rewriteUserDatabase();
				//cout << list.getAllUsers().at(userInputIDNumber).getPinCode();
>>>>>>> parent of e1a5d14... Trying to implement Classes


				//list.rewriteUserDatabase("User_database.txt");
=======
				list.rewriteUserDatabase("User_database.txt");
>>>>>>> parent of 1dd1df5... Rewrite pincode
				//Enter old pin again

				//Enter new code twice

				//Confirm change

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

