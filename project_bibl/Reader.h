#include "Librarian.h"
#include <string>
#include <vector>
#include <fstream>//��� ������ � �������

//�������� ����� ��������
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

	//����� �����
	void take_a_book() {

	}

	//������� �����
	void return_the_book() {

	}

	//������������ �����
	void advice_book() override {
		/////////////////acdive_books
	}

	//������ �����
	void buy_a_book() {

	}

	//������ ������
	void set_money() {

	}

	~Reader() {
		/////////////////
	}
};