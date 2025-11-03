#ifndef HARDWARE_PIN_MAP_HPP
#define HARDWARE_PIN_MAP_HPP

#include "system/gpio.hpp"
#include "system/adc.hpp"

//GPIO Pin Definitions
enum class GPIO_Name : uint8_t
{
	button_1 = 7,
	button_2 = 6,
	button_3 = 5,
	led_1 = 30,
	led_2 = 31,
	led_3 = 32
};

static constexpr std::array<GPIOPinDef, 6> pin_defs =
{{
	{GPIO_Name::button_1, GPIODirection::INPUT, GPIOPull::UP},
	{GPIO_Name::button_2, GPIODirection::INPUT, GPIOPull::UP},
	{GPIO_Name::button_3, GPIODirection::INPUT, GPIOPull::UP},
	{GPIO_Name::led_1, GPIODirection::OUTPUT, GPIOPull::NONE},
	{GPIO_Name::led_2, GPIODirection::OUTPUT, GPIOPull::NONE},
	{GPIO_Name::led_3, GPIODirection::OUTPUT, GPIOPull::NONE}
}};

//ADC Pin Definitions
enum class ADC_Name : uint8_t
{
	pot_1 = 4,
	pot_2 = 2,
	pot_3 = 7,
	pot_4 = 6,
	pot_5 = 5,
	pot_6 = 3
};

static constexpr std::array<ADCDescription, 6> adc_descriptors =
{{
	{ADC_Name::pot_1, 44},
	{ADC_Name::pot_2, 42},
	{ADC_Name::pot_3, 47},
	{ADC_Name::pot_4, 46},
	{ADC_Name::pot_5, 45},
	{ADC_Name::pot_6, 43}
}};


#endif // HARDWARE_PIN_MAP_HPP