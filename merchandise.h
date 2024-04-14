#pragma once
typedef enum{CAN_PURCHASE,CANNOT_PURCHASE}purchace_status;
class Merchandise {
public:
	int JueseInfo[10][2] = {
		{100,2},
		{120,3},
		{110,2},
		{90,1},
		{140,1},
		{150,4},
		{150,7},
		{160,2},
		{170,3},
		{200,5}
	};
	int CanBuy[10];
	bool ConfirmSoldOut(int* key);
	Merchandise();
};