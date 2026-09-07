#include "officestaff.h"
#include <iomanip>
using std::fixed;
using std::setprecision;
OfficeStaff::OfficeStaff() : Employee() {
	LuongCoBan = 8000000;
	HeSoLuong = 1.0;
}
OfficeStaff::OfficeStaff(wstring MaNV, wstring HoTen, int NamSinh, int SoNgayLamViec, double LuongCoBan, double HeSoLuong) : Employee(MaNV, HoTen, NamSinh, SoNgayLamViec) {
	this->LuongCoBan = LuongCoBan;
	this->HeSoLuong = HeSoLuong;
}
void OfficeStaff::NhapThongTin() {
	Employee::NhapThongTin();
	wcout << L"Nhập lương cơ bản: ";
	wcin >> LuongCoBan;
	if (LuongCoBan <= 0) {
		LuongCoBan = 8000000;
	}
	wcout << L"Nhập hệ số lương: ";
	wcin >> HeSoLuong;
	if (HeSoLuong <= 0) {
		HeSoLuong = 1.0;
	}
}
void OfficeStaff::XuatThongTin() {
	Employee::XuatThongTin();
	wcout << L"Lương cơ bản: " << fixed << setprecision(0) << LuongCoBan << endl;
	wcout << L"Hệ số lương: " << fixed << setprecision(0) << HeSoLuong << endl;
	wcout << L"Lương tháng: " << fixed << setprecision(0) << TinhLuong() << endl;
}
double OfficeStaff::TinhLuong() const {
	return LuongCoBan * HeSoLuong + (getSoNgayLamViec() * 200000);
}
double OfficeStaff::getLuongCoBan() const {
	return LuongCoBan;
}
double OfficeStaff::getHeSoLuong() const {
	return HeSoLuong;
}
void OfficeStaff::setLuongCoBan(double LuongCoBan) {
	this->LuongCoBan = LuongCoBan;
}
void OfficeStaff::setHeSoLuong(double HeSoLuong) {
	this->HeSoLuong = HeSoLuong;
}


