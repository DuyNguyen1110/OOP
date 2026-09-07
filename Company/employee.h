#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using std::wcout;
using std::wcin;
using std::getline;
using std::endl;
using std::wstring;
class Employee{
private:
	wstring MaNV;
	wstring HoTen;
	int NamSinh;
	int SoNgayLamViec;
public:
	Employee();
	Employee(wstring MaNV, wstring HoTen, int NamSinh, int SoNgayLamViec);
	virtual ~Employee();
	virtual void NhapThongTin();
	virtual void XuatThongTin();
	virtual double TinhLuong() const = 0;
	wstring getMaNV() const;
	wstring getHoTen() const;
	int getNamSinh() const;
	int getSoNgayLamViec() const;
	void setMaNV(wstring MaNV);
	void setHoTen(wstring HoTen);
	void setNamSinh(int NamSinh);
	void setSoNgayLamViec(int SoNgayLamViec);
};
#endif
