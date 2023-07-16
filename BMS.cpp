#include<iostream>
#include<iomanip>
#include<fstream>
#include<cctype>

using namespace std;

class Bank_Account {
    int account_number;
    char name[50];
    char type;
    int Money_Deposit;

public:
    void modify();
    void report() const;
    int retacno() const{
        return account_number;
    }
    void dep(int x){
        Money_Deposit+=x;
    }
    void draw(int x) {
        Money_Deposit-=x;
    }
    int retdeposit() const{
        return Money_Deposit;
    }
    void create_account();
    void Display_Account();

};
void Bank_Account::report() const{
    cout<<account_number<<setw(10)<<" "<<name<<setw(10)<<type<<setw(10)<<Money_Deposit<<endl;
    
}
void Bank_Account::modify(){
    cout<<"\tAccount number: "<<account_number<<endl;
    cout<<"\tModify account holder name: ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\tModify type of account: ";
    cin>>type;
    type=toupper(type);
    cout<<"\tModify balance amount: ";
    cin>>Money_Deposit;
}

void write_account();
void display_details(int);
void delete_account(int);
void display_all();
void Money_deposit_withdraw(int,int);
void Updation_bank_account(int);

void Bank_Account::create_account(){
    system("clear");
    cout<<"\t Enter the account number: ";
    cin>>account_number;
    cout<<"\t Enter the nam eof the account holder: ";
    cin.ignore();
    cin.getline(name, 50);
    cout<<"\t Enter the type of the account (C/S): ";
    cin>>type;
    type=toupper(type);
    cout<<"\t Enter the initial amount (>=500 for Saving and >=1000 for Current): ";
    cin>>Money_Deposit;
    cout<<endl;
    cout<<"\t Accoutn created.... :";
    cout<<endl;
}

void Bank_Account::Display_Account() {
    cout<<"\t Bank account number: "<<account_number<<endl;
    cout<<"\t Account Holder name: "<<name<<endl;
    cout<<"\t Type of account: "<<type<<endl;
    cout<<"\t Balance amount: "<<Money_Deposit<<endl;
}

int main() {
    char ch;
    int num;
    do {
    cout<<"\t\t -------------------------------------"<<endl;
    cout<<"\t\t | welcome to bank management system |"<<endl;
    cout<<"\t\t -------------------------------------"<<endl;
    cout<<endl;
    cout<<"\t ---Main menu ---"<<endl;
    cout<<"\t 1. Create account"<<endl;
    cout<<"\t 2. Deposit money"<<endl;
    cout<<"\t 3. Withdraw money"<<endl;
    cout<<"\t 4. Balance enquiry"<<endl;
    cout<<"\t 5. All account holder list"<<endl;
    cout<<"\t 6. Close an account"<<endl;
    cout<<"\t 7. Modify an account"<<endl;
    cout<<"\t 8. Exit"<<endl;
    cout<<endl;
    
    cout<<"\tEnter your choice (1-8): ";
    cin>>ch;
    
    switch(ch) {
        case '1':
            write_account();
            break;
        case '2':
            system("clear");
            cout<<"\t Enter the account number: ";
            cin>>num;
            Money_deposit_withdraw(num,1);
            break;
        case '3':
            system("clear");
            cout<<"\t Enter the account number: ";
            cin>>num;
            Money_deposit_withdraw(num,2);
            break;
        case '4':
            system("clear");
            cout<<"\t Enter the account number: ";
            cin>>num;
            display_details(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            system("clear");
            cout<<"\t Enter the account number: ";
            cin>>num;
            delete_account(num);
            break;
        case '7':
            system("clear");
            cout<<"\t Enter the account number: ";
            cin>>num;
            Updation_bank_account(num);
            break;
        case '8':
            cout<<"\t Thanks for using the bank management system"<<endl;
            break;
    }
    cin.ignore();
    cin.get();
    }while(ch!='8');
    return 0;
    // Bank_Account B;
    // B.create_account();
    // B.Display_Account();
    // return 0;
}

void write_account() {
    Bank_Account ac;
    ofstream outFile;
    outFile.open("account.dat",ios::binary|ios::app);
    ac.create_account();
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
    outFile.close();
}

void delete_account(int n){
    Bank_Account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat",ios::binary);
    if (!inFile){
        cout<<"File could not be opn || press any key";
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account))){
        outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
    }
    inFile.close();
    outFile.close();
    remove("Bank_Account.dat");
    rename("Temp.dat","Bank_Account.dat");
    cout<<"\t Record deleted..."<<endl;
    
}

void display_details(int n){
    Bank_Account ac;
    bool flag=false;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile){
        cout<<"File could not be open || Press any key...";
        return;
    }
    cout<<"\t Bank account details"<<endl;
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account))){
        if (ac.retacno()==n){
            ac.Display_Account();
            flag=true;
        }
    }
    inFile.close();
    if(flag==false){
        cout<<"\t Account number does not exist"<<endl;
    }
}

void display_all() {
    system("clear");
    Bank_Account ac;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile) {
        cout<<"File could not be open || Press any key...";
        return;
    }
    cout<<"\t Bank account holder list"<<endl;
    cout<<"============================================"<<endl;
    cout<<"A/c no.      name        type        BALANCE"<<endl;
    cout<<"============================================"<<endl;
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account))) {
        ac.report();
    }
    inFile.close();
}

void Money_deposit_withdraw(int n, int option) {
    int amt;
    bool found = false;
    Bank_Account ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File){
        cout<<"File could not be open || Press any key...";
        return;
    }
    while(!File.eof() && found==false){
        File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
        if(ac.retacno()==n){
            ac.Display_Account();
            if(option==1){
                cout<<"\tEnter the amount to be deposited: ";
                cin>>amt;
                ac.dep(amt);
            }
            if(option==2){
                cout<<"\tEnte rthe amount to be withdrawn: ";
                cin>>amt;
                int balance = ac.retdeposit() - amt;
                if(balance < 0){
                    cout<<"\t Insufficient balance"<<endl;
                }
                else {
                    ac.draw(amt);
                }
            }
            int pos = (-1)*static_cast<int>(sizeof(Bank_Account));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
            cout<<"\t Record updated"<<endl;
            found=true;
        }
    }
    File.close();
    if(found==false){
        cout<<"\tRecord not found"<<endl;
    }
}

void Updation_bank_account(int n){
    bool found = false;
    Bank_Account ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
    if(!File){
        cout<<"File could not be open || Press any key...";
        return;
    }
    while(!File.eof() && found == false){
        File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
        if (ac.retacno()==n){
            ac.Display_Account();
            cout<<"\tEnter the new details of the account"<<endl;
            ac.modify();
            int pos = (-1)*static_cast<int>(sizeof(Bank_Account));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
            cout<<"\t Record updated"<<endl;
            found=true;
        }
    }
    File.close();
    if(found == false){
        cout<<"\tRecord not found"<<endl;
    }
}
