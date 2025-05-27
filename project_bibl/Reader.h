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
			std::vector<std::string>().swap(arguments);//пустой вектор
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
			std::vector<std::string>().swap(arguments);//пустой вектор

		}
	}

	std::string file_account_books_b_email(std::string email, std::string name_file) {
		std::string akk_str = "";//в эту строку сохраняется строка
		std::string akk = "";//сохраняется почта до пробела в строке
		int count = 0;
		std::ifstream file(name_file); // открыли файл для чтения, создали объект

		if (!file.is_open() or file.peek() == EOF) {//проверка, что файл пуст
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
		file.close();//закртыие файла	
		return " ";
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

	//сохранение действий в файл
	void history() {

	}

	void print() override {
		std::cout << "Данные читателя:" << std::endl;
		std::cout << "Почта: " << Email << std::endl;
		std::cout << "ФИО: " << Surname << " " << Name << " " << Middlename << std::endl;
		std::cout << "Возраст: " << Age << std::endl;
		std::cout << "Ваша банковская карта (и деньги на счету аккаунта): " << Bank_card << " (" << Money << ")" << std::endl;
		std::cout << "Кол-во купленных книг: " << Paid_books.size() << std::endl;
		std::cout << "Кол-во взятых книг: " << Free_books.size() << std::endl;
		std::cout << "--------------------------------------------------------------------------------" << std::endl;
		std::cout << "Взять книгу из бесплатной библиотеки (take_a_book)" << std::endl;
		std::cout << "Вернуть книгу в бесплатную библиотеку (return_the_book)" << std::endl;
		std::cout << "Купить книгу (buy_a_book)" << std::endl;
		std::cout << "Предложить библиотеке книгу (advice_book)" << std::endl;
		std::cout << "Внести в аккаунт деньги (set_money)" << std::endl;
		std::cout << "Найстроки (set_bank_card)" << std::endl;
		std::cout << "Выход (exit)" << std::endl;
		std::cout << "Напиши слово из скобок: ";
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
		std::string akk_str = "";//сохраняется почта
		std::string akk_file = "";
		bool flag = false;
		std::vector<std::string> akk;
		std::ifstream file("account_books_n.txt", std::ios::trunc); // открыли файл для чтения, создали объект

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