#include <iostream>
#include <cmath>
using namespace std;
class ToaDo{
private:
    double x;
    double y;
public:
    ToaDo(int a = 0,int b = 0) : x(a), y(b){}
    void Nhap();
    double Distance(const ToaDo& v);
    double getx(){return x;}
    double gety(){return y;}
};
void ToaDo::Nhap(){
    cout << "Nhap thanh phan thu nhat ";
    cin >> x;
    cout << "Nhap thanh phan thu hai: ";
    cin >> y;
}
double ToaDo::Distance(const ToaDo& v){
    return sqrt(pow(x - v.x,2) + pow(y - v.y,2));
}
class TamGiac{
private:
    ToaDo a;
    ToaDo b;
    ToaDo c;
public:
    void Nhap();
    double ChuVi();
    double DienTich();
    void TrongTam();
    void Xuat();
};
void TamGiac::Nhap(){
    cout << "Nhap diem thu nhat: " << endl;
    a.Nhap();
    cout << endl;
    cout << "Nhap diem thu hai: " << endl;
    b.Nhap();
    cout << endl;
    cout << "Nhap diem thu ba: " << endl;
    c.Nhap();
    cout << endl;
}
double TamGiac::ChuVi(){
    double AB = a.Distance(b);
    double BC = b.Distance(c);
    double CA = c.Distance(a);
    return AB + BC + CA;
}
double TamGiac::DienTich(){
    double AB = a.Distance(b);
    double BC = b.Distance(c);
    double CA = c.Distance(a);
    double p = (AB + BC + CA) / 2;
    return sqrt(p * (p - AB) * (p - BC) * (p - CA));
}
void TamGiac::TrongTam(){
    double z = (a.getx() + b.getx() + c.getx()) / 3;
    double w = (a.gety() + b.gety() + c.gety()) / 3;
    cout << "Trong tam cua tam giac la: (" << z << "," << w << ")" << endl;
}
void TamGiac::Xuat(){
    cout << "Chu vi cua tam giac la: " << ChuVi() << endl;
    cout << "Dien tich cua tam giac la: " << DienTich() << endl;
    TrongTam();
}
int main(){
    TamGiac tg;
    tg.Nhap();
    tg.Xuat();
    return 0;
}
