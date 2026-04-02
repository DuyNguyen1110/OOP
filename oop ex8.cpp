#include <iostream>
#include <cmath>
using namespace std;
class ToaDo{
private:
    double x;
    double y;
public:
    void Nhap();
    float KhoangCach(const ToaDo& a);
    double getx(){
        return x;
    }
    double gety(){
        return y;
    }
};
void ToaDo::Nhap(){
    cout << "Nhap thanh phan thu nhat: ";
    cin >> x;
    cout << "Nhap thanh phan thu hai: ";
    cin >> y;
}
float ToaDo::KhoangCach(const ToaDo& a){
    return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
}
int main(){
    ToaDo DiemA;
    ToaDo DiemB;
    ToaDo DiemC;
    cout << "Toa do thu nhat " << endl;
    DiemA.Nhap();
    cout << endl;
    cout << "Toa do thu hai " << endl;
    DiemB.Nhap();
    cout << endl;
    cout << "Toa do thu ba " << endl;
    DiemC.Nhap();
    cout << endl;
    double ab = DiemA.KhoangCach(DiemB);
    double bc = DiemB.KhoangCach(DiemC);
    double ca = DiemC.KhoangCach(DiemA);
    cout << "Do dai canh AB " << ab << endl;
    cout << "Do dai canh BC " << bc << endl;
    cout << "Do dai canh CA " << ca << endl;
    cout << endl;
    double P = ab + bc + ca;
    cout << "Chu vi tam giac la " << P << endl;
    double p = P / 2;
    cout << "Dien tich tam giac la " << sqrt(p * (p - ab) * (p - bc) * (p - ca)) << endl;
    cout << "Toa do trong tam la " << "(" << (DiemA.getx() + DiemB.getx() + DiemC.getx()) / 3 << "," << (DiemA.gety() + DiemB.gety() + DiemC.gety()) / 3 << ")" << endl;
    return 0;
}
