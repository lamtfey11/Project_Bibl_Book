﻿#include "Reader.h"
#include <iostream>
#include <string>
#include <fstream>//для работы с файлами
#include <windows.h> // для system("cls")

void working_in_the_app_meny(Librarian& account, std::string status) {
	std::string str1 = "Карманный помощник 'Мир книг' библиотеки имени Чехова.";
	std::string str2 = "------------------------------------------------------";
	system("cls"); // очищает экран консоли на Windows
	std::cout << str1 << std::endl << str2 << std::endl;
	std::string Key = "";
	int key = -1;
	std::string bank_card = "";

	do {
		account.print();
		std::cin >> Key;
			
		if (Key == "plus_book") key = 0;
		else if (Key == "advice_book") key = 1;
		else if (Key == "delete_history") key = 2;
		else if (Key == "exit") key = 3;

		switch (key)
		{
		case 0:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			account.plus_book();
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			break;
		case 1:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			account.advice_book();
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			break;
		case 2:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			account.delete_history();
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			break;
		case 3:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			std::cout << "Вы вернулись в начальное меню!" << std::endl
				<< "------------------------------" << std::endl;
			break;
		default:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			std::cout << "Неверная команда. Просим Вас написать нужную Вам для работы команду!" << std::endl
				<< "--------------------------------------------------------------------" << std::endl;
			key = -1;
			Key = "";
			break;
		}
	} while (Key != "exit");
}


void working_in_the_app_meny(Reader& account, std::string status) {
	std::string str1 = "Карманный помощник 'Мир книг' библиотеки имени Чехова.";
	std::string str2 = "------------------------------------------------------";
	system("cls"); // очищает экран консоли на Windows
	std::cout << str1 << std::endl << str2 << std::endl;
	std::string Key = "";
	int key = -1;
	std::string bank_card = "";
	std::string money = "";

	do {
		account.print();
		std::cin >> Key;

		if (Key == "take_a_book") key = 0;
		else if (Key == "return_the_book") key = 1;
		else if (Key == "buy_a_book") key = 2;
		else if (Key == "advice_book") key = 3;
		else if (Key == "set_money") key = 4;
		else if (Key == "set_bank_card") key = 5;
		else if (Key == "exit") key = 6;

		switch (key)
		{
		case 0:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			account.take_a_book();
			account.history("take_a_book");
			break;
		case 1:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			account.return_the_book();
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			account.history("return_the_book");
			break;
		case 2:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			account.buy_a_book();
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			account.history("buy_a_book");
			break;
		case 3:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			account.advice_book();
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			break;
		case 4:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			std::cout << "Введите (от 100 до 9999 рублей): " << std::endl;
			std::cin >> money;
			account.set_money(money);
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			money = "";
			break;
		case 5:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			std::cout << "Введите номер банковской карты (16 цифр без пробелов): " << std::endl;
			std::cin >> bank_card;
			account.set_bank_card(bank_card);
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			bank_card = "";
			break;
		case 6:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			std::cout << "Вы вернулись в начальное меню!" << std::endl
				<< "------------------------------" << std::endl;
			break;
		default:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			std::cout << "Неверная команда. Просим Вас написать нужную Вам для работы команду!" << std::endl
				<< "--------------------------------------------------------------------" << std::endl;
			key = -1;
			Key = "";
			break;
		}
	} while (Key != "exit");
}


//вход в приложение и работа в нём в аккаунте
static void working_in_the_app(std::string Email, std::string Status) {
	if (Status == "n") {
		Reader accaunt(Email);
		working_in_the_app_meny(accaunt, Status);
	}
	else if (Status == "b") {
		Librarian accaunt(Email);
		working_in_the_app_meny(accaunt, Status);
	}
}

