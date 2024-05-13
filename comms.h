//Nick Sells, 2024
//ETSU Underwater Robotics

#ifndef COMMS_H
#define COMMS_H

#include "defs.h"
#include <Arduino.h>

//encapsulates all signals we need to be listening for
struct TxPacket {
	u16 esc[Defs::NUM_ESCS];
	u16 claw[Defs::NUM_CLAWS];
};

class Comms {
public:

	//reads the Serial input stream to populate a TxPacket with new signals
	static void Read(TxPacket& packet) {
		for(size_t i = 0; i < Defs::NUM_ESCS; i++)
			packet.esc[i] = (Serial.available() > 0) ? Serial.read() : Defs::HALT;
		for(size_t i = 0; i < Defs::NUM_CLAWS; i++)
			packet.claw[i] = (Serial.available() > 0) ? Serial.read() : Defs::OPEN;
	}
};

#endif //COMMS_H
