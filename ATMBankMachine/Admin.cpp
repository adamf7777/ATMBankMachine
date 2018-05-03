/**
* Provides menu's and functionality to administrate user data and
* perform ATM Maintenance
*
* @author Matthew Cordner <cordner-m1@ulster.ac.uk>
* @license https://www.gnu.org/licenses/gpl-3.0.en.html
* @copyright Matthew Cordner 2018
*
*/

// Includes header files
#include "Admin.h"
#include "User.h"
#include "UserDatabase.h"

using namespace std;

/**
* adminMenu, function to navigate around the Admin Class
*
* Prints out menu with user options shown and waits for user to enter decided option.
* User input is stored within adminMenuInputOption and is used in the switch statement 
* to allow the user to enter another function.
*
* @param adminMenuInputOption variable to contain the users entered menu option they wish to enter
* @see addUser
* @see removeUser
* @see editUser
* @see atmMaintenanceMenu
*/
void Admin::adminMenu(UserDatabase userDatabase)
{
	int adminMenuInputOption;

	cout << "Admin Menu" << endl << endl;
	cout << "Please select one of the options below:" << endl << endl;

	cout << "[1] Add User " << endl;
	cout << "[2] Remove User " << endl;
	cout << "[3] Edit User Data " << endl;
	cout << "[4] ATM Maintenance " << endl << endl;
	cout << "Option: ";

	cin >> adminMenuInputOption;

	system("cls");

	switch (adminMenuInputOption) {
	case 1:

		addUser(userDatabase);

		break;

	case 2:

		removeUser(userDatabase);

		break;

	case 3:

		editUser(userDatabase);

		break;

	case 4:

		atmMaintenanceMenu(userDatabase);

		break;

	default:

		cout << "Error";

		break;
	}
}

/**
* addUser, function to add a user to the array in userDatabase
*
* Writes an input capture form to the command window to allow entry of new user's data 
* to be stored within tthe variables. The size of the array of current users is obtained 
* from the userdatabase class to be used in the calcuation of an account number for the
* new user. A new user is then created called tempUser which is then passed into the 
* userdatabase to be stored as a user using the addUser function. The returnToAdminMenu 
* function is then entered.
*
* @param addUserFirstName variable to store the first name entered by the user
* @param addUserLastName variable to store the last name entered by the user
* @param addUserAccountBalance variable to store the account balance entered by the user
* @param addUserOverdraftLimit variable to store the overdraft limit entered by the user
* @param addUserPincode variable to store the pin code entered by the user
* @param addUserAccountNumber used to store the users account number after sumation
* @param addUserDatabaseSize used to store the database size obtained from the userdatabase
* @see returnToAdminMenu
*/
void Admin::addUser(UserDatabase userDatabase)
{
	std::string addUserFirstName;
	std::string addUserLastName;
	double addUserAccountBalance;
	double addUserOverdraftLimit;
	int addUserPincode;
	int addUserAccountNumber;
	int addUserDatabaseSize;

	addUserDatabaseSize = (userDatabase.getAllUsers().size());

	addUserAccountNumber = addUserDatabaseSize + 1000;
	
	cout << "Admin Menu: Add User" << endl << endl;
	cout << "Please enter the details of the user you would like to add: " << endl << endl;
	cout << "New User Account Number:	" << addUserAccountNumber << endl;
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

	cout << "\nDatabase Updated!" << endl << endl;

	returnToAdminMenu(userDatabase);
}

