//Nick Sells, 2023-2024
//ETSU Underwater Robotics

#ifndef UTIL_H
#define UTIL_H

#define likely(cond) __builtin_expect((cond), 1)
#define unlikely(cond) __builtin_expect((cond), 0)

typedef unsigned char u8;
typedef unsigned short u16;
//typedef unsigned int u32;
typedef unsigned long u64;

typedef char s8;
typedef short s16;
typedef int s32;
typedef long s64;

typedef unsigned int size_t;

namespace Util {
	template <typename T> int Sign(T val) {
		return (T(0) < val) - (val < T(0));
	}
}

namespace Defs {
	namespace Claws {
		static constexpr u8 NUM_CLAWS = 2;
		static constexpr u16 OPEN = 1900;
		static constexpr u16 CLOSED = 1100;
	}

	namespace ESCs {
		static constexpr u8 NUM_ESCS = 8;
		static constexpr u16 HALT = 1500;
		static constexpr u16 FORWARD = 1900;
		static constexpr u16 BACKWARD = 1100;
		static constexpr u16 INIT_DELAY = 7000;
	}

	constexpr u16 STARTUP_DELAY = 300;
	constexpr u16 TICK_DELAY = 50;
	constexpr u16 BAUD_RATE = 9600;

	constexpr u16 ZP_DELAY = 150;
}

#endif
