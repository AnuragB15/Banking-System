
#include <bits/stdc++.h>

using namespace std;

class Bank
{
    private:
    
        string id = "", name="", address="", accountType="", city="", state="";
        
        char type;
        
        int date = 0, month = 0, year = 0, pincode = 0, aadhar = 0, pan = 0;
        
        float balance = 0;
    
    public:
    
        string generateRandomID();
    
        void openAccount();
        
        void depositMoney();
        
        void withdrawMoney();
        
        void accountDetail();
};

string Bank :: generateRandomID() 
{
    random_device rd;
    
    mt19937 rng(rd());
    
    uniform_int_distribution<int> dist(0, 99999999);

    ostringstream oss; 
    
    oss << std::setw(8) << std::setfill('0') << dist(rng);
    
    return oss.str();
}

void Bank ::  openAccount()
{
    
    system("clear");
    
    string text = "Open Account";
    
    string underline(text.length(), '-');
    
    cout<<text<<endl<<underline<<endl<<endl;
    
    cout<<"Enter your full name: ";
    
    cin.ignore();
    
    getline(cin>>ws, name);
    
    cout<<"Enter your city: ";
    
    getline(cin>>ws, city);
    
    cout<<"Enter your state: ";
    
    getline(cin>>ws, state);
    
    cout<<"Enter your address: ";
    
    getline(cin>>ws, address);
    
    cout<<"Enter your pincode: ";
    
    cin>>pincode;
    
    cout<<"Enter your birth year: ";
    
    cin>>year;
    
    cout<<"Enter your birth month(month number): ";
    
    cin>>month;
    
    cout<<"Enter your birth date: ";
    
    cin>>date;
    
    cout<<"Enter Aadhar number: ";
    
    cin>>aadhar;
    
    cout<<"Enter Pancard number: ";
    
    cin>>pan;
    
    string temp = generateRandomID();
    
    id = "NB" + to_string(year) + "-" + temp;
    
    system("clear");
    
    cout<<"To create current account click 'C'. To create savings account click 'S': ";
    
    cin>>type;
    
    system("clear");
    
    while(!(type == 'C' || type == 'c' || type == 'S' || type == 's' ))
    {
        system("clear");
        
        cout<<"Wrong key entered!! Re-enter the correct key to specify account type" << endl << endl;
        
        cout<<"To create current account click 'C'. To create savings account click 'S': ";
        
        cin>>type;
    }
    
    system("clear");
    
    if(type == 'C' || type == 'c') accountType = "Current Account";
    
    else accountType = "Savings Account";
    
    cout<<"Please enter the minimum amount to complete the account opening process(Minimum ₹2000): ₹";
    
    cin>>balance;
    
    system("clear");
    
    while(balance < 2000)
    {
        system("clear");
        
        cout<<"Amount entered is not sufficient! Amount should be more than ₹2000." << endl;
        
        cout << "Enter amount: ₹";
        
        cin>>balance;
    }
    
    system("clear");
    
    cout<<"Dear customer, your "<<accountType<<" have been created. Welcome to National Bank!";
}

void Bank :: depositMoney()
{
    
    system("clear");
    
    string text = "Deposit Amount";
    
    string underline(text.length(), '-');
    
    cout<<text<<endl<<underline<<endl<<endl;
    
    int deposit;
    
    cout<<"Please enter the amount you want to deposit: ₹";
    
    cin>>deposit;
    
    balance = balance + deposit;
    
    cout<<"Dear customer, your current balance is: ₹"<<balance;
    
    cout<<endl;
}

void Bank :: withdrawMoney()
{
    
    system("clear");
    
    string text = "Withdraw Amount";
    
    string underline(text.length(), '-');
    
    cout<<text<<endl<<underline<<endl<<endl;
    
    int withdraw;
    
    cout<<"Please enter amount you want to withdraw: ₹";
    
    cin>>withdraw;
    
    while(withdraw > balance)
    {
        cout<<"Insufficient balance!!"<<endl;
        
        cout<<"If you want to continue press 'Y', else if you want to exit press 'N': "<<endl;
        
        char temp;
        
        cin>>temp;
        
        if(temp == 'N' || temp == 'n') exit(0);
        
        else
        {
            cin>>withdraw;
        }
    }
    
    balance = balance - withdraw;
    
    cout<<"Dear customer, your current balance is: ₹"<<balance;
    
    cout<<endl;

}

void Bank :: accountDetail()
{
    
    system("clear");
    
    string text = "Account Details:";
    
    string underline(text.length(), '-');
    
    cout<<text<<endl<<underline<<endl<<endl;
    
    cout<<"Customer-ID: "<<id<<endl;
    
    cout<<"Name: "<<name<<endl;
    
    string fullAddress = address + ", " + city + ", " + state;
    
    cout<<"Address: "<<fullAddress<<endl;
    
    cout<<"PINCODE: "<<pincode<<endl;
    
    cout<<"Date of Birth: "<<date<<"/"<<month<<"/"<<year<<endl;
    
    cout<<"Your current balance is: ₹"<<balance<<endl;
    
    cout<<"Your Aaadhar number is: "<<aadhar<<endl;
    
    cout<<"Your Pan card number is: "<<pan<<endl;
}

int main()
{
    
    int option, continueProcess;
    
    Bank* obj = new Bank();
    
    string header = "Welcome to National Bank!";
    
    string underline1(header.length(), '-');
    
    cout<<header<<endl<<underline1<<endl<<endl;
    
    bool accountStatus = false;
    
    cout<<"To proceed accordingly please select any one of the options given below: "<<endl<<endl;
    
    do{
        
        cout<<"1) Open Account."<<endl;
    
        cout<<"2) Deposit Money."<<endl;
    
        cout<<"3) Withdraw Money."<<endl;
    
        cout<<"4) Display Account Detail."<<endl;
    
        cout<<"5) Exit."<<endl<<endl;
        
        cin>> option;
        
        system("clear");
        
        switch(option)
        {
            case 1:
            
            obj->openAccount();
            
            accountStatus = true;
            
            break;
            
            case 2:
            
            if(accountStatus) obj->depositMoney();
            
            else
            {
                cout<<"No account found!"<<endl; 
            
                cout<<"Create an account.";
            }
            
            break;
            
            case 3:
            
            if(accountStatus) obj->withdrawMoney();
            
            else
            {
                cout<<"No account found!"<<endl;
            
                cout<<"Create an account.";
            }
            
            break;
            
            case 4:
            
            if(accountStatus) obj->accountDetail();
            
            else
            {
                cout<<"No account found!"<<endl;
            
                cout<<"Create an account.";
            }
            
            break;
            
            case 5:
            
            exit(0);
            
            default:
            
            cout<<"Wrong key entered! Try again."<<endl;
            
            break;
        }
        
        cout<<endl;
        
        cout<<"If you want to continue press 1, else if you want to exit press 0"<<endl;
        
        system("clear");
        
        cin>>continueProcess;
        
        if(!continueProcess) exit(0);
    }
    
    while(continueProcess);

    return 0;
}
