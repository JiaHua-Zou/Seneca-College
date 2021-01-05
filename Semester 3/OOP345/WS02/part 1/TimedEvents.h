/****************************************************************
Name: Jia Hua Zou
ID: 114383193
Date: Oct 8,2020.
Lab 2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************/
#ifndef SDDS_TIMEDEVENTS_H_
#define SDDS_TIMEDEVENTS_H_
#include<iostream>
#include <chrono>

namespace sdds {
	const int MAX_RECORDS = 7;
	class TimedEvents
	{
	private:
		int numRec{ 0 };
		std::chrono::steady_clock::time_point start, end;
		struct
		{
			std::string name; //Event name.
			std::string UT; //Predefined Units of Time.
			std::chrono::steady_clock::duration duration;
		}events[MAX_RECORDS];

	public:
		TimedEvents();
		~TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend std::ostream& operator << (std::ostream&, const TimedEvents&);

	};












}
#endif // !1