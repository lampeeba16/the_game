#include "Pi_in.h"
#include <wiringPi.h>

Pi_Input::Pi_Input(bool initial_state, int pin_num):indicator_state_{ initial_state }, pin_num_{ pin_num }
{
	//check auf PIN nummer --> wenn vergeben abbrechen
	//Falls funzt--> reserve pin

	pinMode(pin_num_, INPUT);
	pullUpDnControl(pin_num_, PUD_DOWN);
}

bool Pi_Input::get_state() const
{
	return digitalRead(pin_num_);
}
