#include "class.h"
#include <iostream>
#include <string>
#include <windows.h> // для system("cls")

bool check_email(std::string Email, std::string Surname, std::string Name, std::string Middlename, int Age) {
	
}

int main() {
	setlocale(LC_ALL, "rus");

	std::string str1 = "Карманный помощник 'Мир книг' библиотеки имени Чехова.";
	std::string str2 = "______________________________________________________";
	std::string Key = "";
	int key = -1;

	std::cout << str1 << std::endl << str2 << std::endl;
	
	do {
		std::string Email = "";
		std::string Surname = "";
		std::string Name = "";
		std::string Middlename = "";
		int Age = 0;
		std::string password = "";
 
		std::cout << "Зарегистрироваться (up) / Войти (in) / Выйти (exit)" << std::endl << "Напиши слово из скобкок: ";
		std::cin >> Key;

		system("cls"); // очищает экран консоли на Windows
		std::cout << str1 << std::endl << str2 << std::endl;

		if (Key == "up") {
			key = 1;
		}
		else if (Key == "in") {
			key = 2;
		}
		else if (Key == "exit") {
			key = 3;
		}

		switch (key)
		{
		case (1):

			std::cout << "Станьте членом нашей семьи! Заполните форму." << std::endl 
				<< "---------------------------" << std::endl;
			std::cout << "Почта: ";
			std::cin >> Email;
			std::cout << "Фамилия: ";
			std::cin >> Surname;
			std::cout << "Имя: ";
			std::cin >> Name;
			std::cout << "Отчество: ";
			std::cin >> Middlename;
			std::cout << "Возраст: ";
			std::cin >> Age;

			if (check_email(Email, Surname, Name, Middlename, Age)) {

			}
			else {

			}

			//////////////////////////////

			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			break;
		case (2):
			std::cout << "Наш верный посититель! С возращением!" << std::endl;

			//////////////////////////////

			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			break;
		case (3):
			std::cout << "Завершение работы. Будем у Вас в кормане, если что:)";

			//////////////////////////////
			break;
		default:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			std::cout << std::endl << "Неверная команда. Просим Вас написать нужную Вам для работы команду!" << std::endl 
				<< "--------------------------------------------------------------------" << std::endl;
			break;
		}
	} while (Key != "exit");
	
	return 0;
}