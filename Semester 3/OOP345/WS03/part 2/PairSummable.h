/****************************************************************
Name: Jia Hua Zou
ID: 114383193
Date: Oct 10,2020.
Lab 3

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************/

#ifndef SDDS_PAIRSUMMABLE_H__
#define SDDS_PAIRSUMMABLE_H__
#include <iostream>
#include <iomanip>
#include "Pair.h"

namespace sdds
{
	template <typename K, typename V>
	class PairSummable : public Pair<K, V>
	{
		static V initial;
		static size_t m_width;
	public:
		PairSummable() {
			initial = {};
			m_width = {};
		}

		PairSummable(const K& key, const V& value = initial): Pair <K,V>(key,value){
			if (key.size() > m_width)
			{
				m_width = key.size();
			}
		}

		const PairSummable& operator+=(const PairSummable& records) {

			if (this->key() == records.key() && this != &records) {
				PairSummable temp(records.key(), records.value() + this->value());
				*this = temp;
			}
			return *this;
		}

		void display(std::ostream& os) const {
			os << std::left;
			os << std::setw(m_width);
			Pair<K, V>::display(os);
			os << std::right;
		}
	};

	template<>
	std::string PairSummable <std::string, std::string> ::initial = "";
	template<>
	int PairSummable <std::string, int> ::initial = 0;
	template <typename K, typename V>
	size_t PairSummable<K, V>::m_width = 0;

	template<>
	const PairSummable <std::string, std::string>& PairSummable <std::string, std::string> ::operator+=(const PairSummable& records) {
		std::string strTemp = this->value() != "" ? this->value() + ", " + records.value() : records.value();
		PairSummable temp(this->key(), strTemp);

		*this = temp;
		return *this;
	}
}
#endif  // ! SDDS_PAIRSUMMABLE_H_