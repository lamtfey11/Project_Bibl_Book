#include "Librarian.h"
#include <string>
#include <vector>
#include <fstream>//для работы с файлами
#include <windows.h> // для system("cls")

//дочерний класс читатель
class Reader : public Human {
private:
	std::string Bank_card;
	std::string Money;
	std::vector<std::string> Free_books;
	std::vector<std::string> Paid_books;
public:
	//конуструктор с параметром
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
			Bank_card = "No_bank_card";
			Money = "No_money";

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

	//установаить карту(поменять)
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

	//взять книгу
	void take_a_book() {
		std::ifstream in_free("free_books.txt"); // окрываем файл для чтения
		std::string in_file_str = "";
		std::vector<std::string> books_free;
		std::vector<std::string> books_free_copy;
		while (std::getline(in_free, in_file_str))
		{
			books_free.push_back(in_file_str);
		}
		in_free.close();     // закрываем файл

		std::cout << "Книги бесплатной библиотеки:" << std::endl;
		for (int i = 0; i < books_free.size(); ++i) {
			std::cout << books_free[i] << std::endl;
		}

		std::string book = "";
		std::cin.ignore();
		std::cout << "Введи книгу (price,Name,Aythor,Age): ";
		std::getline(std::cin, book);
		std::string str1 = "Карманный помощник 'Мир книг' библиотеки имени Чехова.";
		std::string str2 = "------------------------------------------------------";
		system("cls"); // очищает экран консоли на Windows
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
					std::cout << "Книга не подходит по возрасту!"
						      << "------------------------------" << std::endl;
				}
			}
		}
	
		std::ofstream out_free("free_books.txt", std::ios::trunc);
		for (const auto& line : books_free_copy) {
			out_free << line << "\n";
		}
		out_free.close();
		std::vector<std::string>().swap(books_free);//пустой вектор
		std::vector<std::string>().swap(books_free_copy);//пустой вектор
	}

	//вернуть книгу
	void return_the_book() {
		std::cout << "Бесплатные книги вашей библиотеки:" << std::endl;
		for (int i = 0; i < Free_books.size(); ++i) {
			std::cout << Free_books[i] << std::endl;
		}
		std::string book = "";
		std::vector<std::string> Free_books_copy;
		std::cin.ignore();
		std::cout << "Введи книгу,которую хотите вернуть (price,Name,Aythor,Age): ";
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
		std::vector<std::string>().swap(Free_books);//пустой вектор
		for (int i = 0; i < Free_books_copy.size(); ++i) {
			Free_books.push_back(Free_books_copy[i]);
		}
	}
	
	//купить книгу
	void buy_a_book() {
		if (Money != "No_money") {
			std::ifstream in_free("paid_books.txt"); // окрываем файл для чтения
			std::string in_file_str = "";
			std::vector<std::string> books_paid;
			std::vector<std::string> books_paid_copy;
			while (std::getline(in_free, in_file_str))
			{
				books_paid.push_back(in_file_str);
			}
			in_free.close();     // закрываем файл

			std::cout << "Книги платной библиотеки:" << std::endl;
			for (int i = 0; i < books_paid.size(); ++i) {
				std::cout << books_paid[i] << std::endl;
			}

			std::string book = "";
			std::cin.ignore();
			std::cout << "Введи книгу (price,Name,Aythor,Age): ";
			std::getline(std::cin, book);
			std::string str1 = "Карманный помощник 'Мир книг' библиотеки имени Чехова.";
			std::string str2 = "------------------------------------------------------";
			system("cls"); // очищает экран консоли на Windows
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
						std::cout << "Книга не подходит по возрасту или недостаточно средсвтв!"
							<< "--------------------------------------------------------" << std::endl;
					}
				}
			}

			std::ofstream out_free("paid_books.txt", std::ios::trunc);
			for (const auto& line : books_paid_copy) {
				out_free << line << "\n";
			}
			out_free.close();
			std::vector<std::string>().swap(books_paid);//пустой вектор
			std::vector<std::string>().swap(books_paid_copy);//пустой вектор
		}
	}

	//посоветовать книгу
	void advice_book() {
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
		
		if (flag == true) {
			book_in_file += book + "\n";
		}

		if (flag == true) {
			std::ofstream file("adcive_book.txt", std::ios_base::app); // открыли файл для записи и добавления в конец файла нового аккаунта
			file << book_in_file;
			file.close();//закрытие файла
		}
	}

	//внести деньги
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
			std::string str1 = "Карманный помощник 'Мир книг' библиотеки имени Чехова.";
			std::string str2 = "------------------------------------------------------";
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			std::cout << "Введите сначала карту!" << std::endl << str2 << std::endl;
		}
	}

	//сохранение действий в файл
	void history(std::string history) {
		std::ofstream file("history.txt", std::ios_base::app); // открыли файл для записи и добавления в конец файла нового аккаунта
		file << Email + ": " + history + "\n";
		file.close();//закрытие файла
	}

	void print() override {
		std::cout << "Данные читателя:" << std::endl;
		std::cout << "Почта: " << Email << std::endl;
		std::cout << "ФИО: " << Surname << " " << Name << " " << Middlename << std::endl;
		std::cout << "Возраст: " << Age << std::endl;
		std::cout << "Ваша банковская карта (и деньги на счету аккаунта): " << Bank_card << " (" << Money << ")" << std::endl;
		std::cout << "Кол-во купленных книг: " << Paid_books.size() << std::endl;
		std::cout << "Кол-во взятых книг: " << Free_books.size() << std::endl;
		std::cout << "---------------------------------------------------------------------------" << std::endl;
		std::cout << "Взять книгу из бесплатной библиотеки (take_a_book)" << std::endl;
		std::cout << "Вернуть книгу в бесплатную библиотеку (return_the_book)" << std::endl;
		std::cout << "Купить книгу (buy_a_book)" << std::endl;
		std::cout << "Предложить библиотеке книгу (adcive_book)" << std::endl;
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