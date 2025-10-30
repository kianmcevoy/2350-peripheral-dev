#ifndef STATE_DATA_HPP
#define STATE_DATA_HPP

#include "hardware/hardware_data.hpp"
#include "interface/parameter_data.hpp"

struct StateData
{

};

struct StateInputData
{
	const StateData& state;
	const UtilityData& utility;
};

struct StateOutputData
{
	HardwareOutputData& hardware;
};

#endif // STATE_DATA_HPP