//в файле ищет нужный аккаунт
static char check_akk(std::string email, std::string password) {
	std::string akk_str = "";//в эту строку сохраняется строка
	std::string akk = "";//сохраняется почта и пароль до пробела в строке
	char status = '-';//статус (бибилиотекарь или читатель)

	int size = 0;//длина akk_str
	int count = 0;//для того, чтобы считать именно пробелы на почту, пароль в строке(до пробела)

	std::ifstream file("Account_email.txt"); // открыли файл для чтения, создали объект

	if (!file.is_open() or file.peek() == EOF) {//проверка, что файл пуст
		return false;
	}
	else {//файл открылся и будет проверка, есть ли почта в файле или есть(значит, можно создать новый аккаунт)
		while (std::getline(file, akk_str)) {
			size = akk_str.size();
			for (int i = 0; i < size; ++i) {
				if (akk_str[i] == ' ') {
					count += 1;
				}
				if (count == 0) {
					akk += akk_str[i];
				}
				if (count == 5 and akk_str[i] != '\n') {
					akk += akk_str[i];
				}
				if (count == 6 and akk_str[i] != '\n') {
					status = akk_str[i];
				}
			}
			if (akk == email + ' ' + password) {
				return status;
			}

			size = 0;
			count = 0;
			akk_str = "";
			akk = "";
		}
	}

	file.close();//закртыие файла	
	return false;
}

//провреят, чтобы в пароле не было пробелов
static bool check_password(std::string password) {
	for (int i = 0; i < password.size(); ++i) {
		if (password[i] == ' ') {
			return false;
		}
	}
	return true;
}

//проверка, что почты нет в реестре(в файле)
static bool check_email_file(std::string email) {
	std::string email_file = "";//в эту строку сохраняется строка
	std::string email_file_not_space = "";//сохраняется почта до пробела в строке
	int size = 0;//длина стркои email_file
	bool flag = true;//для того, чтобы считать именно почту в строке(до пробела)

	std::ifstream file("Account_email.txt"); // открыли файл для чтения, создали объект

	if (!file.is_open() or file.peek() == EOF) {//проверка, что файл пуст
		return true;
	}
	else {//файл открылся и будет проверка, есть ли почта в файле или есть(значит, можно создать новый аккаунт)
		while (std::getline(file, email_file)) {
			size = email_file.size();
			for (int i = 0; i < size; ++i) {
				if ((email_file[i] == ' ') and flag == true) {
					flag = false;
				}
				else if (flag == true) {
					email_file_not_space += email_file[i];
				}
			}
			if (email_file_not_space == email) {
				return false;
			}
			size = 0;
			flag = true;
			email_file = "";
			email_file_not_space = "";
		}
	}

	file.close();//закртыие файла	

	return true;
}

