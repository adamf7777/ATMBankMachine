
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

	using namespace std;


	void getMachineCashStatus()
	{
	

	int twentynotes;
	int withdrawalamount;
	int tenamount;
	int tennotes;
	int fiveamount;
	int notesdispensed;
	int fivenotes;

	
		withdrawalamount = 10;
		twentynotes = (withdrawalamount / 20);
		cout << "Number of Twenty pound notes:  " << twentynotes << "\n";

		tenamount = (withdrawalamount - (twentynotes * 20));		tennotes = (tenamount / 10);		cout << "Number of Ten pound notes:  " << tennotes << "\n";		fiveamount = (tenamount - (tennotes * 10));		fivenotes = (fiveamount / 5);		cout << "Number of Five pound notes:  " << fivenotes << "\n";		notesdispensed = (fiveamount - (fivenotes * 5));	
	}




