#include <iostream>

using namespace std;

int main(void);


int main(void)
{
	int userInput;
	float withdrawAmount;
	float userBalance = 642;
	float machineBalance = 10000;

	cout << "Welcome to Bank of Ulster \n\n";
	cout << "Please select one of the options below:\n";

	cout << "[1] Cash Withdrawal\n";
	cout << "[2] On-screen balance enquiry \n";
	cout << "[3] Cash - lodgement \n";
	cout << "[4] Admin Access \n";

	cin >> userInput;


	switch (userInput) {
	case 1:
		cout << "Cash Withdrawl Menu\n\n";
		cout << "Please enter the amount of money you would like to withdraw in GBP: \n";


		cin >> withdrawAmount;
		//cout << "\n";

		if (withdrawAmount < (machineBalance))
		{
			cout << "test \n";
			//userBalance = userBalance - withdrawAmount;
			//machineBalance = machineBalance - withdrawAmount;

			cout << "Transaction Approved\n";

			cout << "Counting your money\n";
			//Sleep(10000);
			cout << "Please take your money";
		}

		else if (withdrawAmount >= machineBalance)
		{
			cout << "The machine has insufficient funds for this transaction\n";
			cout << "Please try again later \n";

		}

		else if (withdrawAmount > userBalance)
		{
			cout << "Insufficient funds available in your account \n";
		}

		break;

	case 2:
		cout << "Do nothing";

		break;

	case 3:
		cout << "Do nothing 3";

		break;

	case 4:
		cout << userBalance;
		cout << machineBalance;

	}

	cout << "Would you like any further services?";
	cin >> userInput;


}