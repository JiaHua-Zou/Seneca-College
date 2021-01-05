/**********************************************************************

Name: Jia Hua Zou

ID: 114383193

Date: Nov,11,2020

Lab6

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

**********************************************************************/
#include "Racecar.h"

namespace sdds {
	Racecar::Racecar() {}
	Racecar::~Racecar() {}

	Racecar::Racecar(std::istream& in) :Car(in){
		std::string booster;
		getline(in, booster);
		Car::trim(booster);
		this->m_booster = std::stod(booster);
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return (Car::topSpeed() * (1 +m_booster));
	}
}