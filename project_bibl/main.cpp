#include "class.h"
#include <iostream>
#include <string>
#include <windows.h> // для system("cls")

int main() {
	setlocale(LC_ALL, "rus");

	std::string str1 = "Карманный помощник 'Мир книг' библиотеки имени Чехова.";
	std::string str2 = "______________________________________________________";
	std::string Key = "";
	int key = -1;

	std::cout << str1 << std::endl << str2 << std::endl;
	
	do {
		std::cout << "Войти (in) / Зарегистрироваться (up) / Выйти (exit)" << std::endl << "Напиши слово из скобкок: ";
		std::cin >> Key;

		system("cls"); // очищает экран консоли на Windows
		std::cout << str1 << std::endl << str2 << std::endl;

		if (Key == "in") {
			key = 1;
		}
		else if (Key == "up") {
			key = 2;
		}
		else if (Key == "exit") {
			key = 3;
		}

		switch (key)
		{
		case (1):
			std::cout << "Наш верный посититель! С возращением!" << std::endl;

			//////////////////////////////

			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			break;
		case (2):
			std::cout << "Станьте членом нашей семьи!" << std::endl;

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
			std::cout << std::endl << "-!Неверная команда. Просим Вас написать нужную Вам для работы команду!-" << std::endl << std::endl;
			break;
		}
	} while (Key != "exit");
	
	return 0;
}