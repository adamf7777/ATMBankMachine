/**
* one line description of class or file
*
* @author	Adam Fawcett <fawcett-a@ulster.ac.uk>
* @license https://www.gnu.org/licenses/gpl-3.0.en.html
* @copyright Adam Fawcett 2018
*
*/
#include "UserDatabase.h"
//#include "Admin.h"


using namespace std;

/**
* Function to gather data from database file
*
* Opens the file by getting the filepath 
*
*/
UserDatabase::UserDatabase(string inputFilePath)
{
	filePath = inputFilePath;
	ifstream userFile(filePath);

	string lineContents;
	while (!userFile.eof())
	{
		getline(userFile, lineContents);

		User s(lineContents);
		users.push_back(s);

		addUser(s);
	}

	userFile.close();

}

/**
* Function to rewrite the database
*
* Rewrites the textfile for all of the users
* using the fout function
* Gathers the user info for each user and writes
* each user to a line in the database
*
* @param getAllUsers to call up the array with all user data 
* @param getFirstName to get first name for each user
* @param getLastName to get last name for each user
* @param getAccountNumber to get account number for each user
* @param getBalance to get balance for each user
* @param getOverDraftLimit to get overdraft limit for each user
* @param getPinCode to get pincode for each other
* @see getAllUsers 
*/
void UserDatabase::rewriteUserDatabase()
{
	ofstream fout(filePath);
	std::string lineContents;

	// for each user print all parameters to a single line
	// take a new line for each user
	for (int i = 0; i < getAllUsers().size(); i++) {
		fout << getAllUsers().at(i).getFirstName() << " "
			<< getAllUsers().at(i).getLastName() << " "
			<< getAllUsers().at(i).getAccountNumber() << " "
			<< getAllUsers().at(i).getBalance() << " "
			<< getAllUsers().at(i).getOverdraftLimit() << " "
			<< getAllUsers().at(i).getPinCode();
		
		//prevents an extra line being printed at end of file 
		if (i == getAllUsers().size() - 1) {
		}
		else {
			fout << endl;
		}
	}

	// close the txt file
	fout.close();
}


/**
* Function to store all user data
*
* Creates a vector array which stores all the 
* data for each user.
*
* @return allUsers as a string
*/
std::vector<User> UserDatabase::getAllUsers() {
	return *allUsers;

}



/**
* Function to add new user to the database
*
* Passes in temp user from Admin.cpp into the
* next available line for storage in database
*
* @param user passed in
* @see Admin.addUser
*/
void UserDatabase::addUser(User user) {
	allUsers->push_back(user);
}

/**
* Function to add new user to the database
*
* Passes in temp user from Admin.cpp into the
* next available line for storage in database
*
* @param user passed in
* @see Admin.addUser
*/
//  adds user to array list of all users and rewrites the database
void UserDatabase::addUser(User* user) {
	allUsers->push_back(*user);
	rewriteUserDatabase();

	return;
}

