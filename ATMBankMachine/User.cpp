/**
* Gives users and manipulates user data required for user operation.
*
* @author	Adam Fawcett <fawcett-a@ulster.ac.uk>
* @license https://www.gnu.org/licenses/gpl-3.0.en.html
* @copyright Adam Fawcett 2018
*
*/


// Include the header files
#include "User.h"
#include "UserDatabase.h"


using namespace std;

/**
* String stream function to store user data as variables
*
* Reads in data from the database txt file and stores 
* data in the variables below
*
* @param hello number of hellos to print
* @param world number of worlds to print
* @return zero on failure, non-zero otherwise
* @see func_2 (optional links to other code)
*/
User::User(string userInformation)
{
	stringstream userStream(userInformation);
	userStream >> firstName;
	userStream >> lastName;
	userStream >> accountNumber;
	userStream >> balance;
	userStream >> overdraftLimit;
	userStream >> pinCode;
}


/**
* Function to get user's first name
*
* @return first name as string if successful, zero on failure
*/
string User::getFirstName()
{
	return firstName;
}


/**
* Function to get user's last name
*
* @return last name as string if successful, zero on failure
*/
string User::getLastName()
{
	return lastName;
}


/**
* Function to build user's full name
*
* Combines the first name and last name for the user and combines
* the two names and returns them as a single string.
*
* @return full name name as string if successful, zero on failure
*/
string User::getName()
{
	return firstName + " " + lastName;
}


/**
* Function to get user's account number
*
* @return account number as int if successful, zero on failure
*/
int User::getAccountNumber()
{
	return accountNumber;
}


/**
* Function to get user's balance
*
* @return balance as double if successful, zero on failure
*/
double User::getBalance()
{
	return balance;
}


/**
* Function to get user's overdraft limit
*
* @return overdraft limit as double if successful, zero on failure
*/
double User::getOverdraftLimit()
{
	return overdraftLimit;
}


/**
* Function to get user's pincode
*
* @return pincode as int if successful, zero on failure
*/
int User::getPinCode()
{
	return pinCode;
}


/**
* Function to set new pincode
* 
* Changes the old pincode to a new value.
*
* @param newPinCode 
* @see resetPinCode
*/
void User::setPinCode(int newPinCode)
{
	pinCode = newPinCode;
}


/**
* Function to set new balance
*
* Changes the old balance to a new value.
*
* @param newBalance
* @see printBalance
*/
void User::setBalance(double newBalance)
{
	balance = newBalance;
}


/**
* Function to display user's balance
*
* Displays the user's name along with their balance.
*
* @see printBalance
*/
void User::printBalance() //Make print user balance
{

	cout << endl;
	cout << firstName << ", ";
	//cout << "Name: " << user.getName() << endl;
	//cout << "Account Number: " << user.getAccountNumber() << endl;
	cout << "your current balance is: " << char(156) << balance << endl;
	cout << endl;
}


/**
* Function to display user's overdraft limit
*
* Displays the user's name along with their overdraft limit
*
* @see overdraftLimit
*/
void User::printOverdraft()
{

	cout << firstName << ", ";
	cout << "your current maximum overdraft limit is: " << char(156) << overdraftLimit << endl << endl;

}


/** 
* Function to allow the user to change their pincode
*
* Asks the user to enter a new pincode. 
* Before allowing pincode to update, checks performed to ensure
* matching pincodes are entered twice and the new pincode is 4 digits
* long. 
* If the above requirements are not met, an error message is displayed
* and returns to main menu.
*
* @param userDatabase to get the user details
* @param userInputIDNumber select the details for the correct user
* @see setPinCode
* @see rewriteUserDatabase
*/

void User::resetPinCode(UserDatabase userDatabase, int userInputIDNumber)
{

	// Ask user to enter new pincode twice
	int newPin, newPin1, newPin2;
	cout << "Your new pincode must contain four digits" << endl << endl;
	cout << "Please enter new pincode: ";
	cin >> newPin1;

	system("cls");
	cout << "Your new pincode must contain four digits" << endl << endl;
	cout << "Please re enter your new pincode: ";
	cin >> newPin2;

	
	// check that both of the pincodes entered match
	if (newPin1 == newPin2)
	{ // if pincodes are matching
		newPin = newPin1;

		// check if the pincode has 4 digits between
		// 1000 and 9999

		// if the value is outside these values display error 
		if ((newPin < 1000) || (newPin > 9999))
		{
			cout << "Error - the pin code must have 4 digits!" << endl;
		}

		// if value is within these values update pincode
		else
		{ 
			// set the pincode as new 
			User::setPinCode(newPin);
			
			// rewrite the database overwriting the old pincode for 
			// user who has changed their pincode
			userDatabase.allUsers->at(userInputIDNumber).setPinCode(newPin);
			userDatabase.rewriteUserDatabase();
			
			system("cls");

			// inform user of successful update
			cout << "Your pincode has been successfully updated!" << endl << endl;
		} // end of update pincode

	} // end of if pincodes are matching

	else {
		cout << "Error, the two pincodes do not match!" << endl;
		cout << "Please try again later" << endl;
	} // end of if pincodes don't match

} // end of reset pincode function



  /**
  * Function to allow the user to withdraw cash
  *
  * Asks the user to select cash withdrawl from list of given values.
  * Also allows user to select custom withdrawal amount.
  * If a preselected value, case break used to select withdrawal amount. 
  * If custom value, a check peformed to ensure value is divisible by
  * five as five pound notes are smallest note available/
  * If insufficient funds available, gives user option of overdraft.
  * Check performed to see if overdraft will cover transaction.
  *
  * @param userDatabase to get the user details
  * @param userInputIDNumber select the details for the correct user
  * @see printBalance
  * @see overdraftLimit
  * @see rewriteUserDatabase
  */
