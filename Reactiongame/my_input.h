#pragma once

class IInput { // MFA naming - this is an interface, is it? so IInput
public:
	virtual bool get_state() const = 0;
	virtual ~IInput() = 0;
};