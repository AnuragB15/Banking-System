#include <bits/stdc++.h>

using namespace std;

// Base class representing a generic bank account
class Account {
protected:
    string id, name, address, city, state, accountType;
    int date, month, year, pincode, aadhar, pan;
    float balance;

public:
    Account() : balance(0), date(0), month(0), year(0), pincode(0), aadhar(0), pan(0) {}

    // Encapsulation: Getters and setters
    string getID() { return id; }
    float getBalance() { return balance; }
    string getAccountType() { return accountType; }

    void setBalance(float amount) { balance = amount; }

    virtual void openAccount();   // Abstraction
    virtual void depositMoney();
    virtual void withdrawMoney();
    virtual void accountDetail();

    string generateRandomID() {
        random_device rd;
        mt19937 rng(rd());
        uniform_int_distribution<int> dist(0, 99999999);
        ostringstream oss;
        oss << setw(8) << setfill('0') << dist(rng);
        return "NB" + to_string(year) + "-" + oss.str();
    }
};

// Derived class for Savings Account
class SavingsAccount : public Account {
public:
    void openAccount() override {
        system("clear");
        cout << "Opening Savings Account...\n";
        accountType = "Savings Account";
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter initial deposit (Min ₹2000): ₹";
        cin >> balance;
        while (balance < 2000) {
            cout << "Minimum balance should be ₹2000. Enter again: ₹";
            cin >> balance;
        }
        id = generateRandomID();
        cout << "Savings Account created successfully. ID: " << id << endl;
    }
};

// Derived class for Current Account
class CurrentAccount : public Account {
public:
    void openAccount() override {
        system("clear");
        cout << "Opening Current Account...\n";
        accountType = "Current Account";
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter initial deposit (Min ₹5000): ₹";
        cin >> balance;
        while (balance < 5000) {
            cout << "Minimum balance should be ₹5000. Enter again: ₹";
            cin >> balance;
        }
        id = generateRandomID();
        cout << "Current Account created successfully. ID: " << id << endl;
    }
};

// Polymorphism through pointers
int main() {
    Account* account = nullptr;
    int choice;
    bool accountCreated = false;

    do {
        system("clear");
        cout << "1) Open Account\n2) Deposit Money\n3) Withdraw Money\n4) View Account Details\n5) Exit\n";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Select Account Type (1: Savings, 2: Current): ";
                int type;
                cin >> type;
                if (type == 1)
                    account = new SavingsAccount();
                else
                    account = new CurrentAccount();
                
                account->openAccount();
                accountCreated = true;
                break;

            case 2:
                if (accountCreated) {
                    account->depositMoney();
                } else {
                    cout << "No account found! Please open an account first.\n";
                }
                break;

            case 3:
                if (accountCreated) {
                    account->withdrawMoney();
                } else {
                    cout << "No account found! Please open an account first.\n";
                }
                break;

            case 4:
                if (accountCreated) {
                    account->accountDetail();
                } else {
                    cout << "No account found! Please open an account first.\n";
                }
                break;

            case 5:
                cout << "Exiting...\n";
                delete account;
                exit(0);

            default:
                cout << "Invalid choice! Try again.\n";
        }
        cout << "Press Enter to continue...\n";
        cin.ignore();
        cin.get();
    } while (true);

    return 0;
}
