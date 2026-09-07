#ifndef DEVELOPER_H
#define DEVELOPER_H
#include "employee.h"
#include <iostream>
#include <string>
using std::wcout;
using std::wcin;
using std::getline;
using std::endl;
using std::wstring;
class Developer : public Employee {
private:
	double SoGioTangCa;
	wstring NgonNguLapTrinh;
public:
	Developer();
	Developer(wstring MaNV, wstring HoTen, int NamSinh, int SoNgayLamViec, double SoGioTangCa, wstring NgonNguLapTrinh);
	void NhapThongTin() override;
	void XuatThongTin() override;
	double TinhLuong() const override;
	double getSoGioTangCa() const;
	wstring getNgonNguLapTrinh() const;
	void setSoGioTangCa(double SoGioTangCa);
	void setNgonNguLapTrinh(wstring NgonNguLapTrinh);
};
#endif
