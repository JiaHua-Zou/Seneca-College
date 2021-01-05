/**********************************************************************

Name: Jia Hua Zou

ID: 114383193

Date: Oct 27,2020

Lab5

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

**********************************************************************/
#ifndef SDDS_MOVIE_H_
#define SDDS_MOVIE_H_
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>

namespace sdds {

	class Movie
	{
	public:
		Movie();
		Movie(const std::string& strMovie);
		~Movie();

		const std::string& title() const;

		template <typename T>
		void fixSpelling(T spellChecker);

		friend std::ostream& operator <<(std::ostream& os, const Movie& src);
	private:
		std::string m_title {'\0'};
		size_t m_year{ 0 };
		std::string m_desc{ '\0' };
	};

	template <typename T>
	void Movie::fixSpelling(T spellChecker) {
		spellChecker(m_title);
		spellChecker(m_desc);
	}
}
#endif // !SDDS_MOVIE_H_