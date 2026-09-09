#ifndef ADULT_H
#define ADULT_H
#include "ticket.h"
#include <iostream>
#include <string>
using std::wcout;
using std::wcin;
using std::wstring;
using std::endl;
using std::getline;
class Adult : public Ticket {
public:
	Adult();
	Adult(wstring MaVe, wstring TenPhim, wstring NgayChieu, wstring GioChieu, double GiaGoc);
	double TinhGiaVe() override;
	void XuatThongTin() override;
	int getLoai() override;
};
#endif
