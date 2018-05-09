#pragma once
#include "my_output.h"
#include "iomanager.h"

class Pi_out final : public IOutput {
public:
	Pi_out(Io_manager &Io_manager, bool initial_state = false, int pin_num = 0);

	virtual void set_1() override;

	virtual void set_0() override;

	virtual bool ask_state() const override;

private:
	bool state_;
	int pin_num_;
	Io_manager &Io_manager_;

	//Override deconstructor
};