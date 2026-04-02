#include <iostream>
using namespace std;
#define PI 3.14
class DuongTron{
private:
    double x;
    double y;
    double R;
public:
    void Nhap();
    double ChuVi();
    double DienTich();
};
void DuongTron::Nhap(){
    cout << "Nhap thanh phan thu nhat cua toa do: ";
    cin >> x;
    cout << "Nhap thanh phan thu hai cua toa do: ";
    cin >> y;
    cout << "Nhap ban kinh cua duong tron: ";
    cin >> R;
}
double DuongTron::ChuVi(){
    double p = 2 * PI * R;
    return p;
}
double DuongTron::DienTich(){
    double s = PI * R * R;
    return s;
}
int main(){
    DuongTron a;
    a.Nhap();
    cout << "Chu vi cua duong tron la " << a.ChuVi() << endl;
    cout << "Dien tich cua duong tron la " << a.DienTich() << endl;
    return 0;
}
