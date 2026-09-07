#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "company.h"
#include "officestaff.h"
#include "developer.h"
#include "tester.h"
using std::wcout;
using std::wcin;
using std::getline;
int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	Company QuanLy;
	int choice;
	do{
		wcout << L"HỆ THỐNG QUẢN LÝ NHÂN SỰ CÔNG TY PHẦN MỀM" << endl;
		wcout << L"0. Thoát chương trình" << endl;
		wcout << L"1. Thêm nhân viên" << endl;
		wcout << L"2. Xuất danh sách nhân viên" << endl;
		wcout << L"3. Tính tổng lương nhân viên" << endl;
		wcout << L"4. Tìm nhân viên có lương cao nhất" << endl;
		wcout << L"5. Sắp xếp lương từ cao xuống thấp" << endl;
		wcout << endl;
		wcout << L"Lựa chọn: ";
		wcin >> choice;
		switch (choice) {
		case 0:
			wcout << L"Thoát chương trình. Bái bai, hẹn gặp lại:)))" << endl;
			break;
		case 1: {
			int LoaiNhanVien;
			wcout << L"Chọn loại nhân viên: " << endl;
			wcout << L"1. Nhân viên văn phòng" << endl;
			wcout << L"2. Lập trình viên" << endl;
			wcout << L"3. Kiểm thử" << endl;
			wcout << endl;
			wcout << L"Lựa chọn: "; wcin >> LoaiNhanVien;
			Employee* NhanVien = nullptr;
			switch (LoaiNhanVien) {
			case 1: {
				OfficeStaff* VanPhong = new OfficeStaff();
				VanPhong->NhapThongTin();
				NhanVien = VanPhong;
				break;
			}
			case 2: {
				Developer* LapTrinh = new Developer();
				LapTrinh->NhapThongTin();
				NhanVien = LapTrinh;
				break;
			}
			case 3: {
				Tester* KiemThu = new Tester();
				KiemThu->NhapThongTin();
				NhanVien = KiemThu;
				break;
			}
			default:
				wcout << L"Bấm sai rồi, chọn lại đê:))" << endl;
				wcout << endl;
			}
			if (NhanVien != nullptr) {
				QuanLy.ThemNhanVien(NhanVien);
			}
			break;
		}
		case 2:
			QuanLy.XuatTatCa();
			break;
		case 3:
			wcout << L"Tổng lương công ty phải trả: " << QuanLy.TongLuong() << endl;
			wcout << endl;
			break;
		case 4:
			QuanLy.NhanVienLuongCaoNhat();
			break;
		case 5:
			QuanLy.SapXepTheoLuong();
			break;
		default:
			wcout << L"Chọn lại bạn đê" << endl;
			wcout << endl;
		}
	} while (choice != 0);
}
