/**********************************************************************

Name: Jia Hua Zou

ID: 114383193

Date: Nov,11,2020

Lab6

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

**********************************************************************/
#ifndef SDDS_RACECAR_H_
#define SDDS_RACECAR_H_
#include <iostream>
#include "Car.h"

namespace sdds {
	class Racecar:public Car
	{
	public:
		Racecar();
		~Racecar();

		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;

	private:
		double m_booster{ 0 }; //value 0-1
	};
}
#endif // !SDDS_RACECAR_H_