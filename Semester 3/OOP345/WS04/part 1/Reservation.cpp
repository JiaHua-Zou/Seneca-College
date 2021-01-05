#include <iomanip>
#include <algorithm>
#include <sstream>
#include "Reservation.h"

namespace sdds {
	Reservation::Reservation()
	{
	}

	Reservation::Reservation(const std::string& res) {
		//use isspace to remove spaces.
		std::string s_temp = res;
		// this line will remove all spaces and shifts the letter.
		s_temp.erase(std::remove_if(s_temp.begin(), s_temp.end(), ::isspace), s_temp.end());
		//s_temp.erase(std::find(s_temp.begin(), s_temp.end(), ' '));
		this->id = s_temp.substr(0, s_temp.find(':'));
		s_temp.erase(0, s_temp.find(':') + 1);

		this->name = s_temp.substr(0, s_temp.find(','));
		s_temp.erase(0, s_temp.find(',') + 1);

		this->email = s_temp.substr(0, s_temp.find(','));
		s_temp.erase(0, s_temp.find(',') + 1);

		this->m_ppl = std::stoi(s_temp.substr(0, s_temp.find(',')));
		s_temp.erase(0, s_temp.find(',') + 1);

		this->day = std::stoi(s_temp.substr(0, s_temp.find(',')));
		s_temp.erase(0, s_temp.find(',') + 1);

		this->hr = std::stoi(s_temp.substr(0, s_temp.find(',')));
		s_temp.erase(0, s_temp.find(',') + 1);
	}

	Reservation::~Reservation()
	{
	}

	std::ostream& operator << (std::ostream& os, const Reservation& reservation) {
		os << "Reservation " << reservation.id << ": ";
		os << std::setw(10) << std::right
			<< reservation.name << "  ";
		//need to use + not <<.
		os << std::setw(20) << std::left
			<< "<" + reservation.email + ">";

		if (reservation.hr >= 6 && reservation.hr <= 9) {
			os << "    Breakfast";
		}
		else if (reservation.hr >= 11 && reservation.hr <= 15) {
			os << "    Lunch";
		}
		else if (reservation.hr >= 17 && reservation.hr <= 21) {
			os << "    Dinner";
		}
		else
		{
			os << "    Drinks";
		}
		os << " on day " << reservation.day << " @ " << reservation.hr << ":00 for " << reservation.m_ppl << " people." << std::endl;

		return os;
	}

}
