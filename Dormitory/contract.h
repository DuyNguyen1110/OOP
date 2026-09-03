#ifndef CONTRACT_H
#define CONTRACT_H
#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include <algorithm>
using std::wcout;
using std::wcin;
using std::endl;
using std::wstring;
using std::vector;
using std::getline;
class Room;
class Student;
class Contract {
private:
	wstring MaHopDong;
	Student* SinhVien;
	Room* Phong;
	wstring NgayBatDau;
	int SoThang;
	double TongTien;
	bool DaThanhToan;
	static int DemHopDong;
public:
	static int SoThuTu;
	Contract();
	Contract(Student* SinhVien, Room* Phong, wstring NgayBatDau, int SoThang, bool DaThanhToan);
	~Contract();
	void NhapThongTin();
	void XuatThongTin();
	double tinhTongTien();
	void ThanhToan();
	static int getDemHopDong();
	static int getSoThuTu();
	wstring getMaHopDong() const;
	wstring getNgayBatDau() const;
	int getSoThang() const;
	double getTongTien() const;
	bool getDaThanhToan() const;
	Student* getSinhVien() const;
	Room* getPhong() const;
	void setMaHopDong(wstring MaHopDong);
	void setNgayBatDau(wstring NgayBatDau);
	void setSoThang(int SoThang);
	void setTongTien(double TongTien);
	void setDaThanhToan(bool DaThanhToan);
	void setPhong(Room* Phong);
	void setSinhVien(Student* SinhVien);
};
#endif
