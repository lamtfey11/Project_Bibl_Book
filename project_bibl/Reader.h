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

			argument = "";
			std::vector<std::string>().swap(arguments);//пустой вектор
		}
		else {
			file_result = file_account_books_b_email(email, "Account_email.txt") + ' ';
			std::cout << file_result << std::endl;
			for (int i = 0; i < file_result.size() + 1; ++i) {
				if (file_result[i] == ' ' or file_result[i] == '\n') {
					arguments.push_back(argument);
					argument = "";
				}
				else if (file_result[i] != ' ') {
					std::cout << file_result[i] << std::endl;
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

	~Reader() {
		/////////////////
	}
};