/**
* removeUser, function to remove a user from the array in userDatabase
*
* Writes an input capture form to the command window to allow entry of the account
* number that the user would like to remove. The line within the array that the user is
* stored on is then calculated with a message to the user expecting an input to confirm
* the user they are removing is the correct user. An if statement is used to control this
* option. If the user enters 'Y' then the users information will be overwritten in the
* array using functions within the userdatabase class. The rewritedatabase function is then
* called from the userdatabase class to write the updated array to the .txt file. If the user   
* enters anything else other than 'Y' the returnToAdminMenu function is entered. A message that
* the database has been updated is sent to the command window. The returnToAdminMenu 
* function is then entered.
*
* @param userDeleteConfirm variable to contain the users decison on whether they wish to delete
* @param removeUserAccountNumber variable to contain the account number of the user that is to be deleted
* @param removeUserLineNumber variable to store the line number within the array the user is stored on
* @see returnToAdminMenu
*/
void Admin::removeUser(UserDatabase userDatabase)
{
	std::string userDeleteConfirm;
	int removeUserAccountNumber;
	int removeUserLineNumber;
	
	cout << "Admin Menu: Remove User" << endl << endl;
	cout << "Please enter the Account Number of the user you would like to remove: " << endl << endl;
	cout << "Account Number: ";
	cin >> removeUserAccountNumber;

	removeUserLineNumber = removeUserAccountNumber - 1000;
	
	cout << "\nAre you sure you wish to delete " << userDatabase.allUsers->at(removeUserLineNumber).getName() << "'s "
		<< "account? (Y/N): ";
	cin >> userDeleteConfirm;

	if (userDeleteConfirm == "Y")
		{
		userDatabase.allUsers->at(removeUserLineNumber).setFirstName("Deleted");
		userDatabase.allUsers->at(removeUserLineNumber).setLastName("User");
		userDatabase.allUsers->at(removeUserLineNumber).setAccountNumber(removeUserAccountNumber);
		userDatabase.allUsers->at(removeUserLineNumber).setBalance(0);
		userDatabase.allUsers->at(removeUserLineNumber).setOverdraftLimit(0);
		userDatabase.allUsers->at(removeUserLineNumber).setPinCode(0000);
		
		userDatabase.rewriteUserDatabase();
		
		cout << "\nDatabase Updated!" << endl << endl;
		}

	returnToAdminMenu(userDatabase);
}

/**
* editUser, function to edit a users data within the array in userDatabase
*
* Writes an input capture form to the command window to allow entry of the account
* number that the user would like to edit. The line within the array that the user is
* stored on is then calculated with a message to the user expecting an input to confirm
* the user they are editing is the correct user. An if statement is used to control this
* option. If the user enters 'Y' a menu will be written to the command window to allow the
* user to choose which piece of the users information they would like to edit. The input
* from the user will be stored within the editOption variable and be used to determine the
* case to enter as part of the switch statement. When the user enters any of the case's of
* the swtich statement, the current information for that specific field will be shown and
* a message for the user to enter the new information will be shown. The new user information
* will be stored within the corresponding variable and written to the array at that speific
* line number using the corresponding function within the userdatabase class. The rewritedatabase 
* function is then called from the userdatabase class to write the updated array to the .txt file. If the user
* enters anything else other than 'Y' the returnToAdminMenu function is entered. A message that
* the database has been updated is sent to the command window. The returnToAdminMenu
* function is then entered.
*
* @param userEditConfirm variable to contain the users decison on whether they wish to edit
* @param editUserFirstName variable to contain the entered edited first name
* @param editUserLastName variable to contain the entered edited last name
* @param editUserAccountBalance variable to contain the entered edited account balance
* @param editUserOverdraftLimit variable to contain the entered edited overdraft limit
* @param editUserPincode variable to contain the entered edited pin code
* @param editUserAccountNumber variable to contain the entered account number for editing
* @param editUserLineNumber variable to store the line number within the array the user is stored on
* @param editOption varible to contain the users entered option on what they want to edit
* @see returnToAdminMenu
*/
void Admin::editUser(UserDatabase userDatabase)
{
	std::string userEditConfirm;
	std::string editUserFirstName;
	std::string editUserLastName;
	double editUserAccountBalance;
	double editUserOverdraftLimit;
	int editUserPincode;
	int editUserAccountNumber;
	int editUserLineNumber;
	int editOption;

	cout << "Admin Menu: Edit User" << endl << endl;
	cout << "Please enter the Account Number of the user you would like to edit: " << endl << endl;
	cout << "Account Number: ";
	cin >> editUserAccountNumber;

	editUserLineNumber = editUserAccountNumber - 1000;

	cout << "\nDo you wish to edit " << userDatabase.allUsers->at(editUserLineNumber).getName() << "'s "
		<< "account? (Y/N): ";
	cin >> userEditConfirm;

	if (userEditConfirm == "Y")
	{
		cout << "\nWhich of the following details do you wish to edit?" << endl << endl;
		cout << "[1] First Name" << endl;
		cout << "[2] Last Name" << endl;
		cout << "[3] Balance" << endl;
		cout << "[4] Overdraft Limit" << endl;
		cout << "[5] Pin Code" << endl << endl;
		cout << "Option: ";

		cin >> editOption;

		switch (editOption)
		{
		case 1:

			cout << "\nThe current First Name stored for this account is "
				<< userDatabase.allUsers->at(editUserLineNumber).getFirstName();
			cout << "\n\nPlease enter the new First Name for the user: ";
			cin >> editUserFirstName;
			userDatabase.allUsers->at(editUserLineNumber).setFirstName(editUserFirstName);

			break;

		case 2:

			cout << "\nThe current Last Name stored for this account is "
				<< userDatabase.allUsers->at(editUserLineNumber).getLastName();
			cout << "\nPlease enter the new Last Name for the user: ";
			cin >> editUserLastName;
			userDatabase.allUsers->at(editUserLineNumber).setLastName(editUserLastName);

			break;

		case 3:

			cout << "\nThe current Account Balance stored for this account is "
				<< userDatabase.allUsers->at(editUserLineNumber).getBalance();
			cout << "\nPlease enter the new Account Balance for the user: ";
			cin >> editUserAccountBalance;
			userDatabase.allUsers->at(editUserLineNumber).setBalance(editUserAccountBalance);

			break;

		case 4:

			cout << "\nThe current Overdraft Limit stored for this account is "
				<< userDatabase.allUsers->at(editUserLineNumber).getOverdraftLimit();
			cout << "\nPlease enter the new Overdraft Limit for the user: ";
			cin >> editUserOverdraftLimit;
			userDatabase.allUsers->at(editUserLineNumber).setOverdraftLimit(editUserOverdraftLimit);

			break;
		
		case 5:

			cout << "\nThe current Pin Code stored for this account is "
				<< userDatabase.allUsers->at(editUserLineNumber).getPinCode();
			cout << "\nPlease enter the new Pin Code for the user: ";
			cin >> editUserPincode;
			userDatabase.allUsers->at(editUserLineNumber).setPinCode(editUserPincode);

			break;

		default:

			cout << "Error";

			break;
		}

		userDatabase.rewriteUserDatabase();

		cout << "\nDatabase Updated!" << endl << endl;
	}

	returnToAdminMenu(userDatabase);

}

