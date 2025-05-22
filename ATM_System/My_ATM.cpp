#include <iostream>
using namespace std;

class ATM {  //ATM class holding attributes and methods

private:			  //access specifier 
	int balance=5000;      //variable to hold account balance (can't be accessed outside of class because it is private)
public:
	
	void operations() {

	}

	int getBalance() {     //method to return account balance
		cout << "Balance: $" << balance << "\n";
		return balance;
	}
	void widthdrawl() {  //method to widthdrawl funds from account
		int amountOut;
		cout << "Enter the amount you would like to widthdrawl: \n";
		cin >> amountOut;
		while (amountOut > balance) {
			cout << "The widthdrawl amount exceeds funds available! Please try again\n";
			cin >> amountOut;
		}

		balance = balance - amountOut;
	}

	void deposit() {     //method to add funds to account
		int amountIn;
		cout << "Enter the amount you would like to deposit: \n";
		cin >> amountIn;
		balance = balance + amountIn;

		getBalance();
	}
};


int main() {

	cout << "Welcome to the ATM\n";
	ATM myAtm;  //object creation of ATM class
	bool sessionDone = false;  //boolean to determine if the user is done with the atm or not
	string sessionResponse=""; //holds answer to whether the user wants to make another transaction
	int transaction; //type of transaction user wants to make
	
	

	while (!sessionDone) {
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout << "Select a Transaction:\n\n1: Account Balance\n2: Deposit Funds\n3: Widthdrawl Funds\n\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cin >> transaction;

		switch (transaction) {

			case (1):
				myAtm.getBalance();
				break;
			case (2):
				myAtm.deposit();
				break;
			case (3):
				myAtm.widthdrawl();
				break;
		}

		cout << "Would you like to complete another transaction? (Yes/No): \n";
		cin >> sessionResponse;
		if (sessionResponse == "YES" || sessionResponse == "Yes" || sessionResponse == "yes") {
			sessionDone = false;

		}
		else {
			sessionDone = true;
		}
	}

	cout << "\nHave a great day!";

	return 0;

}