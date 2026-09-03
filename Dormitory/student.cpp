#include "student.h"
#include "room.h"
#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include <algorithm>
using std::wcout;
using std::wcin;
using std::endl;
using std::wstring;
using std::vector;
using std::getline;
int Student::DemSinhVien = 0;
Student::Student() {
	MSSV = L"";
	HoTen = L"";
	Truong = L"";
	Khoa = L"";
	GioiTinh = L"";
	NamHoc = L"";
	SoDienThoai = L"";
	Email = L"";
	PhongDangO = nullptr; // Vì mới tạo nên chưa có phòng
	DemSinhVien++;
}
Student::Student(wstring MSSV, wstring HoTen, wstring Truong, wstring Khoa, wstring GioiTinh, wstring NamHoc, wstring SoDienThoai, wstring Email) {
	this->MSSV = MSSV;
	this->HoTen = HoTen;
	this->Truong = Truong;
	this->Khoa = Khoa;
	this->GioiTinh = GioiTinh;
	this->NamHoc = NamHoc;
	this->SoDienThoai = SoDienThoai;
	this->Email = Email;
	PhongDangO = nullptr;
	DemSinhVien++;
}
Student::~Student() {
	DemSinhVien--;
}
void Student::NhapThongTin() {
	wcout << L"Nhập mã số sinh viên: ";
	wcin >> MSSV;
	wcout << L"Nhập họ và tên: ";
	wcin.ignore();
	getline(wcin, HoTen);
	wcout << L"Nhập giới tính: ";
	getline(wcin, GioiTinh);
	wcout << L"Nhập trường: ";
	getline(wcin, Truong);
	wcout << L"Nhập khoa: ";
	getline(wcin, Khoa);
	wcout << L"Nhập năm học: ";
	getline(wcin, NamHoc);
	wcout << L"Nhập số điện thoại: ";
	getline(wcin, SoDienThoai);
	wcout << L"Nhập email: ";
	getline(wcin, Email);
	PhongDangO = nullptr;
}
void Student::XuatThongTin() {
	wcout << L"Mã số sinh viên: " << MSSV << endl;
	wcout << L"Họ và tên: " << HoTen << endl;
	wcout << L"Trường đang học: " << Truong << endl;
	wcout << L"Khoa đang học: " << Khoa << endl;
	wcout << L"Năm học: " << NamHoc << endl;
	wcout << L"Số điện thoại: " << SoDienThoai << endl;
	wcout << L"Email: " << Email << endl;
	if (PhongDangO != nullptr) {
		wcout << L"Phòng đang ở: " << PhongDangO->getMaPhong() << endl;
		wcout << L"Loại phòng: " << PhongDangO->getLoaiPhong() << endl;
		wcout << L"Số người trong phòng hiện tại: " << PhongDangO->getSoNguoiHienTai() << endl;
	}
	else wcout << L"Phòng hiện tại: chưa có phòng" << endl;
}
wstring Student::getMSSV() const { return MSSV; }
wstring Student::getHoTen() const { return HoTen; }
wstring Student::getTruong() const { return Truong; }
wstring Student::getKhoa() const { return Khoa; }
wstring Student::getGioiTinh() const { return GioiTinh; }
wstring Student::getNamHoc() const { return NamHoc; }
wstring Student::getSoDienThoai() const { return SoDienThoai; }
wstring Student::getEmail() const { return Email; }
Room* Student::getPhongDangO() const { return PhongDangO; }
void Student::setMSSV(wstring MSSV) {
	this->MSSV = MSSV;
}
void Student::setHoTen(wstring HoTen) {
	this->HoTen = HoTen;
}
void Student::setTruong(wstring Truong) {
	this->Truong = Truong;
}
void Student::setKhoa(wstring Khoa) {
	this->Khoa = Khoa;
}
void Student::setGioiTinh(wstring GioiTinh) {
	this->GioiTinh = GioiTinh;
}
void Student::setNamHoc(wstring NamHoc) {
	this->NamHoc = NamHoc;
}
void Student::setSoDienThoai(wstring SoDienThoai) {
	this->SoDienThoai = SoDienThoai;
}
void Student::setEmail(wstring Email) {
	this->Email = Email;
}
void Student::setPhongDangO(Room* A) {
	PhongDangO = A;
}
int Student::getDemSinhVien() {
	return DemSinhVien;
}
