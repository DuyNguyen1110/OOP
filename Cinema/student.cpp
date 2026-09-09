#include "student.h"
Student::Student() {
	MaSinhVien = L"";
	TruongDaiHoc = L"";
}
Student::Student(wstring MaVe, wstring TenPhim, wstring NgayChieu, wstring GioChieu, double GiaGoc, wstring MaSinhVien, wstring TruongDaiHoc) : Ticket(MaVe, TenPhim, NgayChieu, GioChieu, GiaGoc) {
	this->MaSinhVien = MaSinhVien;
	this->TruongDaiHoc = TruongDaiHoc;
}
void Student::NhapThongTin() {
	Ticket::NhapThongTin();
	wcout << L"Nhập mã sinh viên: ";
	wcin >> MaSinhVien;
	wcout << L"Nhập trường đại học: ";
	wcin.ignore();
	getline(wcin, TruongDaiHoc);
}
void Student::XuatThongTin() {
	Ticket::XuatThongTin();
	wcout << L"Mã sinh viên: " << MaSinhVien << endl;
	wcout << L"Trường đại học: " << TruongDaiHoc << endl;
	wcout << L"Gía thực tế: " << TinhGiaVe() << endl;
}
double Student::TinhGiaVe() {
	return 45000;
}
wstring Student::getMaSinhVien() const{
	return MaSinhVien;
}
wstring Student::getTruongDaiHoc() const {
	return TruongDaiHoc;
}
void Student::setMaSinhVien(wstring MaSinhVien) {
	this->MaSinhVien = MaSinhVien;
}
void Student::setTruongDaiHoc(wstring TruongDaiHoc) {
	this->TruongDaiHoc = TruongDaiHoc;
}
int Student::getLoai() {
	return 3;
}
