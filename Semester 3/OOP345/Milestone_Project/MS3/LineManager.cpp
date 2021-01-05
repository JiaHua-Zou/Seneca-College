/*******************************************************
* Name: Jia Hua, Zou
* Seneca Student ID: 114383193
* Seneca email: jhzou@myseneca.ca
* Date of completion: Nov 28,2020.
*
* I confirm that I am the only author of this file
*   and the content was created entirely by me.
********************************************************/
#include "LineManager.h"

LineManager::LineManager(const std::string& filename, std::vector<Workstation*>& s_workstation, std::vector<CustomerOrder>& s_customerOrder) {
	Utilities utility;
	std::string record = "";
	std::string currentStation = "";
	std::string nextStation = "";
	size_t next_pos = 0;
	bool more = false;

	std::ifstream file(filename);
	if (!file) {
		throw "Unable to open file";
	}
	while (!file.eof())
	{
		next_pos = 0;
		getline(file, record);

		currentStation = utility.extractToken(record, next_pos, more); //extract first part
		if (more)
			nextStation = utility.extractToken(record, next_pos, more); //grab second or set to empty state
		else
			nextStation = "";

		for (size_t i = 0; i < s_workstation.size(); i++)
		{
			if (s_workstation[i]->getItemName() == currentStation) {
				for (size_t y = 0; y < s_workstation.size(); y++)
				{
					if (s_workstation[y]->getItemName() == nextStation) {
						s_workstation[i]->setNextStation(*s_workstation[y]);
						break;
					}
				}
				if (m_firstStation == nullptr)
					m_firstStation = s_workstation[i];

			}
		}

	}
	file.close();

	for (size_t i = 0; i < s_customerOrder.size(); i++)
	{
		ToBeFilled.push_back(std::move(s_customerOrder[i]));
	}
	m_cntCustomerOrder = ToBeFilled.size();
	AssemblyLine = s_workstation;
}

bool LineManager::run(std::ostream& os) {
	bool flag = false;
	static size_t iter_counter = 0;
	os << "Line Manager Iteration: " << ++iter_counter << std::endl;
	if (!ToBeFilled.empty()) {
		*m_firstStation += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->runProcess(os);
	}

	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->moveOrder();
		CustomerOrder order;
		if (AssemblyLine[i]->getIfCompleted(order)) {
			Completed.push_back(std::move(order));
		}
	}

	if (Completed.size() == m_cntCustomerOrder) {
		return true;
	}else
	return flag;
}

void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (size_t i = 0; i < Completed.size(); i++)
	{
		Completed[i].display(os);
	}
}

void LineManager::displayStations() const {
	for (size_t i = 0; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->display(std::cout);
	}
}

void LineManager::displayStationsSorted() const {
	const Workstation* sortedStation = m_firstStation;
	while (sortedStation != nullptr)
	{
		sortedStation->display(std::cout);
		sortedStation = sortedStation->getNextStation();
	}
}