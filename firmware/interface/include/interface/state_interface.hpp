#ifndef STATE_INTERFACE_HPP
#define STATE_INTERFACE_HPP

#include "interface/state_data.hpp"
#include "hardware/hardware_data.hpp"

class StateInterface
{
	public:
		StateInterface() = default;

		void process(const StateInputData& input, StateOutputData& output);
};

#endif // STATE_INTERFACE_HPP