#pragma once

#include <vector>
//Zum festlegen welche Pins schon vergeben sind und welche nicht
class Io_manager
{
public:
	void reserve(int pin);

	void release(int pin);

	bool check(int pin);
private:
	static std::vector<int> reserved_pins_;
};