#pragma once
#include "my_input.h"

class Pi_Input final : public IInput {
public:
	Pi_Input(bool initial_state = false, int pin_num=0);
	virtual bool get_state() const override;
private:
	bool indicator_state_; // MFA never used, throw this out!
	int pin_num_;

	//Override deconstructor
};