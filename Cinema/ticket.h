#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <string>
using std::wcout;
using std::wcin;
using std::wstring;
using std::getline;
using std::endl;
class Ticket {
private:
	wstring MaVe;
	wstring TenPhim;
	wstring NgayChieu;
	wstring GioChieu;
	double GiaGoc;
	static int DemSoVe;
public:
	Ticket();
	Ticket(wstring MaVe, wstring TenPhim, wstring NgayChieu, wstring GioChieu, double GiaGoc);
	virtual ~Ticket();
	virtual void NhapThongTin();
	virtual void XuatThongTin();
	virtual double TinhGiaVe() = 0;
	virtual int getLoai() = 0;
	static int getDemSoVe();
	wstring getMaVe() const;
	wstring getTenPhim() const;
	wstring getNgayChieu() const;
	wstring getGioChieu() const ;
	double getGiaGoc() const;
	void setMaVe(wstring MaVe);
	void setTenPhim(wstring TenPhim);
	void setNgayChieu(wstring NgayChieu);
	void setGioChieu(wstring GioChieu);
	void setGiaGoc(double GiaGoc);
};
#endif
