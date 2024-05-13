//Nick Sells, 2024
//ETSU Underwater Robotics

#include "power.h"

//a lookup table to estimate power consumption based on PWM
const Power::PWMPair Power::PWM_AMP_LUT[Power::LUT_SIZE] = {
	{ 1100, 17.03f },
	{ 1200, 8.9f },
	{ 1300, 3.3f },
	{ 1400, 0.5f },
	{ 1500, 0.0f },
	{ 1600, 0.5f },
	{ 1700, 3.3f },
	{ 1800, 8.9f },
	{ 1900, 16.91f }
};

//get an estimate of the amount of amps being drawn by the specified ESC
float Power::getCurrent(u16 pwm) {
	if ((pwm < Defs::BACKWARD) || (pwm > Defs::FORWARD))
		return NAN;
	PWMPair lowerBound = { 0, NAN };
	PWMPair upperBound = { 65535, NAN };

	//loop over each entry in the lookup table
	for (size_t i = 0; i < LUT_SIZE; i++) {
		const PWMPair& entry = PWM_AMP_LUT[i];
		//if we find a match, return it and hop out
		if(entry.pwm == pwm)
			return entry.amps;
		//otherwise find the values that enclose our pwm value
		if((entry.pwm < pwm) && (lowerBound.pwm < entry.pwm)) 
			lowerBound = entry; //get the greatest value less than pwm
		if((pwm < entry.pwm) && (upperBound.pwm > entry.pwm)) 
			upperBound = entry; //get the least value greater than pwm
	}

	//get the proportion between them
	float proportion = 1.0f * (pwm - lowerBound.pwm) / (upperBound.pwm - lowerBound.pwm);
	float result = (upperBound.amps - lowerBound.amps) * proportion + lowerBound.amps;
	return result;
}

//get an estimate of the amount of amps being drawn by all ESCs
float Power::getTotalCurrent() {
	
	float totalCurrent = 0.0f;
	
	for(size_t i = 0; i < Defs::NUM_ESCS; i++)
		totalCurrent += Power::getCurrent(i);
	for(size_t i = 0; i < Defs::NUM_CLAWS; i++)
		totalCurrent += 0.0f; //TODO: figure up the current draw of a claw servo
	
	return totalCurrent;
}
