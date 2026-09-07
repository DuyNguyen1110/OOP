#include "tester.h"
#include <iomanip>
using std::fixed;
using std::setprecision;
Tester::Tester() {
	SoLoiPhatHien = 0;
	LoaiKiemThu = L"";
}
Tester::Tester(wstring MaNV, wstring HoTen, int NamSinh, int SoNgayLamViec, int SoLoiPhatHien, wstring LoaiKiemThu) : Employee(MaNV, HoTen, NamSinh, SoNgayLamViec) {
	this->SoLoiPhatHien = SoLoiPhatHien;
	this->LoaiKiemThu = LoaiKiemThu;
}
void Tester::NhapThongTin() {
	Employee::NhapThongTin();
	wcout << L"Nhập số lỗi phát hiện: ";
	wcin >> SoLoiPhatHien;
	if (SoLoiPhatHien < 0)SoLoiPhatHien = 0;
	wcout << L"Nhập loại kiểm thử: ";
	wcin.ignore();
	getline(wcin, LoaiKiemThu);
}
void Tester::XuatThongTin() {
	Employee::XuatThongTin();
	wcout << L"Số lỗi phát hiện: " << SoLoiPhatHien << endl;
	wcout << L"Loại kiểm thử: " << LoaiKiemThu << endl;
	wcout << L"Lương tháng: " << fixed << setprecision(0) << TinhLuong() << endl;
}
double Tester::TinhLuong() const {
	return 10000000 + (SoLoiPhatHien * 100000);
}
int Tester::getSoLoiPhatHien() const {
	return SoLoiPhatHien;
}
wstring Tester::getLoaiKiemThu() const {
	return LoaiKiemThu;
}
void Tester::setSoLoiPhatHien(int SoLoiPhatHien) {
	this->SoLoiPhatHien = SoLoiPhatHien;
}
void Tester::setLoaiKiemThu(wstring LoaiKiemThu) {
	this->LoaiKiemThu = LoaiKiemThu;
}
