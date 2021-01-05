/****************************************************************
Name: Jia Hua Zou
ID: 114383193
Date: Oct 10,2020.
Lab 3

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************/
#ifndef SDDS_SETSUMMABLE_H__
#define SDDS_SETSUMMABLE_H__
#include <iostream>
#include <iomanip>
#include "Set.h"

namespace sdds
{
	template <typename T, unsigned int N>
	class SetSummable : public Set<T, N>
	{
	public:
		T accumulate(const std::string& filter) const {
			T temp(filter);
			for (size_t i = 0u; i < N; ++i)
			{
				if ((*this)[i].key() == filter)
					temp += (*this)[i];
			}
			return temp;
		}
	};
}

#endif  // ! SDDS_SETSUMMABLE_H_