//проверка корректности почты(заканчивается на @gmail.com, @yandex.ru, @mail.ru), что почты нет в файле с аккаунтами
//проверка корректности фамилии, ими, отчества(чтоб были только буквы)
//проверка корректности возраста(только цифры + в размере разумного)
static bool check_reg(std::string email, std::string surname, std::string name, std::string middlename, std::string age) {
	//проверка, что почта больше 10 символов, а также конец совпадает с типом почты
	if (!((email.size() >= 10) 
		and (email.substr(email.size() - 10) == "@gmail.com" 
			or email.substr(email.size() - 10) == "@yandex.ru"
			or email.substr(email.size() - 8) == "@mail.ru"))) {
		for (int i = 0; i < email.size(); ++i) {
			if (email[i] == ' ') {
				std::cout << "Ошибка! Неправильно набрана почта! Попробуйте снова!" << std::endl
					<< "----------------------------------------------------" << std::endl;
				return false;
			}
		}
		std::cout << "Ошибка! Неправильно набрана почта! Попробуйте снова!" << std::endl
			      << "----------------------------------------------------" << std::endl;
		return false;
	}

	//проверка почты в файле
	if (!(check_email_file(email))) {
		std::cout << "Ошибка! Такая почта уже существует! Попробуйте снова!" << std::endl
				  << "-----------------------------------------------------" << std::endl;
		return false;
	}

	//проверка фамилии(первая буква большая, остальные строчные, и что вообще это именно буквы)
	for (int i = 0; i < surname.size(); ++i) {
		if (!(surname[0] >= 65 and surname[0] <= 90)) {
			std::cout << "Ошибка! Имя с не заглавной буквы! Попробуйте снова!" << std::endl
				      << "---------------------------------------------------" << std::endl;
			return false;
		}
		else if ((surname[0] >= 65 and surname[0] <= 90) and i > 0){
			if (!(surname[i] >= 97 and surname[i] <= 122)) {
				std::cout << "Ошибка! Такого имени быть не может! Попробуйте снова!" << std::endl
					      << "-----------------------------------------------------" << std::endl;
				return false;
			}
		}
	}

	//проверка имени(первая буква большая, остальные строчные, и что вообще это именно буквы)
	for (int i = 0; i < name.size(); ++i) {
		if (!(name[0] >= 65 and name[0] <= 90)) {
			std::cout << "Ошибка! Фамилия с не заглавной буквы! Попробуйте снова!" << std::endl
				      << "-------------------------------------------------------" << std::endl;
			return false;
		}
		else if ((name[0] >= 65 and name[0] <= 90) and i > 0) {
			if (!(name[i] >= 97 and name[i] <= 122)) {
				std::cout << "Ошибка! Такой фамилии быть не может! Попробуйте снова!" << std::endl
					      << "------------------------------------------------------" << std::endl;
				return false;
			}
		}
	}

	//проверка отчества(первая буква большая, остальные строчные, и что вообще это именно буквы)
	for (int i = 0; i < middlename.size(); ++i) {
		if (!(middlename[0] >= 65 and middlename[0] <= 90)) {
			std::cout << "Ошибка! Отчество с не заглавной буквы! Попробуйте снова!" << std::endl
				      << "--------------------------------------------------------" << std::endl;
			return false;
		}
		else if ((middlename[0] >= 65 and middlename[0] <= 90) and i > 0) {
			if (!(middlename[i] >= 97 and middlename[i] <= 122)) {
				std::cout << "Ошибка! Такого отчества быть не может! Попробуйте снова!" << std::endl
					      << "--------------------------------------------------------" << std::endl;
				return false;
			}
		}
	}

	//проверка возраста(не начинался с нуля, были только цифры, и возраст был от 14 до 99)
	if (age.size() > 1 and age.size() < 3 and age[0] != 0) {
		for (int i = 0; i < age.size(); ++i) {
			if (!(age[i] > 47 and age[i] < 58)) {
				std::cout << "Ошибка! Некорректный возраст! Попробуйте снова!" << std::endl
					      << "-----------------------------------------------" << std::endl;
				return false;
			}
		}
		if (std::stoi(age) < 14) {
			std::cout << "Ошибка! Вам меньше 14-ти лет! Попробуйте снова!" << std::endl
				      << "-----------------------------------------------" << std::endl;
			return false;
		}
	}
	else {
		return false;
		std::cout << "Ошибка! Некорректный возраст! Попробуйте снова!" << std::endl
			      << "-----------------------------------------------" << std::endl;
	}

	return true;
}

