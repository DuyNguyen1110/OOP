#include <iostream>
#include <string>
using namespace std;
class Vehicle{
protected:
    string brand;
    string model;
    int year;
public:
    void Input();
    void Output();
};
void Vehicle::Input(){
    cout << "Nhap nha san xuat: ";
    getline(cin, brand);
    cout << "Nhap mau xe: ";
    getline(cin, model);
    cout << "Nhap nam san xuat: ";
    cin >> year;
    cin.ignore();
}
void Vehicle::Output(){
    cout << "Nha san xuat cua xe la " << brand << endl;
    cout << "Mau xe la " << model << endl;
    cout << "Nam san xuat cua xe la " << year << endl;
}
class Car:public Vehicle{
private:
    int numberOfSeats;
    double fuelConsumption;
public:
    void Input();
    void Output();
    bool Fuel(){
        return (fuelConsumption <= 6.5);
    }
    bool Seat(){
        return (numberOfSeats >= 5);
    }
};
void Car::Input(){
    Vehicle::Input();
    cout << "Nhap so ghe: ";
    cin >> numberOfSeats;
    cout << "Nhap luong nhien lieu: ";
    cin >> fuelConsumption;
    cin.ignore();
}
void Car::Output(){
    Vehicle::Output();
    cout << "So ghe cua xe la " << numberOfSeats << endl;
    cout << "Luong nhien lieu cua xe la " << fuelConsumption << endl;
    if(Fuel())cout << "Day la mau xe tiet kiem nhien lieu" << endl;
    else cout << "Xe ton nhien lieu" << endl;
    if(Seat()) cout << "Day la xe gia dinh" << endl;
    else cout << "Nhung loai xe con lai" << endl;
}
int main(){
    Car c;
    c.Input();
    c.Output();
    return 0;
}
