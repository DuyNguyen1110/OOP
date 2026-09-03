#ifndef KTXMANAGER_H
#define KTXMANAGER_H
#include "room.h"
#include "student.h"
#include "contract.h"
#include <vector>
#define MAX_PHONG 9000 // Vì ktx có giới hạn số lượng phòngnhu
using std::vector;
class KTXManager {
private:
	vector<Room*> DanhSachPhong;
	vector<Student*> DanhSachSinhVien;
	vector<Contract*> DanhSachHopDong;
	// Các hàm bổ trợ 
	Room* TaoPhongTheoLoai(int Loai, wstring MaPhong, wstring ToaNha, int Tang, wstring Khu);
	bool KiemTra(wstring MSSV);
	Student* TimSinhVien(wstring MSSV); // Tìm theo mssv
	Contract* TimHopDong(wstring MSSV);
	void HienThiDanhSachToa(wstring Khu);
	wstring ChonLoaiPhong();
	wstring ChonToa(wstring Khu, wstring GioiTinh);
	wstring LayGioiTinh(wstring ToaNha);
	int ChonTang(wstring ToaNha);
	int RandomLoaiPhongKhuA(); // Có AI hỗ trợ
	int RandomLoaiPhongKhuB(); // Có AI hỗ trợ
public:
	KTXManager();
	~KTXManager();
	void KhoiTao();
	void Xoa();
	void DangKyPhong();
	void DoiPhong();
	void XemPhongTrong();
	void XemDanhSachSinhVien();
	void TimSinhVien();
	void XemDanhSachHopDong();
	void ThongKePhongTheoLoai();
	void ThongKeDoanhThu();
	void ThongKeSinhVienTheoTruong();
};
#endif
