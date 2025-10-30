#include "engine/engine.hpp"
#include "system/log.hpp"
#include "pico/time.h"

Engine::Engine()
{
}

void Engine::start()
{
	log_debug("engine starting!\n");
}

void Engine::run()
{
	log_debug("engine running!\n");

	while(true)
	{
		if(audio_ready)
		{
			this->process();
		}
	}
}

void Engine::process()
{
	hardware.process_input(hardware_input_data);

	{
		const ParameterInputData input
		{
			.hardware = hardware_input_data
		};

		ParameterOutputData output
		{
			.parameter = parameter_data,
			.utility = utility_data
		};

		parameter_interface.process(input, output);
	}

	{
		const InstrumentInputData input
		{
			.parameter = parameter_data
		};

		InstrumentOutputData output
		{
			.state = state_data
		};

		instrument.process(input, output);
	}

	{
		const StateInputData input
		{
			.state = state_data,
			.utility = utility_data
		};

		StateOutputData output
		{
			.hardware = hardware_output_data
		};

		state_interface.process(input, output);
	}

	hardware.process_output(hardware_output_data);

	sleep_ms(200);
}
