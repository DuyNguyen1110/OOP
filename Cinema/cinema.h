#ifndef CINEMA_H
#define CINEMA_H
#include <iostream>
#include <string>
#include <vector>
#include "ticket.h"
using std::wcout;
using std::wcin;
using std::getline;
using std::endl;
using std::wstring;
using std::vector;
class Cinema{
private:
	vector<Ticket*> DanhSachVe;
public:
	Cinema();
	~Cinema();
	void ThemVe(Ticket* Ve);
	void XuatTatCa();
	double TongDoanhThu();
	void TimVeGiaCaoNhat();
	void ThongKeVeTheoLoai();
};
#endif
