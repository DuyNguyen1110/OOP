#ifndef COMPANY_H
#define COMPANY_H
#include <iostream>
#include "employee.h"
#include <string>
#include <vector>
using std::wcout;
using std::wcin;
using std::getline;
using std::endl;
using std::vector;
class Company{
private:
	vector<Employee*> DanhSachNhanVien;
public:
	Company();
	~Company();
	void ThemNhanVien(Employee* NhanVien);
	void XuatTatCa();
	double TongLuong();
	void NhanVienLuongCaoNhat();
	void SapXepTheoLuong();
};
#endif
