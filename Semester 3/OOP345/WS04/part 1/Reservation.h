#ifndef SDDS_RESERVATION_H_
#define SDDS_RESERVATION_H_
#include <iostream>
#include <string>

namespace sdds {

	class Reservation
	{
	public:
		Reservation();
		Reservation(const std::string& res); // This format: ID:NAME,EMAIL,PARTY_SIZE,DAY,HOUR
		~Reservation();
		friend std::ostream& operator << (std::ostream& os,  const Reservation& reservation);

	private:
		std::string id {};
		std::string name{};
		std::string email{};
		size_t m_ppl{ 0 };
		size_t day{ 0 }, hr{ 0 };
	};

}
#endif // !SDDS_RESERVATION_H_