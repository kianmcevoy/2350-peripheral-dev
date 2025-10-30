#ifndef INSTRUMENT_DATA_H
#define INSTRUMENT_DATA_H

#include "interface/parameter_data.hpp"
#include "interface/state_data.hpp"

struct InstrumentInputData
{
	const ParameterData& parameter;
};

struct InstrumentOutputData
{
	const StateData& state;
};

#endif // INSTRUMENT_DATA_H