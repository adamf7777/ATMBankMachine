#ifndef User_H
#define User_H
#include <string>
#include <iostream>

using namespace std;

class User
{
	

public: 
	//User(string firstname, string surname, int accountNumber, double initialBalance);
	User(int accountNumber);
	User();
	~User();

	int getAccountNumber();

private:
	
	//std::string firstname;
	//std::string surname;
	int accountNumber;
	double initialBalance;
	
	
};


#endif