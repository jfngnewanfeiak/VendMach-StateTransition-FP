#include "jihanki.h"
#include <iostream>
using namespace std;

//�������ꂽ�Ƃ��ɁA�W���[�X���w���\���m�F����
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

//�W���[�X�ɑΉ�����{�^�����_�����Ă��邩�m�F
bool jihanki::ConfirmLight() {
	if (StateButton[key-1]==BUTTON_ON&&merchandise->JueseInfo[key-1][1]) {
		return true;
	}
	else {
		return false;
	}
}

//��������
void jihanki::InputMoney() {
	cout << "�������ĉ�����" << endl;
	cin >> inputMoney;
	Money = Money + inputMoney;
	inputMoney = 0;
	if (jihankistate[0] == STATE_WAIT) {
		//��ԑJ��
		jihankistate[0] = STATE_INPUT;
	}
	CanIPurchase();
	LightUp();
	ShowMoney();
	cout << "0:����������,1:�{�^��������,2:���o�[������" << endl;
	cin >> action;
	switch (action) {
	case PUTBUTTON:
		//��ԑJ��
		jihankistate[1] = FUNC_PUT;
		break;
	case PULLLEVER:
		//��ԑJ��
		jihankistate[1] = FUNC_PULL;
		break;
	}
}

//�w���\�ȃ{�^����_�����鏈��
void jihanki::LightUp() {
	cout << "LightUp()" << endl;
	for (int i = 0; i < JUICE_MAX; i++) {
		if (merchandise->CanBuy[i] == CAN_PURCHASE) {
			StateButton[i] = BUTTON_ON;
		}
	}
}

//���ނ�o�͏���
void jihanki::OutChange() {
	cout << "�����" << Money << "�~�ł�" << endl;
	Money = 0;
	//�����҂���ԂɑJ��
	jihankistate[0] = STATE_WAIT;
	jihankistate[1] = FUNC_INPUT_0;
}

//�W���[�X�o�͏���
void jihanki::OutJuice() {
	cout << "�W���[�X" << key << "���o�͂��܂���" << endl;
	Money = Money - merchandise->JueseInfo[key - 1][0];
	merchandise->JueseInfo[key - 1][1]--;
	if (merchandise->ConfirmSoldOut(&key) == true) {
		SoldOutLightUp();
	}
	//��ԑJ��
	jihankistate[1] = FUNC_OUTCHANGE;
}

//�ԋp����
void jihanki::PullLever() {
	cout << Money <<"�~��ԋp���܂���" << endl;
	Money = 0;
	jihankistate[0] = STATE_WAIT;
	jihankistate[1] = FUNC_INPUT_0;
}

//�w�����i�I������
void jihanki::PutButton() {
	cout << "�w�����������i�̃{�^���������Ă�������" << endl;
	do {
		cin >> key;
	} while (key < 1 || key>10);
	if (ConfirmLight() == true) {
		//��ԑJ��
		jihankistate[0] = STATE_OUTPUT;
		jihankistate[1] = FUNC_OUTJUICE;

	}
	else {
		cout <<"�W���[�X" <<key << "�͍w���ł��܂���" << endl;
		cout << "0:����������,1:�{�^��������,2:���o�[������" << endl;
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

//����؂ꂽ���i�̃{�^�����������鏈��
void jihanki::SoldOutLightUp() {
	StateButton[key - 1] = BUTTON_SOLDOUT;
}
//�R���X�g���N�^
jihanki::jihanki() {
	//�{�^����ԑS��off
	for (int i = 0; i < JUICE_MAX; i++) {
		StateButton[i] = BUTTON_OFF;
	}
	//���̋@�̏�ԏ�����
	jihankistate[0] = STATE_WAIT;
	jihankistate[1] = FUNC_INPUT_0;
	merchandise = new Merchandise;
}

//�����z�\������
void jihanki::ShowMoney() {
	cout << "�������ꂽ���z��" << Money << "�ł�" << endl;
}