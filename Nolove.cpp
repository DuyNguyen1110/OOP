#include <iostream>
#include <string>
using namespace std;
class BankAccount{
protected:
    string accountNumber;
    string ownerName;
    double balance;
public:
    void Input();
    void Output();
    void deposit(double amount);
    void withdraw(double amount);
};
void BankAccount::Input(){
    cout << "Nhap tai khoan: ";
    getline(cin, accountNumber);
    cout << "Nhap chu so huu: ";
    getline(cin, ownerName);
    cout << "Nhap so du hien tai: ";
    cin >> balance;
    cin.ignore();
}
void BankAccount::Output(){
    cout << "So tai khoan la " << accountNumber << endl;
    cout << "Chu so huu la " << ownerName << endl;
    cout << "So du hien tai la " << balance << endl;
}
void BankAccount::deposit(double amount){
    if(amount > 0){
        balance += amount;
        cout << "Da them " << amount << " vao tai khoan" << endl;
    }else cout << "So tien nap khong hop le" << endl;
}
void BankAccount::withdraw(double amount){
    if(amount > 0 && amount <= balance){
        balance -= amount;
        cout << "Da rut " << amount << " ra khoi tai khoan" << endl;
    }
    else cout << "Khong hop le hoac khong du tien:v" << endl;
}
class SavingAccount:public BankAccount{
private:
    double interestRate;
    int month;
public:
    void Input();
    void Output();
    void deposit(double amount);
    void withdraw(double amount);
    double interest(){
        return (balance * interestRate / 100 * month / 12);
    }
};
void SavingAccount::Input(){
    BankAccount::Input();
    cout << "Nhap lai suat: ";
    cin >> interestRate;
    cout << "Nhap thang: ";
    cin >> month;
    cin.ignore();
}
void SavingAccount::deposit(double amount){
    BankAccount::deposit(amount);
}
void SavingAccount::withdraw(double amount){
    BankAccount::withdraw(amount);
}
void SavingAccount::Output(){
    BankAccount::Output();
    cout << "Lai suat la " << interestRate << endl;
    cout << "So thang lai duoc la " << month << endl;
    cout << "Tien lai ban nhan duoc " << interest() << endl;
}
int main(){
    SavingAccount sv;
    sv.Input();
    double amount;
    cout << "Nhap so tien can nap: ";
    cin >> amount;
    sv.deposit(amount);
    cout << "Nhap so tien can rut: ";
    cin >> amount;
    sv.withdraw(amount);
    sv.Output();
    return 0;
}
