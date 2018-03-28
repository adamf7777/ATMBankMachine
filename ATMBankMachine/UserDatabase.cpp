

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

	}

	userFile.close();

	sort(users.begin(), users.end(), [](User &s1, User &s2) { return s1.getInitialBalance() > s2.getInitialBalance(); });

}

/*User UserDatabase::getUserBalance()
{
	if (users.size() == 0)
		throw noUserFound();
	return users.at(0);
}*/