#include "hardware/hardware.hpp"
#include "pico/stdlib.h"
#include "system/log.hpp"
#include "hardware/adc.h"

Hardware::Hardware()
{
	gpio.init(GPIO_Init);
	adc.init(ADC_Init);
}

void Hardware::process_input(HardwareInputData& input)
{
	button_state_1 = !gpio.read(PinName::button_1);
	button_state_2 = !gpio.read(PinName::button_2);
	button_state_3 = !gpio.read(PinName::button_3);


	unsigned value = adc.read(ADC_Name::pot_1);
	if(value > last_value[0] + threshold || value + threshold < last_value[0])
	{
		log_debug("Pot 1 value: %u\n", value);
		last_value[0] = value;
	}

	value = adc.read(ADC_Name::pot_2);
	if(value > last_value[1] + threshold || value + threshold < last_value[1])
	{
		log_debug("Pot 2 value: %u\n", value);
		last_value[1] = value;
	}

	value = adc.read(ADC_Name::pot_3);
	if(value > last_value[2] + threshold || value + threshold < last_value[2])
	{
		log_debug("Pot 3 value: %u\n", value);
		last_value[2] = value;
	}

	value = adc.read(ADC_Name::pot_4);
	if(value > last_value[3] + threshold || value + threshold < last_value[3])
	{
		log_debug("Pot 4 value: %u\n", value);
		last_value[3] = value;
	}

	value = adc.read(ADC_Name::pot_5);
	if(value > last_value[4] + threshold || value + threshold < last_value[4])
	{
		log_debug("Pot 5 value: %u\n", value);
		last_value[4] = value;
	}

	value = adc.read(ADC_Name::pot_6);
	if(value > last_value[5] + threshold || value + threshold < last_value[5])
	{
		log_debug("Pot 6 value: %u\n", value);
		last_value[5] = value;
	}

}

void Hardware::process_output(const HardwareOutputData& output)
{
	gpio.write(PinName::led_1, button_state_1);
	gpio.write(PinName::led_2, button_state_2);
	gpio.write(PinName::led_3, button_state_3);
}
