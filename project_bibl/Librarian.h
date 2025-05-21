#include "Human.h"
#include <string>
#include <vector>
#include <fstream>//��� ������ � �������

//�������� ����� ������������
class Librarian: public Human{
public:
	Librarian(std::string email) {
		std::string file_result = "";
		std::string argument = "";
		std::vector<std::string> arguments;
		file_result = file_account_books_b_email(email, "account_books_b.txt");


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
			Bank_card = "No_bank_card";
			Money = "No_money";

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

	//������� ������ ������� � ������� ����� � ������
	void advice_book() override {
		/////////////////acdive_books
	}

	//������� ������� ���������� �����
	void delete_history() {
		///////////////////history
	}

	//���������� ����� � ������
	void plus_book() {
		/////////////////free_paid_books
	}

	~Librarian() {
		std::string acc_librarian = Email + " " + Surname + " " + Name + " " + Middlename + " " + Age + " " + Password + " " + Status + " " + Bank_card + " " + Money;
		std::string akk_str = "";//����������� �����
		std::string akk_file = "";
		bool flag = false;
		std::vector<std::string> akk;
		std::ifstream file("account_books_b.txt", std::ios::trunc); // ������� ���� ��� ������, ������� ������
		
		std::ifstream in_file("account_books_b.txt");
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

		// 2. ������ ��������� ���� �� ������ � trunc (��� ������� ���)
		std::ofstream out_file("account_books_b.txt", std::ios::trunc);

		// 3. ���������� ��� ������ �������
		for (const auto& line : akk) {
			out_file << line << "\n";
		}
		out_file.close();
	}
};
