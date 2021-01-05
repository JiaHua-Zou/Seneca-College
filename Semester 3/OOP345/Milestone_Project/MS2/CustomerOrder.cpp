/*******************************************************
* Name: Jia Hua, Zou
* Seneca Student ID: 114383193
* Seneca email: jhzou@myseneca.ca
* Date of completion: Nov 21,2020.
*
* I confirm that I am the only author of this file
*   and the content was created entirely by me.
********************************************************/
#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() {}

CustomerOrder::~CustomerOrder() {
	for (size_t i = 0; i < m_cntItem; i++)
	{
		delete m_lstItem[i];
	}
	delete[] m_lstItem;
}

CustomerOrder::CustomerOrder(std::string& src) {
	Utilities utility;
	bool more = false;
	size_t next_pos = 0;
	if (src.length() != 0) {
		m_name = utility.extractToken(src, next_pos, more);
		m_product = utility.extractToken(src, next_pos, more);

		std::vector<std::string> tmp;
		while (more)
		{
			tmp.push_back(utility.extractToken(src, next_pos, more));
		}
		m_cntItem = tmp.size();
		m_lstItem = new Item * [m_cntItem];

		for (size_t i = 0; i < m_cntItem; i++)
		{
			m_lstItem[i] = new Item(tmp[i]);
		}

		if (m_widthField < utility.getFieldWidth()) {
			m_widthField = utility.getFieldWidth();
		}
	}
}

CustomerOrder::CustomerOrder(CustomerOrder& src) {
	throw "Copy Operator is not allowed!";
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
	*this = std::move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
	if (this != &src) {
		if (m_lstItem) {
			delete[] m_lstItem;
		}
		m_name = std::move(src.m_name);
		m_product = std::move(src.m_product);
		m_cntItem = src.m_cntItem;
		m_lstItem = src.m_lstItem;
		src.m_cntItem = 0;
		src.m_lstItem = nullptr;
	}
	return *this;
}

bool CustomerOrder::isOrderFilled() const {
	bool flag = true;
	for (size_t i = 0; i < m_cntItem; i++)
	{
		if (m_lstItem[i]->m_isFilled == false) {
			flag = m_lstItem[i]->m_isFilled;
			i = m_cntItem;
		}
	}
	return flag;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	bool flag = false;
	for (size_t i = 0; i < m_cntItem; i++)
	{
		if (m_lstItem[i]->m_itemName == itemName)
			flag = true;
	}
	return flag;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	for (size_t i = 0; i < m_cntItem; i++)
	{
		if (station.getItemName() == m_lstItem[i]->m_itemName) {
			if (station.getQuantity()) {
				m_lstItem[i]->m_isFilled = true;
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				os << "    Filled ";
			}
			else {
				os << "Unable to fill ";
			}
			os << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;
		}
	}
}

void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0; i < m_cntItem; i++)
	{
		os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] " << std::setfill(' ')
			<< std::setw(m_widthField+1) << std::left << m_lstItem[i]->m_itemName << "- ";
		if (m_lstItem[i]->m_isFilled == true) {
			os << "FILLED" << std::endl;
		}
		else {
			os << "MISSING" << std::endl;
		}
	}
}