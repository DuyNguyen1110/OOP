#include "room.h"
#include "student.h"
#include "contract.h"
#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <algorithm>
using std::wcout;
using std::wcin;
using std::endl;
using std::wstring;
using std::to_wstring;
using std::getline;
using std::vector;
int Contract::DemHopDong = 0;
int Contract::SoThuTu = 0;
Contract::Contract() {
	MaHopDong = L"";
	SinhVien = nullptr;
	Phong = nullptr;
	NgayBatDau = L"";
	SoThang = 0;
	TongTien = 0.0;
	DaThanhToan = false;
	DemHopDong++;
}
Contract::Contract(Student* SinhVien, Room* Phong, wstring NgayBatDau, int SoThang, bool DaThanhToan) {
	this->SinhVien = SinhVien;
	this->Phong = Phong; // Hợp đồng phải có cả sinh viên và phòng nên phải gán
	this->NgayBatDau = NgayBatDau;
	this->SoThang = SoThang;
	this->DaThanhToan = DaThanhToan;
	SoThuTu++;
	MaHopDong = L"BD";
	if (SoThuTu < 10) MaHopDong += L"00" + to_wstring(SoThuTu);
	else if (SoThuTu > 9 && SoThuTu < 100) MaHopDong += L"0" + to_wstring(SoThuTu);
	else MaHopDong += to_wstring(SoThuTu);
	TongTien = tinhTongTien(); // để sau khi gán phòng và số tháng mới tính được
}
Contract::~Contract() {
	DemHopDong--;
}
void Contract::NhapThongTin() {
	wcout << L"Nhập ngày bắt đầu: ";
	wcin.ignore();
	getline(wcin, NgayBatDau);
	wcout << L"Nhập số tháng thuê (gồm loại 10, 11, 12 tháng): ";
	wcin >> SoThang;
	wcout << L"Đã thanh toán chưa? Nhập 1 nếu rồi, nhập 0 nếu chưa";
	wcin >> DaThanhToan;
	TongTien = tinhTongTien();
}
void Contract::XuatThongTin() {
	wcout << L"Mã hợp đồng: " << MaHopDong << endl;
	if (SinhVien != nullptr) { // Hợp đồng phải có thông tin của người đăng ký
		wcout << L"Sinh viên: " << SinhVien->getHoTen() << L" - " << SinhVien->getMSSV() << L" - " << SinhVien->getTruong() << endl;
	}
	else {
		wcout << L"Sinh viên: chưa có" << endl;
	}
	if (Phong != nullptr) { // Thông tin phòng mà sinh viên đăng ký
		wcout << L"Phòng " << Phong->getMaPhong() << L" - " << Phong->getLoaiPhong() << endl;
	}
	else {
		wcout << L"Phòng: chưa có" << endl;
	}
	wcout << L"Ngày bắt đầu: " << NgayBatDau << endl;
	wcout << L"Số tháng thuê: " << SoThang << endl;
	wcout << L"Tổng tiền: " << TongTien << L" Đồng" << endl;
	wcout << L"Tình trạng thanh toán: " << (DaThanhToan ? L"Rồi" : L"Chưa") << endl;
}
double Contract::tinhTongTien() {
	if (Phong != nullptr) {
		return SoThang * Phong->getDonGia();
	}
	return 0.0;
}
void Contract::ThanhToan() {
	DaThanhToan = true;
	wcout << L"Hợp đồng " << MaHopDong << L" đã được thanh toán thành công!" << endl;
}
int Contract::getDemHopDong() {
	return DemHopDong;
}
int Contract::getSoThuTu() {
	return SoThuTu;
}
wstring Contract::getMaHopDong() const{
	return MaHopDong;
}
wstring Contract::getNgayBatDau() const {
	return NgayBatDau;
}
int Contract::getSoThang() const {
	return SoThang;
}
double Contract::getTongTien() const {
	return TongTien;
}
bool Contract::getDaThanhToan() const {
	return DaThanhToan;
}
Student* Contract::getSinhVien() const {
	return SinhVien;
}
Room* Contract::getPhong() const {
	return Phong;
}
void Contract::setMaHopDong(wstring MaHopDong) {
	this->MaHopDong = MaHopDong;
}
void Contract::setNgayBatDau(wstring NgayBatDau) {
	this->NgayBatDau = NgayBatDau;
}
void Contract::setSoThang(int SoThang) {
	this->SoThang = SoThang;
	TongTien = tinhTongTien(); // Cập nhật lại khi thay đổi số tháng
}
void Contract::setTongTien(double TongTien) {
	this->TongTien = TongTien;
}
void Contract::setDaThanhToan(bool DaThanhToan) {
	this->DaThanhToan = DaThanhToan;
}
void Contract::setPhong(Room* Phong) {
	this->Phong = Phong;
	TongTien = tinhTongTien(); // Cập nhật lại khi thay đổi phòng
}
void Contract::setSinhVien(Student* SinhVien) {
	this->SinhVien = SinhVien;
}
