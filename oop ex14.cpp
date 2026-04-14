/*Dữ liệu thành viên (private):
unsigned int tongSoXe - tổng số xe đã qua
double tongSoTien - tổng số tiền thu được
Constructor:
Khởi tạo tongSoXe = 0, tongSoTien = 0
Phương thức:
payingCar(): tăng tongSoXe lên 1, cộng tongSoTien thêm 0.5
nopayCar(): tăng tongSoXe lên 1, không cộng tiền
display(): in ra tongSoXe và tongSoTien
Cho phép người dùng nhấn phím khác để đếm xe không trả phí
Nhấn phím Esc → in ra tổng số xe và tổng số tiền → thoát chương trình
Không cần làm gì thêm ngoài các yêu cầu trên
Chỉ cần đúng chức năng: xe trả phí (payingCar) và xe không trả phí (nopayCar)
*/
#include <iostream>
#include <conio.h>
using namespace std;
class TollBooth{
private:
    unsigned int TongXe;
    double TongTien;
public:
    TollBooth(){
        TongXe = 0;
        TongTien = 0;
    }
    void PayingCar();
    void NopayCar();
    void Display();
};
void TollBooth::PayingCar(){
    TongXe++;
    TongTien += 0.5;
}
void TollBooth::NopayCar(){
    TongXe++;
}
void TollBooth::Display(){
    cout << "Tong so xe qua tram thu phi la " << TongXe << endl;
    cout << "Tong tien thu duoc la " << TongTien << endl;
}
int main(){
    TollBooth tb;
    int kytu;
    cout << "Nhan phim a hay A (KHONG ENTER) de hien xe tra phi" << endl;
    cout << "Nhan phim b hay B (KHONG ENTER) de hien xe khong tra phi" << endl;
    cout << "Nhan Esc + Enter de ket thuc chuong trinh" << endl;
    cout << endl;
    do{
        cout << "Moi ban nhap phim: ";
        kytu = _getch();
        if(kytu == 'a' || kytu == 'A'){
            tb.PayingCar();
            cout << "Xe tra phi" << endl;
        }else if(kytu == 'b' || kytu == 'B'){
            tb.NopayCar();
            cout << "Xe khong tra phi" << endl;
        }else if(kytu == 27){
            getchar();
            tb.Display();
            break;
        }else cout << "Ban nhap khong dung. Vui long nhap lai!" << endl;
    }while(1);
    return 0;
}
