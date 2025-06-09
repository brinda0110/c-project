#include <iostream>
#include <string>
using namespace std;


class BankAccount
 {
protected:
    string accountNumber;
    string accountHolderName;

private:
    double balance;

public:
    BankAccount(string accNum = "", string holderName = "", double initialBalance = 0.0)
        : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance) {}

    virtual ~BankAccount() {}

    void deposit(double amount) 
	{
        if (amount > 0)
		 {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else 
		{
            cout << "Invalid amount!" << endl;
        }
    }

    virtual void withdraw(double amount) 
	{
        if (amount <= balance) 
		{
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else 
		{
            cout << "Insufficient balance!" << endl;
        }
    }

    double getBalance() const 
	{
        return balance;
    }

    virtual void displayAccountInfo() const
	 {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual void calculateInterest() const = 0;

    string getAccountNumber() const
	 {
        return accountNumber;
    }
};


class SavingsAccount : public BankAccount 
{
private:
    double interestRate;

public:
    SavingsAccount(string accNum, string holderName, double balance, double rate)
        : BankAccount(accNum, holderName, balance), interestRate(rate) {}

    void calculateInterest() const override
	 {
        double interest = getBalance() * interestRate / 100;
        cout << "Savings Account Interest: " << interest << endl;
    }
};


class CheckingAccount : public BankAccount 
{
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNum, string holderName, double balance, double limit)
        : BankAccount(accNum, holderName, balance), overdraftLimit(limit) {}

    void withdraw(double amount) override 
	{
        if (amount <= getBalance() + overdraftLimit) 
		{
            double bal = getBalance();
            if (amount <= bal)
			 {
                BankAccount::withdraw(amount);
            } else 
			{
                double overdraftUsed = amount - bal;
                cout << "Overdraft used: " << overdraftUsed << endl;
                BankAccount::withdraw(bal);
            }
        } else 
		{
            cout << "Exceeds overdraft limit!" << endl;
        }
    }

    void calculateInterest() const override
	 {
        cout << "Checking accounts do not earn interest." << endl;
    }
};


class FixedDepositAccount : public BankAccount
 {
private:
    int term; 

public:
    FixedDepositAccount(string accNum, string holderName, double balance, int t)
        : BankAccount(accNum, holderName, balance), term(t) {}

    void calculateInterest() const override 
	{
        double rate = 6.5;
        double interest = getBalance() * rate * term / (100 * 12);
        cout << "Fixed Deposit Interest for " << term << " months: " << interest << endl;
    }
};


int main() 
{
    const int MAX_ACCOUNTS = 100;
    BankAccount* accounts[MAX_ACCOUNTS];
    int accountCount = 0;

    int choice;
    do {
        cout << "\n--- Bank Account Management System ---\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Create Fixed Deposit Account\n";
        cout << "4. Deposit\n";
        cout << "5. Withdraw\n";
        cout << "6. Display Account Info\n";
        cout << "7. Calculate Interest\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        string accNum, name;
        double balance, amount;
        double rate, limit;
        int term;

        switch (choice) 
		
		{
        case 1:
            if (accountCount < MAX_ACCOUNTS) 
			{
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Holder Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Initial Balance: ";
                cin >> balance;
                cout << "Enter Interest Rate: ";
                cin >> rate;
                accounts[accountCount++] = new SavingsAccount(accNum, name, balance, rate);
                cout << "Savings Account created.\n";
            }
            break;

        case 2:
            if (accountCount < MAX_ACCOUNTS)
			 {
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Holder Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Initial Balance: ";
                cin >> balance;
                cout << "Enter Overdraft Limit: ";
                cin >> limit;
                accounts[accountCount++] = new CheckingAccount(accNum, name, balance, limit);
                cout << "Checking Account created.\n";
            }
            break;

        case 3:
            if (accountCount < MAX_ACCOUNTS) 
			{
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Holder Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Initial Balance: ";
                cin >> balance;
                cout << "Enter Term (months): ";
                cin >> term;
                accounts[accountCount++] = new FixedDepositAccount(accNum, name, balance, term);
                cout << "Fixed Deposit Account created.\n";
            }
            break;

        case 4:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            for (int i = 0; i < accountCount; ++i) {
                if (accounts[i]->getAccountNumber() == accNum) {
                    accounts[i]->deposit(amount);
                    break;
                }
            }
            break;

        case 5:
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            for (int i = 0; i < accountCount; ++i) {
                if (accounts[i]->getAccountNumber() == accNum) {
                    accounts[i]->withdraw(amount);
                    break;
                }
            }
            break;

        case 6:
            cout << "Enter Account Number: ";
            cin >> accNum;
            for (int i = 0; i < accountCount; ++i) {
                if (accounts[i]->getAccountNumber() == accNum) {
                    accounts[i]->displayAccountInfo();
                    break;
                }
            }
            break;

        case 7:
            cout << "Enter Account Number: ";
            cin >> accNum;
            for (int i = 0; i < accountCount; ++i) {
                if (accounts[i]->getAccountNumber() == accNum) {
                    accounts[i]->calculateInterest();
                    break;
                }
            }
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

   
    for (int i = 0; i < accountCount; ++i) {
        delete accounts[i];
    }

    return 0;
}
/*output:
--- Bank Account Management System ---
1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest
0. Exit
Enter choice: 1
Enter Account Number: 1002
Enter Holder Name: pintu
Enter Initial Balance: 45000
Enter Interest Rate: 4
Savings Account created.

--- Bank Account Management System ---
1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest
0. Exit
Enter choice: 2
Enter Account Number: 1002
Enter Holder Name: vidhya
Enter Initial Balance: 34000
Enter Overdraft Limit: 32000
Checking Account created.

--- Bank Account Management System ---
1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest
0. Exit
Enter choice: 3
Enter Account Number: 1006
Enter Holder Name: erica
Enter Initial Balance: 56000
Enter Term (months): 3
Fixed Deposit Account created.

--- Bank Account Management System ---
1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest
0. Exit
Enter choice: 4
Enter Account Number: 1006
Enter Amount to Deposit: 390000
Deposited: 390000

--- Bank Account Management System ---
1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest
0. Exit
Enter choice: 5
Enter Account Number: 1008
Enter Amount to Withdraw: 230000

--- Bank Account Management System ---
1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest
0. Exit
Enter choice: 6
Enter Account Number: 1002

Account Number: 1002
Account Holder: pintu
Balance: 45000

--- Bank Account Management System ---
1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest
0. Exit
Enter choice: 7
Enter Account Number: 1004

--- Bank Account Management System ---
1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest
0. Exit
Enter choice: 0
Exiting...
*/