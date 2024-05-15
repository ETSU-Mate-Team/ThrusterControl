//Nick Sells, 2024
//ETSU Underwater Robotics

#include "comms.h"
#include <Arduino.h>

void Comms::Read(TxPacket &packet) {

	if(Serial.available() <= 0)
		return;

	static char buf[16];
	memset(buf, '\0', 16);

	//for each esc
	for(size_t i = 0; i < Defs::ESCs::NUM_ESCS; i++) {
		Serial.readBytesUntil(' ', buf, 16);
		int pwm = atoi(buf);
		packet.esc[i] = pwm;
		Serial.println(pwm);
		memset(buf, '\0', 16);
	}
	//for each claw
	for(size_t i = 0; i < Defs::Claws::NUM_CLAWS; i++) {
		Serial.readBytesUntil(' ', buf, 16);
		int pwm = atoi(buf);
		packet.claw[i] = pwm;
		Serial.println(pwm);
		memset(buf, '\0', 16);
	}
}
