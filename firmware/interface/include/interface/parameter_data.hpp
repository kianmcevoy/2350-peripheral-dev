#ifndef PARAMETER_DATA_HPP
#define PARAMETER_DATA_HPP

#include "hardware/hardware_data.hpp"

struct ParameterData
{

};

struct UtilityData
{

};

struct ParameterInputData
{
	const HardwareInputData& hardware;
};

struct ParameterOutputData
{
	ParameterData& parameter;
	UtilityData& utility;
};

#endif // PARAMETER_DATA_HPP