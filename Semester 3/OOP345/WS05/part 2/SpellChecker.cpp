/**********************************************************************

Name: Jia Hua Zou

ID: 114383193

Date: Oct 27,2020

Lab5

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

**********************************************************************/
#include <fstream>
#include "SpellChecker.h"

namespace sdds {

	SpellChecker::SpellChecker() {}
	SpellChecker::~SpellChecker() {}

	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		else
		{
			std::string strTemp = { "\0" };
			unsigned int cnt = { 0 };
			do
			{
				std::getline(file, strTemp);

				if(file){
					this->m_badWords[cnt] = strTemp.substr(0, strTemp.find(' '));
					strTemp.erase(0, strTemp.find(' ') + 1);
		
					strTemp.erase(std::remove_if(strTemp.begin(), strTemp.end(), isspace), strTemp.end());
				
					this->m_goodWords[cnt++] = strTemp;
				}
			} while (file);
		}
	}

	void SpellChecker::operator()(std::string& text) const {
		for (size_t i = 0; i < MAX; i++)
		{
			while (text.find(m_badWords[i]) != std::string::npos)
			{
				text = text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
			}
		}
	}
}