/*******************************************************
* Name: Jia Hua, Zou
* Seneca Student ID: 114383193
* Seneca email: jhzou@myseneca.ca
* Date of completion: Nov 28,2020.
*
* I confirm that I am the only author of this file
*   and the content was created entirely by me.
********************************************************/
#ifndef SDDS_WORDSTATION_H_
#define SDDS_WORDSTATION_H_
#include <iostream>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

class Workstation : public Station
{
public:
	Workstation(const std::string& src);
	Workstation(Workstation&) = delete;
	Workstation(Workstation&&) = delete;
	Workstation& operator = (Workstation&) = delete;
	Workstation& operator = (Workstation&&) = delete;

	void runProcess(std::ostream& os);
	bool moveOrder();
	void setNextStation(Station& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream& os) const;
	Workstation& operator+=(CustomerOrder&& order);
private:
	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation{ nullptr };
};
#endif // !SDDS_WORDSTATION_H_