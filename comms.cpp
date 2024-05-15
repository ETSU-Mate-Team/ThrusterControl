//Nick Sells, 2024
//ETSU Underwater Robotics

#include "comms.h"
#include <Arduino.h>

#include <sstream>
#include <vector>

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

void Comms::Read(TxPacket &packet) {

	//Serial.print(F("packet: { ")); 
  if(Serial.available() <= 0)
    return;
  
  char buf[50]; //6 characters per thruster, 8 thrusters, plus a $ terminator
  Serial.readBytesUntil('$', buf, 50);

  Serial.println(buf);

  std::vector<std::string> tokens = split(std::string(buf), ' ');
  if(tokens.size() != Defs::NUM_ESCS)
    return;
  for(size_t i = 0; i < Defs::NUM_ESCS; i++)
    Serial.println(tokens[i].c_str());

  /*
	for(size_t i = 0; i < Defs::NUM_ESCS; i++) {
		

    if(Serial.available() > 0) {
      Serial.readBytesUntil('$', buf, 4);
      Serial.println(buf);
    }

    //packet.esc[i] = temp;
		//Serial.print(temp);
		//Serial.print(F(", "));
	}
  */
  /*
	for(size_t i = 0; i < Defs::NUM_CLAWS; i++) {
    u16 temp = (Serial.available() > 0) ? Serial.read() : Defs::OPEN;
		packet.claw[i] = temp;
    Serial.print(temp);
		Serial.print(F(", "));
  }
  */

	//Serial.println(F("}"));
}
