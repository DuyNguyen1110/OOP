#include <iostream>
#include <string>
using namespace std;
class Employee{
protected:
    string fullName;
    int age;
private:
    double baseSalary;
public:
    void Input();
    void Output();
    double getBaseSalary();
};
void Employee::Input(){
    cout << "Nhap ten: ";
    getline(cin, fullName);
    cout << "Nhap tuoi: ";
    cin >> age;
    cout << "Nhap luong co ban: ";
    cin >> baseSalary;
    cin.ignore();
}
void Employee::Output(){
    cout << "Ho ten la " << fullName << endl;
    cout << "Tuoi cua nhan vien la " << age << endl;
    cout << "Luong co ban cua nhan vien la " << baseSalary << endl;
}
double Employee::getBaseSalary(){
    return baseSalary;
}
class OfficeEmployee:public Employee{
private:
    int workingDays;
    double allowance;
public:
    void Input();
    void Output();
    double CalculateSalary(){
        return (getBaseSalary() + workingDays * 200000 + allowance);
    }
};
void OfficeEmployee::Input(){
    Employee::Input();
    cout << "So ngay lam viec: ";
    cin >> workingDays;
    cout << "Nhap phu cap: ";
    cin >> allowance;
}
void OfficeEmployee::Output(){
    Employee::Output();
    cout << "So ngay lam viec cua nhan vien la " << workingDays << endl;
    cout << "Phu cap cua nhan vien la " << allowance << endl;
    cout << "Luong chinh thuc la " << CalculateSalary() << endl;
}
int main(){
    OfficeEmployee nv;
    nv.Input();
    nv.Output();
    return 0;
}
