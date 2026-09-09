#include "vip.h"
VIP::VIP() {
	DichVuDiKem = L"";
	PhuPhi = 0.0;
}
VIP::VIP(wstring MaVe, wstring TenPhim, wstring NgayChieu, wstring GioChieu, double GiaGoc, wstring DichVuDiKem, double PhuPhi) : Ticket(MaVe, TenPhim, NgayChieu, GioChieu, GiaGoc) {
	this->DichVuDiKem = DichVuDiKem;
	this->PhuPhi = PhuPhi;
}
void VIP::NhapThongTin() {
	Ticket::NhapThongTin();
	wcout << L"Nhập dịch vụ đi kèm: ";
	wcin.ignore();
	getline(wcin, DichVuDiKem);
	wcout << L"Nhập phụ phí: ";
	wcin >> PhuPhi;
	if (PhuPhi < 0) PhuPhi = 0;
}
void VIP::XuatThongTin() {
	Ticket::XuatThongTin();
	wcout << L"Dịch vụ đi kèm: " << DichVuDiKem << endl;
	wcout << L"Phụ phí: " << PhuPhi << endl;
	wcout << L"Gía thực tế: " << TinhGiaVe() << endl;
}
double VIP::TinhGiaVe() {
	return getGiaGoc() * 1.2 + PhuPhi;
}
wstring VIP::getDichVuDiKem() const {
	return DichVuDiKem;
}
double VIP::getPhuPhi() const {
	return PhuPhi;
}
void VIP::setDichVuDiKem(wstring DichVuDiKem) {
	this->DichVuDiKem = DichVuDiKem;
}
void VIP::setPhuPhi(double PhuPhi) {
	this->PhuPhi = PhuPhi;
}
int VIP::getLoai() {
	return 4;
}
