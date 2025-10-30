#ifndef INSTRUMENT_HPP
#define INSTRUMENT_HPP

#include "instrument/instrument_data.hpp"


class Instrument
{
	public:
		Instrument() = default;

		void process(const InstrumentInputData& data, InstrumentOutputData& output);
};

#endif // INSTRUMENT_HPP