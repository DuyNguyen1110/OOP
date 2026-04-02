#include <iostream>
#include <string>
using namespace std;
class SinhVien{
private:
    string ten;
    float DiemToan;
    float DiemVan;
public:
    void Nhap();
    float DTB();
    void Xuat();
};
void SinhVien::Nhap(){
    cout << "Nhap ho ten sinh vien: ";
    cin.ignore();
    getline(cin, ten);
    cout << "Nhap diem toan: ";
    cin >> DiemToan;
    cout << "Nhap diem van: ";
    cin >> DiemVan;
}
float SinhVien::DTB(){
    float dtb = (DiemToan + DiemVan) / 2;
    return dtb;
}
void SinhVien::Xuat(){
    cout << DTB();
}
int main(){
    SinhVien a;
    a.Nhap();
    cout << "Diem trung binh 2 mon cua sinh vien la ";
    a.Xuat();
    return 0;
}
