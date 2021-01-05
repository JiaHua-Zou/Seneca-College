/**********************************************************************

Name: Jia Hua Zou

ID: 114383193

Date: Oct 27,2020

Lab5

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

**********************************************************************/
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>

namespace sdds {
	class Book
	{
	public:
		Book();
		Book(const std::string& strBook);
		~Book();

		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();

		template<typename T>
		void fixSpelling(T spellChecker);

		friend std::ostream& operator <<(std::ostream& os, const Book& src);
	private:
		std::string m_author{ '\0' };
		std::string m_title{ '\0' };
		std::string m_country{ '\0' };
		size_t m_year { 0 };
		double m_price = 0 ;
		std::string m_summary{ '\0' };
	};
	template<typename T>
	void Book::fixSpelling(T spellChecker) {
		spellChecker(m_summary);
	}
}
#endif // !SDDS_BOOK_H_