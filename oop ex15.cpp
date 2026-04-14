/*Giả sử mỗi đối tượng sách trong hệ thống thư viện có các thuộc tính sau: Mã sách, Tên sách, Năm xuất bản, Tổng số trang
Hãy xây dựng lớp Book với cá thuộc tính như trên và các phương thức cần thiết sau:
•	Thiết lập thông tin sách
•	Nhập thông tin cho đối tượng sách từ bàn phím
•	Xuất thông tin đối tượng sách ra màn hình
•	Truy vấn và câp nhật thông tin
Xây dựng lớp BookList để quản lý danh sách các dối tượng sách và thực hiện các yêu cầu sau:
•	Nhập danh sách các đối tượng sách
•	Xuất danh sách các đối tượng sách
•	Cho biết thông tin sách nào được xuất bản gần đây nhất
*/
#include <iostream>
#include <string>
using namespace std;
class Book{
private:
    int MaSach;
    string TenSach;
    int NamXuatBan;
    int TongSoTrang;
public:
    Book(){
        MaSach = 0;
        TenSach = "Khong co du lieu";
        NamXuatBan = 0;
        TongSoTrang = 0;
    }
    Book(int MS, string TS,int Nam, int Trang) : MaSach(MS), TenSach(TS), NamXuatBan(Nam), TongSoTrang(Trang){};
    void NhapThongTin();
    void XuatThongTin();
    int getMaSach(){return MaSach;}
    string getTenSach(){return TenSach;}
    int getNamXuatBan(){return NamXuatBan;}
    int getTongSoTrang(){return TongSoTrang;}
};
void Book::NhapThongTin(){
    cout << "Nhap ma sach: ";
    cin >> MaSach;
    cout << "Nhap ten sach: ";
    cin.ignore();
    getline(cin, TenSach);
    cout << "Nhap nam xuat ban cua sach: ";
    cin >> NamXuatBan;
    cout << "Nhap so trang cua sach: ";
    cin >> TongSoTrang;
}
void Book::XuatThongTin(){
    cout << "Ma sach: " << MaSach << endl;
    cout << "Ten sach: " << TenSach << endl;
    cout << "Nam xuat ban: " << NamXuatBan << endl;
    cout << "Tong so trang: " << TongSoTrang << endl;
}
class BookList{
private:
    Book* ds;
    int n;
public:
    BookList(){
        n = 0;
        ds = nullptr;
    }
    ~BookList(){
        delete[] ds;
    }
    void Nhap();
    void Xuat();
    void BookRecently();
};
void BookList::Nhap(){
    cout << "Nhap so sach: ";
    cin >> n;
    cout << endl;
    ds = new Book[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin sach thu " << i + 1 << endl;
        ds[i].NhapThongTin();
        cout << endl;
    }
}
void BookList::Xuat(){
    for(int i = 0; i < n; i++){
        cout << "Thong tin sach thu " << i + 1 << endl;
        ds[i].XuatThongTin();
        cout << endl;
    }
}
void BookList::BookRecently(){
    int Max = 0;
    for(int i = 0 ; i < n; i++){
        if(ds[i].getNamXuatBan() > ds[Max].getNamXuatBan())Max = i;
    }
    ds[Max].XuatThongTin();
}
int main(){
    BookList ks;
    ks.Nhap();
    cout << endl;
    ks.Xuat();
    cout << "Sach duoc xuat ban gan day la: " << endl;
    ks.BookRecently();
    return 0;
}
