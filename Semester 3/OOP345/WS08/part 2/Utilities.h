#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
/********************************************
Name: Jia Hua, Zou

Date: Nov 22,2020.

Lab: 8

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

********************************************/

#include "List.h"
#include "Element.h"

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif