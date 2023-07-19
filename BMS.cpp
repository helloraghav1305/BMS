#include<iostream>
#include<iomanip>
#include<fstream>
#include<cctype>

using namespace std;

class Account {
    
    // This class contains 4 private attributes and 8 public member functions 
    
    int acc_num;
    char name[50];
    char type;
    int amt_deposit;

public:

    void modify_acc();
    void display_info() const;
    void create_account();
    void display_acc();
    
    int return_acc_num() const{
        return acc_num;
    }
    void deposit(int x){
        amt_deposit+=x;
    }
    void withdraw_amt(int x) {
        amt_deposit-=x;
    }
    int return_dep() const{
        return amt_deposit;
    }

};

void Account:: display_info() const{
    
    // This method displays the account number, account type and money deposited
    
    cout<< acc_num <<setw(10)<<" "<<name<<setw(10)<<type<<setw(10)<< amt_deposit<<endl;
    
}

void Account:: modify_acc(){
    
    // This method asks for user input to modify the bank account details 
    
    cout<<"\tAccount number: "<< acc_num<<endl;
    cout<<"\tEnter new account holder name: ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\tEnter new type of account: ";
    cin>>type;
    type=toupper(type);
    cout<<"\tEnter new balance amount: ";
    cin>> amt_deposit;
    
}

// Function declaration

void login();
void registration();
void page();
void create_acc();
void display_details(int);
void delete_account(int);
void display_all_details();
void Deposit_withdraw_acc(int,int);
void Updation_bank_account(int);

void Account::display_acc() {
    
    // Display the user account details
    
    cout<<"\t Bank account number: "<< acc_num<<endl;
    cout<<"\t Account Holder name: "<<name<<endl;
    cout<<"\t Type of account: "<<type<<endl;
    cout<<"\t Balance amount: "<< amt_deposit <<endl;
    
}

void Account::create_account() {
    
    // This method is used to create bank account for the user
    
    system("clear");
    
    cout<<"\t Enter account number: ";
    cin>> acc_num;
    cout<<"\t Enter name of account holder: ";
    cin.ignore();
    cin.getline(name, 50);
    cout<<"\t Enter type of the account (C for Current, S for Savings): ";
    cin>>type;
    type=toupper(type);
    cout<<"\t Enter initial amount (>=1000 for Saving and >=5000 for Current): ";
    int temp=0;
    
    while (temp == 0) {
        
        cin>>amt_deposit;
        if ((amt_deposit <1000 && type=='S') || (amt_deposit <5000 && type=='C')) {
            cout<<"\t Wrong input! Enter again"<<endl<<"\t ";
        } else {
            temp=1;
        }
        
    }
    
    cout<<endl;
    cout<<"\t Account is created. Thanks :";
    cout<<endl;
}

int main() {
    
    // The main function contains the login page with switch case
    
    int c;
    cout<<"\t\t\t______________________________________________\n\n\n";
    cout<<"\t\t\t             Welcome to login page            \n\n\n";
    cout<<"\t\t\t________________     MENU    _________________\n\n";
    cout<<"                                                    \n\n";
    cout<<"\t| Press 1 to LOGIN               |"<<endl;
    cout<<"\t| Press 2 to REGISTER            |"<<endl;
    cout<<"\t| Press 3 to EXIT                |"<<endl;
    cout<<"\n\t\t\t Please enter your choice ";
    cin>>c;
    cout<<endl;
    
    switch(c) {
        
        case 1:
            login();
            break;
        
        case 2:
            registration();
            break;
            
        case 3:
            cout<<"\t\t\t Thank you! \n\n";
            break;
        
        default:
            system("clear");
            cout<<"\t\t\t Please select from the options given above \n"<<endl;
            main();
    }
    
    return 0;
 
}

