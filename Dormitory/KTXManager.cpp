#include "KTXManager.h"
#include "roomcategory.h"
#include "contract.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using std::wcout;
using std::wcin;
using std::endl;
using std::left;
using std::vector;
using std::wstring;
using std::to_wstring;
using std::right;
using std::setw;
using std::fixed;
using std::setprecision;
KTXManager::KTXManager() {}
KTXManager::~KTXManager() {
	Xoa();
}
Room* KTXManager::TaoPhongTheoLoai(int Loai, wstring MaPhong, wstring ToaNha, int Tang, wstring Khu) {
	switch(Loai) { // Trả về địa chỉ của từng loại phòng ( căn bản là hàm này chỉ khởi tạo 1 phòng )
		case 1:
			return new Room8(MaPhong, ToaNha, Tang, Khu);
		case 2:
			return new Room6(MaPhong, ToaNha, Tang, Khu);
		case 3:
			return new Room6AC(MaPhong, ToaNha, Tang, Khu);
		case 4:
			return new Room4(MaPhong, ToaNha, Tang, Khu);
		case 5:
			return new Room4AC(MaPhong, ToaNha, Tang, Khu);
		case 6:
			return new Room4ACFull(MaPhong, ToaNha, Tang, Khu);
		case 7:
			return new Room4ACVIP(MaPhong, ToaNha, Tang, Khu);
		case 8:
			return new Room2(MaPhong, ToaNha, Tang, Khu);
		case 9:
			return new Room2AC(MaPhong, ToaNha, Tang, Khu);
		case 10:
			return new Room2ACFull(MaPhong, ToaNha, Tang, Khu);
		case 11:
			return new Room2ACVIP(MaPhong, ToaNha, Tang, Khu);

	}
}
bool KTXManager::KiemTra(wstring MSSV) { // Kiểm tra để chắc chắn 1 sinh viên đăng ký 1 chỗ, 1 hợp đồng
	for (int i = 0; i < DanhSachSinhVien.size(); i++) {
		if (DanhSachSinhVien[i]->getMSSV() == MSSV)return true;
	}
	return false;
}
Student* KTXManager::TimSinhVien(wstring MSSV) {
	for (int i = 0; i < DanhSachSinhVien.size(); i++) {
		if (DanhSachSinhVien[i]->getMSSV() == MSSV) return DanhSachSinhVien[i];
	}
	return nullptr;
}
Contract* KTXManager::TimHopDong(wstring MSSV) {
	for (int i = 0; i < DanhSachHopDong.size(); i++) {
		if (DanhSachHopDong[i]->getSinhVien()->getMSSV() == MSSV) return DanhSachHopDong[i];
	}
	return nullptr;
}
wstring KTXManager::ChonLoaiPhong() {
	int choice;
	wcout << endl;
	wcout << L"DANH SÁCH LOẠI PHÒNG DÀNH CHO SINH VIÊN" << endl;
	wcout << L"1.Phòng 8 sinh viên" << endl;
	wcout << L"2.Phòng 6 sinh viên" << endl;
	wcout << L"3.Phòng dịch vụ 6 sinh viên có máy lạnh, rèm" << endl;
	wcout << L"4.Phòng dịch vụ 4 sinh viên" << endl;
	wcout << L"5.Phòng dịch vụ 4 sinh viên có máy lạnh, rèm" << endl;
	wcout << L"6.Phòng dịch vụ 4 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt" << endl;
	wcout << L"7.Phòng dịch vụ 4 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt, máy nước nóng, kệ dép" << endl;
	wcout << L"8.Phòng dịch vụ 2 sinh viên" << endl;
	wcout << L"9.Phòng dịch vụ 2 sinh viên có máy lạnh, rèm" << endl;
	wcout << L"10.Phòng dịch vụ 2 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt" << endl;
	wcout << L"11.Phòng dịch vụ 2 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt, máy nước nóng, kệ dép" << endl;
	wcout << endl;
	wcout << L"CÁCH CHỌN LOẠI PHÒNG" << endl;
	wcout << L"Chọn phòng nào thì nhấn số thứ tự tương ứng" << endl;
	wcout << L"VD: Muốn chọn phòng dịch vụ 6 sinh viên có máy lạnh, rèm thì nhấn phím 2" << endl;
	wcout << endl;
	wcout << L"Lựa chọn: ";
	wcin >> choice;
	switch (choice) {
		case 1: return L"Phòng 8 sinh viên";
		case 2: return L"Phòng 6 sinh viên";
		case 3: return L"Phòng dịch vụ 6 sinh viên có máy lạnh, rèm";
		case 4: return L"Phòng dịch vụ 4 sinh viên";
		case 5: return L"Phòng dịch vụ 4 sinh viên có máy lạnh, rèm";
		case 6: return L"Phòng dịch vụ 4 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt";
		case 7: return L"Phòng dịch vụ 4 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt, máy nước nóng, kệ dép";
		case 8: return L"Phòng dịch vụ 2 sinh viên";
		case 9: return L"Phòng dịch vụ 2 sinh viên có máy lạnh, rèm";
		case 10: return L"Phòng dịch vụ 2 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt";
		case 11: return L"Phòng dịch vụ 2 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt, máy nước nóng, kệ dép";
		default: return L"";
	}
}
void KTXManager::HienThiDanhSachToa(wstring Khu) {
	if (Khu == L"A") {
		wcout << L"1.A1  2.A2  3.A3  4.A4  5.A5" << endl;
		wcout << L"6.A6  7.A7  8.A8  9.A9  10.A10" << endl;
		wcout << L"11.A11  12.A12  13.A14  14.A15  15.A17" << endl;
		wcout << L"16.A18 17.A19 18.A20" << endl;
		wcout << L"19.H1 20.H2 21.H3 22.H4" << endl;
	}
	else if (Khu == L"B") {
		wcout << L"1.BA1 2.BA2 3.BA3 4.BA4 5.BA5" << endl;
		wcout << L"6.BB1 7.BB2 8.BB3 9.BB4 10.BB5" << endl;
		wcout << L"11.BC1 12.BC2 13.BC3 14.BC4 15.BC5 16.BC6" << endl;
		wcout << L"17.BD2 18.BD3 19.BD4 20.BD5 21.BD6" << endl;
		wcout << L"22.BE1 23.BE2 24.BE3 25.BE4" << endl;
	}
}
wstring KTXManager::LayGioiTinh(wstring ToaNha) {
	if (ToaNha == L"A1" || ToaNha == L"A4" || ToaNha == L"A5" || ToaNha == L"A7" || ToaNha == L"A8" || ToaNha == L"A9" || ToaNha == L"A10" || ToaNha == L"A12" || ToaNha == L"A17" || ToaNha == L"A19") {
		return L"Nữ";
	}
	if (ToaNha == L"A2" || ToaNha == L"A3" || ToaNha == L"A6" || ToaNha == L"A11" || ToaNha == L"A14" || ToaNha == L"A15" || ToaNha == L"A18" || ToaNha == L"A20") {
		return L"Nam";
	}
	if (ToaNha == L"H1" || ToaNha == L"H2" || ToaNha == L"H3") {
		return L"Nam";
	}
	if (ToaNha == L"H4") {
		return L"Nữ";
	}
	if (ToaNha == L"BA1" || ToaNha == L"BA2" || ToaNha == L"BA3" || ToaNha == L"BA5") {
		return L"Nữ";
	}
	if (ToaNha == L"BA4") {
		return L"Nam";
	}
	if (ToaNha == L"BB1" || ToaNha == L"BB2" || ToaNha == L"BB3") {
		return L"Nữ";
	}
	if (ToaNha == L"BB4" || ToaNha == L"BB5") {
		return L"Nam";
	}
	if (ToaNha == L"BC1" || ToaNha == L"BC2" || ToaNha == L"BC3" || ToaNha == L"BC6") {
		return L"Nam";
	}
	if (ToaNha == L"BC4" || ToaNha == L"BC5") {
		return L"Nữ";
	}
	if (ToaNha == L"BD2" || ToaNha == L"BD5" || ToaNha == L"BD6") {
		return L"Nam";
	}
	if (ToaNha == L"BD3" || ToaNha == L"BD4") {
		return L"Nữ";
	}
	if (ToaNha == L"BE1" || ToaNha == L"BE3") {
		return L"Nữ";
	}
	if (ToaNha == L"BE2") {
		return L"Nam";
	}
	if (ToaNha == L"BE4") {
		return L"Hỗn hợp";  
	}
	return L"";
}
wstring KTXManager::ChonToa(wstring Khu, wstring GioiTinh) {
	int choice;
	vector<wstring> DanhSachToa;
	if (Khu == L"A") {
		vector<wstring> DanhSachA = {
			L"A1", L"A2", L"A3", L"A4", L"A5",
			L"A6", L"A7", L"A8", L"A9", L"A10",
			L"A11", L"A12", L"A14", L"A15", L"A17",
			L"A18", L"A19", L"A20",
			L"H1", L"H2", L"H3", L"H4"
		};
		for (int i = 0; i < DanhSachA.size(); i++) {
			wstring gt = LayGioiTinh(DanhSachA[i]);
			if (GioiTinh == L"" || gt == GioiTinh || gt == L"Hỗn hợp") {
				DanhSachToa.push_back(DanhSachA[i]);
			}
		}
	}
	else if (Khu == L"B") {
		vector<wstring> DanhSachB = {
			L"BA1", L"BA2", L"BA3", L"BA4", L"BA5",
			L"BB1", L"BB2", L"BB3", L"BB4", L"BB5",
			L"BC1", L"BC2", L"BC3", L"BC4", L"BC5", L"BC6",
			L"BD2", L"BD3", L"BD4", L"BD5", L"BD6",
			L"BE1", L"BE2", L"BE3", L"BE4"
		};
		for (int i = 0; i < DanhSachB.size(); i++) {
			wstring gt = LayGioiTinh(DanhSachB[i]);
			if (GioiTinh == L"" || gt == GioiTinh || gt == L"Hỗn hợp") {
				DanhSachToa.push_back(DanhSachB[i]);
			}
		}
	}
	if (DanhSachToa.empty()) {
		return L"";
	}
	for (int i = 0; i < DanhSachToa.size(); i++) {
		wcout << i + 1 << L"." << DanhSachToa[i] << L"  ";
		if ((i + 1) % 5 == 0)
			wcout << endl;
	}
	wcout << endl;
	wcout << L"Chọn tòa: ";
	wcin >> choice;
	if (choice >= 1 && choice <= DanhSachToa.size()) {
		return DanhSachToa[choice - 1];
	}
	return L"";
}
int KTXManager::ChonTang(wstring ToaNha) {
	int TangToiDa = 0;
	if (ToaNha.substr(0, 1) == L"A")TangToiDa = 5;
	else if (ToaNha.substr(0, 1) == L"H")TangToiDa = 11;
	else if (ToaNha.substr(0, 2) == L"BA" || ToaNha.substr(0, 2) == L"BB" || ToaNha.substr(0, 2) == L"BC" || ToaNha.substr(0, 2) == L"BD" || ToaNha.substr(0, 2) == L"BE") {
		if (ToaNha == L"BA1" || ToaNha == L"BA2" || ToaNha == L"BB1" || ToaNha == L"BB2" || ToaNha == L"BC1" || ToaNha == L"BC2" || ToaNha == L"BC3" || ToaNha == L"BC4" || ToaNha == L"BC5" || ToaNha == L"BC6" || ToaNha == L"BD2" || ToaNha == L"BD3" || ToaNha == L"BD4" || ToaNha == L"BD5" || ToaNha == L"BD6")TangToiDa = 11;
		else if (ToaNha == L"BA3" || ToaNha == L"BA4" || ToaNha == L"BA5" || ToaNha == L"BB3" || ToaNha == L"BB4" || ToaNha == L"BB5")TangToiDa = 9;
		else if (ToaNha == L"BE1" || ToaNha == L"BE2" || ToaNha == L"BE3" || ToaNha == L"BE4")TangToiDa = 16;
	}
	int TangBatDau = (ToaNha.substr(0, 1) == L"A") ? 1 : 2;
	wcout << L"Tòa " << ToaNha << L" có " << TangToiDa << L" tầng, bắt đầu từ tầng " << TangBatDau << endl;
	int choice;
	wcout << L"Lựa chọn tầng: ";
	wcin >> choice;
	return choice;
}
int KTXManager::RandomLoaiPhongKhuA() {
	int r = rand() % 100;
	if (r < 40) return 1;      
	if (r < 65) return 2;      
	if (r < 75) return 3;      
	if (r < 85) return 4;      
	if (r < 90) return 5;      
	if (r < 93) return 6;      
	if (r < 95) return 7;     
	if (r < 98) return 8;      
	if (r < 99) return 9;      
	if (r < 100) return 10;   
	return 11;               
}
int KTXManager::RandomLoaiPhongKhuB() {
	int r = rand() % 100;
	if (r < 20) return 1;      
	if (r < 40) return 2;    
	if (r < 60) return 4;    
	if (r < 75) return 8;     
	if (r < 80) return 3;      
	if (r < 85) return 5;     
	if (r < 89) return 6;      
	if (r < 93) return 7;      
	if (r < 96) return 9;   
	if (r < 98) return 10;     
	return 11;                 
}
void KTXManager::KhoiTao() {
	srand((unsigned)time(0));
	wcout << L"ĐÃ KHỞI TẠO DỮ LIỆU PHÒNG" << endl;
	wcout << endl;
	wstring AG[] = { L"A1", L"A2", L"A3", L"A4", L"A5", L"A6", L"A7", L"A8", L"A9", L"A10", L"A11", L"A12", L"A14", L"A15", L"A17", L"A18", L"A19", L"A20" };
	for (int i = 0; i < 18; i++) {
		for (int j = 1; j <= 5; j++) {
			for (int k = 1; k <= 10; k++) {
				int LoaiPhong = RandomLoaiPhongKhuA();
				wstring MaPhong = AG[i] + to_wstring(j) + (k < 10 ? L"0" : L"") + to_wstring(k);
				DanhSachPhong.push_back(TaoPhongTheoLoai(LoaiPhong, MaPhong, AG[i], j, L"A"));
			}
		}
	}
	wstring AH[] = { L"H1", L"H2", L"H3", L"H4" };
	for (int i = 0; i < 4; i++) {
		for (int j = 2; j <= 11; j++) {
			for (int k = 1; k <= 24; k++) {
				int LoaiPhong = RandomLoaiPhongKhuA();
				wstring MaPhong = AH[i] + to_wstring(j) + (k < 10 ? L"0" : L"") + to_wstring(k);
				DanhSachPhong.push_back(TaoPhongTheoLoai(LoaiPhong, MaPhong, AH[i], j, L"A"));
			}
		}
	}
	wstring BA[] = { L"BA1", L"BA2", L"BA3", L"BA4", L"BA5" };
	int TangBA[] = { 11, 11, 9, 9, 9 };
	for (int i = 0; i < 5; i++) {
		for (int j = 2; j <= TangBA[i]; j++) {
			for (int k = 1; k <= 24; k++) {
				int LoaiPhong = RandomLoaiPhongKhuB();
				wstring MaPhong = BA[i] + to_wstring(j) + (k < 10 ? L"0" : L"") + to_wstring(k);
				DanhSachPhong.push_back(TaoPhongTheoLoai(LoaiPhong, MaPhong, BA[i], j, L"B"));
			}
		}
	}
	wstring BB[] = { L"BB1", L"BB2", L"BB3", L"BB4", L"BB5" };
	int TangBB[] = { 11, 11, 9, 9, 9 };
	for (int i = 0; i < 5; i++) {
		for (int j = 2; j <= TangBB[i]; j++) {
			for (int k = 1; k <= 24; k++) {
				int LoaiPhong = RandomLoaiPhongKhuB();
				wstring MaPhong = BB[i] + to_wstring(j) + (k < 10 ? L"0" : L"") + to_wstring(k);
				DanhSachPhong.push_back(TaoPhongTheoLoai(LoaiPhong, MaPhong, BB[i], j, L"B"));
			}
		}
	}
	wstring BC[] = { L"BC1", L"BC2", L"BC3", L"BC4", L"BC5", L"BC6" };
	int TangBC[] = { 11, 11, 11, 11, 11, 11 };
	for (int i = 0; i < 6; i++) {
		for (int j = 2; j <= TangBC[i]; j++) {
			for (int k = 1; k <= 24; k++) {
				int LoaiPhong = RandomLoaiPhongKhuB();
				wstring MaPhong = BC[i] + to_wstring(j) + (k < 10 ? L"0" : L"") + to_wstring(k);
				DanhSachPhong.push_back(TaoPhongTheoLoai(LoaiPhong, MaPhong, BC[i], j, L"B"));
			}
		}
	}
	wstring BD[] = { L"BD2", L"BD3", L"BD4", L"BD5", L"BD6" };
	int TangBD[] = { 11, 11, 11, 11, 11 };
	for (int i = 0; i < 5; i++) {
		for (int j = 2; j <= TangBD[i]; j++) {
			for (int k = 1; k <= 24; k++) {
				int LoaiPhong = RandomLoaiPhongKhuB();
				wstring MaPhong = BD[i] + to_wstring(j) + (k < 10 ? L"0" : L"") + to_wstring(k);
				DanhSachPhong.push_back(TaoPhongTheoLoai(LoaiPhong, MaPhong, BD[i], j, L"B"));
			}
		}
	}
	wstring BE[] = { L"BE1", L"BE2", L"BE3", L"BE4" };
	int TangBE[] = { 16, 16, 16, 16 };
	for (int i = 0; i < 4; i++) {
		for (int j = 2; j <= TangBE[i]; j++) {
			for (int k = 1; k <= 24; k++) {
				int LoaiPhong = RandomLoaiPhongKhuB();
				wstring MaPhong = BE[i] + to_wstring(j) + (k < 10 ? L"0" : L"") + to_wstring(k);
				DanhSachPhong.push_back(TaoPhongTheoLoai(LoaiPhong, MaPhong, BE[i], j, L"B"));
			}
		}
	}
}
void KTXManager::Xoa() {
	for (int i = 0; i < DanhSachPhong.size(); i++) {
		delete DanhSachPhong[i];
	}
	DanhSachPhong.clear();
	for (int i = 0; i < DanhSachSinhVien.size(); i++) {
		delete DanhSachSinhVien[i];
	}
	DanhSachSinhVien.clear();
	for (int i = 0; i < DanhSachHopDong.size(); i++) {
		delete DanhSachHopDong[i];
	}
	DanhSachHopDong.clear();
}
void KTXManager::DangKyPhong() {
	wcout << L"ĐĂNG KÝ PHÒNG" << endl;
	bool PhongTrong = false;
	for (int i = 0; i < DanhSachPhong.size(); i++) {
		if (DanhSachPhong[i]->ConTrong()) {
			PhongTrong = true;
			break;
		}
	}
	if (!PhongTrong) {
		wcout << L"Huhu KTX đã hết chỗ, quay lại hoặc kiếm chỗ khác nheee!" << endl;
		return;
	}
	Student* st = new Student();
	st->NhapThongTin();
	if (KiemTra(st->getMSSV())) {
		wcout << L"Tham thế bạn eyyy" << endl;
		delete st;
		return;
	}

	int ChoiceKhu;
	wcout << L"Chọn khu (1.A 2.B): ";
	wcin >> ChoiceKhu;
	if (ChoiceKhu != 1 && ChoiceKhu != 2) {
		wcout << L"Lựa chọn khu không hợp lệ!" << endl;
		delete st;
		return;
	}
	wstring Khu = (ChoiceKhu == 1) ? L"A" : L"B";

	wstring ToaNha = ChonToa(Khu, st->getGioiTinh());
	if (ToaNha.empty()) {
		wcout << L"Lựa chọn tòa không hợp lệ" << endl;
		delete st;
		return;
	}
	wstring gioiTinhToa = LayGioiTinh(ToaNha);
	if (gioiTinhToa == L"Nam" && st->getGioiTinh() != L"Nam") {
		wcout << L"Tòa " << ToaNha << L" chỉ dành cho sinh viên nam" << endl;
		delete st;
		return;
	}
	if (gioiTinhToa == L"Nữ" && st->getGioiTinh() != L"Nữ") {
		wcout << L"Tòa " << ToaNha << L" chỉ dành cho sinh viên nữ" << endl;
		delete st;
		return;
	}

	wstring LoaiPhong = ChonLoaiPhong();
	if (LoaiPhong.empty()) {
		wcout << L"Lựa chọn loại phòng không hợp lệ" << endl;
		delete st;
		return;
	}

	wcout << L"Danh sách tất cả phòng trống - Tòa " << ToaNha << L" - Khu " << Khu << endl;
	vector<int> DanhSachPhongTrong;
	for (int i = 0; i < DanhSachPhong.size(); i++) {
		if (DanhSachPhong[i]->getToaNha() == ToaNha && DanhSachPhong[i]->getLoaiPhong() == LoaiPhong && DanhSachPhong[i]->ConTrong()) {
			int Tang = DanhSachPhong[i]->getTang();
			if (ToaNha == L"BE4") {
				if (Tang >= 2 && Tang <= 12 && st->getGioiTinh() != L"Nam") continue;
				if (Tang >= 13 && Tang <= 16 && st->getGioiTinh() != L"Nữ") continue;
			}
			DanhSachPhongTrong.push_back(i);
			wcout << DanhSachPhongTrong.size() << L". Mã phòng: " << DanhSachPhong[i]->getMaPhong() << L" (Tầng " << Tang << L" - Số người hiện tại: " << DanhSachPhong[i]->getSoNguoiHienTai() << L", Số chỗ trống: " << DanhSachPhong[i]->getSoChoToiDa() - DanhSachPhong[i]->getSoNguoiHienTai() << L")" << endl;
		}
	}
	if (DanhSachPhongTrong.empty()) {
		wcout << L"Không có phòng trống thuộc loại này trong tòa " << ToaNha << endl;
		delete st;
		return;
	}

	int ChoicePhong;
	wcout << L"Chọn phòng: ";
	wcin >> ChoicePhong;
	if (ChoicePhong < 1 || ChoicePhong > DanhSachPhongTrong.size()) {
		wcout << L"Lựa chọn phòng không hợp lệ!" << endl;
		delete st;
		return;
	}
	int PhongDaChon = DanhSachPhongTrong[ChoicePhong - 1];
	Contract* ct = new Contract();
	ct->NhapThongTin();
	ct->setSinhVien(st);
	ct->setPhong(DanhSachPhong[PhongDaChon]);
	ct->setTongTien(ct->tinhTongTien());
	DanhSachPhong[PhongDaChon]->ThemNguoi();
	st->setPhongDangO(DanhSachPhong[PhongDaChon]);
	DanhSachSinhVien.push_back(st);
	DanhSachHopDong.push_back(ct);
	wcout << L"Đăng ký phòng thành công" << endl;
	wcout << L"Mã hợp đồng: " << ct->getMaHopDong() << endl;
}
void KTXManager::DoiPhong() {
	wcout << L"ĐỔI PHÒNG" << endl;
	wcout << L"Nhập mã số sinh viên để đổi phòng: ";
	wstring mssv; wcin >> mssv;
	Student* st = TimSinhVien(mssv);
	if (st == nullptr) {
		wcout << L"Không có mssv của bạn để đổi phòng: " << mssv << endl;
		return;
	}
	Room* PhongHienTai = st->getPhongDangO();
	if (PhongHienTai == nullptr) {
		wcout << L"Bạn chưa có phòng để đổi" << endl;
		return;
	}
	Contract* ct = TimHopDong(mssv);
	if (ct == nullptr) {
		wcout << L"Không tìm thấy hợp đồng của bạn để đổi phòng" << endl;
		return;
	}
	wcout << L"Thông tin phòng hiện tại: " << endl;
	wcout << L"Phòng số : " << PhongHienTai->getMaPhong() << L" - " << PhongHienTai->getLoaiPhong() << L" - " << PhongHienTai->getToaNha() << L" - Tầng " << PhongHienTai->getTang() << endl;

	int ChoiceKhu;
	wcout << L"Chọn khu (1.A 2.B): ";
	wcin >> ChoiceKhu;
	if (ChoiceKhu != 1 && ChoiceKhu != 2) {
		wcout << L"Lựa chọn khu không hợp lệ" << endl;
		return;
	}
	wstring Khu = (ChoiceKhu == 1) ? L"A" : L"B";

	wstring ToaNha = ChonToa(Khu, st->getGioiTinh());
	if (ToaNha.empty()) {
		wcout << L"Lựa chọn tòa không hợp lệ" << endl;
		return;
	}
	wstring gioiTinhToa = LayGioiTinh(ToaNha);
	if (gioiTinhToa == L"Nam" && st->getGioiTinh() != L"Nam") {
		wcout << L"Tòa " << ToaNha << L" chỉ dành cho sinh viên nam" << endl;
		return;
	}
	if (gioiTinhToa == L"Nữ" && st->getGioiTinh() != L"Nữ") {
		wcout << L"Tòa " << ToaNha << L" chỉ dành cho sinh viên nữ" << endl;
		return;
	}

	wstring LoaiPhong = ChonLoaiPhong();
	if (LoaiPhong.empty()) {
		wcout << L"Lựa chọn loại phòng không hợp lệ!" << endl;
		return;
	}

	wcout << L"Danh sách tất cả phòng trống - Tòa " << ToaNha << L" - Khu " << Khu << endl;
	vector<int> DanhSachPhongTrong;
	for (int i = 0; i < DanhSachPhong.size(); i++) {
		if (DanhSachPhong[i]->getToaNha() == ToaNha && DanhSachPhong[i]->getLoaiPhong() == LoaiPhong && DanhSachPhong[i]->ConTrong() && DanhSachPhong[i] != PhongHienTai) {
			int Tang = DanhSachPhong[i]->getTang();
			if (ToaNha == L"BE4") {
				if (Tang >= 2 && Tang <= 12 && st->getGioiTinh() != L"Nam") continue;
				if (Tang >= 13 && Tang <= 16 && st->getGioiTinh() != L"Nữ") continue;
			}
			DanhSachPhongTrong.push_back(i);
			wcout << DanhSachPhongTrong.size() << L". Mã phòng: " << DanhSachPhong[i]->getMaPhong() << L" (Tầng " << Tang << L" - Số người hiện tại: " << DanhSachPhong[i]->getSoNguoiHienTai() << L", Số chỗ trống: " << DanhSachPhong[i]->getSoChoToiDa() - DanhSachPhong[i]->getSoNguoiHienTai() << L")" << endl;
		}
	}
	if (DanhSachPhongTrong.empty()) {
		wcout << L"Không có phòng trống thuộc loại này trong tòa " << ToaNha << endl;
		return;
	}

	int ChoicePhong;
	wcout << L"Chọn phòng: ";
	wcin >> ChoicePhong;
	if (ChoicePhong < 1 || ChoicePhong > DanhSachPhongTrong.size()) {
		wcout << L"Lựa chọn phòng không hợp lệ!" << endl;
		return;
	}
	int PhongDaChon = DanhSachPhongTrong[ChoicePhong - 1];
	Room* PhongMoi = DanhSachPhong[PhongDaChon];
	int XacNhan;
	wcout << L"Bạn có chắc chắn muốn đổi từ phòng " << PhongHienTai->getMaPhong() << L" sang phòng " << PhongMoi->getMaPhong() << L"? (1. Có / 0. Không): ";
	wcin >> XacNhan;
	if (XacNhan == 0) {
		wcout << L"Đổi phòng đã bị hủy" << endl;
		return;
	}
	PhongHienTai->GiamNguoi();
	PhongMoi->ThemNguoi();
	st->setPhongDangO(PhongMoi);
	for (int i = 0; i < DanhSachHopDong.size(); i++) {
		if (DanhSachHopDong[i] == ct) {
			delete DanhSachHopDong[i];
			DanhSachHopDong.erase(DanhSachHopDong.begin() + i);
			break;
		}
	}
	Contract* HopDongMoi = new Contract();
	Contract::SoThuTu++;
	wstring MaHopDong = L"BD";
	if (Contract::SoThuTu < 10) MaHopDong += L"00" + to_wstring(Contract::SoThuTu);
	else if (Contract::SoThuTu > 9 && Contract::SoThuTu < 100) MaHopDong += L"0" + to_wstring(Contract::SoThuTu);
	else MaHopDong += to_wstring(Contract::SoThuTu);
	HopDongMoi->setMaHopDong(MaHopDong);
	HopDongMoi->setSinhVien(st);
	HopDongMoi->setPhong(PhongMoi);
	HopDongMoi->setNgayBatDau(ct->getNgayBatDau());
	HopDongMoi->setSoThang(ct->getSoThang());
	HopDongMoi->setTongTien(HopDongMoi->tinhTongTien());
	DanhSachHopDong.push_back(HopDongMoi);
	wcout << L"Đổi phòng thành công!" << endl;
	wcout << L"Phòng cũ: " << PhongHienTai->getMaPhong() << L" - " << PhongHienTai->getLoaiPhong() << L" - " << PhongHienTai->getToaNha() << L" - Tầng " << PhongHienTai->getTang() << endl;
	wcout << L"Phòng mới: " << PhongMoi->getMaPhong() << L" - " << PhongMoi->getLoaiPhong() << L" - " << PhongMoi->getToaNha() << L" - Tầng " << PhongMoi->getTang() << endl;
}
void KTXManager::XemPhongTrong() {
	wcout << L"DANH SÁCH PHÒNG TRỐNG " << endl;
	int ChoiceKhu;
	wcout << L"Chọn khu (1.A 2.B): ";
	wcin >> ChoiceKhu;
	if (ChoiceKhu != 1 && ChoiceKhu != 2) {
		wcout << L"Lựa chọn khu không hợp lệ" << endl;
		return;
	}
	wstring Khu = (ChoiceKhu == 1) ? L"A" : L"B";
	wstring ToaNha = ChonToa(Khu, L"");
	if (ToaNha.empty()) {
		wcout << L"Lựa chọn tòa không hợp lệ" << endl;
		return;
	}
	wstring LoaiPhong = ChonLoaiPhong();
	if (LoaiPhong.empty()) {
		wcout << L"Lựa chọn loại phòng không hợp lệ" << endl;
		return;
	}
	wcout << L"Danh sách phòng trống - Tòa " << ToaNha << L" - Khu " << Khu << endl;
	vector<int> DanhSachPhongTrong;
	for (int i = 0; i < DanhSachPhong.size(); i++) {
		if (DanhSachPhong[i]->getToaNha() == ToaNha && DanhSachPhong[i]->getLoaiPhong() == LoaiPhong && DanhSachPhong[i]->ConTrong()) {
			DanhSachPhongTrong.push_back(i);
			wcout << DanhSachPhongTrong.size() << L". Mã phòng: " << DanhSachPhong[i]->getMaPhong() << L" (Tầng " << DanhSachPhong[i]->getTang() << L" - Số người hiện tại: " << DanhSachPhong[i]->getSoNguoiHienTai() << L", Số chỗ trống: " << DanhSachPhong[i]->getSoChoToiDa() - DanhSachPhong[i]->getSoNguoiHienTai() << L")" << endl;
		}
	}
	if (DanhSachPhongTrong.empty()) {
		wcout << L"Không có phòng trống thuộc loại này tại tòa đã chọn" << endl;
		return;
	}
}
void KTXManager::XemDanhSachSinhVien() {
	wcout << L"DANH SÁCH SINH VIÊN" << endl;
	if (DanhSachSinhVien.empty()) {
		wcout << L"Chưa có sinh viên nào đăng ký phòng" << endl;
		return;
	}
	for (int i = 0; i < DanhSachSinhVien.size(); i++) {
		wcout << L"Sinh viên thứ " << i + 1 << L": " << endl;
		DanhSachSinhVien[i]->XuatThongTin();
		wcout << endl;
	}
}
void KTXManager::TimSinhVien() {
	wstring MSSV;
	wcout << L"Nhập mã số sinh viên cần tìm: ";
	wcin >> MSSV;
	Student* st = TimSinhVien(MSSV);
	if (st == nullptr) {
		wcout << L"Không tìm thấy sinh viên có mã số: " << MSSV << endl;
		return;
	}
	wcout << L"Đã tìm thấy sinh viên:" << endl;
	st->XuatThongTin();
}
void KTXManager::XemDanhSachHopDong() {
	wcout << L"DANH SÁCH HỢP ĐỒNG" << endl;
	if (DanhSachHopDong.empty()) {
		wcout << L"Chưa có hợp đồng nào được tạo" << endl;
		return;
	}
	for (int i = 0; i < DanhSachHopDong.size(); i++) {
		wcout << L"Hợp đồng thứ " << i + 1 << L": " << endl;
		DanhSachHopDong[i]->XuatThongTin();
		wcout << endl;
	}
}
void KTXManager::ThongKePhongTheoLoai() {
	wcout << L"THỐNG KÊ PHÒNG THEO LOẠI" << endl;
	if (DanhSachPhong.empty()) {
		wcout << L"Chưa có phòng nào được tạo" << endl;
		return;
	}
	vector<wstring> LoaiPhongList = { L"Phòng 8 sinh viên", L"Phòng 6 sinh viên", L"Phòng dịch vụ 6 sinh viên có máy lạnh, rèm", L"Phòng dịch vụ 4 sinh viên", L"Phòng dịch vụ 4 sinh viên có máy lạnh, rèm", L"Phòng dịch vụ 4 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt", L"Phòng dịch vụ 4 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt, máy nước nóng, kệ dép", L"Phòng dịch vụ 2 sinh viên", L"Phòng dịch vụ 2 sinh viên có máy lạnh, rèm", L"Phòng dịch vụ 2 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt", L"Phòng dịch vụ 2 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt, máy nước nóng, kệ dép" };
	int Phong[11] = { 0 };
	int Thue[11] = { 0 };
	int Trong[11] = { 0 };
	for (int i = 0; i < DanhSachPhong.size(); i++) {
		wstring loai = DanhSachPhong[i]->getLoaiPhong();
		for (int j = 0; j < LoaiPhongList.size(); j++) {
			if (loai == LoaiPhongList[j]) {
				Phong[j]++;
				if (DanhSachPhong[i]->getSoNguoiHienTai()) Thue[j]++;
				else Trong[j]++;
				break;
			}
		}
	}
	wcout << left << setw(35) << L"Loại phòng" << right << setw(8) << L"Tổng" << setw(10) << L"Đã thuê" << setw(10) << L"Trống"<< setw(10) << L"Tỷ lệ" << endl;
	for (int i = 0; i < 11; i++) {
		double tyLe = (Phong[i] > 0) ? (double)Thue[i] / Phong[i] * 100 : 0;
		wcout << left << setw(35) << LoaiPhongList[i] << right << setw(8) << Phong[i] << setw(10) << Thue[i] << setw(10) << Trong[i] << setw(9) << fixed << setprecision(1) << tyLe << L"%" << endl;
	}
}
void KTXManager::ThongKeDoanhThu() {
	wcout << L"THỐNG KÊ DOANH THU" << endl;
	if (DanhSachHopDong.empty()) {
		wcout << L"Chưa có hợp đồng nào được tạo" << endl;
		return;
	}
	double TongDoanhThu = 0;
	double DoanhThuKhuA = 0;
	double DoanhThuKhuB = 0;
	double ListDoanhThu[11] = { 0 };
	vector<wstring> LoaiPhongList = { L"Phòng 8 sinh viên", L"Phòng 6 sinh viên", L"Phòng dịch vụ 6 sinh viên có máy lạnh, rèm", L"Phòng dịch vụ 4 sinh viên", L"Phòng dịch vụ 4 sinh viên có máy lạnh, rèm", L"Phòng dịch vụ 4 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt", L"Phòng dịch vụ 4 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt, máy nước nóng, kệ dép", L"Phòng dịch vụ 2 sinh viên", L"Phòng dịch vụ 2 sinh viên có máy lạnh, rèm", L"Phòng dịch vụ 2 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt", L"Phòng dịch vụ 2 sinh viên có máy lạnh, rèm, tủ lạnh, máy giặt, máy nước nóng, kệ dép" };
	for (int i = 0; i < DanhSachHopDong.size(); i++) {
		if (DanhSachHopDong[i]->getDaThanhToan()) {
			double Mon = DanhSachHopDong[i]->getTongTien();
			TongDoanhThu += Mon;
			Room* PhongHienTai = DanhSachHopDong[i]->getPhong();
			if (PhongHienTai != nullptr) {
				if (PhongHienTai->getKhu() == L"A")DoanhThuKhuA += Mon;
				else if (PhongHienTai->getKhu() == L"B")DoanhThuKhuB += Mon;
				wstring Loai = PhongHienTai->getLoaiPhong();
				for (int j = 0; j < 11; j++) {
					if (Loai == LoaiPhongList[j]) {
						ListDoanhThu[j] += Mon;
						break;
					}
				}
			}
		}
	}
	wcout << L"Tổng doanh thu: " << fixed << setprecision(0) << TongDoanhThu << L" Đồng" << endl;
	wcout << L"Theo khu" << endl;
	wcout << L"Khu A: " << DoanhThuKhuA << L" VND\n";
	wcout << L"Khu B: " << DoanhThuKhuB << L" VND\n\n";
	wcout << L"Theo loại phòng" << endl;
	for (int i = 0; i < 11; i++) {
		if (ListDoanhThu[i] > 0) {
			wcout << L"  - " << LoaiPhongList[i] << L": " << ListDoanhThu[i] << L" Đồng" << endl;
		}
	}
}
void KTXManager::ThongKeSinhVienTheoTruong() {
	wcout << L"THỐNG KÊ SINH VIÊN THEO TRƯỜNG" << endl;
	if (DanhSachSinhVien.empty()) {
		wcout << L"Chưa có sinh viên nào được tạo" << endl;
		return;
	}
	vector<wstring> DanhSachTruong;
	vector<int> SoLuongTruong;
	for (int i = 0; i < DanhSachSinhVien.size(); i++) {
		wstring Truong = DanhSachSinhVien[i]->getTruong();
		bool Find = false;
		for (int j = 0; j < DanhSachTruong.size(); j++) {
			if (DanhSachTruong[j] == Truong) {
				SoLuongTruong[j]++;
				Find = true;
				break;
			}
		}
		if (!Find) {
			DanhSachTruong.push_back(Truong);
			SoLuongTruong.push_back(1);
		}
	}
	wcout << left << setw(20) << L"Trường" << right << setw(12) << L"Số lương" << setw(10) << L"Tỷ lệ" << endl;
	for (int i = 0; i < DanhSachTruong.size(); i++) {
		double TyLe = (DanhSachSinhVien.size() > 0) ? (double)SoLuongTruong[i] / DanhSachSinhVien.size() * 100 : 0;
		wcout << left << setw(20) << DanhSachTruong[i]	<< right << setw(12) << SoLuongTruong[i] << setw(9) << fixed << setprecision(1) << TyLe << L"%" << endl;
	}
}
