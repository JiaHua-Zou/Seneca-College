/*******************************************************
* Name: Jia Hua, Zou
* Seneca Student ID: 114383193
* Seneca email: jhzou@myseneca.ca
* Date of completion: Nov 21,2020.
*
* I confirm that I am the only author of this file
*   and the content was created entirely by me.
********************************************************/
#ifndef SDDS_CUSTOMERORDER_H_
#define SDDS_CUSTOMERORDER_H_
#include <iostream>
#include <vector>
#include <iomanip>
#include "Station.h"

struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};
class CustomerOrder
{
public:
	CustomerOrder();
	CustomerOrder(std::string& src);
	CustomerOrder(CustomerOrder& src);
	CustomerOrder(CustomerOrder&&) noexcept;
	CustomerOrder& operator= (const CustomerOrder&) = delete;
	CustomerOrder& operator=(CustomerOrder&&) noexcept;
	~CustomerOrder();

	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
private:
	std::string m_name{ '\0' };
	std::string m_product{ '\0' };
	unsigned int m_cntItem{ 0 }; //# of items for customer's order
	Item** m_lstItem{ nullptr }; //pointer of a pointer.
	static size_t m_widthField;
};
#endif // !SDDS_CUSTOMERORDER_H_