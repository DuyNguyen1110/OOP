#ifndef OFFICESTAFF_H
#define OFFICESTAFF_H
#include "employee.h"
#include <iostream>
#include <string>
using std::wcout;
using std::wcin;
using std::getline;
using std::wstring;
using std::endl;
class OfficeStaff : public Employee {
private:
	double LuongCoBan;
	double HeSoLuong;
public:
	OfficeStaff();
	OfficeStaff(wstring MaNV, wstring HoTen, int NamSinh, int SoNgayLamViec, double LuongCoBan, double HeSoLuong);
	void NhapThongTin() override;
	void XuatThongTin() override;
	double TinhLuong() const override;
	double getLuongCoBan() const;
	double getHeSoLuong() const;
	void setLuongCoBan(double LuongCoBan);
	void setHeSoLuong(double HeSoLuong);
};
#endif
