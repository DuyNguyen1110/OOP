#include <iostream>
#include <string>
using namespace std;
class Product{
protected:
    string productName;
    double price;
    int warrantyMonths;
public:
    void Input();
    void Output();
};
void Product::Input(){
    cout << "Nhap ten san pham: ";
    getline(cin, productName);
    cout << "Nhap gia cua san pham: ";
    cin >> price;
    cout << "Nhap so thang bao hanh: ";
    cin >> warrantyMonths;
    cin.ignore();
}
void Product::Output(){
    cout << "Ten cua san pham la " << productName << endl;
    cout << "Gia cua san pham la " << price << endl;
    cout << "So phieu giam gia ma ban dang co la " << warrantyMonths << endl;
}
class Laptop:public Product{
private:
    string cpu;
    int ram;
    int storage;
public:
    void Input();
    void Output();
    double discountPrice(){
        return price * 0.9;
    }
    void CheckLaptop(){
        if(ram >= 16 && storage >= 512) cout << "Laptop co cau hinh tot" << endl;
        else cout << "Laptop lo" << endl;
    }
};
void Laptop::Input(){
    Product::Input();
    cout << "Nhap ten cpu: ";
    getline(cin, cpu);
    cout << "Nhap ram: ";
    cin >> ram;
    cout << "Nhap luu tru: ";
    cin >> storage;
    cin.ignore();
}
void Laptop::Output(){
    Product::Output();
    cout << "Ten cpu la " << cpu << endl;
    cout << "Loai ram: " << ram << endl;
    cout << "Luu tru: " << storage << endl;
    cout << "Gia sau khi khuyen mai la " << discountPrice() << endl;
    CheckLaptop();
}
int main(){
    Laptop lt;
    lt.Input();
    lt.Output();
    return 0;
}
