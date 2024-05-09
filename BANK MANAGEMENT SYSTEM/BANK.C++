#include <iostream>
#include <string>
using namespace std;
const int NUM_ACCOUNTS = 5;  
struct Account {
    string name;
    string accountNumber;
    double balance;
    double loanAmount;
};
void DEPOSIT(Account& account, double amount);
void withdraw(Account& account, double amount);
void getBalance(const Account& account);
void applyLoan(Account& account, double amount);
int main() {
    Account accounts[NUM_ACCOUNTS];
    for (int i = 0; i < NUM_ACCOUNTS; ++i) {
        cout << "Enter account holder's name for account " << i + 1 << ": ";
        cin >> accounts[i].name;
        cout << "Enter account number for account " << i + 1 << ": ";
        cin >> accounts[i].accountNumber;
       cout << "Enter initial balance of the account " << i + 1 << ": ";
 cin>>accounts[i].balance ;
        accounts[i].loanAmount=0.0 ;
    }
    cout << "Accounts data has been entered." << endl;
cout << "\t=============================='';
    string enteredAccountNumber;
    cout << "Enter your account number: ";
    cin >> enteredAccountNumber;
    Account* currentUser = nullptr;
    for (int i = 0; i < NUM_ACCOUNTS; ++i) {
        if (enteredAccountNumber == accounts[i].accountNumber) {
            currentUser = &accounts[i];
            break;
        }
    }

    if (currentUser == nullptr) {
        cout << "Account not found. Exiting..." << endl;
        return 1;
    }
else {
    int Enter;
    while (true) {
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Get balance" << endl;
        cout << "4. Apply for a loan" << endl;
        cout << "5. Check loan balance" << endl;
        cout << "6. TO CHECK THE PROGRAM CREATOR " << endl;
        cout << "7. Quit" << endl;
        cout << "Enter what you want to perform: ";
        cin >> Enter;
 if (Enter == 1) 
{
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            DEPOSIT(*currentUser, amount);
        } 
else if (Enter == 2) 
{
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            withdraw(*currentUser, amount);
 }
 else if (Enter == 3) 
{
            getBalance(*currentUser);
   } 
else if (Enter == 4)
 {
            double loanAmount;
            cout << "Enter the loan amount: ";
            cin >> loanAmount;
            applyLoan(*currentUser, loanAmount);
  } 
else if (Enter == 5) 
{
            cout << "Loan balance: $" << currentUser->loanAmount << endl;
} 
else if (Enter == 6)
 {
            cout << "THE PROJECT CREATOR is " << endl;
              << "***** MOIZ ABBASI*****" << endl;
} 
else {
            break;
        }
    }
    cout << "No function is performed." << endl;
    return 0;
}
}
void DEPOSIT(Account& account, double amount) {
    account.balance += amount;
    cout << "Successfully deposited $" << amount << " into account " << account.accountNumber << endl;
}

void withdraw(Account& account, double amount) 
{
    if (account.balance < amount) 
{
        cout << "Error: Insufficient balance" << endl;
    } else {
        account.balance -= amount;
        cout << "Successfully withdrew $" << amount << " from account " << account.accountNumber << endl;
    }
}

void getBalance(const Account& account) 
{
    cout << "Account " << account.accountNumber << " balance: $" << account.balance << endl;
}

void applyLoan(Account& account, double amount)
 {
    if (account.loanAmount > 0.0) {
        cout << "You already have an existing loan. Please repay it before applying for a new loan." << endl;
    } 
else {
        account.loanAmount += amount;
        cout << "Loan of $" << amount << " applied for account " << account.accountNumber << endl;
    }
}