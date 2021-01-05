#ifndef SDDS_UTILITIES_H_
#define SDDS_UTILITIES_H_
#include <iostream>
#include <sstream>
#include "Vehicle.h"
#include "Car.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);

}
#endif // !SDDS_UTILITIES_H_