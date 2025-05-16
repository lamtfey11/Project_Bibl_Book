#include "class.h"
#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "rus");

	std::cout << "Карманный помощник 'Мир книг' библиотеки имени Чехова." << std::endl;
	std::cout << "______________________________________________________" << std::endl;
	std::cout << "Войти, как гость (hin) / Войти (in) / Зарегистрироваться (up) / Выйти (exit)" << std::endl;
	std::string Key = "";
	int key = 0;
	
	do {
		std::cout << "Напиши слово из скобкок: ";
		
		std::cin >> Key;
		
		if (Key == "hin") {
			key = 0;
		}
		else if (Key == "in") {
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
		case (0):
			std::cout << "Вы гость нашей библиотеки! Добро пожаловать!" << std::endl;
			break;
		case (1):
			std::cout << "Наш верный посититель! С возращением!" << std::endl;
			break;
		case (2):
			std::cout << "Станьте членом нашей семьи!" << std::endl;
			break;
		case (3):
			std::cout << "Завершение работы. Будем у Вас в кормане, если что)";
			break;
		default:
			std::cout << "Неверная команда. Просим Вас написать нужную Вам для работы команду." << std::endl;
			break;
		}

	} while (Key != "exit");
	
	return 0;
}