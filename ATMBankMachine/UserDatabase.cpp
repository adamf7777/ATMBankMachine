#include "UserDatabase.h"

using namespace std;

UserDatabase::UserDatabase(string filePath)
{
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

//UserDatabase::UserDatabase(string filePath)
//{
//
//	ifstream userFile(filePath);
//	string lineContents;
//
//	while (!userFile.eof()) //while not at end of file 
//	{
//		getline(userFile, lineContents);
//
//		User x(lineContents);
//		//adds the user to the array of users 
//		//addUser(x);
//	}
//
//	userFile.close();
//}
//
void UserDatabase::rewriteUserDatabase(std::string filePath)
{
	ofstream fout(filePath);
	string lineContents;

	

	fout.close();
}

//returns array of all users 
std::vector<User> UserDatabase::getAllUsers() {
	return *allUsers;
}

//takes a user, adds the user to the array of all users
void UserDatabase::addUser(User user) {
	allUsers->push_back(user);
}