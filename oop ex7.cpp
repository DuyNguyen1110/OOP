#include <iostream>
using namespace std;
class Yesterday{
private:
    int day;
    int month;
    int year;
    bool KiemTraNamNhuan(){
        if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))return 1;
        return 0;
    }
    int KiemTraThang(){
        if(month == 2){
            if(KiemTraNamNhuan() == 1)return 29;
            return 28;
        }else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)return 31;
        else if(month == 4 || month == 6 || month == 9 || month == 11)return 30;
        return 0;
    }
    bool KiemTraNgayThangNam(){
        if(day < 1 || day > KiemTraThang())return 0;
        if(month < 1 || month > 12)return 0;
        if(year < 1000)return 0;
        return 1;
    }
public:
    void Nhap();
    Yesterday NgayHomQua();
    void Xuat();
};
void Yesterday::Nhap(){
    do{
        cout << "Moi ban nhap ngay: ";
        cin >> day;
        cout << "Moi ban nhap thang: ";
        cin >> month;
        cout << "Moi ban nhap nam: ";
        cin >> year;
        if(KiemTraNgayThangNam() == 0)cout << "Ban nhap sai du lieu. Vui long nhap lai" << endl;
    }while(KiemTraNgayThangNam() == 0);
}
Yesterday Yesterday::NgayHomQua(){
    Yesterday HomQua;
    HomQua.day = day - 1;
    HomQua.month = month;
    HomQua.year = year;
    if(HomQua.day < 1){
        HomQua.month = month - 1;
        HomQua.day = HomQua.KiemTraThang();
        if(HomQua.month < 1){
            HomQua.day = 31;
            HomQua.month = 12;
            HomQua.year = year - 1;
        }
    }
    return HomQua;
}
void Yesterday::Xuat(){
    cout << day << "/" << month << "/" << year << endl;
}
int main(){
    Yesterday a;
    a.Nhap();
    Yesterday HomQua;
    HomQua = a.NgayHomQua();
    cout << "Ngay hom qua la ";
    HomQua.Xuat();
    return 0;
}
