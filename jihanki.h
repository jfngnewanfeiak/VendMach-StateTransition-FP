#pragma once
#include <iostream>
#include "merchandise.h"
#define JUICE_MAX 10

typedef enum{BUTTON_OFF,BUTTON_ON,BUTTON_SOLDOUT}state_Button;
typedef enum { STATE_WAIT, STATE_INPUT, STATE_OUTPUT }state;
typedef enum { FUNC_INPUT_0 }state_wait;
typedef enum { FUNC_INPUT_1, FUNC_SHOW, FUNC_PUT, FUNC_PULL }state_input;
typedef enum { FUNC_OUTJUICE, FUNC_OUTCHANGE }state_output;
typedef enum{INPUTMONEY,PUTBUTTON,PULLLEVER}action_state;

class jihanki {
public:
	typedef void (jihanki::*FUNC_TABLE)();
	FUNC_TABLE func_table[3][4] = {
		{&jihanki::InputMoney,NULL,NULL,NULL},
		{&jihanki::InputMoney,&jihanki::ShowMoney,&jihanki::PutButton,&jihanki::PullLever},
		{&jihanki::OutJuice,&jihanki::OutChange,NULL,NULL}
	};
	int Money = 0;
	int inputMoney = 0;
	int key = 0;
	int action = 0;
	int jihankistate[2];
	char StateButton[JUICE_MAX];
	Merchandise* merchandise;
	void CanIPurchase();
	bool ConfirmLight();
	void OutJuice();
	void OutChange();
	void LightUp();
	void PutButton();
	void InputMoney();
	void PullLever();
	void SoldOutLightUp();
	void ShowMoney();
	jihanki();
	
};

