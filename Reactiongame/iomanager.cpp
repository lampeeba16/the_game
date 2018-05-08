#include "iomanager.h"
#include <algorithm>

void Io_manager::reserve(int pin)
{
	reserved_pins_.push_back(pin);
}

void Io_manager::release(int pin)
{
	reserved_pins_.erase(std::remove(reserved_pins_.begin(), reserved_pins_.end(), pin), reserved_pins_.end());//Funktion zum suchen und löschen
}

bool Io_manager::check(int pin)
{
	if (std::find(reserved_pins_.begin(), reserved_pins_.end(), pin) != reserved_pins_.end())//Wenn Element vorhanden     Funktion zum suchen von Element
		return true;
	else //wenn nicht vrhandne
		return false;
}
