#include <iostream>
#include <string>
using namespace std;
#define MAX 100
class SinhVien{
private:
    string ten;
    float Toan;
    float Van;
public:
    void Nhap();
    float DTB();
    void Xuat();
};
void SinhVien::Nhap(){
    cout << "Nhap ten cua sinh vien: ";
    cin.ignore();
    getline(cin, ten);
    do{
        cout << "Nhap diem toan: ";
        cin >> Toan;
        if(Toan < 0)cout << "Du lieu mon toan nhap sai. Vui long nhap lai." << endl;
    }while(Toan < 0);
    do{
        cout << "Nhap diem van: ";
        cin >> Van;
        if(Van < 0)cout << "Du lieu mon van nhap sai. Vui long nhap lai." << endl;
    }while(Van < 0);
}
float SinhVien::DTB(){
    float dtb = (Toan + Van ) / 2;
    return dtb;
}
void SinhVien::Xuat(){
    cout << ten << endl;
    cout << DTB();
}
void InputArray(SinhVien sv[], int n){
    for(int i = 0; i < n; i++){
        cout << "Nhap sinh vien thu " << i + 1 << endl;
        sv[i].Nhap();
        cout << endl;
    }
}
int DiemMax(SinhVien sv[], int n){
    int maxsv = 0;
    for(int i = 1; i < n; i++){
        if(sv[i].DTB() > sv[maxsv].DTB())maxsv = i;
    }
    return maxsv;
}
int DiemMin(SinhVien sv[], int n){
    int minsv = 0;
    for(int i = 1; i < n; i++){
        if(sv[i].DTB() < sv[minsv].DTB())minsv = i;
    }
    return minsv;
}
int main(){
    SinhVien sv[MAX];
    cout << "Nhap so sinh vien: ";
    int n;
    cin >> n;
    InputArray(sv, n);
    int maxs = DiemMax(sv, n);
    cout << "Sinh vien co DTB cao nhat la: " << endl;
    sv[maxs].Xuat();
    cout << endl;
    int mins = DiemMin(sv, n);
    cout << "Sinh vien co DTB thap nhat la: " << endl;
    sv[mins].Xuat();
    return 0;
}
