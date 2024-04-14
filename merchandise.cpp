#include "merchandise.h"
Merchandise::Merchandise() {
	for (int i = 0; i < 10; i++) {
		CanBuy[i] = CAN_PURCHASE;
	}
}

bool Merchandise::ConfirmSoldOut(int* key) {
	if (JueseInfo[*key - 1][1] == 0) {
		return true;
	}
	else {
		return false;
	}
}