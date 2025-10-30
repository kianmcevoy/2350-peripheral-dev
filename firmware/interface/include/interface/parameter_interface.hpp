#ifndef PARAMETER_INTERFACE_HPP
#define PARAMETER_INTERFACE_HPP

#include "interface/parameter_data.hpp"
#include "hardware/hardware_data.hpp"

class ParameterInterface
{
	public:
		ParameterInterface() = default;

		void process(const ParameterInputData& input, ParameterOutputData& output);

};

#endif // PARAMETER_INTERFACE_HPP