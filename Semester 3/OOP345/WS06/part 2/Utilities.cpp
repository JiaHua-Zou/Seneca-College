/**********************************************************************

Name: Jia Hua Zou

ID: 114383193

Date: Nov,11,2020

Lab6

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

**********************************************************************/
#include "Utilities.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		std::string line{ '\0' };
		char value{ '\0' };
		Car* newCar{ nullptr };

		getline(in, line);
		std::stringstream buff(line);
		buff >> value;
		if (value == 'c' || value == 'C') {
			newCar = new Car(buff);
		}
		else if (value == 'r' || value == 'R')
		{
			newCar = new Racecar(buff);
		}
		else if( value != '\0')
		{
			throw value;
		}


		return newCar;
	}
}