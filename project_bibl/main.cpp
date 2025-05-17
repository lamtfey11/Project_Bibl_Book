#include "class.h"
#include <iostream>
#include <string>
#include <fstream>//для работы с файлами
#include <windows.h> // для system("cls")
//using namespace std;

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
bool check_email_file(std::string email) {
	std::string email_file = "";//в эту строку сохраняется строка
	std::string email_file_not_space = "";//сохраняется почта до пробела в строке
	int size = 0;//длина стркои email_file
	bool flag = true;//для того, чтобы считать именно почту в строке(до пробела)
	std::ifstream file("Akkaunt_email.txt"); // открыли файл для чтения, создали объект
	if (!file.is_open() or file.peek() == EOF) {//проверка, что файл пуст
		return true;
	}
	//else if (!file.is_open()) {//проверка, что файл не открылся
	//
	//}
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
		std::string password_test = "";
 
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

				std::string fullname = Email + " " + Surname + " " + Name + " " + Middlename + " " + Age + " " + password + "\n";

				std::ofstream file("Akkaunt_email.txt", std::ios_base::app); // открыли файл для записи и добавления в конец файла нового аккаунта
				file << fullname;
				file.close();//закрытие файла
				
				system("cls"); // очищает экран консоли на Windows
				std::cout << str1 << std::endl << str2 << std::endl;
				std::cout << "Аккаунт успешно создан!" << std::endl <<
					"-----------------------" << std::endl;
			}

			key = -1;
			Key = "";
			break;
			
		case (2):
			std::cout << "Наш верный посититель! С возращением!" << std::endl;

			//////////////////////////////

			system("cls"); // очищает экран консоли на Windows
			std::cout << str1 << std::endl << str2 << std::endl;
			key = -1;
			Key = "";
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
			key = -1;
			Key = "";
			break;
		}
	} while (Key != "exit");
	
	return 0;
}