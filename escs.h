//Nick Sells, 2024
//ETSU Underwater Robotics

#ifndef ESCS_H
#define ESCS_H

#include "comms.h"

class ESCs {
public:
	static void Init();
	static void Update(const TxPacket& packet) noexcept;
};

#endif //ESCS_H
