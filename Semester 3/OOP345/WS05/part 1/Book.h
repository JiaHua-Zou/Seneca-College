#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include <algorithm>
#include <string>


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

		friend std::ostream& operator <<(std::ostream& os, const Book& src);
	private:
		std::string m_author{ '\0' };
		std::string m_title{ '\0' };
		std::string m_country{ '\0' };
		unsigned int m_yr = { 0 };
		double m_price = { 0 };
		std::string m_summary;
	};








}
#endif // !SDDS_BOOK_H_