void User::withdrawCash(UserDatabase userDatabase, int userInputIDNumber)
{
	double withdrawalAmount, withdrawalCheck = 0, withdrawalBalance;
	int  withdrawalOption;
	char overdraftCheck;

	//cout << "Cash Withdrawal Menu" << endl << endl;
	printBalance();

	// allow user to select one of the 8 options
	cout << "Please select amount to be withdrawn:" << endl << endl;
	cout << "[1] " << char(156) << "10" << "		" << "[2] " << char(156) << "20" << endl;
	cout << "[3] " << char(156) << "40" << "		" << "[4] " << char(156) << "50" << endl;
	cout << "[5] " << char(156) << "60" << "		" << "[6] " << char(156) << "80" << endl;
	cout << "[7] " << char(156) << "100" << "	" << "[8] " << "Other Amount " << endl;

	cin >> withdrawalOption;

	system("cls");

	// if custom amount selected
	if (withdrawalOption == 8)
	{
		// tell user smallest note value available is five pounds
		cout << "Please note, this smallest available note value is " << char(156) << "5" << endl << endl;
		cout << "Please enter the amount you wish to withdraw" << endl << endl;
		cout << char(156) << " ";
		cin >> withdrawalAmount;

		// check that withdrawal amount is divisible by 5
		withdrawalCheck = (withdrawalAmount / 5);

		// if it can be divided into five pound notes
		// set withdrawal check as 0
		if (withdrawalCheck - (int)withdrawalCheck > 0.0)
		{
			withdrawalCheck = 0;
		} // end of check divisible by 5

		// if not set as 1
		else
		{
			withdrawalCheck = 1;
		}

	} // end of if withdrawal option = 8


	else // if the withdrawal option is not = 8
	{
		switch (withdrawalOption) {

		case 1:
			withdrawalAmount = 10;
			break;
		case 2:
			withdrawalAmount = 20;
			break;
		case 3:
			withdrawalAmount = 40;
			break;
		case 4:
			withdrawalAmount = 50;
			break;
		case 5:
			withdrawalAmount = 60;
			break;
		case 6:
			withdrawalAmount = 80;
			break;
		case 7:
			withdrawalAmount = 100;
			break;

		default:

			// if withdrawal option not between 1 and 8 display error
			cout << "Error, incorrect value selected." << endl;
			cout << "Please try again later" << endl;
		} // end of switch case
	} // end of else  for option other than 8


	// if the withdrawal check is successful
	// update balance

	if (withdrawalCheck == 1)
	{

		// if withdrawal amount is less than/ equal to balance
		// perform the transaction
		if (withdrawalAmount <= balance)
		{
			withdrawalBalance = (balance - withdrawalAmount);

			// rewrite userdatabase with new balance for the selected user
			User::setBalance(withdrawalBalance);
			userDatabase.allUsers->at(userInputIDNumber).setBalance(withdrawalBalance);
			userDatabase.rewriteUserDatabase();

			system("cls");

			cout << "Counting " << char(156) << withdrawalAmount << endl << endl;
			cout << "Please take your cash" << endl;
		} // end of sufficient balance

		else // if user insufficient funds to perform transaction
		 // allow them option to use overdraft
		{
			system("cls");
			cout << "You have insufficient funds for this transaction" << endl << endl;
			printOverdraft();
			cout << endl;
			cout << "Would you like to use your overdraft for this transaction? [Y/N]" << endl;
			cin >> overdraftCheck;

			if (overdraftCheck == 'Y')
			{

				if (withdrawalAmount <= (balance + overdraftLimit))
				{
					// if overdraft will cover the transaction
				}

				else
				{
					cout << "The overdraft limit is insufficient for this transaction" << endl;
				}

			} // end of insufficient funds

			// if amount selected not available display error message
			else
			{
				cout << "Error, this machine cannot dispense the amount of money you have requested" << endl;
			}


		} // end of withdraw cash function
	}
} // end of withdrawCash function

  /**
  * Function to allow the user lodge cash
  *
  * Asks user to enter the amount of cash they wish to lodge 
  * and then updates their accountbalance
  *
  * @param userDatabase to get the user details
  * @param userInputIDNumber select the details for the correct user
  * @see printBalance
  * @see setBalance
  * @see rewriteUserDatabase
  */
void User::lodgeCash(UserDatabase userDatabase, int userInputIDNumber) 
	{
	
	double lodgementAmount, lodgementBalance;

	cout << "Please enter the amount you of money you wish to lodge" << endl << endl;

	cout << char(156);
	cin >> lodgementAmount;


    // add lodgement amount onto existing balance
	lodgementBalance = balance + lodgementAmount;

	// set user balance equal to balance after lodgement and rewrite database
	User::setBalance(lodgementBalance);
	userDatabase.allUsers->at(userInputIDNumber).setBalance(lodgementBalance);
	userDatabase.rewriteUserDatabase();

	system("cls");

	// inform user of successful lodgment and display their new balance
	cout << "Your lodgement of " << char(156) << lodgementAmount << " has been completed" << endl;

	printBalance();

	}