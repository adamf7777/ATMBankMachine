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

	fout.close();
}

void UserDatabase::rewriteUserDatabaseNewUser()
{
	ofstream fout(filePath);
	std::string lineContents;
	//int newUserDatabaseSize = 22;

	for (int i = 0; i < 22; i++) {
		if (i < 21) {
			fout << getAllUsers().at(i).getFirstName() << " "
				<< getAllUsers().at(i).getLastName() << " "
				<< getAllUsers().at(i).getAccountNumber() << " "
				<< getAllUsers().at(i).getBalance() << " "
				<< getAllUsers().at(i).getOverdraftLimit() << " "
				<< getAllUsers().at(i).getPinCode();
		}

		else
		{
			cout << "22" << endl;
			
			fout << "Matthew " << "Cordner " << "1022 " << "1234 " << "250 " << "1234 " << endl;
			
		}
		//prevents an extra line being printed at end of file 
		if (i == getAllUsers().size()-1) {

			//cout << "Maatt" << endl;
			//fout << "Matthew " << "Cordner " << "1022 " << "1234 "<< "250 " << "1234 " <<endl;
		}
	
		
		else {
			
			//fout << "Matthew" << endl;
			//cout << "Matthew" << endl;
			
		}



		/*for (i = 21; i < 22; i++)
		{
			string name = "Matt";
			cout << "Matthew";
			fout << getAllUsers().at(i)
		}*/

		fout << endl;
	}
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

/*//Updates the array with the current user - Beta
std::vector<User> UserDatabase::getCurrentUser() {
}*/

//takes a user, adds the user to the array of all users
void UserDatabase::addUser(User user) {
	allUsers->push_back(user);
}