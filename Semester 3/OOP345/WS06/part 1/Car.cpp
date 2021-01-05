#include "Car.h"


namespace sdds {
	Car::~Car() {}
	Car::Car() {}

	Car::Car(std::istream& input) {
		auto trim = [](std::string& word) {
			size_t start = word.find_first_not_of(" ");
			word = (start == std::string::npos) ? "" : word.substr(start);
			size_t end = word.find_last_not_of(" ");
			word = (end == std::string::npos) ? "" : word.substr(0, end + 1);
		};

		std::string strCar{ '\0' };


			std::getline(input, strCar);
			strCar.erase(0, strCar.find(',') + 1);

			this->m_maker = strCar.substr(0, strCar.find(','));
			strCar.erase(0, strCar.find(',') + 1);
			trim(m_maker);

			//need to change it to words
			this->condi = strCar.substr(0, strCar.find(','));
			strCar.erase(0, strCar.find(',') + 1);
			trim(condi);
			if (condi == "n")
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
			
			std::string temp = strCar.substr(0, strCar.find(','));
			strCar.erase(0, strCar.find(',') + 1);
			trim(temp);
			this->m_topSpeed = std::stod(temp);


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
		out << std::setw(6) << std::fixed << std::setprecision(2) << m_topSpeed << " |" << std::endl;
	}
}