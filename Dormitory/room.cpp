#include "room.h"
#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include <algorithm>
using std::wstring;
using std::wcout;
using std::wcin;
using std::endl;
using std::getline;
using std::vector;
Room::Room() {
	MaPhong = L"";
	SoChoToiDa = 0;
	SoNguoiHienTai = 0;
	DonGia = 0.0;
	LoaiPhong = L"";
	ToaNha = L"";
	Tang = 0;
	Khu = L"";
}
Room::Room(wstring MaPhong, int SoChoToiDa, double DonGia, wstring LoaiPhong, wstring ToaNha, int Tang, wstring Khu) {
	this->MaPhong = MaPhong;
	this->SoChoToiDa = SoChoToiDa;
	SoNguoiHienTai = 0; // Mặc dù không khai báo trong tham số của Constructor nhưng vẫn gán vì nếu không gán sẽ tự động có giá trị rác
	this->DonGia = DonGia;
	this->LoaiPhong = LoaiPhong;
	this->ToaNha = ToaNha;
	this->Tang = Tang;
	this->Khu = Khu;
}
Room::~Room() {}
void Room::NhapThongTin() {
	wcout << L"Nhập mã phòng: ";
	wcin >> MaPhong;
	wcout << L"Nhập số chỗ tối đa: ";
	wcin >> SoChoToiDa;
	wcout << L"Nhập đơn giá phòng: ";
	wcin >> DonGia;
	wcout << L"Nhập loại phòng: ";
	wcin.ignore();
	getline(wcin, LoaiPhong);
	wcout << L"Nhập tòa nhà: ";
	wcin >> ToaNha;
	wcout << L"Nhập số tầng: ";
	wcin >> Tang;
	wcout << L"Nhập khu";
	wcin.ignore();
	getline(wcin, Khu);
}
void Room::XuatThongTin() {
	wcout << L"Mã phòng: " << MaPhong << endl;
	wcout << L"Số chỗ tối đa: " << SoChoToiDa << endl;
	wcout << L"Số người hiện tại: " << SoNguoiHienTai << endl;
	wcout << L"Đơn giá phòng: " << DonGia << endl;
	wcout << L"Loại phòng: " << LoaiPhong << endl;
	wcout << L"Tòa nhà: " << ToaNha << endl;
	wcout << L"Số tầng: " << Tang << endl;
	wcout << L"Khu: " << Khu << endl;
}
void Room::ThemNguoi() {
	if (ConTrong()) {
		SoNguoiHienTai++;
	}
	else wcout << L"Phòng đã đầy, vui lòng chọn phòng khác" << endl;
}
void Room::GiamNguoi() {
	if (SoNguoiHienTai > 0) {
		SoNguoiHienTai--;
	}
	else wcout << L"Phòng không có người" << endl;
}
wstring Room::getMaPhong() const {
	return MaPhong;
}
int Room::getSoChoToiDa() const {
	return SoChoToiDa;
}
int Room::getSoNguoiHienTai() const {
	return SoNguoiHienTai;
}
double Room::getDonGia() const {
	return DonGia;
}
wstring Room::getToaNha() const {
	return ToaNha;
}
int Room::getTang() const{
	return Tang;
}
wstring Room::getKhu() const {
	return Khu;
}
void Room::setMaPhong(wstring MaPhong) {
	this->MaPhong = MaPhong;
}
void Room::setSoChoToiDa(int SoChoToiDa) {
	this->SoChoToiDa = SoChoToiDa;
}
void Room::setDonGia(double DonGia) {
	this->DonGia = DonGia;
}
void Room::setLoaiPhong(wstring LoaiPhong) {
	this->LoaiPhong = LoaiPhong;
}
void Room::setSoNguoiHienTai(int SoNguoiHienTai) {
	this->SoNguoiHienTai = SoNguoiHienTai;
}
void Room::setToaNha(wstring ToaNha) {
	this->ToaNha = ToaNha;
}
void Room::setTang(int Tang) {
	this->Tang = Tang;
}
void Room::setKhu(wstring Khu) {
	this->Khu = Khu;
}

