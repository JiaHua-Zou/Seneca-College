#ifndef  SDDS_SET_H_
#define SDDS_SET_H_
#include <iostream>

namespace sdds {

	template <typename T, unsigned int N>
	class Set
	{
	private:
		T m_elements[N];
		size_t m_size{ 0 };
	public:
		size_t size() const {
			return m_size;
		}

		const T& operator[](size_t idx)const {
			return m_elements[idx];
		}

		void operator +=(const T& item) {
			if (N >m_size) {
				m_elements[m_size++] = item;
			}
		}

	};









}
#endif // ! SDDS_SET_H_