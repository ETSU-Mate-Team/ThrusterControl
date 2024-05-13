//Nick Sells, 2024
//ETSU Underwater Robotics

#ifndef POWER_H
#define POWER_H

#include "defs.h"

class Power {
private:
	struct PWMPair {
		u16 pwm;
		float amps;
	};

	static const size_t LUT_SIZE = 9;
	static const PWMPair PWM_AMP_LUT[LUT_SIZE];

public:
	static float getCurrent(u16 pwm);
	static float getTotalCurrent();
};

#endif //POWER_H
