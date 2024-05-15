//Nick Sells, 2024
//ETSU Underwater Robotics

#ifndef LEAKSENSOR_H
#define LEAKSENSOR_H

class LeakSensor {
private:
	static const u8 PIN = 0; //TODO: edit to match real
	static const u16 THRESHOLD = 100;
	static void Warn();
	
public:
	static void Init();
	static void Update();
};

#endif //LEAKSENSOR_H
