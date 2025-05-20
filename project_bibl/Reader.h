#include "Librarian.h"
#include <string>
#include <vector>
#include <fstream>//для работы с файлами

//дочерний класс читатель
class Reader : public Human {
private:
	std::vector<std::string> Free_books;
	std::vector<std::string> Paid_books;
public:
	Reader(std::string Email, std::string Surname, std::string Name, std::string Middlename, std::string Age, std::string Password, std::string Status) {
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

	//взять книгу
	void take_a_book() {

	}

	//вернуть книгу
	void return_the_book() {

	}

	//посоветовать книгу
	void advice_book() override {
		/////////////////acdive_books
	}

	//купить книгу
	void buy_a_book() {

	}

	//внести деньги
	void set_money() {

	}

	~Reader() {
		/////////////////
	}
};