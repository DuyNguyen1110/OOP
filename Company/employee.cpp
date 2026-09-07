#include "employee.h"
Employee::Employee() {
	MaNV = L"";
	HoTen = L"";
	NamSinh = 0;
	SoNgayLamViec = 0;
}
Employee::Employee(wstring MaNV, wstring HoTen, int NamSinh, int SoNgayLamViec) {
	this->MaNV = MaNV;
	this->HoTen = HoTen;
	this->NamSinh = NamSinh;
	this->SoNgayLamViec = SoNgayLamViec;
}
Employee::~Employee() {}
void Employee::NhapThongTin() {
	wcout << L"Nhập mã nhân viên: ";
	wcin >> MaNV;
	wcout << L"Nhập họ và tên: ";
	wcin.ignore();
	getline(wcin, HoTen);
	wcout << L"Nhập năm sinh: ";
	wcin >> NamSinh;
	wcout << L"Nhập số ngày làm việc: ";
	wcin >> SoNgayLamViec;
}
void Employee::XuatThongTin() {
	wcout << L"Mã nhân viên: " << MaNV << endl;
	wcout << L"Họ và tên: " << HoTen << endl;
	wcout << L"Năm sinh: " << NamSinh << endl;
	wcout << L"Số ngày làm việc: " << SoNgayLamViec << endl;
}
wstring Employee::getMaNV() const {
	return MaNV;
}
wstring Employee::getHoTen() const {
	return HoTen;
}
int Employee::getNamSinh() const {
	return NamSinh;
}
int Employee::getSoNgayLamViec() const {
	return SoNgayLamViec;
}
void Employee::setMaNV(wstring MaNV) {
	this->MaNV = MaNV;
}
void Employee::setHoTen(wstring HoTen) {
	this->HoTen = HoTen;
}
void Employee::setNamSinh(int NamSinh) {
	this->NamSinh = NamSinh;
}
void Employee::setSoNgayLamViec(int SoNgayLamViec) {
	this->SoNgayLamViec = SoNgayLamViec;
}
