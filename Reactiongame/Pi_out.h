#pragma once
#include "my_output.h"

class Pi_out final : public IOutput {
public:
	Pi_out(bool initial_state = false, int pin_num = 0);

	virtual void set_1() override;

	virtual void set_0() override;

	virtual bool ask_state() const override;

private:
	bool state_;
	int pin_num_;
};