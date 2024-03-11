#include <iostream>
#include <map>

int main()
{
	std::cout << "***************** Registration office *****************\n\n";

	std::map <std::string, int> queue;
	std::string last_name;
	/*int i = 0;
	while (true) {	//Лечим до последнего больного (выход из программы - очередь пуста)
		//Ожидаем поступления в очередь посетителя или команды Next
		std::cout << "To register in the queue, enter the last name of the visitor. To call the registry, enter the 'next' command.\n";
		std::cin >> last_name;
		if (last_name != "next") {
			queue.insert(std::pair<std::string, int>(last_name, i));
			i++;
		}
		else {
			std::map<std::string, int>::iterator it = queue.begin();
			if (it == queue.end()) {
				std::cout << "The queue is empty.Exit programm.\n\n";
				break;
			}
			else {
				std::cout << it->first << " is called to the registry.\n\n";
				queue.erase(it);
			}
		}
	}*/
	while (true) {	//Лечим до последнего больного (выход из программы - очередь пуста)
		//Ожидаем поступления в очередь посетителя или команды Next
		std::cout << "To register in the queue, enter the last name of the visitor. To call the registry, enter the 'next' command.\n";
		std::cin >> last_name;
		if (last_name != "next") {
			std::map<std::string, int>::iterator it = queue.find(last_name);
			if (it == queue.end())
				queue.insert(std::pair<std::string, int>(last_name, 1));
			else
				queue[it->first] = it->second + 1;
		}
		else {
			std::map<std::string, int>::iterator it = queue.begin();
			if (it == queue.end()) {
				std::cout << "The queue is empty.Exit programm.\n\n";
				break;
			}
			else {
				//В первом варианте просто было несколько записей по количеству однофамильцев
				//Точно так же они уходили из очереди без дополнительных условий
				//Зато у нас был итератор i - количество обратившихся в регистратуру больных
				std::cout << it->first << " is called to the registry.\n\n";
				if (it->second == 1)
					queue.erase(it);
				else
					it->second -= 1;
			}
		}
	}
}