/**
* adminMenu, function to navigate around the Admin Class
*
* Prints out menu with user options shown and waits for user to enter decided option.
* User input is stored within adminMaintenanceOption and is used in the switch statement
* to allow the user to enter another function.
*
* @param adminMaintenanceOption variable to contain the users entered menu option they wish to enter
* @see updateATMBalance
* @see updateReceiptAmount
* @see viewTransactionHistory
* @see adminMenu
*/
void Admin::atmMaintenanceMenu(UserDatabase userDatabase)
{
	int adminMaintenanceOption;

	cout << "Admin Menu: ATM Maintenance\n" << endl;
	cout << "Please select one of the options below:" << endl << endl;

	cout << "[1] Update ATM Balance " << endl;
	cout << "[2] Update Receipt Amount " << endl;
	cout << "[3] View Transaction History " << endl;
	cout << "[4] Return to Admin Menu" << endl << endl;
	cout << "Option: ";

	cin >> adminMaintenanceOption;

	system("cls");

	switch (adminMaintenanceOption) {
	case 1:

		updateATMBalance(userDatabase);

		break;

	case 2:

		updateReceiptAmount(userDatabase);

		break;

	case 3:

		viewTransactionHistory(userDatabase);

		break;

	case 4:

		adminMenu(userDatabase);

		break;
	}
}

