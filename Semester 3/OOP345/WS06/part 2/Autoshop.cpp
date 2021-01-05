/**********************************************************************

Name: Jia Hua Zou

ID: 114383193

Date: Nov,11,2020

Lab6

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

**********************************************************************/
#include"Autoshop.h"

namespace sdds {

	Autoshop::Autoshop() {}

	Autoshop::~Autoshop() {
		while (!m_vehicles.empty())
		{
			delete m_vehicles.back();
			m_vehicles.pop_back();
		}
	}

	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << std::endl
			<< "| Cars in the autoshop!        |" << std::endl
			<< "--------------------------------" << std::endl;
		for (auto ptr = m_vehicles.begin(); ptr != m_vehicles.end(); ptr++)
		{
			(*ptr)->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}
}