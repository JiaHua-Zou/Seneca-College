#include <iomanip>
#include "Book.h"
using namespace std;
namespace sdds {


	Book::Book() {
	}

	Book::Book(const std::string& strBook) {
		string s_temp = strBook;
		string convert;
		// this line will remove all spaces and shifts the letter.
		s_temp.erase(std::remove_if(s_temp.begin(), s_temp.end(), ::isspace), s_temp.end());
		this->m_author = s_temp.substr(0, s_temp.find(','));
		s_temp.erase(0, s_temp.find(',') + 1);

		this->m_title = s_temp.substr(0, s_temp.find(','));
		s_temp.erase(0, s_temp.find(',') + 1);

		this->m_country = s_temp.substr(0, s_temp.find(','));
		s_temp.erase(0, s_temp.find(',') + 1);

		//price
		convert = s_temp.substr(0, s_temp.find(','));
		s_temp.erase(0, s_temp.find(',') + 1);
		this->m_price = std::stof(convert);

		//yr
		convert = s_temp.substr(0, s_temp.find(','));
		s_temp.erase(0, s_temp.find(',') + 1);
		this->m_yr = std::stoi(convert);

		this->m_summary = s_temp.substr(0, s_temp.find(','));
		s_temp.erase(0, s_temp.find(',') + 1);
	}
	Book::~Book() {
	}

	const std::string& Book::title() const {
		return m_title;
	}
	const std::string& Book::country() const {
		return m_country;
	}
	const size_t& Book::year() const {
		return m_yr;
	}
	double& Book::price() {
		return m_price;
	}

	std::ostream& operator <<(std::ostream& os, const Book& src) {
		os << std::setw(20) << src.m_author << " | "
			<< std::setw(22) << src.m_title << " | "
			<< std::setw(5) << src.m_country << " | "
			<< std::setw(4) << src.m_yr << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << src.m_price << " | "
			<< src.m_summary << std::endl;
		return os;
	}
}