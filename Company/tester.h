#ifndef TESTER_H
#define TESTER_H
#include <iostream>
#include <string>
#include "employee.h"
using std::wcout;
using std::wcin;
using std::wstring;
using std::endl;
using std::getline;
class Tester : public Employee{
private:
	int SoLoiPhatHien;
	wstring LoaiKiemThu;
public:
	Tester();
	Tester(wstring MaNV, wstring HoTen, int NamSinh, int SoNgayLamViec, int SoLoiPhatHien, wstring LoaiKiemThu);
	void NhapThongTin() override;
	void XuatThongTin() override;
	double TinhLuong() const override;
	int getSoLoiPhatHien() const;
	wstring getLoaiKiemThu() const;
	void setSoLoiPhatHien(int SoLoiPhatHien);
	void setLoaiKiemThu(wstring LoaiKiemThu);
};
#endif
