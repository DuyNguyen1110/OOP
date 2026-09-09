#include "ticket.h"
int Ticket::DemSoVe = 0;
Ticket::Ticket() {
	MaVe = L"";
	TenPhim = L"";
	NgayChieu = L"";
	GioChieu = L"";
	GiaGoc = 0.0;
}
Ticket::Ticket(wstring MaVe, wstring TenPhim, wstring NgayChieu, wstring GioChieu, double GiaGoc) {
	this->MaVe = MaVe;
	this->TenPhim = TenPhim;
	this->NgayChieu = NgayChieu;
	this->GioChieu = GioChieu;
	this->GiaGoc = GiaGoc;
}
Ticket::~Ticket() {
	DemSoVe--;
}
void Ticket::NhapThongTin() {
	wcout << L"Nhập mã vé: ";
	wcin >> MaVe;
	wcout << L"Nhập tên phim: ";
	wcin.ignore();
	getline(wcin, TenPhim);
	wcout << L"Nhập ngày chiếu: ";
	getline(wcin, NgayChieu);
	wcout << L"Nhập giờ chiếu: ";
	getline(wcin, GioChieu);
	wcout << L"Nhập giá: ";
	wcin >> GiaGoc;
	wcin.ignore();
}
void Ticket::XuatThongTin() {
	wcout << L"Mã vé: " << MaVe << endl;
	wcout << L"Tên phim: " << TenPhim << endl;
	wcout << L"Ngày chiếu: " << NgayChieu << endl;
	wcout << L"Giờ chiếu: " << GioChieu << endl;
	wcout << L"Gía: " << GiaGoc << endl;
}
int Ticket::getDemSoVe() {
	return DemSoVe;
}
wstring Ticket::getMaVe() const {
	return MaVe;
}
wstring Ticket::getTenPhim() const {
	return TenPhim;
}
wstring Ticket::getNgayChieu() const {
	return NgayChieu;
}
wstring Ticket::getGioChieu() const {
	return GioChieu;
}
double Ticket::getGiaGoc() const {
	return GiaGoc;
}
void Ticket::setMaVe(wstring MaVe) {
	this->MaVe = MaVe;
}
void Ticket::setTenPhim(wstring TenPhim) {
	this->TenPhim = TenPhim;
}
void Ticket::setNgayChieu(wstring NgayChieu) {
	this->NgayChieu = NgayChieu;
}
void Ticket::setGioChieu(wstring GioChieu) {
	this->GioChieu = GioChieu;
}
void Ticket::setGiaGoc(double GiaGoc) {
	this->GiaGoc = GiaGoc;
}
