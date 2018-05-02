#pragma once

class IOutput { // MFA this is an interface -> IOutput
public:
	virtual void set_1() = 0;
	virtual void set_0() = 0;
	virtual bool ask_state() const = 0;
	virtual ~IOutput() = 0;
};
