#ifndef STUDENT_H
#define STUDENT_H
#include "ticket.h"
#include <iostream>
#include <string>
using std::wcout;
using std::wcin;
using std::getline;
using std::endl;
using std::wstring;
class Student : public Ticket {
private:
	wstring MaSinhVien;
	wstring TruongDaiHoc;
public:
	Student();
	Student(wstring MaVe, wstring TenPhim, wstring NgayChieu, wstring GioChieu, double GiaGoc, wstring MaSinhVien, wstring TruongDaiHoc);
	void NhapThongTin() override;
	void XuatThongTin() override;
	double TinhGiaVe() override;
	int getLoai() override;
	wstring getMaSinhVien() const;
	wstring getTruongDaiHoc() const;
	void setMaSinhVien(wstring MaSinhVien);
	void setTruongDaiHoc(wstring TruongDaiHoc);
};
#endif 
