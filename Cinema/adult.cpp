#include "adult.h"
Adult::Adult() {}
Adult::Adult(wstring MaVe, wstring TenPhim, wstring NgayChieu, wstring GioChieu, double GiaGoc) : Ticket(MaVe, TenPhim, NgayChieu, GioChieu, GiaGoc) {}
double Adult::TinhGiaVe() {
	return getGiaGoc();
}
void Adult::XuatThongTin() {
	Ticket::XuatThongTin();
	wcout << L"Gía thực tế: " << TinhGiaVe() << endl;
}
int Adult::getLoai() {
	return 1;
}
