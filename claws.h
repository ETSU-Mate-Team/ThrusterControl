//Nick Sells, 2024
//ETSU Underwater Robotics

#ifndef CLAWS_H
#define CLAWS_H

#include "defs.h"
#include "comms.h"

class Claws {
public:
	static void Init();
	static void Update(const TxPacket& packet);
};

#endif //CLAWS_H
