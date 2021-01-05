#include"Autoshop.h"

namespace sdds {

	Autoshop::Autoshop(){}

	Autoshop::~Autoshop(){}

	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << std::endl
			<< "| Cars in the autoshop!        |" << std::endl
			<< "--------------------------------" << std::endl;
		for (auto ptr = m_vehicles.begin();ptr != m_vehicles.end(); ptr++)
		{
			(*ptr)->display(out);
		}
		out << "--------------------------------" << std::endl;
	}
}