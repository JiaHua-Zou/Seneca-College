/*******************************************************
* Name: Jia Hua, Zou
* Seneca Student ID: 114383193
* Seneca email: jhzou@myseneca.ca
* Date of completion: Nov 21,2020.
*
* I confirm that I am the only author of this file
*   and the content was created entirely by me.
********************************************************/
#include "Station.h"


size_t Station::m_widthField = 0;
size_t Station::id_generator = 0;

Station::Station(const std::string& src) {
	Utilities utility;
	bool more = false;
	size_t next_pos = 0;
	if (src.length() != 0) {
		m_id = (++id_generator);
		m_item = utility.extractToken(src, next_pos, more);
		if (more) {
			m_serialNum = std::stoi(utility.extractToken(src, next_pos, more));
		}
		if (more) {
			m_quantity = std::stoi(utility.extractToken(src, next_pos, more));
		}
		if (m_widthField < utility.getFieldWidth()) {
			m_widthField = utility.getFieldWidth();
		}

		if (more) {
			m_desc = utility.extractToken(src, next_pos, more);
		}
	}
}

const std::string& Station::getItemName() const {
	return m_item;
}

unsigned int Station::getNextSerialNumber() {
	return m_serialNum++;
}
unsigned int Station::getQuantity() const {
	return m_quantity;
}
void Station::updateQuantity() {
	if (m_quantity > 0) {
		m_quantity--;
	}
	else
	{
		throw "IT IS EMPTY!";
	}
}

void Station::display(std::ostream& os, bool full) const {
	if (full) {
		os << "[" << std::setw(3) << std::right << std::setfill('0') << m_id << "]" << std::setfill(' ')
			<< " Item: " << std::left << std::setw(m_widthField + 1) << m_item
			<< "[" << std::right << std::setw(6) << std::setfill('0') << m_serialNum << std::setfill(' ') << "] "
			<< "Quantity: " << std::left << std::setw(m_widthField+1) << m_quantity
			<< "Description: " << std::left << m_desc << std::endl;
	}
	else {
		os << "[" << std::setw(3) << std::right << std::setfill('0') << m_id << "]" << std::setfill(' ')
			<< " Item: " << std::left << std::setw(m_widthField+1) << m_item
			<< "[" << std::right << std::setw(6) << std::setfill('0') << m_serialNum << std::setfill(' ') << "]" << std::endl;
	}
}
