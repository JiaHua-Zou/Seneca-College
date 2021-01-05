/**********************************************************************

Name: Jia Hua Zou

ID: 114383193

Date: Nov,11,2020

Lab6

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

**********************************************************************/
#ifndef SDDS_UTILITIES_H_
#define SDDS_UTILITIES_H_
#include <iostream>
#include <sstream>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
}
#endif // !SDDS_UTILITIES_H_