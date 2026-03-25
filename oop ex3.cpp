#include <iostream>
using namespace std;
class PhanSo{
private:
    int tu;
    int mau;
public:
    void Nhap(int i);
    int SoSanh(const PhanSo& v);
    void Xuat();
};
void PhanSo::Nhap(int i){
    cout << "Nhap tu so cua phan so thu " << i << ": ";
    cin >> tu;
    do{
        cout << "Nhap mau so cua phan so thu: " << i << ": ";
        cin >> mau;
        if(mau == 0){
            cout << "Xin vui long nhap mau khac 0. Cam on " << endl;
        }
    }while(mau == 0);
}
int PhanSo::SoSanh(const PhanSo& v){
    if(tu * v.mau > v.tu * mau)return 1;
    else if(tu * v.mau < v.tu * mau)return -1;
    else return 0;
}
void PhanSo::Xuat(){
    cout << "Phan so lon hon la " << tu << "/" << mau << endl;
}
int main(){
   PhanSo a;
   PhanSo b;
   int i = 1;
   a.Nhap(i);
   i = 2;
   b.Nhap(i);
   if(a.SoSanh(b) == 1)a.Xuat();
   else if(a.SoSanh(b) == -1)b.Xuat();
   else cout << "Hai phan so bang nhau " << endl;
   return 0;
}
