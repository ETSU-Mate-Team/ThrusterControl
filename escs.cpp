//Nick Sells, 2024
//ETSU Underwater Robotics

#include "comms.h"
#include "escs.h"
#include <Arduino.h>
#include <Servo.h>

static u8 pins[Defs::NUM_ESCS] = { 0, 0, 0, 0, 0, 0, 0, 0 }; //TODO: edit to match real
static Servo escs[Defs::NUM_ESCS];
//these track the last recieved PWM signal for each ESC
static u16 oldPWM[Defs::NUM_ESCS];

//initialize the ESCs by sending the halt signal and waiting
void ESCs::Init() noexcept {
	Serial.print(F("Initializing ESCs..."));

    for(size_t i = 0; i < Defs::NUM_ESCS; i++) {
      pinMode(pins[i], OUTPUT);
      escs[i].attach(pins[i], Defs::BACKWARD, Defs::FORWARD);
      escs[i].writeMicroseconds(Defs::HALT);
    }

    delay(Defs::INIT_DELAY);

    Serial.println(F("ESCs Initialized!"));
}

//apply new signals to the ESCs
void ESCs::Update(const TxPacket& packet) {
	
	for(size_t i = 0; i < Defs::NUM_ESCS; i++) {

		u16 newPWM = packet.esc[i];

		//if the jump between the two values would cross 1500, halt for a moment first
		s16 temp = (newPWM - Defs::HALT) * (oldPWM[i] - Defs::HALT);
		if(Util::Sign(temp) == -1)
			escs[i].writeMicroseconds(Defs::HALT);

		//TODO: make a timer for each ESC so that we can time the delay for each one without halting the whole device
		//NOTE: or alternatively, make zeropass a concern of the master device, and factor it into the scheduling of transmission
		delay(Defs::ZP_DELAY);

		escs[i].writeMicroseconds(newPWM);
		oldPWM[i] = newPWM;
	}
}
