#ifndef HARDWARE_PIN_MAP_HPP
#define HARDWARE_PIN_MAP_HPP

#include "system/gpio.hpp"

enum class PinName : uint8_t
{
	button_1 = 6,
	button_2 = 5,
	button_3 = 7,
	led_1 = 30,
	led_2 = 31,
	led_3 = 32
};

static constexpr std::array<GPIOPinDef, 6> pin_defs = 
{{
	{PinName::button_1, GPIODirection::INPUT, GPIOPull::UP},
	{PinName::button_2, GPIODirection::INPUT, GPIOPull::UP},
	{PinName::button_3, GPIODirection::INPUT, GPIOPull::UP},
	{PinName::led_1, GPIODirection::OUTPUT, GPIOPull::NONE},
	{PinName::led_2, GPIODirection::OUTPUT, GPIOPull::NONE},
	{PinName::led_3, GPIODirection::OUTPUT, GPIOPull::NONE}
}};

#endif // HARDWARE_PIN_MAP_HPP