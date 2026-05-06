#include <iostream>
using namespace std;
class Date{
private:
    int day;
    int month;
    int year;
    bool KiemTraNamNhuan(){
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)return 1;
        return 0;
    }
    int KiemTraThang(){
        if(month == 2){
            if(KiemTraNamNhuan() == 1)return 29;
            else return 28;
        }
        else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)return 31;
        else if(month == 4 || month == 6 || month == 9 || month == 11)return 30;
        else return 0;
    }
    bool KiemTraNgayThangNam(){
        if(year < 1000)return 0;
        if(month < 1 || month > 12)return 0;
        if(day < 1 || day > KiemTraThang())return 0;
        return 1;
    }
public:
    void Nhap();
    Date NgayTiepTheo();
    void Xuat();
};
void Date::Nhap(){
    do{
        cout << "Nhap ngay: ";
        cin >> day;
        cout << "Nhap Thang: ";
        cin >> month;
        cout << "Nhap nam: ";
        cin >> year;
        if(KiemTraNgayThangNam() == 0)cout << "Du lieu ban nhap khong hop le. Vui long nhap lai" << endl;
    }while(KiemTraNgayThangNam() == 0);
}
void Date::Xuat(){
    cout << day << " / " << month << " / " << year << endl;
}
Date Date::NgayTiepTheo(){
    Date NextDate;
    NextDate.day = day + 1;
    NextDate.month = month;
    NextDate.year = year;
    if(NextDate.day > NextDate.KiemTraThang()){
        NextDate.day = 1;
        NextDate.month = month + 1;
        if(NextDate.month > 12){
            NextDate.day = 1;
            NextDate.month = 1;
            NextDate.year = year + 1;
        }
    }
    return NextDate;
}
int main(){
    Date a;
    a.Nhap();
    Date NextDate;
    NextDate = a.NgayTiepTheo();
    cout << "Ngay tiep theo la ";
    NextDate.Xuat();
    return 0;
}
