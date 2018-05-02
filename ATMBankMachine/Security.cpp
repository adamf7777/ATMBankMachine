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

//Security::security;
//currentUser.getPinCode();
 
int Security::pinCodeCheck(User currentUser, UserDatabase userDatabase)
{
	int requestUserPin;
	int retrievedPin;
	int pinCheckCount = 0;
	int pinSuccessful = 0;
	int pinStatusCheck;

	retrievedPin = currentUser.getPinCode();


	//requestUserPin = 1111;
	while ((pinSuccessful == 0) && (pinCheckCount <= 3))
	{

		cout << "Please enter pin" << endl;
		cin >> requestUserPin;

		if ((retrievedPin == requestUserPin) && pinCheckCount < 3)
		{
			pinSuccessful = 1;
		}

		else if (pinCheckCount < 2)
		{
			system("cls");

			pinStatusCheck = pinCheckCount;
			pinStatusCheck = pinStatusCheck + 2;

			cout << "Pin is incorrect - please try again" << endl << endl;
			cout << "Attempt [" << pinStatusCheck << " of 3]" << endl;
			
			pinCheckCount++;
			//return 0;
			pinSuccessful = 0;
		}

		else if (pinSuccessful == 0 && pinCheckCount >= 2)
		{
			//return 0;
			int getAccountNo;
			int getLineNo;
			int getLockPin;
			int accountLock;
			getAccountNo = currentUser.getAccountNumber();
			getLineNo = getAccountNo - 1000;

			
			userDatabase.allUsers->at(getLineNo).setPinCode(8357);
			userDatabase.rewriteUserDatabase();
			
			pinCheckCount = 5;
			system("cls");

			cout << "**************************************************" << endl;
			cout << "**               Security Alert!                **" << endl;
			cout << "**************************************************" << endl << endl;

			cout << "You have entered your pincode incorrectly 3 times!" << endl << endl;
			cout << "Your account has been locked " << endl << endl;
			cout << "You will need to contact your bank to unlock your account" << endl << endl;

			cout << "**************************************************" << endl;

			cout << "Press any key to exit " << endl;
			
			cin >> accountLock;

			//return 0;
			//pinSuccessful = 0;
			
		}

	}

	if (pinSuccessful == 0)
	{
		//cout << "The pin has been incorrectly entered " << endl << endl;
		return 0;
	}

	else 
	{
		return 1;
	}
}
