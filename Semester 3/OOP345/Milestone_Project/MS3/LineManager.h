/*******************************************************
* Name: Jia Hua, Zou
* Seneca Student ID: 114383193
* Seneca email: jhzou@myseneca.ca
* Date of completion: Nov 28,2020.
*
* I confirm that I am the only author of this file
*   and the content was created entirely by me.
********************************************************/
#ifndef SDDS_LINEMANAGER_H_
#define SDDS_LINEMANAGER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include "Workstation.h"
#include "CustomerOrder.h"

class LineManager
{
public:
	LineManager(const std::string& filename, std::vector<Workstation*>& s_workstation, std::vector<CustomerOrder>& s_customerOrder);

	bool run(std::ostream& os);
	void displayCompletedOrders(std::ostream& os) const;
	void displayStations() const;
	void displayStationsSorted() const;
private:
	std::vector<Workstation*> AssemblyLine; //A container containing all the references of the Workstation objects on the assembly line
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder{ 0 };

	Workstation* m_firstStation { nullptr };
};
#endif // !SDDS_LINEMANAGER_H_