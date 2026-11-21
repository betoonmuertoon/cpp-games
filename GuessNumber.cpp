#include <iostream>
#include <chrono>
#include <windows.h>


int randomm() {
	auto seed1(std::chrono::system_clock::now().time_since_epoch().count());
	int seed{ seed1 % 100 + 1 };
	return seed;
}
int after() {
	std::cout << "Хочешь еще раз?:  ";
	char next('y');
	char stop('n');
	char buf;
	while (true) {
		std::cin >> buf;
		if (buf == next) {
			std::cout << "ты знаешь, что делать. Загадал новое число:  ";
			return 1;
			break;
		}
		else if (buf == stop) {
			std::cout << "прощай!";
			return 2;
			break;
		}
		else {
			std::cout << "ошибка ввода. Напиши y или n:  ";
			continue;

		}
	}
	
}

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
		std::cout << "я загадал  число от 1 до 100, попробуй его угадать за 7 попыток.После того, как ты назовешь число, я отвечу: моё \n число больше или меньше, в зависимости от их разности:  ";
		auto seed(randomm());
		int atts(7);
		bool isrunning(true);
		while (isrunning) 
		{	
			if (atts > 0) {
				int input;
				std::cin >> input;

				if (input == seed) {
					std::cout << "Ты угадал число!";
					int res{ after() };
					seed = randomm();
					atts = 7;
					if (res == 2) {
							break;
					}
					continue;
				}

				else {
					if (input > seed) {
						std::cout << "меньше\n";
					}
					else {
						std::cout << "больше\n";
					}
					atts -= 1;
				}
			}
			else {
				std::cout << "попытки закончились. Ты проиграл.";
				int res{ after() };
				if (res == 1) {
					seed = randomm();
					atts = 7;
					continue;
				}
				else {
					break;
				}
			}
			

		}



	return 0;


}