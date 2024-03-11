#include <iostream>
#include <map>
#include <string>
#include <vector>

bool check_phone_number(std::string& phone_number) {	//Проверим формат телефонного номера на валидность
	if (phone_number.length() == 8 && phone_number[2] == '-' && phone_number[5] == '-' &&
		phone_number[0] >= '0' && phone_number[0] <= '9' && phone_number[1] >= '0' && phone_number[1] <= '9' &&
		phone_number[3] >= '0' && phone_number[3] <= '9' && phone_number[4] >= '0' && phone_number[4] <= '9' &&
		phone_number[6] >= '0' && phone_number[6] <= '9' && phone_number[7] >= '0' && phone_number[7] <= '9')
		return true;
	else
		return false;
}

void check_last_name(std::string& last_name) {		//Избежим непреднамеренных ошибок с заглавной первой буквой фамилии
	if (last_name[0] >= 97 && last_name[0] <= 122)
		last_name[0] -= 32;
}

int main()
{
	std::cout << "***************** Phone Directory *****************\n\n";

	std::map<std::string, std::string> phone_dir;
	std::map<std::string, std::vector<std::string>> surnameToNumber;
	std::string phone_number, last_name, command;
	

	while (true) {
		std::cout << "\nEnter a request ('a' - adding an entry , 's' - find out the subscriber's last name by phone number\n";
		std::cout << "'p' - find out the subscriber's phone number by last name)\n";
		std::cin >> command;

		if (command == "a" || command == "add") {
			std::cout << "\nEnter the subscriber's phone number and his last name by space: ";
			std::cin >> phone_number >> last_name;

			if (check_phone_number(phone_number)) {
				check_last_name(last_name);

				phone_dir[phone_number] = last_name;
				std::map<std::string, std::vector<std::string>>::iterator it = surnameToNumber.find(last_name);
				if (it == surnameToNumber.end()) {
					std::vector<std::string> numbers;
					numbers.push_back(phone_number);
					surnameToNumber[last_name] = numbers;
				}
				else
				{
					it->second.push_back(phone_number);
				}
			}
			else
				std::cout << "\nInvalid format of phone_number.\n";
		}
		else if (command == "s") {
			std::cout << "\nEnter the subscriber's phone number: ";
			std::cin >> phone_number;
			if (check_phone_number(phone_number)) {
				//Выводим результат с поиском по дереву за O(logn) операций (т.е. 2 в степени n операций)
				std::map<std::string, std::string>::iterator it = phone_dir.find(phone_number);
				if (it != phone_dir.end())
					std::cout << "\nFound last name - " << it->second << "\n";
				else
					std::cout << "\nNot found\n";
			}
			else
				std::cout << "\nInvalid format of phone_number.\n";
		}
		else if (command == "p") {
			std::cout << "Enter the subscriber's last name: ";
			std::cin >> last_name;

			check_last_name(last_name);

			//Выводим результат с асимптотической сложностью O(logn × количество номеров с этой фамилией) операций  
			std::map<std::string, std::vector<std::string>>::iterator it = surnameToNumber.find(last_name);
			if (it != surnameToNumber.end()) {
				std::cout << "\nFound numbers: ";
				for (int i = 0; i < it->second.size(); i++) 
					std::cout << it->second[i] << " ";
				std::cout << std::endl;
			}
			else
				std::cout << "\nNot found\n";
		}
		else {
			std::cout << "\nExit\n";
			break;
		}
	}
}