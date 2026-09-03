#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
using std::wcout;
using std::wcin;
using std::getline;
using std::endl;
using std::wstring;
class Room{
private:
	wstring MaPhong;
	int SoChoToiDa;
	int SoNguoiHienTai;
	double DonGia;
	wstring LoaiPhong;
	wstring ToaNha;
	int Tang;
	wstring Khu;
public:
	Room();
	Room(wstring MaPhong, int SoChoToiDa, double DonGia, wstring LoaiPhong, wstring ToaNha, int Tang, wstring Khu);
	virtual ~Room();
	virtual double TinhTien(int SoThang) = 0;
	virtual bool ConTrong() = 0;
	virtual wstring getLoaiPhong() = 0;
	virtual void NhapThongTin();
	virtual void XuatThongTin();
	void ThemNguoi();
	void GiamNguoi();
	wstring getMaPhong() const;
	int getSoChoToiDa() const;
	int getSoNguoiHienTai() const;
	double getDonGia() const;
	wstring getToaNha() const;
	int getTang() const;
	wstring getKhu() const;
	void setMaPhong(wstring MaPhong);
	void setSoChoToiDa(int SoChoToiDa);
	void setSoNguoiHienTai(int SoNguoiHienTai);
	void setDonGia(double DonGia);
	void setLoaiPhong(wstring LoaiPhong);
	void setToaNha(wstring ToaNha);
	void setTang(int Tang);
	void setKhu(wstring Khu);
};
#endif 
