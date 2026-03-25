#include <iostream>
#include <cmath>
using namespace std;
class ToaDo{
private:
    int x;
    int y;
    int z;
public:
    void NhapToaDo();
    float KhoangCach(const ToaDo& a);
};
void ToaDo::NhapToaDo(){
    cout << "Nhap thanh phan thu nhat: ";
    cin >> x;
    cout << "Nhap thanh phan thu hai: ";
    cin >> y;
    cout << "Nhap thanh phan thu ba: ";
    cin >> z;
}
float ToaDo::KhoangCach(const ToaDo& a){
    float dis = sqrt(pow(x - a.x,2) + pow(y - a.y, 2) + pow(z - a.z, 2));
    return dis;
}
int main(){
    ToaDo a;
    ToaDo b;
    a.NhapToaDo();
    cout << endl;
    b.NhapToaDo();
    cout << endl;
    cout << "Khoang cach giua hai diem la " << a.KhoangCach(b) << endl;
    return 0;
}
