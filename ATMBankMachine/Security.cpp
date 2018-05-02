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

	retrievedPin = currentUser.getPinCode();


	//requestUserPin = 1111;
	while (pinSuccessful == 0 && pinCheckCount <= 2)
	{

		cout << "Please enter pin" << endl;
		cin >> requestUserPin;

		if ((retrievedPin == requestUserPin) && pinCheckCount < 3)
		{
			pinSuccessful = 1;
		}

		else if (pinCheckCount < 3)
		{
			pinCheckCount++;
			//return 0;
			pinSuccessful = 0;
		}

		else if (pinCheckCount >= 2)
		{
			//return 0;

			pinSuccessful = 0;
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
