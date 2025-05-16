#include "class.h"
#include <iostream>
#include <string>
#include <windows.h> // для system("cls")

//проверка корректности почты(заканчивается на @gmail.com, @yandex.ru, @mail.ru), что почты нет в файле с аккаунтами
//проверка корректности фамилии, ими, отчества(чтоб были только буквы)
//проверка корректности возраста(только цифры + в размере разумного)
bool check_reg(std::string email, std::string surname, std::string name, std::string middlename, std::string age) {
	//проверка, что почта больше 10 символов, а также конец совпадает с типом почты
	if (!((email.size() > 10) 
		and (email.substr(email.size() - 10) == "@gmail.com" 
			or email.substr(email.size() - 10) == "@yandex.ru"
			or email.substr(email.size() - 8) == "@mail.ru"))) {
		return false;
	}
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
		std::string Age = "";
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

			if (check_reg(Email, Surname, Name, Middlename, Age)) {
				
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
			std::cout << "Завершение работы. Будем у Вас в кормане, если что:)" << std::endl;

			//////////////////////////////
			break;
		default:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			std::cout << "Неверная команда. Просим Вас написать нужную Вам для работы команду!" << std::endl 
				<< "--------------------------------------------------------------------" << std::endl;
			break;
		}
	} while (Key != "exit");
	
	return 0;
}