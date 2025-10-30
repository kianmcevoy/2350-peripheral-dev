#ifndef HARDWARE_HPP
#define HARDWARE_HPP

#include "hardware/hardware_data.hpp"

class Hardware
{
	public:
		Hardware() = default;

		void process_input(HardwareInputData& input);
		void process_output(const HardwareOutputData& output);
};

#endif // HARDWARE_HPP