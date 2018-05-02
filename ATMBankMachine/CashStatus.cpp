
/**
* Controls the notes depensed from the system.
*
* Provides variables based on the type of notes in the system
* which can be removed by the user when using the variable cashwithdrawal.
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


	/*void getMachineCashStatus()
	{


		int twentynotes;
		int withdrawalamount;
		int tenamount;
		int tennotes;
		int fiveamount;
		int notesdispensed;
		int fivenotes;
		int Balance;
		int twentybalance;
	}*/

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

		ifstream inFile;
		inFile.open("twentynotes.txt");
		
		/*
		check for error
		if (inFile.fail()){
		cout << "Error Opening File" << endl;
		*/

		cout << "100" << endl;
		ofstream twentyfile;
		
		//inFile.close("twentynotes.txt");
		
		
		Balance = (Balance - tennotes);
		twentyfile.close();


		tenamount = (currentUser.getWithdrawalAmount(withdrawalAmount) - (twentynotes * 20));		tennotes = (tenamount / 10);		cout << "Number of Ten pound notes:  " << tennotes << "\n";		ofstream tenfile;
		tenfile.open("tennotes.txt");
		tenfile << "balance";
		Balance = (Balance - tennotes);
		tenfile.close();
		fiveamount = (tenamount - (tennotes * 10));		fivenotes = (fiveamount / 5);		cout << "Number of Five pound notes:  " << fivenotes << "\n";		ofstream fivefile;
		fivefile.open("fivenotes.txt");
		fivefile << "500";
		Balance = (500 - fivenotes);
		fivefile.close();
		notesdispensed = (fiveamount - (fivenotes * 5));	}

	/*double CashStatus::getWithdrawalAmount(User user) {
		withdrawalAmount = 
	}*/
