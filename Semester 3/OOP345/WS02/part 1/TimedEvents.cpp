/****************************************************************
Name: Jia Hua Zou
ID: 114383193
Date: Oct 8,2020.
Lab 2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************/
#include <iomanip>
#include "TimedEvents.h"

namespace sdds {
	TimedEvents::TimedEvents()
	{
	}
	TimedEvents::~TimedEvents()
	{
	}

	void TimedEvents::startClock()
	{
		start = std::chrono::steady_clock::now();
	}


	void TimedEvents::stopClock()
	{
		end = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* event_name)
	{
		if (numRec < MAX_RECORDS) {
			this->events[numRec].name = event_name;
			this->events[numRec].UT = "nanoseconds";
			this->events[numRec].duration = std::chrono::duration_cast<std::chrono::nanoseconds> (end - start);
			numRec++;
		}
	}

	std::ostream& operator<< (std::ostream& os, const TimedEvents& record)
	{
		os << "--------------------------" << std::endl
			<< "Execution Times:" << std::endl
			<< "--------------------------" << std::endl;
		for (int i = 0; i < record.numRec; i++) {
			os << std::setw(20) << std::left << record.events[i].name;
			os << std::setw(13) << std::right << record.events[i].duration.count();
			os << " " << record.events[i].UT << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}



}