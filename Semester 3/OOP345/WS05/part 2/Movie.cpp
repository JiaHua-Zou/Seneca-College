/**********************************************************************

Name: Jia Hua Zou

ID: 114383193

Date: Oct 27,2020

Lab5

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

**********************************************************************/
#include <iomanip>
#include "Movie.h"
using namespace std;

namespace sdds {
	Movie::Movie() {};
	Movie::~Movie() {};

	Movie::Movie(const string& strMovie) {
		auto trim = [](std::string& word) {
			size_t start = word.find_first_not_of(" ");
			word =(start == std::string::npos) ? "" : word.substr(start);
			size_t end = word.find_last_not_of(" ");
			word = (end == std::string::npos) ? "" : word.substr(0,end+1);
		};

		std::string s_temp = strMovie;
		std::string convert;
		
		this->m_title = s_temp.substr(0, s_temp.find(','));
		trim(m_title);
		s_temp.erase(0, s_temp.find(',') + 1);

		convert = s_temp.substr(0, s_temp.find(','));
		trim(convert);
		s_temp.erase(0, s_temp.find(',') + 1);
		this->m_year = stoi(convert);

		this->m_desc = s_temp.substr();
		trim(m_desc);
	}

	const std::string& Movie::title() const {
		return m_title;
	}

	ostream& operator<<(ostream& os, const Movie& movie) {
		os << setw(40) << movie.m_title << " | "
		   << setw(4) << movie.m_year << " | "
		   << movie.m_desc << endl;
		return os;
	}
}