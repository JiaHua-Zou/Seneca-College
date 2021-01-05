#include "ConfirmationSender.h"

namespace sdds {
	ConfirmationSender::ConfirmationSender() {
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& confirm) {
		*this = confirm;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& confirm) noexcept {
		*this = std::move(confirm);
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] reserve;
		reserve = nullptr;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool flag = false;

		for (auto i = 0u; i < this->cnt && flag == false; i++)
		{
			if (reserve[i] == &res) {
				flag = true;
			}
		}

		if (flag == false) {
			const Reservation** temp = nullptr;
			temp = new const Reservation * [this->cnt + 1];
			for (size_t i = 0u; i < this->cnt; i++)
			{
				temp[i] = this->reserve[i];
			}

			temp[this->cnt] = &res;
			delete[] this->reserve;
			this->cnt++;
			reserve = temp;
			temp = nullptr;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		for (size_t i = 0u; i < this->cnt; i++)
		{
			if (reserve[i] == &res) {
				this->reserve[i] = nullptr;
				this->cnt--;
			}
		}

		//resize the space
		const Reservation** temp = new const Reservation * [this->cnt];
		size_t counter = 0;
		for (size_t i = 0u; i < this->cnt; i++)
		{
			if (this->reserve[i] != nullptr) {
				temp[counter] = this->reserve[i];
				counter++;
			}
		}
		delete[]this->reserve;
		this->reserve = temp;
		temp = nullptr;
		return *this;
	}

	std::ostream& operator << (std::ostream& os, const ConfirmationSender& confirm) {
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (confirm.reserve == nullptr) {
			os << "The object is empty!" << std::endl;
			os << "--------------------------" << std::endl;
		}
		else
		{
			for (size_t i = 0u; i < confirm.cnt; i++)
			{
				if (confirm.reserve[i] != nullptr) {

					os << *confirm.reserve[i];
				}
			}
			os << "--------------------------" << std::endl;
		}
		return os;
	}

	ConfirmationSender& ConfirmationSender::operator= (const ConfirmationSender& confirm) {
		if (this != &confirm) {
			delete[] this->reserve;
			this->cnt = confirm.cnt;
			if (this->cnt != 0) {
				this->reserve = new const Reservation * [cnt];
				for (size_t i = 0u; i < confirm.cnt; i++)
				{
					this->reserve[i] = confirm.reserve[i];
				}
			}
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator= (ConfirmationSender&& confirm) noexcept {
		if (this != &confirm) {
			delete[] this->reserve;
			this->reserve = confirm.reserve;
			this->cnt = confirm.cnt;
			confirm.cnt = 0;
			confirm.reserve = nullptr;
		}
		return *this;
	}
}