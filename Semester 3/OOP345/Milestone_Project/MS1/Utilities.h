/*******************************************************
* Name: Jia Hua, Zou
* Seneca Student ID: 114383193
* Seneca email: jhzou@myseneca.ca
* Date of completion: Nov 14,2020.
*
* I confirm that I am the only author of this file
*   and the content was created entirely by me.
********************************************************/
#ifndef SDDS_UTILITIES_H_
#define SDDS_UTILITIES_H_
#include <iostream>
#include <string>

class Utilities
{
public:
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
private:
	size_t m_widthField = 1;
	static char m_delimiter;
};

#endif // !SDDS_UTILITIES_H_