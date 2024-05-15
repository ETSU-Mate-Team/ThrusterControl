//Nick Sells, 2024
//ETSU Underwater Robotics

#ifndef COMMS_H
#define COMMS_H

#include "defs.h"
#include <Arduino.h>

//encapsulates all signals we need to be listening for
struct TxPacket {
	u16 esc[Defs::ESCs::NUM_ESCS];
	u16 claw[Defs::Claws::NUM_CLAWS];
};

class Comms {
public:

	//reads the Serial input stream to populate a TxPacket with new signals
	static void Read(TxPacket& packet);
};

#endif //COMMS_H
