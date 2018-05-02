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
 
void pinCodeCheck()
{
	int storeUserPin;

	cout << "Please Enter Pin Code:" << endl << endl;
	cin >> storeUserPin;

	if (storeUserPin < 1000 || storeUserPin > 9999)
	{
		while (storeUserPin < 1000 || storeUserPin > 9999)
		{
			cout << "Invalid Pin Code, Please Enter a 4 Digit Pin Code!" << endl;
			cout << "Please Enter Pin Code:" << endl;
				cin >> storeUserPin;
	 }
}


}
