
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
#include <fstream>
#include "User.h"
#include "UserDatabase.h"
#include "CashStatus.h"
#include "Admin.h"

	using namespace std;

	/*
	* funtion created to remove the correct amount of notes away from the specific text file
	* using the withdrawl amount that was created in the user class
	*/


	void CashStatus::withdrawCash(User currentUser, UserDatabase userDatabase, double withdrawalAmount)
	{
		//withdrawalAmount for number of notes
		double twentynotes;
		//int withdrawalamount;
		double dispenseAmount;
		double tenamount;
		double tennotes=0;
		double fiveamount;
		double notesdispensed;
		double fivenotes;
	
		double twentybalance;
		double Balance = 0;

		dispenseAmount = currentUser.getWithdrawalAmount(withdrawalAmount);

		twentynotes = (dispenseAmount / 20);
		cout << "Number of Twenty pound notes:  " << twentynotes << "\n";
		fstream inFile;
		inFile.open("twentynotes.txt", ios::out));
		
		/*
		check for error
		if (inFile.fail()){
		cout << "Error Opening File" << endl;0
		*/

		int numberoftwenty = 500;
		int newtwenty = numberoftwenty - twentynotes;
		tenfile << newtwenty << endl;
		inFile.close();
		//inFile.close("twentynotes.txt");
			

		//remove the required amount of £20 notes from the withdrawl amount to find out how many £10 notes are required
		tenamount = (currentUser.getWithdrawalAmount(withdrawalAmount) - (twentynotes * 20));		tennotes = (tenamount / 10);		cout << "Number of Ten pound notes:  " << tennotes << "\n";		fstream tenfile;
		tenfile.open("tennotes.txt", ios::out));
		//i set the number of notes in the text file to 500 as i had difficulty trying to remove the number of tennotes from an orginal number on the text file
		int numberoftens = 500;
		int newten = numberoftens - tennotes;
		tenfile << newten << endl;
		tenfile.close();
		fiveamount = (tenamount - (tennotes * 10));		fivenotes = (fiveamount / 5);		cout << "Number of Five pound notes:  " << fivenotes << "\n";		fstream fivefile;
		fivefile.open("fivenotes.txt", ios::out));
		//i set the number of notes in the text file to 500 as i had difficulty trying to remove the number of tennotes from an orginal number on the text file
		int numberoffives = 500;
		int newfive = numberoffives - fivenotes;
		tenfile << newfive << endl;
		fivefile.close();
		notesdispensed = (fiveamount - (fivenotes * 5));	}

	/*double CashStatus::getWithdrawalAmount(User user) {
		withdrawalAmount = 
	}*/
