// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


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
						user_product->validate();
						priceList += user_product;
						delete user_product;
				}
			}
		}
		return priceList;
	}
}