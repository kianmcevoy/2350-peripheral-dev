#include "hardware/hardware.hpp"
#include "pico/stdlib.h" 

Hardware::Hardware()
{
	gpio.init(gpio_map);
}

void Hardware::process_input(HardwareInputData& input)
{
	button_state_1 = !button_state_1;
	button_state_2 = !button_state_2;
	button_state_3 = !button_state_3;
}

void Hardware::process_output(const HardwareOutputData& output)
{
	gpio.write(PinName::led_1, button_state_1);
	gpio.write(PinName::led_2, button_state_2);
	gpio.write(PinName::led_3, button_state_3);
}