int main() {
	setlocale(LC_ALL, "rus");

	std::string str1 = "Карманный помощник 'Мир книг' библиотеки имени Чехова.";
	std::string str2 = "------------------------------------------------------";
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
		std::string password_test = "";
		std::string status = "";

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
				<< "--------------------------------------------" << std::endl;
			std::cin.ignore();
			std::cout << "Почта (mail.ru, gmail.com, yandex.ru): ";
			std::getline(std::cin, Email);
			std::cout << "Фамилия (С больщой буквы без пробелов): ";
			std::getline(std::cin, Surname);
			std::cout << "Имя (С больщой буквы без пробелов): ";
			std::getline(std::cin, Name);
			std::cout << "Отчество (С больщой буквы без пробелов): ";
			std::getline(std::cin, Middlename);
			std::cout << "Возраст (от 14 до 99 лет): ";
			std::getline(std::cin, Age);
			do {
				if (status != "") {
					system("cls"); // очищает экран консоли на Windows
					std::cout << str1 << std::endl << str2 << std::endl;
					std::cout << "Станьте членом нашей семьи! Заполните форму." << std::endl
						<< "--------------------------------------------" << std::endl;
					std::cout << "Почта (mail.ru, gmail.com, yandex.ru): " << Email << std::endl;
					std::cout << "Фамилия (С больщой буквы без пробелов): " << Surname << std::endl;
					std::cout << "Имя (С больщой буквы без пробелов): " << Name << std::endl;
					std::cout << "Отчество (С больщой буквы без пробелов): " << Middlename << std::endl;
					std::cout << "Возраст (от 14 до 99 лет): " << Age << std::endl;
				}
				std::cout << "Вы библитекарь (yes/no): ";
				std::getline(std::cin, status);
			} while (status != "yes" and status != "no");

			if (status == "no") {
				status = "n";
			}
			else {
				std::cout << "Введите ключ-пароль: ";
				std::getline(std::cin, status);
				if (status == "314") {
					status = "b";
				}
				else {
					system("cls"); // очищает экран консоли на Windows
					std::cout << str1 << std::endl << str2 << std::endl;
					std::cout << "Неправильный код библиотекаря." << std::endl
						<< "------------------------------" << std::endl;
					key = -1;
					Key = "";
					Email = "";
					Surname = "";
					Name = "";
					Middlename = "";
					Age = "";
					password = "";
					password_test = "";
					status = "";
					break;
				}
			}

			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;

			if (check_reg(Email, Surname, Name, Middlename, Age)) {//ввод пароля, если всё отлично
				do {
					do {
						system("cls"); // очищает экран консоли на Windows
						std::cout << str1 << std::endl << str2 << std::endl;
						std::cout << "Придумай теперь пароль!" << std::endl
							<< "-----------------------" << std::endl
							<< "Логин: " << Email << std::endl << "Пароль (без пробелов): ";
						std::getline(std::cin, password);
					} while (check_password(password) != true);

					do {
						system("cls"); // очищает экран консоли на Windows
						std::cout << str1 << std::endl << str2 << std::endl;
						std::cout << "Отлично! Придумай теперь пароль!" << std::endl
							<< "--------------------------------" << std::endl
							<< "Логин: " << Email << std::endl << "Повторно введите пароль (без пробелов): ";
						std::getline(std::cin, password_test);
					} while (check_password(password_test) != true);

				} while (password != password_test);

				std::string fullname = Email + " " + Surname + " " + Name + " " + Middlename + " " + Age + " " + password + " " + status + "\n";

				std::ofstream file("Account_email.txt", std::ios_base::app); // открыли файл для записи и добавления в конец файла нового аккаунта
				file << fullname;
				file.close();//закрытие файла

				system("cls"); // очищает экран консоли на Windows
				std::cout << str1 << std::endl << str2 << std::endl;
				std::cout << "Аккаунт успешно создан!" << std::endl <<
					"-----------------------" << std::endl;
			}
			key = -1;
			Key = "";
			Email = "";
			Surname = "";
			Name = "";
			Middlename = "";
			Age = "";
			password = "";
			password_test = "";
			status = "";
			break;
		case (2):
			std::cout << "Наш верный посититель! С возращением!" << std::endl
				<< "-------------------------------------" << std::endl;
			std::cin.ignore();
			std::cout << "Логин (ваша почта): ";
			std::getline(std::cin, Email);
			std::cout << "Пароль: ";
			std::getline(std::cin, password);
			status = check_akk(Email, password);

			if (status == "n" or status == "b") {
				working_in_the_app(Email, status);
			}
			else {
				system("cls"); // очищает экран консоли на Windows
				std::cout << str1 << std::endl << str2 << std::endl;
				std::cout << "Неверная логин или пароль! Или Вы ещё не зарегестрировались!" << std::endl
					<< "------------------------------------------------------------" << std::endl;
			}

			Email = "";
			password = "";
			status = "";
			key = -1;
			Key = "";
			break;
		case (3):
			std::cout << "Завершение работы. Будем у Вас в кормане, если что:)" << std::endl;
			break;
		default:
			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			std::cout << "Неверная команда. Просим Вас написать нужную Вам для работы команду!" << std::endl
				<< "--------------------------------------------------------------------" << std::endl;
			key = -1;
			Key = "";
			break;
		}
	} while (Key != "exit");

	return 0;
}