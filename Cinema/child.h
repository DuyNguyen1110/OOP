#ifndef CHILD_H
#define CHILD_H
#include "ticket.h"
#include <iostream>
#include <string>
using std::wcout;
using std::wcin;
using std::getline;
using std::endl;
using std::wstring;
class Child : public Ticket{
private:
	int Tuoi;
public:
	Child();
	Child(wstring MaVe, wstring TenPhim, wstring NgayChieu, wstring GioChieu, double GiaGoc, int Tuoi);
	void NhapThongTin() override;
	void XuatThongTin() override;
	double TinhGiaVe() override;
	int getLoai() override;
	int getTuoi() const;
	void setTuoi(int Tuoi);
};
#endif
