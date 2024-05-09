#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class account
{
    int acno;
    char name[50];
    int deposit;
    char phone[50];

public:
    void create_account();
    void show_account() const;
    void dep(int);
    void draw(int);
    void report() const;
    int retacno() const;
    int retdeposit() const;
};

void account::report() const
{
    cout << acno << setw(10) << " " << name << setw(10) << " " << phone << setw(6) << deposit << endl;
}

void account::create_account()
{
    cout << "\n\n================= NEW ACCOUNT FORM =================\n";
    cin.ignore();
    cout << "Enter the Account Holder's Name: ";
    cin.getline(name, 50);
    cout << "Enter the Account Number: ";
    cin >> acno;
    cin.ignore();
    cout << "Enter Phone Number: ";
    cin.getline(phone, 50);
    cout << "Enter Initial Amount: ";
    cin >> deposit;
}

void account::show_account() const
{
    cout << "\nAccount No. : " << acno;
    cout << "\nAccount Name : " << name;
    cout << "\nBalance Amount : " << deposit;
}

void account::dep(int x)
{
    deposit += x;
}

void account::draw(int x)
{
    deposit -= x;
}

int account::retacno() const
{
    return acno;
}

int account::retdeposit() const
{
    return deposit;
}

void new_account()
{
    account acc;
    ofstream outFile("accountDetails.dat", ios::binary | ios::app);
    acc.create_account();
    outFile.write(reinterpret_cast<char*>(&acc), sizeof(account));
    outFile.close();
}

void display_all_account()
{
    account acc;
    ifstream inFile("accountDetails.dat", ios::binary);
    if (!inFile)
    {
        cout << "\nFile could not be opened! Press any Key...";
        return;
    }
    cout << "\n\n\t\tACCOUNT HOLDER LIST";
    cout << "\n====================================================";
    cout << "\nACC NO.        NAME             PHONE NO.   Balance";
    cout << "\n====================================================\n";
    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(account)))
    {
        acc.report();
    }
    inFile.close();
}

void display_acc_details(int n)
{
    account acc;
    bool flag = false;
    ifstream inFile("accountDetails.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened! Press any Key...";
        return;
    }




    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(account)))
    {
        if (acc.retacno() == n)
        {
            cout << "\n---ACCOUNT STATUS---\n";
            acc.show_account();
            flag = true;
            break;
        }
    }
    inFile.close();
    if (!flag)
        cout << "\n\nAccount number does not exist";
}

void deposit_withdraw(int n, int option)
{
    int amt;
    bool found = false;
    account acc;
    fstream File("accountDetails.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be opened! Press any Key...";
        return;
    }
    while (File.read(reinterpret_cast<char*>(&acc), sizeof(account)))
    {
        if (acc.retacno() == n)
        {
            acc.show_account();
            if (option == 1)
            {
                cout << "\n\nEnter the Amount to Deposit: ";
                cin >> amt;
                acc.dep(amt);
            }
            else if (option == 2)
            {
                cout << "\n\nEnter the Amount to Withdraw: ";
                cin >> amt;
                int bal = acc.retdeposit() - amt;
                if (bal < 500)
                {
                    cout << "Insufficient balance";
                }
                else
                {
                    acc.draw(amt);
                }
            }
            int pos = -1 * static_cast<int>(sizeof(acc));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char*>(&acc), sizeof(account));
            cout << "\n\nRecord Updated!";
            found = true;
            break;
        }
    }
    File.close();
    if (!found)
        cout << "\n\nRecord Not Found";
}

void delete_account(int n)
{
    account acc;
    ifstream inFile("accountDetails.dat", ios::binary);
    if (!inFile)
    {
        cout << "\nFile could not be opened! Press any Key...";
        return;
    }
    ofstream outFile("Temp.dat", ios::binary);
    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(account)))
    {
        if (acc.retacno() != n)
        {
            outFile.write(reinterpret_cast<char*>(&acc), sizeof(account));
        }
    }
    inFile.close();
    outFile.close();
    remove("accountDetails.dat");
    rename("Temp.dat", "accountDetails.dat");
    cout << "\n\nRecord Deleted ..";
}

void login()
{
    int password = 0;
    cout << "\n\n\n\t  WELCOME!!!";
    cout << "\n========================================\n";
    while (password != 1234)
    {
        cout << "\n\nPlease enter the password to Login.";
        cout << "\n\n\tPassword: ";
        cin >> password;
        if (password == 1234)
        {
            cout << "\nLogin Success!!!";
            break;
        }
        else
        {
            cout << "\nIncorrect Password!!! Please try again.";
        }
    }
}

int main()
{
    
    
    try {
        char menu='0';
        login();

        while (menu != '6')
        {
            cout << "\n\n\n\t\tMAIN MENU";
            cout << "\n====================================================";
            cout << "\n1. NEW ACCOUNT";
            cout << "\n2. EXISTING ACCOUNT";
            cout << "\n====================================================";
            cout << "\nSelect an Option: ";
            cin >> menu;

            switch (menu)
            {
            case '1':
                new_account();
                break;

            case '2':
            {
                char ch;
                int num;
                do
                {
                    cout << "\n\n================= TRANSACTION MENU =================\n";
                    cout << "\n1. ALL ACCOUNT HOLDER LIST ";
                    cout << "\n2. BALANCE ENQUIRY ";
                    cout << "\n3. DEPOSIT AMOUNT ";
                    cout << "\n4. WITHDRAW AMOUNT ";
                    cout << "\n5. CLOSE AN ACCOUNT ";
                    cout << "\n6. EXIT";
                    cout << "\n====================================================";
                    cout << "\nSelect an Option: ";
                    cin >> ch;

                    switch (ch)
                    {
                    case '1':
                        display_all_account();
                        break;

                    case '2':
                        cout << "\n\n================= BALANCE DETAILS =================";
                        cout << "\nEnter the Account Number: ";
                        cin >> num;
                        display_acc_details(num);
                        break;

                    case '3':
                        cout << "\n\n================= ACCOUNT TRANSACTION =================";
                        cout << "\nEnter the Account Number: ";
                        cin >> num;
                        deposit_withdraw(num, 1);
                        break;

                    case '4':
                        cout << "\n\n================= ACCOUNT TRANSACTION =================";
                        cout << "\nEnter the Account Number: ";
                        cin >> num;
                        deposit_withdraw(num, 2);
                        break;

                    case '5':
                        cout << "\n\n================= DELETE ACCOUNT =================";
                        cout << "\nEnter the Account Number: ";
                        cin >> num;
                        delete_account(num);
                        break;

                    case '6':
                        cout << "\n====================================================";
                        cout << "\n\tTHANK YOU FOR USING OUR SERVICE!!!";
                        cout << "\n====================================================";
                        break;

                    default:
                        cout << "\a";
                    }
                } while (ch != '6');
                break;
            }

            default:
                cout << "\a";
            }
        }
    }
    catch (const exception& ex) {
        cout << "An exception occurred: " << ex.what() << endl;
    }
    catch (...) {
        cout << "An unknown exception occurred." << endl;
    }
    return 0;
}
