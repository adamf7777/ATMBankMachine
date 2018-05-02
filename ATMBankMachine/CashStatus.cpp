
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

	void CashStatus::withdrawCash(User currentUser, UserDatabase userDatabase)
	{
		//withdrawalAmount for number of notes
		int twentynotes;
		int withdrawalamount;
		int tenamount;
		int tennotes;
		int fiveamount;
		int notesdispensed;
		int fivenotes;
		int Balance;
		int twentybalance;


		twentynotes = (currentUser.getWithdrawalAmount() 20);
		cout << "Number of Twenty pound notes:  " << twentynotes << "\n";
		ofstream twentyfile;
		twentyfile.open("tennotes.txt");
		twentyfile << "balance";
		Balance = (Balance - tennotes);
		twentyfile.close();


		tenamount = (withdrawalamount - (twentynotes * 20));		tennotes = (tenamount / 10);		cout << "Number of Ten pound notes:  " << tennotes << "\n";		ofstream tenfile;
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

	//}
