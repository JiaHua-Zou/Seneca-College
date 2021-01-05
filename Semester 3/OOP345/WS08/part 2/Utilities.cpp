// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
/********************************************
Name: Jia Hua, Zou

Date: Nov 22,2020.

Lab: 8

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

********************************************/

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t d = 0; d < desc.size(); d++)
		{
			for (size_t p = 0; p < price.size(); p++)
			{
				if (desc[d].code == price[p].code) {
					Product* user_product = new Product(desc[d].desc, price[p].price);
					//Memeory leak if the validate() throws an error because it does not delete the user_product.
					try
					{
						user_product->validate();
						priceList += user_product;
						delete user_product;
					}
					catch (const std::string&)
					{
						user_product->Trace = false;
						delete user_product;
						user_product->Trace = true;
						throw;
					}
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		for (size_t d = 0; d < desc.size(); d++)
		{
			for (size_t p = 0; p < price.size(); p++)
			{
				if (desc[d].code == price[p].code) {
					std::unique_ptr<Product> user_product (new Product(desc[d].desc, price[p].price));
					//Memeory leak if the validate() throws an error because it does not delete the user_product.
						user_product->validate();
						priceList += std::move(user_product);
				}
			}
		}
		return priceList;
	}
}