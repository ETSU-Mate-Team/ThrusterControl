//Nick Sells, 2024
//ETSU Underwater Robotics

#include "LeakSensor.h"

void LeakSensor::Warn() noexcept {
	//TODO: implement
}

void LeakSensor::Init() noexcept {
	pinMode(PIN, INPUT);
}

void LeakSensor::Update() noexcept {
	if(analogRead(PIN) >= THRESHOLD) {
		Warn();
	}
}
