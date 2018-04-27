
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

using namespace std;
int amount;
int twentynotes;
int fivenotes;
int tennotes;
int withdrawal20;

int main()
{
	ifstream fivenotes("fivenotes.txt");
	string s;
	fivenotes >> s;

	ifstream tennotes("tennotes.txt");
	string j;
	tennotes >> j;

	ifstream twentynotes("twentynotes.txt");
	string c;
	twentynotes >> c;

if  20


	return 0;

}