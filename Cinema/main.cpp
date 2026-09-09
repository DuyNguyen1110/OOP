#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "cinema.h"
#include "adult.h"
#include "child.h"
#include "student.h"
#include "vip.h"
using std::wcout;
using std::wcin;
using std::endl;
int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	Cinema RapChieuPhim;
	int choice;
	do {
		wcout << L"QUẢN LÝ RẠP CHIẾU PHIM" << endl;
		wcout << L"0. Thoát chương trình" << endl;
		wcout << L"1. Thêm vé" << endl;
		wcout << L"2. Xuất danh sách vé" << endl;
		wcout << L"3. Tính tổng doanh thu" << endl;
		wcout << L"4. Tìm vé có giá cao nhất" << endl;
		wcout << L"5. Thống kê vé theo loại" << endl;
		wcout << endl;
		wcout << L"Lựa chọn: ";
		wcin >> choice;
		switch (choice) {
		case 0:
			wcout << L"Một ngày tốt lành nháaaaaaa, bái baiii" << endl;
			break;
		case 1: {
			int Loai;
			wcout << L"1. Vé người lớn" << endl;
			wcout << L"2. Vé trẻ em" << endl;
			wcout << L"3. Vé học sinh" << endl;
			wcout << L"4. Vé VIP" << endl;
			wcout << endl;
			wcout << L"Lựa chọn: ";
			wcin >> Loai;
			Ticket* Ve = nullptr;
			switch (Loai) {
			case 1: {
				Adult* NguoiLon = new Adult();
				NguoiLon->NhapThongTin();
				Ve = NguoiLon;
				break;
			}
			case 2: {
				Child* TreEm = new Child();
				TreEm->NhapThongTin();
				Ve = TreEm;
				break;
			}
			case 3: {
				Student* SinhVien = new Student();
				SinhVien->NhapThongTin();
				Ve = SinhVien;
				break;
			}
			case 4: {
				VIP* vip = new VIP();
				vip->NhapThongTin();
				Ve = vip;
				break;
			}
			default:
				wcout << L"Không biết nhìn số à" << endl;
				wcout << endl;
				break;
			}
			if (Ve != nullptr) {
				RapChieuPhim.ThemVe(Ve);
			}
			break;
		}
		case 2:
			RapChieuPhim.XuatTatCa();
			wcout << endl;
			break;
		case 3:
			wcout << L"Tổng doanh thu: " << RapChieuPhim.TongDoanhThu() << endl;
			wcout << endl;
			break;
		case 4:
			RapChieuPhim.TimVeGiaCaoNhat();
			wcout << endl;
			break;
		case 5:
			RapChieuPhim.ThongKeVeTheoLoai();
			wcout << endl;
			break;
		} 
	} while (choice != 0);
}
