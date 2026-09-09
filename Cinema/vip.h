#ifndef VIP_H
#define VIP_H
#include <iostream>
#include <string>
#include "ticket.h"
using std::wcout;
using std::wcin;
using std::getline;
using std::endl;
using std::wstring;
class VIP : public Ticket{
private:
	wstring DichVuDiKem;
	double PhuPhi;
public:
	VIP();
	VIP(wstring MaVe, wstring TenPhim, wstring NgayChieu, wstring GioChieu, double GiaGoc, wstring DichVuDiKem, double PhuPhi);
	void NhapThongTin() override;
	void XuatThongTin() override;
	double TinhGiaVe() override;
	int getLoai() override;
	wstring getDichVuDiKem() const;
	double getPhuPhi() const;
	void setDichVuDiKem(wstring DichVuDiKem);
	void setPhuPhi(double PhuPhi);
};
#endif 
