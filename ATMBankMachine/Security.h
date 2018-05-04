 #ifndef Security_H_
#define Security_H_

/**
* Used to determine security protocols are being met before any transactions occur.
*
* Header File determining pin code is matching of account pin code.
* Takes into account who the current user is and cross references with the .txt file 
*
* @author	Christopher Hull <Faulkner-c5@ulster.ac.uk>
* @license https://www.gnu.org/licenses/gpl-3.0.en.html
* @copyright Christopher Hull 2018
*
*/

#include <string>
#include <iostream>

// String stream function gathers data from the user database txt file
#include <sstream> 

//The UserDatabase class works with the user class.
class UserDatabase;
class User;

class Security
{

public:
	//Defining public functions involving class parameters
	//Cross references the entered pin of the current user with the .txt file pin.
	int pinCodeCheck(User currentUser, UserDatabase userDatabase);
	
private: 
 
};

#endif


