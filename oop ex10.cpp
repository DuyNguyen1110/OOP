#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100
class PhanSo{
private:
    int tu;
    int mau;
    int UCLN(){
        int a = abs(tu); // Khử âm
        int b = abs(mau);
        if(a == 0)return b;
        if(b == 0)return a;
        while(a != b){
            if(b > a)b = b - a;
            else a = a - b;
        }
        return a;
    }
    void RutGon(){
        if(tu == 0)return;
        int utln = UCLN();
        tu = tu / utln;
        mau = mau / utln;
        if(mau < 0){
            tu *= -1;
            mau *= -1;
        }
    }
public:
    void Nhap();
    int SoSanh(const PhanSo& ps);
    void Xuat();

};
void PhanSo::Nhap(){
    cout << "Nhap tu so: ";
    cin >> tu;
    do{
        cout << "Nhap mau so: ";
        cin >> mau;
        if(mau == 0)cout << "Du lieu nhap sai. Vui long thuc hien lai." << endl;
    }while(mau == 0);
    RutGon();
}
int PhanSo::SoSanh(const PhanSo& ps){
    if(tu * ps.mau > ps.tu * mau)return 1;
    else if(ps.tu * mau > tu * ps.mau)return -1;
    else return 0;
}
void PhanSo::Xuat(){
    if(tu == 0)cout << 0;
    else if(mau == 1)cout << tu;
    else cout << tu << "/" << mau;
}
void InputArray(PhanSo DayPS[], int n){
    for(int i = 0; i < n; i++){
        cout << "Phan so thu " << i + 1 << endl;
        DayPS[i].Nhap();
        cout << endl;
    }
}
void InsertionSort1(PhanSo DayPS[], int n){
    for(int i = 1; i < n; i++){
        PhanSo e = DayPS[i];
        int k;
        for(k = i - 1; k > -1; k--){
            if(DayPS[k].SoSanh(e) == 1)break;
            DayPS[k + 1]= DayPS[k];
        }
        DayPS[k + 1] = e;
    }
}
void InsertionSort2(PhanSo DayPS[], int n){
    for(int i = 1; i < n; i++){
        PhanSo e = DayPS[i];
        int k;
        for(k = i - 1; k > -1; k--){
            if(DayPS[k].SoSanh(e) == -1)break;
            DayPS[k + 1]= DayPS[k];
        }
        DayPS[k + 1] = e;
    }
}
void OutputArray(PhanSo DayPS[], int n){
    for(int i = 0; i < n; i++){
        DayPS[i].Xuat();
        cout << " ";
    }
}
int main(){
    PhanSo DayPS[MAX];
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    cout << endl;
    InputArray(DayPS, n);
    int max = 0;
    for(int i = 1; i < n; i++){
        if(DayPS[i].SoSanh(DayPS[max]) == 1)max = i;
    }
    cout << "Phan so lon nhat la ";
    DayPS[max].Xuat();
    cout << endl;
    InsertionSort2(DayPS, n);
    cout << "Sap xep tang dan: ";
    OutputArray(DayPS, n);
    cout << endl;
    InsertionSort1(DayPS, n);
    cout << "Sap xep giam dan: ";
    OutputArray(DayPS, n);
    return 0;
}
