#include <iostream>
#include <string>
#include <locale.h>
#include <fstream>//для работы с файлами

//родительный класс человек
class Human {
protected:
	std::string Email;
	std::string Surname;
	std::string Name;
	std::string Middlename;
	std::string Age;
	std::string Password;
	std::string Status;
	std::string Bank_card;
	std::string Money;
public:
	//конструктор по умолчанию
	Human() {
		this->Email = "";
		this->Surname = "";
		this->Name = "";
		this->Middlename = "";
		this->Age = "";
		this->Password = "";
		this->Status = "";
		this->Bank_card = "";
		this->Money = "";
	}

	//установаить карту(поменять)
	void set_bank_card(std::string Bank_card) {
		bool flag = true;
		if (Bank_card.size() != 16) flag = false;
		for (int i = 0; i < Bank_card.size(); ++i) {
			if (int(Bank_card[i]) < 48 or int(Bank_card[i]) > 57) {
				flag = false;
				break;
			}
		}

		if(flag == true) this->Bank_card = Bank_card;
	}

	virtual void print() {
	}

	virtual ~Human() {
	}
};