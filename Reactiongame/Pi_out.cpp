#include "Pi_out.h"
#include <iostream>
#include "piproxy.h"
#include "iomanager.h"



Pi_out::Pi_out(Io_manager &Io_manager, bool initial_state, int pin_num) :Io_manager_{ Io_manager }, state_{ initial_state }, pin_num_{ pin_num }
{
	if (Io_manager_.check(pin_num_))//Schaun ob pin belegt ist
	{
		std::cout << "ERROR PIN BEREITS BELEGT!!" << std::endl;
		return;
	}
	else
	{
		Io_manager_.reserve(pin_num_);
		pinMode(pin_num_, OUTPUT);
	}
}

void Pi_out::set_1()
{
	if (digitalRead(pin_num_)) {
		return;
	}
	digitalWrite(pin_num_, HIGH);
	state_ = true;
}

void Pi_out::set_0()
{
	if (!digitalRead(pin_num_)) {
		return;
	}
	digitalWrite(pin_num_, LOW);
	state_ = false;
	
}

bool Pi_out::ask_state() const
{ // MFA - cached state is dangerous! what if you have a copy? what if there are two instances operating on one pin? use digitalRead instead!
	return digitalRead(pin_num_);
}
