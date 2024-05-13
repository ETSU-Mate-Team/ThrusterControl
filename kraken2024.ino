//Nick Sells, 2023-2024
//ETSU Underwater Robotics

#include "defs.h"

#include "claws.h"
#include "comms.h"
#include "escs.h"

void setup() {
	delay(Defs::STARTUP_DELAY);
	Serial.begin(Defs::BAUD_RATE);
	ESCs::Init();
	Claws::Init();
	Serial.println("All Systems Initialized!");
}

static TxPacket packet;

void loop() {
	Comms::Read(packet);
	ESCs::Update(packet);
	Claws::Update(packet);
	delay(Defs::TICK_DELAY);
}