/**
* updateATMBalance, function to update the balance of the ATM within the array in userDatabase
*
* Writes the current ATM balance to the command window using the getBalance function in
* the user database class. A message is then written to the command window asking the user
* to enter the total amount of money being added to the ATM, this value is stored within
* the variable totalAdded. The message is then output asking the user to enter the amount
* of each note being added which is stored within its corresponding variable. A calculation
* takes place to calcuate totalNotes, the amount the entered notes adds up to. An if statement 
* is used to compare totalAdded to totalNotes to see if they are equal. If they are the if statement
* will run outputing a message that the database is updating. The new overall balance is then
* calculated using the getBalance function from the userdatabase class by adding the totalAdded
* variable to this and storing the result as newBalance. The setBalance function from the userdatabase
* class is then called to add the contents of the  newBalance variable to the array. The rewritedatabase function
* is then called from the userdatabase class to write the updated array to the .txt file. If the if
* statement requirements are not met, the else statement is entered. The else statement outputs a message
* to the command window asking the user if they wish to re-enter the info, the user input is stored in 
* tryAgain. If the user enters 'Y' another if statment is used that preforms as above only this time if
* the parameters are not met, the else statement is entered, displaying a message to contact service to 
* report the problem. The returnToAdminMenu function is then entered after succession of the first if or
* the else.
* 
* @param totalAdded variable to contain the amount of money the user enters to be added to the ATM
* @param totalNotes variable to contain the amount of money calculated from the amount of notes the user 
*		 enters to be added to the ATM
* @param newBalance variable to contain the new updated total of money within the ATM
* @param newATMNotesFive variable to contain the amount of 5 pound notes being added to the ATM
* @param newATMNotesTen variable to contain the amount of 10 pound notes being added to the ATM
* @param newATMNotesTwenty variable to contain the amount of 20 pound notes being added to the ATM
* @param tryAgain variable to contain the users answer as to whether they would like to re-enter the information
* @see returnToAdminMenu
*/
void Admin::updateATMBalance(UserDatabase userDatabase)
{
	double totalAdded;
	double totalNotes;
	double newBalance;
	int newATMNotesFive;
	int newATMNotesTen;
	int newATMNotesTwenty;
	std::string tryAgain;

	cout << "Admin Menu: ATM Maintenance: Update ATM Balance" << endl << endl;
	cout << "Current ATM Balance: " << userDatabase.allUsers->at(0).getBalance() << endl << endl;
	cout << "Please enter the total amount of money being added to the ATM, " << endl << endl;
	cout << "Total amount of money being added: ";
	cin >> totalAdded;

	cout << endl << "Please enter the amount of each note being added to the ATM: " << endl << endl;
	cout << "Amount of FIVE(5) pound notes being added:	";
	cin >> newATMNotesFive;
	cout << "Amount of TEN(10) pound notes being added:	";
	cin >> newATMNotesTen;
	cout << "Amount of TWENTY(20) pound notes being added:	";
	cin >> newATMNotesTwenty;

	totalNotes = ((newATMNotesFive * 5) + (newATMNotesTen * 10) + (newATMNotesTwenty * 20));

	if (totalNotes == totalAdded)
	{
		cout << endl << "------------UPDATING DATABASE------------" << endl;
		newBalance = (userDatabase.allUsers->at(0).getBalance()) + totalAdded;
		userDatabase.allUsers->at(0).setBalance(newBalance);
		userDatabase.rewriteUserDatabase();
		cout << endl << "ATM Balance Updated!" << endl << endl;
	}
	else
	{
		cout << endl << "ERROR! Incorrect amount of each note entered, amount does not match the total being added!" << endl;
		cout << "Would you like to re-enter? (Y/N): ";
		cin >> tryAgain;

		if (tryAgain == "Y")
		{
			cout << "\nTotal amount of money being added: ";
			cin >> totalAdded;
			cout << endl << "Please enter the amount of each note being added to the ATM: " << endl << endl;
			cout << "Amount of FIVE(5) pound notes being added:	";
			cin >> newATMNotesFive;
			cout << "Amount of TEN(10) pound notes being added:	";
			cin >> newATMNotesTen;
			cout << "Amount of TWENTY(20) pound notes being added:	";
			cin >> newATMNotesTwenty;

			totalNotes = ((newATMNotesFive * 5) + (newATMNotesTen * 10) + (newATMNotesTwenty * 20));

			if (totalNotes == totalAdded)
			{
				cout << endl << "------------UPDATING DATABASE------------" << endl;
				newBalance = (userDatabase.allUsers->at(0).getBalance()) + totalAdded;
				userDatabase.allUsers->at(0).setBalance(newBalance);
				userDatabase.rewriteUserDatabase();
				cout << endl << "ATM Balance Updated!" << endl << endl;
			}
			else
			{
				cout << endl << "There has been an error, please report the problem to service!" << endl << endl;
			}

		}
	}

	returnToATMMaintenanceMenu(userDatabase);

}

