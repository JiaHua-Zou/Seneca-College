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
	private:
		std::string m_maker{ '\0' };
		std::string condi{ '\0' };
		double m_topSpeed{ 0 };
	};
}
#endif // !SDDS_CAR_H_