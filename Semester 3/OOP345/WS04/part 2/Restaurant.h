/****************************************************************
Name: Jia Hua Zou
ID: 114383193
Date: Oct 18,2020.
Lab 4

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************/
#ifndef SDDS_RESTAURANT_H_
#define SDDS_RESTAURANT_H_
#include <iostream>
#include <string>
#include "Reservation.h"

namespace sdds {

	class Restaurant
	{
	public:
		Restaurant();
		Restaurant(const Restaurant& res);
		Restaurant(Restaurant&& res);
		Restaurant(Reservation* reservations[], size_t cnt);
		~Restaurant();
		size_t size() const;
		friend std::ostream& operator << (std::ostream& os, const Restaurant& res);
	private:
		Reservation* reserve = { nullptr };
		size_t cnt = { 0 };
	};



}
#endif // !SDDS_RESTAURANT_H_