void page() {
    
    // This method displays various options to the user including creating account, depositing money etc
    
    char ch;
    int num;
    
    do {
        
    system("clear");
    cout<<"\t\t -------------------------------------"<<endl;
    cout<<"\t\t |       Bank management system       |"<<endl;
    cout<<"\t\t -------------------------------------"<<endl;
    cout<<endl;
    cout<<"\t ---  Menu ---"<<endl;
    cout<<"\t 1. Create user account"<<endl;
    cout<<"\t 2. Deposit money"<<endl;
    cout<<"\t 3. Withdraw money"<<endl;
    cout<<"\t 4. Balance enquiry"<<endl;
    cout<<"\t 5. Display all account holders"<<endl;
    cout<<"\t 6. Close an account"<<endl;
    cout<<"\t 7. Modify account details"<<endl;
    cout<<"\t 8. Exit"<<endl;
    cout<<endl;
    
    cout<<"\tEnter your choice (1-8): ";
    cin>>ch;
    
    switch(ch) {
        
        case '1':
            create_acc();
            break;
        case '2':
            system("clear");
            cout<<"\t Enter the account number: ";
            cin>>num;
            Deposit_withdraw_acc(num,1);
            break;
        case '3':
            system("clear");
            cout<<"\t Enter the account number: ";
            cin>>num;
            Deposit_withdraw_acc(num,2);
            break;
        case '4':
            system("clear");
            cout<<"\t Enter the account number: ";
            cin>>num;
            display_details(num);
            break;
        case '5':
            display_all_details();
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
    
}

void login() {
    
    // This login page asks for username and password
    
    int count;
    string userId, password, id, pass;
    system("clear");
    cout<<"\t\t -------------------------------------"<<endl;
    cout<<"\t\t |                LOGIN               |"<<endl;
    cout<<"\t\t -------------------------------------"<<endl;
    cout<<"\t\t\t Please enter the username and password : "<<endl;
    cout<<"\t\t\t USERNAME ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD ";
    cin>>password;
    
    ifstream input("records.txt");
    
    while (input>>id>>pass) {
        
        if (id == userId && pass == password) {
            count = 1;
            system("clear");
        }
        
    }
    
    input.close();
    
    if (count == 1) {
        cout<<userId<<"\n Successful login \n Thanks for logging in ! \n";
        page();
    }
    else {
        cout<<"\n LOGIN ERROR \n Reenter username and password \n";   
        main();
    }
}

void registration() {
    
    // This registration page asks for username and password
    
    string ruserId, rpassword, rid, rpass;
    system("clear");
    cout<<"\t\t -------------------------------------"<<endl;
    cout<<"\t\t |              REGISTER               |"<<endl;
    cout<<"\t\t -------------------------------------"<<endl;
    cout<<"\t\t\t Enter the username : ";
    cin>>ruserId;
    cout<<"\t\t\t Enter the password : ";
    cin>>rpassword;
    
    ofstream f1("records.txt", ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("clear");
    
    cout<<"\n\t\t\t Registration is successful! \n";
    login();
}

void delete_account(int n){
    
    /*
    
        ifstream class
        
        1. To read any information contained in the file
        2. seekg() - to seek an arbitrary position in a file
        3. ios::beg (indicates that location is number of bytes from beginning of the file)
    
    */
    
    Account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("Account.dat",ios::binary);
    
    if (!inFile){
        cout<<"File cannot be opened";
        return;
    }
    
    outFile.open("File.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))){
        if (ac.return_acc_num() != n) {    // return_acc_num () returns the account number
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
        }
    }
    
    inFile.close();
    outFile.close();
    
    remove("Account.dat");
    rename("File.dat"," Account.dat"); // name of File.dat changes to Account.dat
    cout<<"\t Record deleted..."<<endl;
    
}

void create_acc() {
    
    /*
        ofstream class
        
        1. Provides output operations 
        2. contains open() function with default output mode
        3. ios::binary (open a file in binary mode)
        4. ios::app (seek to end before each write)
        5. reinterpret_cast (convert a pointer of same data type into pointer of another data type)
    */
    
    Account ac;
    ofstream outFile;
    outFile.open("Account.dat",ios::binary|ios::app);
    ac.create_account();
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
    outFile.close();
    
}

void display_all_details() {
    
    // This method is used to display the information of all the accounts
    
    system("clear");   // To clear the screen
    Account ac;
    ifstream inFile;
    inFile.open("Account.dat",ios::binary);
    
    if(!inFile) {
        cout<<"No accounts exist. Sorry ";
        return;
    }
    
    cout<<"\t Bank account holder list"<<endl;
    cout<<"============================================="<<endl;
    cout<<"|A/c no.      Name        Type        Balance|"<<endl;
    cout<<"============================================="<<endl;
    
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))) {
        ac. display_info();
    }
    
    inFile.close();
    
}

void display_details(int n){
    
    // This method is used to display the account details
    
    Account ac;
    bool flag=false;
    ifstream inFile;
    inFile.open("Account.dat",ios::binary);
    
    if(!inFile){
        cout<<"Account does not exist. Sorry ";
        return;
    }
    
    cout<<"\t Bank account details"<<endl;
    
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account))){
        if (ac.return_acc_num()==n){
            ac.display_acc();
            flag=true;
        }
    }
    
    inFile.close();
    
    if(flag==false){
        cout<<"\t Account number does not exist"<<endl;
    }
    
}

void Updation_bank_account(int n){
    
    // This method is used to update the bank account details
    
    bool found = false;
    Account ac;
    fstream File;
    File.open("Account.dat", ios::binary|ios::in|ios::out);
    if(!File){
        cout<<"File could not be open. Press any key ";
        return;
    }
    while(!File.eof() && found == false){
        
        File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
        
        if (ac.return_acc_num()==n){
            ac.display_acc();
            cout<<"\tEnter the new details of the account"<<endl;
            ac.modify_acc();
            int pos = (-1)*static_cast<int>(sizeof(Account));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            cout<<"\t Record is updated. Thanks "<<endl;
            found=true;
        }
        
    }
    
    File.close();
    
    if(found == false){
        cout<<"\tRecord not found. Sorry"<<endl;
    }
    
}

void Deposit_withdraw_acc(int n, int opt) {
    
    // Based on the value of opt (1 or 2), this method helps to deposit and withdraw money from bank account
    
    int amt;
    bool found = false;
    Account ac;
    fstream File;
    File.open("Account.dat", ios::binary|ios::in|ios::out);
    
    if(!File){
        cout<<"File could not be open. Press any key...";
        return;
    }
    
    while(!File.eof() && found==false){
        
        File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
        
        if(ac.return_acc_num()==n){
            ac.display_acc();
            if(opt==1){
                cout<<"\tEnter the amount to be deposited: ";
                cin>>amt;
                ac.deposit(amt);
            }
            if(opt==2){
                cout<<"\tEnter the amount to be withdrawn: ";
                cin>>amt;
                int balance = ac.return_dep() - amt;
                if(balance < 0){
                    cout<<"\t Insufficient balance"<<endl;
                }
                else {
                    ac.withdraw_amt(amt);
                }
            }
            
            // static_cast operator allows casting from any pointer type to void pointer and vice versa
            // ios:cur (indicates that location is the number of bytes from the current file pointer location)
            
            int pos = (-1)*static_cast<int>(sizeof(Account));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
            cout<<"\t Record is updated. Thanks "<<endl;
            found=true;
        }
    }
    
    File.close();
    
    if(found==false){
        cout<<"\tRecord not found. Sorry"<<endl;
    }
    
}

