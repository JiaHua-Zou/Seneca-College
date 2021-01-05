/****************************************************************
Name: Jia Hua Zou
ID: 114383193
Date: Oct 8,2020.
Lab 2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************/
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include "RecordSet.h"

namespace sdds {
	RecordSet::RecordSet()
	{
		counter = 0;
		file = nullptr;
	}

	RecordSet::RecordSet(const std::string& input)
	{
		std::string tempRec{ 0 };
		std::ifstream f(input);
		while (!f.eof())
		{
			std::getline(f, tempRec, ' ');
			counter++;
		}

		f.clear();
		f.seekg(0);
		file = new std::string[counter];
		for (auto i = 0u; i < counter; i++)
		{
			std::getline(f, file[i], ' ');
		}

		f.close();
	}

	RecordSet::RecordSet(const RecordSet& copy)
	{
		*this = copy;
	}

	RecordSet::RecordSet(RecordSet&& copy)
	{
		*this = std::move(copy);
	}

	RecordSet::~RecordSet()
	{
		delete[] file;
		file = nullptr;
	}


	size_t RecordSet::size() const
	{
		return this->counter;
	}

	std::string RecordSet::getRecord(size_t size)
	{
		if (counter <= size || file == nullptr) {
			return "";
		}
		else
		{
			return (file[size]);
		}
	}

	RecordSet& RecordSet::operator =(const RecordSet& copy)
	{
		if (this != &copy) {
			counter = copy.counter;
			delete[] file;
			file = nullptr;
			if (counter != 0) {
				file = new std::string[copy.counter];
				for (auto i = 0u; i < counter; i++)
				{
					file[i] = copy.file[i];
				}
			}
		}
		return *this;
	}

	RecordSet& RecordSet::operator =(RecordSet&& copy) {
		if (this != &copy) {
			delete[]file;
			file = copy.file;
			copy.file = nullptr;
			counter = copy.counter;
			copy.counter = 0;
		}
		return *this;
	}
}