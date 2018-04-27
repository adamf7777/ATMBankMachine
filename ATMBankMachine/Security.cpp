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
 
void checkPincode(UserDatabase userdatabase, User currentUser)
{
	cout << currentUser.getAccountNumber();
	cout << currentUser.getPinCode();
	

}
