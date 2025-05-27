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
	Reader(std::string email) {
		std::string file_result = "";
		std::string argument = "";
		std::vector<std::string> arguments;
		file_result = file_account_books_b_email(email, "account_books_n.txt");

		if (file_result != " ") {
			file_result += ' ';
			for (int i = 0; i < file_result.size() + 1; ++i) {
				if (file_result[i] == ' ' or file_result[i] == '\n') {
					arguments.push_back(argument);
					argument = "";
				}
				else if (file_result[i] != ' ') {
					argument += file_result[i];
				}

			}

			Email = arguments[0];
			Surname = arguments[1];
			Name = arguments[2];
			Middlename = arguments[3];
			Age = arguments[4];
			Password = arguments[5];
			Status = arguments[6];
			Bank_card = arguments[7];
			Money = arguments[8];
			if (arguments.size() > 9) {
				for (int i = 9; i < arguments.size(); ++i) {
					if (arguments[i][0] == 'f') {
						Free_books.push_back(arguments[i]);
					}
					else if (arguments[i][0] != 'f') {
						Paid_books.push_back(arguments[i]);
					}
				}
			}

			argument = "";
			std::vector<std::string>().swap(arguments);//������ ������
		}
		else {
			file_result = file_account_books_b_email(email, "Account_email.txt") + ' ';
			
			for (int i = 0; i < file_result.size() + 1; ++i) {
				if (file_result[i] == ' ' or file_result[i] == '\n') {
					arguments.push_back(argument);
					argument = "";
				}
				else if (file_result[i] != ' ') {
					argument += file_result[i];
				}

			}

			Email = arguments[0];
			Surname = arguments[1];
			Name = arguments[2];
			Middlename = arguments[3];
			Age = arguments[4];
			Password = arguments[5];
			Status = arguments[6];
			Bank_card = "No bank_card";
			Money = "No money";

			argument = "";
			std::vector<std::string>().swap(arguments);//������ ������

		}
	}

	std::string file_account_books_b_email(std::string email, std::string name_file) {
		std::string akk_str = "";//� ��� ������ ����������� ������
		std::string akk = "";//����������� ����� �� ������� � ������
		int count = 0;
		std::ifstream file(name_file); // ������� ���� ��� ������, ������� ������

		if (!file.is_open() or file.peek() == EOF) {//��������, ��� ���� ����
			return " ";
		}
		else {
			while (std::getline(file, akk_str)) {
				for (int i = 0; i < akk_str.size(); ++i) {
					if (akk_str[i] == ' ') {
						count += 1;
					}
					if (count == 0) {
						akk += akk_str[i];
					}
				}
				if (akk == email) {
					return akk_str;
				}
				count = 0;
				akk_str = "";
				akk = "";
			}
		}
		file.close();//�������� �����	
		return " ";
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

	//���������� �������� � ����
	void history() {

	}

	void print() override {
		std::cout << "������ ��������:" << std::endl;
		std::cout << "�����: " << Email << std::endl;
		std::cout << "���: " << Surname << " " << Name << " " << Middlename << std::endl;
		std::cout << "�������: " << Age << std::endl;
		std::cout << "���� ���������� ����� (� ������ �� ����� ��������): " << Bank_card << " (" << Money << ")" << std::endl;
		std::cout << "���-�� ��������� ����: " << Paid_books.size() << std::endl;
		std::cout << "���-�� ������ ����: " << Free_books.size() << std::endl;
		std::cout << "--------------------------------------------------------------------------------" << std::endl;
		std::cout << "����� ����� �� ���������� ���������� (take_a_book)" << std::endl;
		std::cout << "������� ����� � ���������� ���������� (return_the_book)" << std::endl;
		std::cout << "������ ����� (buy_a_book)" << std::endl;
		std::cout << "���������� ���������� ����� (advice_book)" << std::endl;
		std::cout << "������ � ������� ������ (set_money)" << std::endl;
		std::cout << "��������� (set_bank_card)" << std::endl;
		std::cout << "����� (exit)" << std::endl;
		std::cout << "������ ����� �� ������: ";
	}

	~Reader() {
		std::string acc_librarian = Email + " " + Surname + " " + Name + " " + Middlename + " " + Age + " " + Password + " " + Status + " " + Bank_card + " " + Money;
		if (Free_books.size() != 0) {
			for (int i = 0; i < Free_books.size(); ++i) {
				acc_librarian += " " + Free_books[i];
			}
		}
		if (Paid_books.size() != 0) {
			for (int i = 0; i < Paid_books.size(); ++i) {
				acc_librarian += " " + Paid_books[i];
			}
		}
		std::string akk_str = "";//����������� �����
		std::string akk_file = "";
		bool flag = false;
		std::vector<std::string> akk;
		std::ifstream file("account_books_n.txt", std::ios::trunc); // ������� ���� ��� ������, ������� ������

		std::ifstream in_file("account_books_n.txt");
		if (!in_file.is_open() || in_file.peek() == EOF) {
			akk.push_back(acc_librarian + "\n");
		}
		else {
			while (std::getline(in_file, akk_file)) {
				size_t first_space = akk_file.find(' ');
				akk_str = akk_file.substr(0, first_space);

				if (Email == akk_str) {
					akk.push_back(acc_librarian);
					flag = true;
				}
				else {
					akk.push_back(akk_file);
				}
				akk_str = "";
			}
			if (!flag) {
				akk.push_back(acc_librarian);
			}
		}
		in_file.close();

		std::ofstream out_file("account_books_n.txt", std::ios::trunc);

		for (const auto& line : akk) {
			out_file << line << "\n";
		}
		out_file.close();
	}
};