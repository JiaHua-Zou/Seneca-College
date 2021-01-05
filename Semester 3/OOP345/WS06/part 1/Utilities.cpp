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

		return newCar;
	}
}