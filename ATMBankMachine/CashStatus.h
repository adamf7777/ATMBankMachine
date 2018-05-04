#ifndef CashStatus_H_
#define CashStatus_H_

/**
* Controls the notes depensed from the system.
* Provides variables based on the type of notes in the system
* which can be removed by the user when using the variable cashwithdrawal.
* Unable to remove the number of notes from the text files
*
* @author Mícheál Glass <glass-m@ulster.ac.uk>
* @license https://www.gnu.org/licenses/gpl-3.0.en.html
* @copyright Mícheál Glass 2018
*
*/

#include <string>
#include <iostream>
#include <sstream> //string stream function

//using namespace std;


//class User;
class UserDatabase;
class CashStatus
{
public:
//void getMachineCashStatus(User currentUser, UserDatabase userDatabase);
void withdrawCash(User currentUser, UserDatabase userDatabase, double withdrawalAmount);


private:

};



#endif
/**
* The CashStatus class is the overseeing the dispensation and depositing of cash by recording the quantity of notes within the system
*
* Remove twenty pound notes, ten pound notes and five pound notes from system.
* Add twenty pound notes, ten pound notes and five pound notes from system.
*/#pragma once
