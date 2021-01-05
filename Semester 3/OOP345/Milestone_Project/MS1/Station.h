/*******************************************************
* Name: Jia Hua, Zou
* Seneca Student ID: 114383193
* Seneca email: jhzou@myseneca.ca
* Date of completion: Nov 14,2020.
*
* I confirm that I am the only author of this file
*   and the content was created entirely by me.
********************************************************/
#ifndef SDDS_STATION_H_
#define SDDS_STATION_H_
#include <iostream>
#include <string>
#include <iomanip>
#include "Utilities.h"

class Station
{

public:
	Station(const std::string& src);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
private:
	size_t m_id{ 0 };
	std::string m_item{ '\0' };
	std::string m_desc{ '\0' };
	unsigned int m_serialNum{ 0 };
	unsigned int m_quantity{ 0 };
	static size_t m_widthField;
	static size_t id_generator;
};
#endif // !SDDS_STATION_H_