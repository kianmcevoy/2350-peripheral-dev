#ifndef HARDWARE_HPP
#define HARDWARE_HPP

#include "hardware/hardware_data.hpp"
#include "hardware/pin_map.hpp"
#include "system/log.hpp"
#include "system/gpio.hpp"
#include <cstdint>
#include <span>
#include <array>
class Hardware
{
	public:
		Hardware();

		void process_input(HardwareInputData& input);
		void process_output(const HardwareOutputData& output);
	
	private:

		uint16_t last_value[6]{0};
    	const uint16_t threshold = 16;   // ignore tiny changes

		bool button_state_1 = false;
		bool button_state_2 = true;
		bool button_state_3 = false;

		GPIOPinMap gpio_map = GPIOPinMap{.pins = std::span<const GPIOPinDef>{pin_defs}};
		GPIO gpio;

		ADCPinMap adc_map = ADCPinMap{.adc_descriptors = std::span<const ADCDescription>{adc_descriptors}};
		ADC adc;		
};

#endif // HARDWARE_HPP