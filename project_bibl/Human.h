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
	}

	//виртуальная функция вывода заданий и данных
	virtual void print() {
	}

	virtual ~Human() {
	}
};