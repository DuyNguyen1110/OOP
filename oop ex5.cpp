#include <iostream>
using namespace std;
class SoPhuc{
private:
    double thuc;
    double ao;
public:
    void Nhap(int i);
    void Xuat();
    SoPhuc Tong(SoPhuc& sp);
    SoPhuc Hieu(SoPhuc& sp);
    SoPhuc Tich(SoPhuc& sp);
};
void SoPhuc::Nhap(int i){
    cout << "Nhap thanh phan so thuc thu " << i << ": ";
    cin >> thuc;
    cout << "Nhap thanh phan so ao thu " << i << ": ";
    cin >> ao;
}
void SoPhuc::Xuat(){
    if(ao == 0)cout << thuc;
    else if(thuc == 0) cout << ao << "i";
    else if(ao > 0) cout << thuc << " + " << ao << "i" << endl;
    else if(ao < 0) cout << thuc << " - " << -ao << "i" << endl;
}
SoPhuc SoPhuc::Tong(SoPhuc& sp){
    SoPhuc moi;
    moi.thuc = thuc + sp.thuc;
    moi.ao = ao + sp.ao;
    return moi;
}
SoPhuc SoPhuc::Hieu(SoPhuc& sp){
    SoPhuc moi;
    moi.thuc = thuc - sp.thuc;
    moi.ao = ao - sp.ao;
    return moi;
}
SoPhuc SoPhuc::Tich(SoPhuc& sp){
    SoPhuc moi;
    moi.thuc = thuc * sp.thuc - ao * sp.ao;
    moi.ao = thuc * sp.ao + ao * sp.thuc;
    return moi;
}
int main(){
    SoPhuc a;
    SoPhuc b;
    int i = 1;
    a.Nhap(i);
    cout << endl;
    i = 2;
    b.Nhap(i);
    cout << endl;
    SoPhuc moi;
    moi = a.Tong(b);
    cout << "Tong hai so phuc: ";
    moi.Xuat();
    moi = a.Hieu(b);
    cout << "Hieu hai so phuc: ";
    moi.Xuat();
    moi = a.Tich(b);
    cout << "Tich hai so phuc: ";
    moi.Xuat();
    return 0;
}
