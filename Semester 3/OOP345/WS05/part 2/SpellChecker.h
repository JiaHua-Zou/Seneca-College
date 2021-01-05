/**********************************************************************

Name: Jia Hua Zou

ID: 114383193

Date: Oct 27,2020

Lab5

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

**********************************************************************/
#ifndef SDDS_SPELLCHECKER_H_
#define SDDS_SPELLCHECKER_H_
#include <iostream>
#include <string>
#include <algorithm>

namespace sdds {
	const int MAX = 5;
	class SpellChecker
	{
	public:
		SpellChecker();
		SpellChecker(const char* filename);
		~SpellChecker();

		void operator()(std::string& text) const;
	private:
		std::string m_badWords[MAX]{ "\0" };
		std::string m_goodWords[MAX]{ "\0" };
	};
}
#endif // !SDDS_SPELLCHECKER_H_