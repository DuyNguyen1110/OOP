#include "KTXManager.h"
#include  <iostream>
#include <io.h>
#include <fcntl.h>
using std::wcout;
using std::wcin;
using std::endl;
int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	KTXManager* QuanLy = new KTXManager();
	int choice; 
	do{
		wcout << L"TRUNG TÂM QUẢN LÝ KÝ TÚC XÁ ĐẠI HỌC QUỐC GIA THÀNH PHỐ HỒ CHÍ MINH" << endl;
		wcout << L"0. Thoát chương trình" << endl;
		wcout << L"1. Khởi tạo dữ liệu phòng" << endl;
		wcout << L"2. Đăng ký phòng " << endl;
		wcout << L"3. Đổi phòng" << endl;
		wcout << L"4. Xem danh sách phòng trống" << endl;
		wcout << L"5. Xem danh sách sinh viên" << endl;
		wcout << L"6. Xem dánh sách hợp đồng" << endl;
		wcout << L"7. Thống kê" << endl;
		wcout << endl;
		wcout << L"Nhập lựa chọn: ";
		wcin >> choice;
		switch (choice) {
		case 0:
			wcout << L"Thoát chương trình" << endl;
			break;
		case 1:
			QuanLy->KhoiTao();
			break;
		case 2:
			QuanLy->DangKyPhong();
			break;
		case 3:
			QuanLy->DoiPhong();
			break;
		case 4:
			QuanLy->XemPhongTrong();
			break;
		case 5:
			QuanLy->XemDanhSachSinhVien();
			break;
		case 6:
			QuanLy->XemDanhSachHopDong();
			break;
		case 7:
			int choice2;
			do {
				wcout << L"THỐNG KÊ" << endl;
				wcout << L"0. Quay lại" << endl;
				wcout << L"1. Thống kê phòng theo loại" << endl;
				wcout << L"2. Thống kê doanh thu" << endl;
				wcout << L"3. Thống kê sinh viên theo trường" << endl;
				wcout << L"Lựa chọn: ";
				wcin >> choice2;
				switch (choice2) {
				case 0:
					break;
				case 1:
					QuanLy->ThongKePhongTheoLoai();
					break;
				case 2:
					QuanLy->ThongKeDoanhThu();
					break;
				case 3:
					QuanLy->ThongKeSinhVienTheoTruong();
					break;
				default:
					wcout << L"Lựa chọn không hợp lệ, vui lòng thử lại" << endl;
					break;
				}
			} while (choice2 != 0);
			break;
		}
	} while (choice != 0);
	delete QuanLy;
	return 0;
}
