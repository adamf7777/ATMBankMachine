#include "UserDatabase.h"

using namespace std;

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


void UserDatabase::rewriteUserDatabase(std::vector<User> *allUsers)
{
	ofstream fout(filePath);
	std::string lineContents;

	for (int i = 0; i < getAllUsers().size(); i++) {
		fout << getAllUsers().at(i).getFirstName() << " "
			<< getAllUsers().at(i).getLastName() << " "
			<< getAllUsers().at(i).getAccountNumber() << " "
			<< getAllUsers().at(i).getInitialBalance() << " "
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

//returns array of all users 
std::vector<User> UserDatabase::getAllUsers() {
	return *allUsers;
}

//Updates the array with the current user - Beta
std::vector<User> UserDatabase::getCurrentUser() {


}

//takes a user, adds the user to the array of all users
void UserDatabase::addUser(User user) {
	allUsers->push_back(user);
}