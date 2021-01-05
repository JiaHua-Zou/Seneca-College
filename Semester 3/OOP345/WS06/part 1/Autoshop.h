#ifndef SDDS_AUTOSHOP_H_
#define SDDS_AUTOSHOP_H_
#include <iostream>
#include <vector>
#include "Vehicle.h"

namespace sdds {

	class Autoshop
	{
	public:
		Autoshop();
		~Autoshop();

		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
	private:
		std::vector<Vehicle*> m_vehicles; //vector to store all vehicles
	};
}
#endif // !SDDS_AUTOSHOP_H_