#pragma once

#include <vector>
#include <algorithm>
//Zum festlegen welche Pins schon vergeben sind und welche nicht
class Io_manager
{
public:
	Io_manager();

	void reserve(int pin);

	void release(int pin);

	bool check(int pin);
private:
	std::vector<int> reserved_pins_;
};