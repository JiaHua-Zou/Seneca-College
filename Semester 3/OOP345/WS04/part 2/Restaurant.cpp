#include "Restaurant.h"

namespace sdds {

	Restaurant::Restaurant() {
	}
	Restaurant::Restaurant(const Restaurant& res) {
		if (this != &res && res.cnt != 0) {
			delete[]this->reserve;
			this->cnt = res.cnt;
			this->reserve = new Reservation[this->cnt];
			for (size_t i = 0u; i < this->cnt; i++)
			{
				this->reserve[i] = res.reserve[i];
			}
		}
	}

	Restaurant::Restaurant(Restaurant&& res) {
		if (this != &res && res.cnt != 0) {
			delete[]this->reserve;
			this->cnt = res.cnt;
			this->reserve = res.reserve;

			res.cnt = 0;
			res.reserve = nullptr;
		}
	}

	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
		if (this->reserve != *reservations) {
			this->reserve = new Reservation[cnt];
			this->cnt = cnt;
			for (size_t i = 0u; i < cnt; i++)
			{
				this->reserve[i] = *reservations[i];
			}
			//this->reserve = *reservations;
		}
	}
	Restaurant::~Restaurant() {
		if (this->reserve != nullptr) {
			delete[]this->reserve;
			this->reserve = nullptr;
		}
	}
	size_t Restaurant::size() const {
		return cnt;
	}
	std::ostream& operator << (std::ostream& os, const Restaurant& res) {
		os << "--------------------------" << std::endl
			<< "Fancy Restaurant" << std::endl
			<< "--------------------------" << std::endl;
		
		if (res.size() == 0)
		{
			os << "The object is empty!" << std::endl;
		}
		else
		{
			for (size_t i = 0u; i < res.cnt; i++)
			{
				os << res.reserve[i];
			}
		}
		os << "--------------------------" << std::endl;

		return os;
	}








}