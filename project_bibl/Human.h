#include <iostream>
#include <string>
#include <locale.h>

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
	Human(std::string Email, std::string Surname, std::string Name, std::string Middlename, std::string Age, std::string Password, std::string Status) {
		this->Email = Email;
		this->Surname = Surname;
		this->Name = Name;
		this->Middlename = Middlename;
		this->Age = Age;
		this->Password = Password;
		this->Status = Status;
		this->Bank_card = "Not bank_card";
		this->Money = "0";
	}

	virtual void set_bank_card(std::string Bank_card) {
		this->Bank_card = Bank_card;
	}

	virtual void set_money(std::string Money) {
		if (Bank_card != "Not bank_card") {
			this->Money = Money;
		}
		else {
			std::cout << Bank_card << std::endl;
		}
	}

	virtual std::string get_money() {
		std::cout << "Bank_card: " << Bank_card << ". Money: " << Money << "." << std::endl;
	}

};