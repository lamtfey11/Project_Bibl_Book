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
	}

	//����������� ������� ������ ������� � ������
	virtual void print() {
	}

	virtual ~Human() {
	}
};