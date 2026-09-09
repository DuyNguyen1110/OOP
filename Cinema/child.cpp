#include "child.h"
Child::Child() {
	Tuoi = 0;
}
Child::Child(wstring MaVe, wstring TenPhim, wstring NgayChieu, wstring GioChieu, double GiaGoc, int Tuoi) : Ticket(MaVe, TenPhim, NgayChieu, GioChieu, GiaGoc) {
	this->Tuoi = Tuoi;
}
void Child::NhapThongTin() {
	Ticket::NhapThongTin();
	wcout << L"Nhập tuổi: ";
	wcin >> Tuoi;
	wcin.ignore();
}
void Child::XuatThongTin() {
	Ticket::XuatThongTin();
	wcout << L"Tuổi: " << Tuoi << endl;
	wcout << L"Gía thực tế: " << TinhGiaVe() << endl;
}
double Child::TinhGiaVe() {
	if (Tuoi < 5)return 0;
	else if (Tuoi >= 5 && Tuoi <= 10)return getGiaGoc() * 0.5;
	return getGiaGoc() * 0.8;
}
int Child::getTuoi() const {
	return Tuoi;
}
void Child::setTuoi(int Tuoi) {
	this->Tuoi = Tuoi;
}
int Child::getLoai() {
	return 2;
}
