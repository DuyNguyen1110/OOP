#include <iostream>
#include <cmath>
using namespace std;
class PhanSo{
private:
    int tu;
    int mau;
    int UocChungLonNhat(int tu, int mau){
        int a = abs(tu);
        int b = abs(mau);
        if(b == 0)return a;
        if(a == 0)return b;
        while(a != b){
            if(a > b)a = a - b;
            else b = b - a;
        }
        return a;
    }
    void RutGon(){
        int utln = UocChungLonNhat(tu, mau);
        tu = tu / utln;
        mau = mau / utln;
        if(mau < 0){
            mau *= -1;
            tu *= -1;
        }
    }
public:
    void Nhap(int i);
    void Xuat();
    PhanSo Tong(PhanSo& ps);
    PhanSo Hieu(PhanSo& ps);
    PhanSo Tich(PhanSo& ps);
    PhanSo Thuong(PhanSo& ps);
};
PhanSo PhanSo::Tong(PhanSo& ps){
    PhanSo cuoi;
    cuoi.tu = tu * ps.mau + mau * ps.tu;
    cuoi.mau = mau * ps.mau;
    cuoi.RutGon();
    return cuoi;
}
PhanSo PhanSo::Hieu(PhanSo& ps){
    PhanSo cuoi;
    cuoi.tu = tu * ps.mau - mau * ps.tu;
    cuoi.mau = mau * ps.mau;
    cuoi.RutGon();
    return cuoi;
}
PhanSo PhanSo::Tich(PhanSo& ps){
    PhanSo cuoi;
    cuoi.tu = tu * ps.tu;
    cuoi.mau = mau * ps.mau;
    cuoi.RutGon();
    return cuoi;
}
PhanSo PhanSo::Thuong(PhanSo& ps){
    PhanSo cuoi;
    if(ps.tu == 0){
        cout << "Loi: Khong the chia cho 0!" << endl;
        cuoi.tu = 0;
        cuoi.mau = 1;
        return cuoi;
    }
    cuoi.tu = tu * ps.mau;
    cuoi.mau = mau * ps.tu;
    cuoi.RutGon();
    return cuoi;
}
void PhanSo::Nhap(int i){
    cout << "Nhap tu so cua phan so thu " << i << ": ";
    cin >> tu;
    do{
        cout << "Nhap mau so cua phan so thu " << i << ": ";
        cin >> mau;
        if(mau == 0){
            cout << "Du lieu dau vao khong hop le. Vui long nhap lai " << endl;
        }
    }while(mau == 0);
}
void PhanSo::Xuat(){
    if(tu == 0) cout << 0;
    else if(mau == 1)cout << tu;
    else cout << tu << "/" << mau;
}
int main(){
    PhanSo a;
    PhanSo b;
    PhanSo cuoi;
    int i = 1;
    a.Nhap(i);
    cout << endl;
    i = 2;
    b.Nhap(i);
    cout << endl;
    cuoi = b.Tong(a);
    cout << "Tong cua hai phan so la: ";
    cuoi.Xuat();
    cout << endl;
    cuoi = b.Hieu(a);
    cout << "Hieu cua hai phan so la: ";
    cuoi.Xuat();
    cout << endl;
    cuoi = b.Tich(a);
    cout << "Tich cua hai phan so la: ";
    cuoi.Xuat();
    cout << endl;
    cuoi = b.Thuong(a);
    cout << "Thuong cua hai phan so la: ";
    cuoi.Xuat();
    return 0;
}
