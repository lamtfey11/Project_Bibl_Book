#include "Human.h"
#include <string>

//дочерний класс библиотекарь
class Librarian: public Human{
public:
	Librarian(std::string Email, std::string Surname, std::string Name, std::string Middlename, std::string Age, std::string Password, std::string Status) {
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

	//смотрит список советов и добялет книги в реестр
	void advice_book() {
		/////////////////
	}

	//удаляет историю конкретной почты
	void delete_history() {
		///////////////////
	}

	//добавление книги в список
	void plus_book() {
		/////////////////
	}

	~Librarian() {
		////////////////////////тут надо в файл переносить данные
	}
};