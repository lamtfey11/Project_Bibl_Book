#include "Human.h"
#include <string>
#include <vector>
#include <fstream>//для работы с файлами
#include <windows.h> // для system("cls")

//дочерний класс библиотекарь
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

	//смотрит список советов и добялет книги в реестр
	void advice_book() {
		std::ifstream in_free("advice_book.txt"); // окрываем файл для чтения
		std::string in_file_str = "";
		std::vector<std::string> books_advice;
		std::vector<std::string> books_adcive_copy;
		while (std::getline(in_free, in_file_str))
		{
			books_advice.push_back(in_file_str);
		}
		in_free.close();     // закрываем файл

		std::cout << "Преложенные книги:" << std::endl;
		for (int i = 0; i < books_advice.size(); ++i) {
			std::cout << books_advice[i] << std::endl;
		}

		std::string book = "";
		std::cin.ignore();
		std::cout << "Введи книгу, которую хотите добавить в библиотеку: ";
		std::getline(std::cin, book);
		std::string str1 = "Карманный помощник 'Мир книг' библиотеки имени Чехова.";
		std::string str2 = "------------------------------------------------------";
		system("cls"); // очищает экран консоли на Windows
		std::cout << str1 << std::endl << str2 << std::endl;
		for (int i = 0; i < books_advice.size(); ++i) {
			if (books_advice[i] != book) {
				books_adcive_copy.push_back(books_advice[i]);
			}
			else {
				if (books_advice[i][0] == 'f') {
					std::ofstream out_free("free_books.txt", std::ios::app);
					out_free << books_advice[i] + "\n";
					out_free.close();
				}
				else {
					std::ofstream out_free("paid_books.txt", std::ios::app);
					out_free << books_advice[i] + "\n";
					out_free.close();
				}
			}
		}

		std::ofstream out_free("adcive_book.txt", std::ios::trunc);
		for (const auto& line : books_adcive_copy) {
			out_free << line << "\n";
		}
		out_free.close();
		std::vector<std::string>().swap(books_advice);//пустой вектор
		std::vector<std::string>().swap(books_adcive_copy);//пустой вектор
	}

	//удаляет историю конкретной почты
	void delete_history() {
		std::ifstream in_free("history.txt"); // окрываем файл для чтения
		std::string in_file_str = "";
		std::vector<std::string> books_history;
		std::vector<std::string> books_history_copy;
		while (std::getline(in_free, in_file_str))
		{
			books_history.push_back(in_file_str);
		}
		in_free.close();     // закрываем файл

		std::cout << "История читателей (взяли, вернули и купили книгу):" << std::endl;
		for (int i = 0; i < books_history.size(); ++i) {
			std::cout << books_history[i] << std::endl;
		}

		std::string book = "";
		std::cin.ignore();
		std::cout << "Введи пункт, который хотите удалить из истории: ";
		std::getline(std::cin, book);
		std::string str1 = "Карманный помощник 'Мир книг' библиотеки имени Чехова.";
		std::string str2 = "------------------------------------------------------";
		system("cls"); // очищает экран консоли на Windows
		std::cout << str1 << std::endl << str2 << std::endl;
		for (int i = 0; i < books_history.size(); ++i) {
			if (books_history[i] != book) {
				books_history_copy.push_back(books_history[i]);
			}
		}

		std::ofstream out_free("history.txt", std::ios::trunc);
		for (const auto& line : books_history_copy) {
			out_free << line << "\n";
		}
		out_free.close();
		std::vector<std::string>().swap(books_history);//пустой вектор
		std::vector<std::string>().swap(books_history_copy);//пустой вектор
	}

	//добавление книги в список
	void plus_book() {
		std::string str1 = "Карманный помощник 'Мир книг' библиотеки имени Чехова.";
		std::string str2 = "------------------------------------------------------";
		bool flag = true;
		std::string book = "";
		std::string book_in_file = "";
		std::cout << "Введи беслпатной (f) или платной (цену) будет книга: ";
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
		std::cout << "Введи название книги (слитно): ";
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
		std::cout << "Введи фамилию автора книги: ";
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
		std::cout << "Введи возрастное ограничение книги: ";
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

		if (flag == true and book[0] == 'f') {
			std::ofstream file("free_books.txt", std::ios_base::app); // открыли файл для записи и добавления в конец файла нового аккаунта
			file << book_in_file + "\n";
			file.close();//закрытие файла
		}
		else if (flag == true) {
			std::ofstream file("paid_books.txt", std::ios_base::app); // открыли файл для записи и добавления в конец файла нового аккаунта
			file << book_in_file + "\n";
			file.close();//закрытие файла
		}
	}

	void print() override {
		std::cout << "Данные библиотекаря:" << std::endl;
		std::cout << "Почта: " << Email << std::endl;
		std::cout << "ФИО: " << Surname << " " << Name << " " << Middlename << std::endl;
		std::cout << "Возраст: " << Age << std::endl;
		std::cout << "---------------------------------------------------------------------------" << std::endl;
		std::cout << "Добавить книгу в бесплатную или платную библиотеки (plus_book)" << std::endl;
		std::cout << "Посмотреть список предложенных книг (advice_book)" << std::endl;
		std::cout << "Удалить всю историю пользователя (delete_history)" << std::endl;
		std::cout << "Выход (exit)" << std::endl;
		std::cout << "Напиши слово из скобок: ";
	}

	~Librarian() {
		std::string acc_librarian = Email + " " + Surname + " " + Name + " " + Middlename + " " + Age + " " + Password + " " + Status;
		std::string akk_str = "";//сохраняется почта
		std::string akk_file = "";
		bool flag = false;
		std::vector<std::string> akk;
		std::ifstream file("account_books_b.txt", std::ios::trunc); // открыли файл для чтения, создали объект
		
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

		std::ofstream out_file("account_books_b.txt", std::ios::trunc);

		for (const auto& line : akk) {
			out_file << line << "\n";
		}
		out_file.close();
	}
};
