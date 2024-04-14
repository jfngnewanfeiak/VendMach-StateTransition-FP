#include "jihanki.h"
#include <iostream>
using namespace std;

//入金されたときに、ジュースが購入可能か確認する
void jihanki::CanIPurchase() {
	cout << "CanIpurchace()" << endl;
	for (int i = 0; i < JUICE_MAX; i++) {
		cout << i << endl;
		if ((Money >= (merchandise->JueseInfo[i][0]))&&((merchandise->JueseInfo[i][1])!=0)) {
			merchandise->CanBuy[i] = CAN_PURCHASE;
		}
	}
	cout << "CanIpurchace()end" << endl;
}

//ジュースに対応するボタンが点灯しているか確認
bool jihanki::ConfirmLight() {
	if (StateButton[key-1]==BUTTON_ON&&merchandise->JueseInfo[key-1][1]) {
		return true;
	}
	else {
		return false;
	}
}

//入金処理
void jihanki::InputMoney() {
	cout << "入金して下さい" << endl;
	cin >> inputMoney;
	Money = Money + inputMoney;
	inputMoney = 0;
	if (jihankistate[0] == STATE_WAIT) {
		//状態遷移
		jihankistate[0] = STATE_INPUT;
	}
	CanIPurchase();
	LightUp();
	ShowMoney();
	cout << "0:お金を入れる,1:ボタンを押す,2:レバーを引く" << endl;
	cin >> action;
	switch (action) {
	case PUTBUTTON:
		//状態遷移
		jihankistate[1] = FUNC_PUT;
		break;
	case PULLLEVER:
		//状態遷移
		jihankistate[1] = FUNC_PULL;
		break;
	}
}

//購入可能なボタンを点灯する処理
void jihanki::LightUp() {
	cout << "LightUp()" << endl;
	for (int i = 0; i < JUICE_MAX; i++) {
		if (merchandise->CanBuy[i] == CAN_PURCHASE) {
			StateButton[i] = BUTTON_ON;
		}
	}
}

//お釣り出力処理
void jihanki::OutChange() {
	cout << "おつりは" << Money << "円です" << endl;
	Money = 0;
	//入金待ち状態に遷移
	jihankistate[0] = STATE_WAIT;
	jihankistate[1] = FUNC_INPUT_0;
}

//ジュース出力処理
void jihanki::OutJuice() {
	cout << "ジュース" << key << "を出力しました" << endl;
	Money = Money - merchandise->JueseInfo[key - 1][0];
	merchandise->JueseInfo[key - 1][1]--;
	if (merchandise->ConfirmSoldOut(&key) == true) {
		SoldOutLightUp();
	}
	//状態遷移
	jihankistate[1] = FUNC_OUTCHANGE;
}

//返却処理
void jihanki::PullLever() {
	cout << Money <<"円を返却しました" << endl;
	Money = 0;
	jihankistate[0] = STATE_WAIT;
	jihankistate[1] = FUNC_INPUT_0;
}

//購入商品選択処理
void jihanki::PutButton() {
	cout << "購入したい商品のボタンを押してください" << endl;
	do {
		cin >> key;
	} while (key < 1 || key>10);
	if (ConfirmLight() == true) {
		//状態遷移
		jihankistate[0] = STATE_OUTPUT;
		jihankistate[1] = FUNC_OUTJUICE;

	}
	else {
		cout <<"ジュース" <<key << "は購入できません" << endl;
		cout << "0:お金を入れる,1:ボタンを押す,2:レバーを引く" << endl;
		cin >> action;
		switch (action) {
		case INPUTMONEY:
			jihankistate[1] = FUNC_INPUT_1;
			break;
		case PUTBUTTON:
			jihankistate[1] = FUNC_PUT;
			break;
		case PULLLEVER:
			jihankistate[0] = STATE_WAIT;
			jihankistate[1] = FUNC_PULL;
			break;
		}
		
	}

}

//売り切れた商品のボタンを消灯する処理
void jihanki::SoldOutLightUp() {
	StateButton[key - 1] = BUTTON_SOLDOUT;
}
//コンストラクタ
jihanki::jihanki() {
	//ボタン状態全てoff
	for (int i = 0; i < JUICE_MAX; i++) {
		StateButton[i] = BUTTON_OFF;
	}
	//自販機の状態初期化
	jihankistate[0] = STATE_WAIT;
	jihankistate[1] = FUNC_INPUT_0;
	merchandise = new Merchandise;
}

//入金額表示処理
void jihanki::ShowMoney() {
	cout << "投入された金額は" << Money << "です" << endl;
}