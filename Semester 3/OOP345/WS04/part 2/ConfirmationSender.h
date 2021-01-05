/****************************************************************
Name: Jia Hua Zou
ID: 114383193
Date: Oct 18,2020.
Lab 4

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************/
#ifndef SDDS_CONFIRMATIONSENDER_H_
#define SDDS_CONFIRMATIONSENDER_H_
#include <iostream>
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender
	{
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& confirm);//copy
		ConfirmationSender(ConfirmationSender&& confirm) noexcept;//move
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator << (std::ostream& os, const ConfirmationSender& confirm);

		ConfirmationSender& operator= (const ConfirmationSender& confirm);// copy
		ConfirmationSender& operator= (ConfirmationSender&& confirm) noexcept;//move
	private:
		const Reservation** reserve = { nullptr };
		size_t cnt = { 0 };
	};
}
#endif // !SDDS_CONFIRMATIONSENDER_H_