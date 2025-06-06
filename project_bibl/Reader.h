#include "Librarian.h"
#include <string>
#include <vector>
#include <fstream>//��� ������ � �������
#include <windows.h> // ��� system("cls")

//�������� ����� ��������
class Reader : public Human {
private:
	std::string Bank_card;
	std::string Money;
	std::vector<std::string> Free_books;
	std::vector<std::string> Paid_books;
public:
	//������������ � ����������
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

	//����������� �����(��������)
	void set_bank_card(std::string Bank_card) {
		bool flag = true;
		if (Bank_card.size() != 16) flag = false;
		for (int i = 0; i < Bank_card.size(); ++i) {
			if (int(Bank_card[i]) < 48 or int(Bank_card[i]) > 57) {
				flag = false;
				break;
			}
		}

		if (flag == true) this->Bank_card = Bank_card;
	}

	//����� �����
	void take_a_book() {
		std::ifstream in_free("free_books.txt"); // �������� ���� ��� ������
		std::string in_file_str = "";
		std::vector<std::string> books_free;
		std::vector<std::string> books_free_copy;
		while (std::getline(in_free, in_file_str))
		{
			books_free.push_back(in_file_str);
		}
		in_free.close();     // ��������� ����

		std::cout << "����� ���������� ����������:" << std::endl;
		for (int i = 0; i < books_free.size(); ++i) {
			std::cout << books_free[i] << std::endl;
		}

		std::string book = "";
		std::cin.ignore();
		std::cout << "����� ����� (price,Name,Aythor,Age): ";
		std::getline(std::cin, book);
		std::string str1 = "��������� �������� '��� ����' ���������� ����� ������.";
		std::string str2 = "------------------------------------------------------";
		system("cls"); // ������� ����� ������� �� Windows
		std::cout << str1 << std::endl << str2 << std::endl;
		for (int i = 0; i < books_free.size(); ++i) {
			if (books_free[i] != book) {
				books_free_copy.push_back(books_free[i]);
			}
			else if (books_free[i] == book) {
				if ((int(books_free[i][books_free[i].size() - 2]) - 48) * 10 + int(books_free[i][books_free[i].size() - 1] - 48) <= std::stoi(Age)) {
					Free_books.push_back(book);
				}
				else {
					books_free_copy.push_back(books_free[i]);
					std::cout << "����� �� �������� �� ��������!"
						      << "------------------------------" << std::endl;
				}
			}
		}
	
		std::ofstream out_free("free_books.txt", std::ios::trunc);
		for (const auto& line : books_free_copy) {
			out_free << line << "\n";
		}
		out_free.close();
		std::vector<std::string>().swap(books_free);//������ ������
		std::vector<std::string>().swap(books_free_copy);//������ ������
	}

	//������� �����
	void return_the_book() {
		std::cout << "���������� ����� ����� ����������:" << std::endl;
		for (int i = 0; i < Free_books.size(); ++i) {
			std::cout << Free_books[i] << std::endl;
		}
		std::string book = "";
		std::vector<std::string> Free_books_copy;
		std::cin.ignore();
		std::cout << "����� �����,������� ������ ������� (price,Name,Aythor,Age): ";
		std::getline(std::cin, book);
		for (int i = 0; i < Free_books.size(); ++i) {
			if (Free_books[i] != book) {
				Free_books_copy.push_back(Free_books[i]);
			}
			else {
				std::ofstream out_free("free_books.txt", std::ios::app);
				out_free << book + "\n";
				out_free.close();
			}
		}
		std::vector<std::string>().swap(Free_books);//������ ������
		for (int i = 0; i < Free_books_copy.size(); ++i) {
			Free_books.push_back(Free_books_copy[i]);
		}
	}
	
