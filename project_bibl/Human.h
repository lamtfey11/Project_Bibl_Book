#include <iostream>
#include <string>
#include <locale.h>
#include <fstream>//��� ������ � �������

//����������� ����� �������
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
	//����������� �� ���������
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

	//����������� �����(��������)
	void set_bank_card(std::string Bank_card) {
		this->Bank_card = Bank_card;
	}

	//�������� ������
	std::string get_money() const {
		std::cout << "Bank_card: " << Bank_card << ". Money: " << Money << "." << std::endl;
	}

	virtual void advice_book() {
	}

	virtual void print() {
	}

	virtual ~Human() {
	}
};