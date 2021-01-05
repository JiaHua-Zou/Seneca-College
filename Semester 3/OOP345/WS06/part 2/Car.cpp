/**********************************************************************

Name: Jia Hua Zou

ID: 114383193

Date: Nov,11,2020

Lab6

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

**********************************************************************/
#include "Car.h"

namespace sdds {
	Car::~Car() {}
	Car::Car() {}

	Car::Car(std::istream& input) {
		std::string strCar{ '\0' };
		std::getline(input, strCar, ','); //removes the first ,

		std::getline(input, this->m_maker, ',');
		trim(m_maker);

		std::getline(input, this->condi, ',');
		trim(condi);
		if (condi == "n" || condi == "")
		{
			condi = "new";
		}
		else if (condi == "u")
		{
			condi = "used";
		}
		else if (condi == "b")
		{
			condi = "broken";
		}
		else
		{
			throw"Invalid record!";
		}

		std::getline(input, strCar, ',');
		trim(strCar);

		try
		{
			this->m_topSpeed = std::stod(strCar);
		}
		catch (const std::exception&)
		{
			throw "Invalid record!";
		}
	}

	std::string Car::condition() const {
		return condi;
	}
	double Car::topSpeed() const {
		return m_topSpeed;
	}
	void Car::display(std::ostream& out) const {
		out << std::right << "| " << std::setw(10) << m_maker << " | ";
		out << std::left << std::setw(6) << condi << " | ";
		out << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
	}

	void Car::trim(std::string& word) {
		size_t start = word.find_first_not_of(" ");
		word = (start == std::string::npos) ? "" : word.substr(start);
		size_t end = word.find_last_not_of(" ");
		word = (end == std::string::npos) ? "" : word.substr(0, end + 1);
	}
}