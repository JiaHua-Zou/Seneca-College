/**********************************************************************

Name: Jia Hua Zou

ID: 114383193

Date: Nov,11,2020

Lab6

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

**********************************************************************/
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include <iostream>
#include <iomanip>
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle
	{
	public:
		~Car();
		Car();
		Car(std::istream& input);

		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		void trim(std::string& word);
	private:
		std::string m_maker{ '\0' };
		std::string condi{ '\0' };
		double m_topSpeed{ 0 };
	};
}
#endif // !SDDS_CAR_H_