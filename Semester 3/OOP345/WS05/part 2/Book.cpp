/**********************************************************************

Name: Jia Hua Zou

ID: 114383193

Date: Oct 27,2020

Lab5

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

**********************************************************************/
#include "Book.h"
using namespace std;
namespace sdds {


	Book::Book() {}

	Book::Book(const std::string& strBook) {
		auto trim = [](std::string& word) {
			size_t start = word.find_first_not_of(" ");
			word = (start == std::string::npos) ? "" : word.substr(start);
			size_t end = word.find_last_not_of(" ");
			word = (end == std::string::npos) ? "" : word.substr(0, end + 1);
		};
		string s_temp = strBook;
		string convert;

		//author
		this->m_author = s_temp.substr(0, s_temp.find(','));
		s_temp.erase(0, s_temp.find(',') + 1);
		trim(m_author);

		//title
		this->m_title = s_temp.substr(0, s_temp.find(','));
		s_temp.erase(0, s_temp.find(',') + 1);
		trim(m_title);

		//country
		this->m_country = s_temp.substr(0, s_temp.find(','));
		s_temp.erase(0, s_temp.find(',') + 1);
		trim(m_country);

		//price
		convert = s_temp.substr(0, s_temp.find(','));
		s_temp.erase(0, s_temp.find(',') + 1);
		trim(convert);
		this->m_price = std::stod(convert);

		//yr
		convert = s_temp.substr(0, s_temp.find(','));
		s_temp.erase(0, s_temp.find(',') + 1);
		trim(convert);
		this->m_year = std::stoi(convert);

		//desc
		this->m_summary = s_temp.substr();
		trim(m_summary);
		//s_temp.erase(0, s_temp.find(',') + 1);
	}
	Book::~Book() {}

	const std::string& Book::title() const {
		return m_title;
	}
	const std::string& Book::country() const {
		return m_country;
	}
	const size_t& Book::year() const {
		return m_year;
	}
	double& Book::price() {
		return m_price;
	}

	std::ostream& operator <<(std::ostream& os, const Book& src) {
		os << std::setw(20) << src.m_author << " | "
			<< std::setw(22) << src.m_title << " | "
			<< std::setw(5) << src.m_country << " | "
			<< std::setw(4) << src.m_year << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) <<  src.m_price << " | "
			<< src.m_summary << std::endl;
		return os;
	}
}