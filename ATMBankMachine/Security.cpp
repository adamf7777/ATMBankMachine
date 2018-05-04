/**
* Checks Security protocols ensuring the correct user is accessing the correct account
*
* @author	Christopher Hull <Faulkner-c5@ulster.ac.uk>
* @license https://www.gnu.org/licenses/gpl-3.0.en.html
* @copyright Christopher Hull 2018
*
*/

using namespace std;
// Include Header Files
#include "Security.h"
#include "UserDatabase.h"
#include "User.h"

/**
* System upon start up asks for Account ID
* Then asks for Pin Code, below checks the entered pin with the 
* retrieved pin from the .txt file and checks if they are matching,
* if it is a failed or invalid attempt, it asks the user for the pin again
* whilst showcasing that the user is now on attempt 2 out of 3.
* If failed after 3 attempts it returns the card and locks the account with a
* set pin code that the user will not know and will have to contact their 
* bank to rectify any issue.
*
*@param requestUserPin variable that stores the user pin when entered
*@param retrievedPin variable that retrieves thecorrect pin
*@param pinCheckCount this variable counts the amount of times the pin has been entered
*@return if pin is correctly entered returns 1 and goes to next interface
*/
 
int Security::pinCodeCheck(User currentUser, UserDatabase userDatabase)
{
	int requestUserPin;
	int retrievedPin;
	int pinCheckCount = 0;
	int pinSuccessful = 0;
	int pinStatusCheck;

	retrievedPin = currentUser.getPinCode();


	
	while ((pinSuccessful == 0) && (pinCheckCount <= 3))
	{
		cout << "************************************************************************" << endl << endl;
		cout << "                      Welcome to Bank of Ulster                         " << endl << endl;
		cout << "************************************************************************" << endl << endl;
		cout << "Please enter your Pin Number " << endl << endl;
		cout << "Pin Number: ";
		cin >> requestUserPin; // waits for user pin input

		if ((retrievedPin == requestUserPin) && pinCheckCount < 3)// when the pin from the .txt file matches the user entered one and the count is less than 3 proceed to the next interface
		{
			pinSuccessful = 1;
		}

		else if (pinCheckCount < 2)
		{
			system("cls"); // Clears Command Window

			pinStatusCheck = pinCheckCount;
			pinStatusCheck = pinStatusCheck + 2;

			cout << "Pin is incorrect - please try again" << endl << endl;
			cout << "Attempt [" << pinStatusCheck << " of 3]" << endl;
			
			pinCheckCount++; // Adds 1 to the pin counter if incorrectly entered
			
			pinSuccessful = 0;
		}

		else if (pinSuccessful == 0 && pinCheckCount >= 2)
		{
			
			
			//account gets locked if 
			//pin was incorrectly entered 3 times.
			
			int getAccountNo;
			int getLineNo;
			int getLockPin;
			int accountLock;
			getAccountNo = currentUser.getAccountNumber();
			getLineNo = getAccountNo - 1000;

			
			userDatabase.allUsers->at(getLineNo).setPinCode(8357);
			userDatabase.rewriteUserDatabase();
			
			pinCheckCount = 5;
			system("cls"); // Clears Command Window

			cout << "**************************************************" << endl;
			cout << "**               Security Alert!                **" << endl;
			cout << "**************************************************" << endl << endl;

			cout << "You have entered your pincode incorrectly 3 times!" << endl << endl;
			cout << "Your account has been locked " << endl << endl;
			cout << "You will need to contact your bank to unlock your account" << endl << endl;

			cout << "**************************************************" << endl;

			cout << "Press any key to exit " << endl;
			
			cin >> accountLock;

			
			
		}

	}

	if (pinSuccessful == 0)
	{
		
		return 0;
	}

	else 
	{
		return 1;
	}
}
