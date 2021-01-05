/**********************************************************************

Name: Jia Hua Zou

ID: 114383193

Date: Oct 27,2020

Lab5

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

**********************************************************************/
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
#include <iostream>
#include <string>

namespace sdds {
	template <typename T>
	class Collection
	{
	public:
		Collection();
		Collection(std::string name);
		~Collection();

		const std::string& name() const;
		size_t size() const;
		void setObserver(void (*observer)(const Collection<T>&, const T&));
		Collection<T>& operator+=(const T& item);
		T& operator[](size_t idx) const;
		T* operator[](std::string title) const;

		friend std::ostream& operator <<(std::ostream& os, const Collection& src){
			for (size_t i = 0; i < src.arr_size; i++)
			{
				os << src[i];
			}
			return os;
		}
	private:
		std::string m_name= { "\0" };
		T* m_items ={ nullptr };
		size_t arr_size{ 0 };

		//function pointer
		void (*m_observer)(const Collection<T>&, const T&) =  nullptr;
	};

	template<typename T>
	Collection<T>::Collection(std::string name) {
		m_name = name;
	}

	template<typename T>
	Collection<T>::~Collection() {
		delete[] m_items;
	}

	template<typename T>
	const std::string& Collection<T>::name() const {
		return m_name;
	}

	template<typename T>
	size_t Collection<T>::size() const {
		return arr_size;
	}

	template<typename T>
	void Collection<T>::setObserver(void (*observer)(const Collection<T>&, const T&)) {
		m_observer = observer;
	}

	template<typename T>
	Collection<T>& Collection<T>::operator+=(const T& item) {
		bool flag = false;
		for (size_t i = 0; i < arr_size; i++)
		{
			if (m_items[i].title() == item.title()) {
				flag = true;
			}
		}

		if (flag == false) {
			T* tmp_items = m_items;
			m_items = new T[arr_size +1];
			for (size_t i = 0; i < arr_size; i++)
			{
				m_items[i] = tmp_items[i];
			}
			m_items[arr_size++] = item;
			delete[] tmp_items;
			
		// observer*************
			if (m_observer != nullptr) {
				m_observer(*this, m_items[arr_size - 1]);
			}
		}
		return *this;
	}

	template<typename T>
	T& Collection<T>::operator[](size_t idx) const {
		std::string err_message;
		if (arr_size <= idx) {
			err_message = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(arr_size) + "] items.";
			throw std::out_of_range(err_message);
		}
		return m_items[idx];
	}

	template<typename T>
	T* Collection<T>::operator[](std::string title) const {
		T* temp{ nullptr };
		for (size_t i = 0; i < arr_size; i++)
		{
			if (this->m_items[i].title() == title) {
				temp = &m_items[i];
				i = arr_size;
			}
		}
		return temp;
	}
}
#endif // !SDDS_COLLECTION_H_