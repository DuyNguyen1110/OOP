/* Lớp BankAccount với các thuộc tính: Số tài khoản, tên chủ tài khoản, số dư cùng với các phương thức cần thiết, trong đó có ít nhất phải có các phương thức: nạp tiền, rút tiền, xuất thông tin tài khoản
  */
#include <iostream>
#include <string>
using namespace std;
class BankAccount{
private:
    int SoTaiKhoan;
    string ChuTaiKhoan;
    long long SoDu;
public:
    BankAccount(){
        SoTaiKhoan = 0;
        ChuTaiKhoan = "Khong co du lieu";
        SoDu = 0;
    }
    BankAccount(int stk, string name, long long sd) : SoTaiKhoan(stk), ChuTaiKhoan(name), SoDu(sd){}
    void Nhap();
    void KiemTra();
    void NapTien(int AddMoney);
    void RutTien(int TakeMoney);
    void Xuat();
};
void BankAccount::Nhap(){
    cout << "Nhap ten cua ban: ";
    getline(cin, ChuTaiKhoan);
    cout << "Nhap so tai khoan: ";
    cin >> SoTaiKhoan;
    cout << "Nhap so du hien tai: ";
    cin >> SoDu;
}
void BankAccount::KiemTra(){
    cout << "So du hien co trong tai khoan cua ban la: " << SoDu << endl;
}
void BankAccount::NapTien(int AddMoney){
    SoDu += AddMoney;
    cout << "So tien da nap la: " << AddMoney << endl;
}
void BankAccount::RutTien(int TakeMoney){
    if(SoDu > TakeMoney){
        SoDu -= TakeMoney;
        cout << "So tien da rut la: " << TakeMoney << endl;
    }else cout << "Khong du so du trong tai khoan!" << endl;
}
void BankAccount::Xuat(){
    cout << "Thong tin chu so huu: " << ChuTaiKhoan << endl;
    cout << "So tai khoan: " << SoTaiKhoan << endl;
    cout << "So du trong tai khoan: " << SoDu << endl;
}
int main(){
    BankAccount a;
    cout << "Qua trinh nhap thong tin bat dau: " << endl;
    a.Nhap();
    cout << endl;
    cout << "Ban co muon nap tien khong? ";
    string result1, result2;
    cin >> result1;
    if(result1 == "YES" || result1 == "Yes" || result1 == "yes" || result1 == "Co" || result1 == "CO" || result1 == "co"){
        cout << "Nhap so tien can nap: ";
        int AddMoney;
        cin >> AddMoney;
        a.NapTien(AddMoney);
        a.KiemTra();
    }else{
        cout << "Khong co giao dich!" << endl;
    }
    cout << endl;
    cout << "Ban co muon rut tien khong? ";
    cin >> result2;
    if(result2 == "YES" || result2 == "Yes" || result2 == "yes" || result2 == "Co" || result2 == "CO" || result2 == "co"){
        cout << "Nhap so tien can rut: ";
        int TakeMoney;
        cin >> TakeMoney;
        a.RutTien(TakeMoney);
        a.KiemTra();
    }else{
        cout << "Khong co giao dich!" << endl;
    }
    cout << endl;
    a.Xuat();
    return 0;
}
