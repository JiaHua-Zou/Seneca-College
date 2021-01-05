/*******************************************************
* Name: Jia Hua, Zou
* Seneca Student ID: 114383193
* Seneca email: jhzou@myseneca.ca
* Date of completion: Nov 14,2020.
*
* I confirm that I am the only author of this file
*   and the content was created entirely by me.
********************************************************/
#include "Utilities.h"


char Utilities::m_delimiter = '\0';

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	std::string token{ '\0' };

	if (str.size() != 0) {
		size_t pos = str.find(m_delimiter, next_pos);
		more = true;
		if (pos != std::string::npos) {
			token = str.substr(next_pos, pos - next_pos);
			next_pos = pos + 1;
		}
		else
		{
			token = str.substr(next_pos);
		}

		if (token.empty()) {
			more = false;
			throw "ERROR!";
		}
		if (m_widthField < token.length()) {
			this->m_widthField = token.length();
		}
	}
	return token;
}

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}