	//������ �����
	void buy_a_book() {
		if (Money != "No_money") {
			std::ifstream in_free("paid_books.txt"); // �������� ���� ��� ������
			std::string in_file_str = "";
			std::vector<std::string> books_paid;
			std::vector<std::string> books_paid_copy;
			while (std::getline(in_free, in_file_str))
			{
				books_paid.push_back(in_file_str);
			}
			in_free.close();     // ��������� ����

			std::cout << "����� ������� ����������:" << std::endl;
			for (int i = 0; i < books_paid.size(); ++i) {
				std::cout << books_paid[i] << std::endl;
			}

			std::string book = "";
			std::cin.ignore();
			std::cout << "����� ����� (price,Name,Aythor,Age): ";
			std::getline(std::cin, book);
			std::string str1 = "��������� �������� '��� ����' ���������� ����� ������.";
			std::string str2 = "------------------------------------------------------";
			system("cls"); // ������� ����� ������� �� Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			for (int i = 0; i < books_paid.size(); ++i) {
				if (books_paid[i] != book) {
					books_paid_copy.push_back(books_paid[i]);
				}
				else if (books_paid[i] == book) {
					book = "";
					for (int j = 0; j < books_paid[i].size(); ++j) {
						if (books_paid[i][j] != ',') {
							book += books_paid[i][j];
						}
						else if (books_paid[i][j] == ',') {
							break;
						}
					}
					if (((int(books_paid[i][books_paid[i].size() - 2]) - 48) * 10 + int(books_paid[i][books_paid[i].size() - 1] - 48) <= std::stoi(Age))
						and (std::stoi(Money) - std::stoi(book) > 0)) {
						Money = std::to_string(std::stoi(Money) - std::stoi(book));
						Paid_books.push_back(books_paid[i]);
					}
					else {
						books_paid_copy.push_back(books_paid[i]);
						std::cout << "����� �� �������� �� �������� ��� ������������ ��������!"
							<< "--------------------------------------------------------" << std::endl;
					}
				}
			}

			std::ofstream out_free("paid_books.txt", std::ios::trunc);
			for (const auto& line : books_paid_copy) {
				out_free << line << "\n";
			}
			out_free.close();
			std::vector<std::string>().swap(books_paid);//������ ������
			std::vector<std::string>().swap(books_paid_copy);//������ ������
		}
	}

	//������������ �����
	void advice_book() {
		std::string str1 = "��������� �������� '��� ����' ���������� ����� ������.";
		std::string str2 = "------------------------------------------------------";
		bool flag = true;
		std::string book = "";
		std::string book_in_file = "";
		std::cout << "����� ���������� (f) ��� ������� (����) ����� �����: ";
		std::cin >> book;
		if (book != "f") {
			for (int i = 0; i < book.size(); ++i) {
				if (int(book[i]) < 48 or int(book[i]) > 57) {
					flag = false;
					break;
				}
			}
		}
		if (flag == true) {
			book_in_file += book + ",";
		}
		book = "";
		std::cin.ignore();
		std::cout << "����� �������� ����� (������): ";
		std::getline(std::cin, book);
		for (int i = 0; i < book.size(); ++i) {
			if (book == " ") {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			book_in_file += book + ",";
		}
		book = "";
		std::cout << "����� ������� ������ �����: ";
		std::getline(std::cin, book);
		for (int i = 0; i < book.size(); ++i) {
			if (book == " ") {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			book_in_file += book + ",";
		}
		book = "";
		std::cout << "����� ���������� ����������� �����: ";
		std::getline(std::cin, book);
		
		if (book.size() < 1 or book.size() > 3) {
			flag = false;
		}

		for (int i = 0; i < book.size(); ++i) {
			if (int(book[i]) < 48 or int(book[i]) > 57) {
				flag = false;
				break;
			}
		}
		
		if (flag == true) {
			book_in_file += book + "\n";
		}

		if (flag == true) {
			std::ofstream file("adcive_book.txt", std::ios_base::app); // ������� ���� ��� ������ � ���������� � ����� ����� ������ ��������
			file << book_in_file;
			file.close();//�������� �����
		}
	}

	//������ ������
	void set_money(std::string Money) {
		if (Bank_card != "No_bank_card") {
			bool flag = true;
			if (Money.size() > 4 or Money.size() < 2) flag = false;

			for (int i = 0; i < Money.size(); ++i) {
				if (int(Money[i]) < 48 or int(Money[i]) > 57) {
					flag = false;
				}
			}

			if (flag == true and this->Money != "No_money") {
				this->Money = std::to_string(std::stoi(Money) + std::stoi(this->Money));
			}
			else {
				this->Money = Money;
			}
		}
		else {
			std::string str1 = "��������� �������� '��� ����' ���������� ����� ������.";
			std::string str2 = "------------------------------------------------------";
			system("cls"); // ������� ����� ������� �� Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			std::cout << "������� ������� �����!" << std::endl << str2 << std::endl;
		}
	}

	//���������� �������� � ����
	void history(std::string history) {
		std::ofstream file("history.txt", std::ios_base::app); // ������� ���� ��� ������ � ���������� � ����� ����� ������ ��������
		file << Email + ": " + history + "\n";
		file.close();//�������� �����
	}

	void print() override {
		std::cout << "������ ��������:" << std::endl;
		std::cout << "�����: " << Email << std::endl;
		std::cout << "���: " << Surname << " " << Name << " " << Middlename << std::endl;
		std::cout << "�������: " << Age << std::endl;
		std::cout << "���� ���������� ����� (� ������ �� ����� ��������): " << Bank_card << " (" << Money << ")" << std::endl;
		std::cout << "���-�� ��������� ����: " << Paid_books.size() << std::endl;
		std::cout << "���-�� ������ ����: " << Free_books.size() << std::endl;
		std::cout << "---------------------------------------------------------------------------" << std::endl;
		std::cout << "����� ����� �� ���������� ���������� (take_a_book)" << std::endl;
		std::cout << "������� ����� � ���������� ���������� (return_the_book)" << std::endl;
		std::cout << "������ ����� (buy_a_book)" << std::endl;
		std::cout << "���������� ���������� ����� (adcive_book)" << std::endl;
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