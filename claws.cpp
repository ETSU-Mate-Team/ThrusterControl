//Nick Sells, 2024
//ETSU Underwater Robotics

#include "claws.h"
#include "defs.h"
#include <Arduino.h>
#include <Servo.h>

static const u8 pins[Defs::NUM_CLAWS] = { 0, 0 }; //TODO: edit to match real
static Servo claws[Defs::NUM_CLAWS];

//initialize the claws and their pins
void Claws::Init() {
	Serial.print(F("Initializing Claws..."));
	
	for(size_t i = 0; i < Defs::NUM_CLAWS; i++) {
		pinMode(pins[i], OUTPUT);
		claws[i].attach(pins[i], Defs::OPEN, Defs::CLOSED);
	}

	Serial.println(F("Claws Initialized!"));
}

//apply new signals to each of the claws
void Claws::Update(const TxPacket& packet) {
	for(size_t i = 0; i < Defs::NUM_CLAWS; i++) {
		claws[i].writeMicroseconds(packet.claw[i]);
	}
}
