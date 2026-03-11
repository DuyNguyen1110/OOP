#include <iostream>
using namespace std;
class PhanSo{
private:
    int tu;
    int mau;
public:
    bool Nhap();
    int KiemTra();
};
bool PhanSo::Nhap(){
    cout << "You enter first number: ";
    cin >> tu;
    cout << "You enter second number: ";
    cin >> mau;
    if(mau == 0)return false;
    return true;
}
int PhanSo::KiemTra(){
    if(tu * mau > 0) return 1;
    else if(tu * mau < 0)return -1;
    return 0;
}
int main(){
    PhanSo ps;
    ps.Nhap();
    if(ps.KiemTra() == 1)cout << "Phan so la so duong" << endl;
    else if(ps.KiemTra() == -1)cout << "Phan so la so am" << endl;
    else cout << "Phan So bang 0" << endl;
    return 0;
}
