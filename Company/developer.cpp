#include "developer.h"
#include <iomanip>
using std::fixed;
using std::setprecision;
Developer::Developer() {
	SoGioTangCa = 0;
	NgonNguLapTrinh = L"";
}
Developer::Developer(wstring MaNV, wstring HoTen, int NamSinh, int SoNgayLamViec, double SoGioTangCa, wstring NgonNguLapTrinh) : Employee(MaNV, HoTen, NamSinh, SoNgayLamViec) {
	this->SoGioTangCa = SoGioTangCa;
	this->NgonNguLapTrinh = NgonNguLapTrinh;
}
void Developer::NhapThongTin() {
	Employee::NhapThongTin();
	wcout << L"Nhập số giờ tăng ca: ";
	wcin >> SoGioTangCa;
	if (SoGioTangCa < 0) SoGioTangCa = 0;
	wcout << L"Nhập ngôn ngữ lập trình: ";
	wcin.ignore();
	getline(wcin, NgonNguLapTrinh);
}
void Developer::XuatThongTin() {
	Employee::XuatThongTin();
	wcout << L"Số giờ tăng ca: " << SoGioTangCa << endl;
	wcout << L"Ngôn ngữ lập trình: " << NgonNguLapTrinh << endl;
	wcout << L"Lương tháng: " << fixed << setprecision(0) << TinhLuong() << endl;
}
double Developer::TinhLuong() const {
	return 12000000 + (SoGioTangCa * 300000);
}
double Developer::getSoGioTangCa() const {
	return SoGioTangCa;
}
wstring Developer::getNgonNguLapTrinh() const {
	return NgonNguLapTrinh;
}
void Developer::setSoGioTangCa(double SoGioTangCa) {
	this->SoGioTangCa = SoGioTangCa;
}
void Developer::setNgonNguLapTrinh(wstring NgonNguLapTrinh) {
	this->NgonNguLapTrinh = NgonNguLapTrinh;
}
