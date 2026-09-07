#include "company.h"
#include <algorithm>
Company::Company() {}
Company::~Company() {
	for (int i = 0; i < DanhSachNhanVien.size(); i++) {
		delete DanhSachNhanVien[i];
	}
	DanhSachNhanVien.clear();
}
void Company::ThemNhanVien(Employee* NhanVien) {
	DanhSachNhanVien.push_back(NhanVien);
	wcout << L"Đã thêm nhân viên thành công" << endl;
	wcout << endl;
}
void Company::XuatTatCa() {
	wcout << L"DANH SÁCH NHÂN VIÊN" << endl;
	if (DanhSachNhanVien.empty()) {
		wcout << L"Chưa có nhân viên" << endl;
		return;
	}
	for (int i = 0; i < DanhSachNhanVien.size(); i++) {
		wcout << L"Thông tin nhân viên thứ " << i + 1 << L": " << endl;
		DanhSachNhanVien[i]->XuatThongTin();
		wcout << endl;
	}
}
double Company::TongLuong() {
	double Tong = 0;
	for (int i = 0; i < DanhSachNhanVien.size(); i++) {
		Tong += DanhSachNhanVien[i]->TinhLuong();
	}
	return Tong;
}
void Company::NhanVienLuongCaoNhat() {
	wcout << L"NHÂN VIÊN CÓ LƯƠNG CAO NHẤT" << endl;
	if (DanhSachNhanVien.empty()) { 
		wcout << L"Chưa có nhân viên" << endl;
		return;
	}
	Employee* Max = DanhSachNhanVien[0];
	for (int i = 1; i < DanhSachNhanVien.size(); i++) {
		if (DanhSachNhanVien[i]->TinhLuong() > Max->TinhLuong())Max = DanhSachNhanVien[i];
	}
	Max->XuatThongTin();
	wcout << endl;
}
void Company::SapXepTheoLuong() {
	wcout << L"SẮP XẾP LƯƠNG NHÂN VIÊN GIẢM DẦN" << endl;
	if (DanhSachNhanVien.empty()) { 
		wcout << L"Chưa có nhân viên" << endl;
		return;
	}
	for (int i = 1; i < DanhSachNhanVien.size(); i++) {
		Employee* e = DanhSachNhanVien[i];
		int k;
		for (k = i - 1; k > -1; k--) {
			if (DanhSachNhanVien[k]->TinhLuong() >= e->TinhLuong())break;
			DanhSachNhanVien[k + 1] = DanhSachNhanVien[k];
		}
		DanhSachNhanVien[k + 1] = e;
	}
	wcout << endl;
}
