#ifndef ROOMCATEGORY_H
#define ROOMCATEGORY_H
#include "ROOM.h"
class Room8 : public Room{
public:
	Room8(wstring MaPhong, wstring ToaNha, int Tang, wstring Khu);
	double TinhTien(int SoThang) override;
	bool ConTrong() override;
	wstring getLoaiPhong() override;
};
class Room6 : public Room{
public:
	Room6(wstring MaPhong, wstring ToaNha, int Tang, wstring Khu);
	double TinhTien(int SoThang) override;
	bool ConTrong() override;
	wstring getLoaiPhong() override;
};
class Room6AC : public Room {
public:
	Room6AC(wstring MaPhong, wstring ToaNha, int Tang, wstring Khu);
	double TinhTien(int SoThang) override;
	bool ConTrong() override;
	wstring getLoaiPhong() override;
}; 
class Room4 : public Room{
public:
	Room4(wstring MaPhong, wstring ToaNha, int Tang, wstring Khu);
	double TinhTien(int SoThang) override;
	bool ConTrong() override;
	wstring getLoaiPhong() override;
};
class Room4AC : public Room{
public:
	Room4AC(wstring MaPhong, wstring ToaNha, int Tang, wstring Khu);
	double TinhTien(int SoThang) override;
	bool ConTrong() override;
	wstring getLoaiPhong() override;
};
class Room4ACFull : public Room{
public:
	Room4ACFull(wstring MaPhong, wstring ToaNha, int Tang, wstring Khu);
	double TinhTien(int SoThang) override;
	bool ConTrong() override;
	wstring getLoaiPhong() override;
};
class Room4ACVIP : public Room{
public:
	Room4ACVIP(wstring MaPhong, wstring ToaNha, int Tang, wstring Khu);
	double TinhTien(int SoThang) override;
	bool ConTrong() override;
	wstring getLoaiPhong() override;
};
class Room2 : public Room {
public:
	Room2(wstring MaPhong, wstring ToaNha, int Tang, wstring Khu);
	double TinhTien(int SoThang) override;
	bool ConTrong() override;
	wstring getLoaiPhong() override;
};
class Room2AC : public Room {
public:
	Room2AC(wstring MaPhong, wstring ToaNha, int Tang, wstring Khu);
	double TinhTien(int SoThang) override;
	bool ConTrong() override;
	wstring getLoaiPhong() override;
};
class Room2ACFull : public Room {
public:
	Room2ACFull(wstring MaPhong, wstring ToaNha, int Tang, wstring Khu);
	double TinhTien(int SoThang) override;
	bool ConTrong() override;
	wstring getLoaiPhong() override;
};
class Room2ACVIP : public Room {
public:
	Room2ACVIP(wstring MaPhong, wstring ToaNha, int Tang, wstring Khu);
	double TinhTien(int SoThang) override;
	bool ConTrong() override;
	wstring getLoaiPhong() override;
};
#endif
