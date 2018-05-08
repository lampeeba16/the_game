#include "Pi_out.h"
#include <iostream>
#include <wiringPi.h>



Pi_out::Pi_out(bool initial_state, int pin_num) :state_{ initial_state }, pin_num_{ pin_num }
{
	//check auf PIN nummer --> wenn vergeben abbrechen
	//Falls funzt--> reserve pin
	pinMode(pin_num_, OUTPUT);
}

void Pi_out::set_1()
{
	if (state_) {
		return;
	}
	digitalWrite(pin_num_, HIGH);
	state_ = true;
}

void Pi_out::set_0()
{
	if (!state_) {
		return;
	}
	digitalWrite(pin_num_, LOW);
	state_ = false;
	
}

bool Pi_out::ask_state() const
{ // MFA - cached state is dangerous! what if you have a copy? what if there are two instances operating on one pin? use digitalRead instead!
	return digitalRead(pin_num_);
}
