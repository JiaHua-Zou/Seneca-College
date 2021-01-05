#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_
#include <iostream>

namespace sdds {

	template <typename K, typename V>
	class Pair
	{
	private:
		K m_key;
		V m_value;
	public:
		Pair() {
			m_key = {};
			m_value = {};
		}
		Pair(const K& key, const V& value) {
			m_key = key;
			m_value = value;
		}
		const K& key() const;
		
		const V& value() const {
			return m_value;
		}
		void display(std::ostream& os) const {
			os << m_key << " : " << m_value << std::endl;
		}
	};

	template <typename K, typename V>
	const K& Pair<K, V>::key() const {
		return m_key;
	}
	template <typename K, typename V>
	std::ostream& operator <<(std::ostream& os, const Pair <K, V>& Pair) {
		Pair.display(os);
		return os;
	}

}
#endif // !SDDS_PAIR_H_