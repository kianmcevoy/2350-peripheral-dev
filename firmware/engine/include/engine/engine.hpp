#ifndef ENIGINE_HPP
#define ENIGINE_HPP

#include "interface/state_interface.hpp"
#include "interface/parameter_interface.hpp"
#include "hardware/hardware.hpp"
#include "instrument/instrument.hpp"

#include "interface/state_data.hpp"
#include "instrument/instrument_data.hpp"
#include "interface/parameter_data.hpp"
#include "hardware/hardware_data.hpp"

class Engine
{
	public:
		Engine();

		void start();
		void run();

	private:
		void process();

		bool audio_ready;
		Hardware hardware;
		Instrument instrument;
		StateInterface state_interface;
		ParameterInterface parameter_interface;

		HardwareInputData hardware_input_data;
		HardwareOutputData hardware_output_data;
		ParameterData parameter_data;
		StateData state_data;
		UtilityData utility_data;
};

#endif // ENGINE_HPP