/**
* updateReceiptAmount, function to update the reciept amount of the ATM within the array in userDatabase
*
* Writes the current receipt amount to the command window using the getOverdraftLimit function in
* the user database class as the admin user will never require an overdraft limit this section of the
* array will store the reciept amount instead. A message is then written to the command window asking the user
* if they wish to add another receipt roll to the ATM, their answer will be stored in receiptOption. An
* if statement will then run if the user has entered 'Y' displaying a message to the user that the database
* is being updated with the new receipt amount. A calculate is completed to add the current receipt amount
* and 1000 (for a new receipt roll) and stored within newReceiptAmount. The setOverdraftLimit function from the 
* class is then called to add the contents of the newReceiptAmount variable to the array. The rewritedatabase function
* is then called from the userdatabase class to write the updated array to the .txt file. A message is then displayed
* showing the updated receipt amount. The returnToAdminMenu function is then entered.
*
* @param receiptOption variable to contain the users answer as to whether they would like to add a new receipt roll
* @param newReceiptAmount variable to contain the newly calculated total reciept amount
* @see returnToAdminMenu
*/
void Admin::updateReceiptAmount(UserDatabase userDatabase)
{
	std::string receiptOption;
	int newReceiptAmount;

	cout << "Admin Menu: ATM Maintenance: Update Receipt Amount" << endl << endl;
	cout << "Current Receipt Amount: " << userDatabase.allUsers->at(0).getOverdraftLimit() << endl << endl;
	cout << "Do you wish to add a new receipt roll into the ATM? (Y/N): " ;
	cin >> receiptOption;

	if (receiptOption == "Y")
	{
		cout << endl << "------------UPDATING RECEIPT AMOUNT------------" << endl;
		newReceiptAmount = (userDatabase.allUsers->at(0).getOverdraftLimit()) + 1000;
		userDatabase.allUsers->at(0).setOverdraftLimit(newReceiptAmount);
		userDatabase.rewriteUserDatabase();
		cout << endl << "Receipt Amount Updated! New Receipt Amount is " << newReceiptAmount << endl << endl;
	}

	returnToATMMaintenanceMenu(userDatabase);
}

void Admin::viewTransactionHistory(UserDatabase userDatabase)
{

}

/**
* returnToAdminMenu, function to return the user to the admin menu
*
* Writes a message to the command window asking the user if they would like to return to the admin menu.
* The users answer is then taken and stored within the variable returnOption, which is used in an
* if statement which is the condition is met, returns the user to the admin menu, otherwise if the 
* condition is not met, the else statement is entered and a message thanking the user for using the
* service is shown instructing them to exit.
*
* @param returnOption variable to contain the users answer as to whether they would like to return to the admin menu
* @see adminMenu
*/
void Admin::returnToAdminMenu(UserDatabase userDatabase)
{
	std::string returnOption;

	cout << "Would you like to return to the Admin menu? (Y/N): ";
	cin >> returnOption;

	system("cls");

	if (returnOption == "Y")
	{
		adminMenu(userDatabase);
	}
	else
	{
		cout << "\n\n\n		Thanks for using this service, please press 'X' to exit!" << endl;
		cin >> returnOption;
	}
}

/**
* returnToATMMaintenanceMenu, function to return the user to the ATM Maintenance Menu
*
* Writes a message to the command window asking the user if they would like to return to the ATM Maintenance Menu.
* The users answer is then taken and stored within the variable returnOption, which is then used in an
* if statement, which is the condition is met, returns the user to the ATM Maintenance Menu, otherwise if the
* condition is not met, the else statement is entered and a message thanking the user for using the
* service is shown instructing them to exit.
*
* @param returnOption variable to contain the users answer as to whether they would like to return to the ATM Maintenance Menu
* @see atmMaintenanceMenu
*/
void Admin::returnToATMMaintenanceMenu(UserDatabase userDatabase)
{
	std::string returnOption;

	cout << "Would you like to return to the ATM Maintenance menu? (Y/N): ";
	cin >> returnOption;

	system("cls");

	if (returnOption == "Y")
	{
		atmMaintenanceMenu(userDatabase);
	}
	else
	{
		cout << "\n\n\n		Thanks for using this service, please press 'X' to exit!" << endl;
		cin >> returnOption;
	}
}