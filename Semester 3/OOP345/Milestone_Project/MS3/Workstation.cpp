/*******************************************************
* Name: Jia Hua, Zou
* Seneca Student ID: 114383193
* Seneca email: jhzou@myseneca.ca
* Date of completion: Nov 28,2020.
*
* I confirm that I am the only author of this file
*   and the content was created entirely by me.
********************************************************/
#include "Workstation.h"

Workstation::Workstation(const std::string& src) :Station(src) {
	m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		m_orders.front().fillItem(*this, os);
	}
}

bool Workstation::moveOrder() {
	bool flag = false;
	if (!m_orders.empty()) {
		if (m_orders.front().isItemFilled(this->getItemName()) && m_pNextStation) {
			*m_pNextStation += std::move(m_orders.front());
			m_orders.pop_front();
			flag = true;
		}
	}
	return flag;
}

void Workstation::setNextStation(Station& station) {
	m_pNextStation = static_cast<Workstation*>(&station);
}

const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order) {
	bool flag = false;
	if (!m_orders.empty()) {
		if (m_orders.front().isOrderFilled()) {
			order = std::move(m_orders.front());
			m_orders.pop_front();
			flag = true;
		}
	}
	return flag;
}

void Workstation::display(std::ostream& os) const {
	if (m_pNextStation == nullptr) {
		os << getItemName() << " --> END OF LINE" << std::endl;
	}
	else
	{
		os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
	}
}

Workstation& Workstation::operator+=(CustomerOrder&& order) {
	m_orders.push_back(std::move(order));
	return *this;
}