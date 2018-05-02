#ifndef CashStatus_H_
#define CashStatus_H_

/**
* one line description of class or file
*
* optional, long description, spanning
* several lines.
*
* @author Adam Fawectt <fawcett-a@ulster.ac.uk>
* @license (url of your license)
* @copyright Adam Fawcett 2018
*
*/

#include <string>
#include <iostream>
#include <sstream> //string stream function

//using namespace std;


class User;
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
