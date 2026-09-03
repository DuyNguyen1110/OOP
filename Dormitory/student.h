#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <algorithm>
using std::wcout;
using std::wcin;
using std::endl;
using std::wstring;
using std::getline;
class Room; // Trong class Student có Room*, k cần viết ROOM.h lại
class Student {
private:
	wstring MSSV;
	wstring HoTen;
	wstring Truong;
	wstring Khoa;
	wstring GioiTinh;
	wstring NamHoc;
	wstring SoDienThoai;
	wstring Email;
	Room* PhongDangO; // trỏ đến room, dùng con trỏ để đỡ tốn bộ nhớ
	static int DemSinhVien;
public:
	Student();
	Student(wstring MSSV, wstring HoTen, wstring Truong, wstring Khoa, wstring GioiTinh, wstring NamHoc, wstring SoDienThoai, wstring Email);
	~Student();
	void NhapThongTin();
	void XuatThongTin();
	static int getDemSinhVien();
    wstring getMSSV() const;  // Không thay đổi thuộc tính của đối tượng
	wstring getHoTen() const;
	wstring getTruong() const;
	wstring getKhoa() const;
	wstring getGioiTinh() const;
	wstring getNamHoc() const;
	wstring getSoDienThoai() const;
	wstring getEmail() const;
	Room* getPhongDangO() const;
	void setMSSV(wstring MSSV);
	void setHoTen(wstring HoTen);
	void setTruong(wstring Truong);
	void setKhoa(wstring Khoa);
	void setGioiTinh(wstring GioiTinh);
	void setNamHoc(wstring NamHoc);
	void setSoDienThoai(wstring SoDienThoai);
	void setEmail(wstring Email);
	void setPhongDangO(Room* A);
};
#endif
