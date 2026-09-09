#include "cinema.h"
Cinema::Cinema() {}
Cinema::~Cinema() {
	for (int i = 0; i < DanhSachVe.size(); i++) {
		delete DanhSachVe[i];
	}
	DanhSachVe.clear();
}
void Cinema::ThemVe(Ticket* Ve) {
	DanhSachVe.push_back(Ve);
	wcout << L"Đã thêm vé" << endl;
	wcout << endl;
}
void Cinema::XuatTatCa() {
	if (DanhSachVe.empty()) {
		wcout << L"Chưa có vé nào" << endl;
		return;
	}
	wcout << L"DANH SÁCH VÉ" << endl;
	for (int i = 0; i < DanhSachVe.size(); i++) {
		wcout << L"Thông tin vé thứ: " << i + 1 << L": " << endl;
		DanhSachVe[i]->XuatThongTin();
		wcout << endl;
	}
}
double Cinema::TongDoanhThu() {
	double Tong = 0;
	for (int i = 0; i < DanhSachVe.size(); i++) {
		Tong += DanhSachVe[i]->TinhGiaVe();
	}
	return Tong;
}
void Cinema::TimVeGiaCaoNhat() {
	wcout << L"VÉ CÓ GIÁ CAO NHẤT" << endl;
	if (DanhSachVe.empty()) {
		wcout << L"Chưa có vé nào" << endl;
		return;
	}
	Ticket* Max = DanhSachVe[0];
	for (int i = 1; i < DanhSachVe.size(); i++) {
		if (DanhSachVe[i]->TinhGiaVe() > Max->TinhGiaVe()) Max = DanhSachVe[i];
	}
	Max->XuatThongTin();
}
void Cinema::ThongKeVeTheoLoai() {
	wcout << L"THỐNG KÊ THEO LOẠI" << endl;
	if (DanhSachVe.empty()) {
		wcout << L"Chưa có vé nào" << endl;
		return;
	}
	int Adult = 0, Child = 0, Student = 0, VIP = 0;
	for (int i = 0; i < DanhSachVe.size(); i++) {
		switch (DanhSachVe[i]->getLoai()) {
		case 1:
			Adult++;
			break;
		case 2:
			Child++;
			break;
		case 3:
			Student++;
			break;
		case 4:
			VIP++;
			break;
		}
	}
	wcout << L"Số vé người lớn: " << Adult << endl;
	wcout << L"Số vé trẻ em: " << Child << endl;
	wcout << L"Số vé học sinh: " << Student << endl;
	wcout << L"Số vé VIP: " << VIP << endl;
}
