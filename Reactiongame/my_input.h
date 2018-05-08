#pragma once

class IInput {
public:
	virtual bool get_state() const = 0;
	virtual ~IInput() = 0;
};