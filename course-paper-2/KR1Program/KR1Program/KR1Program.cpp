#include "Task.h"
#include "Task2.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
	srand(time(NULL));

	int choice = -1;
	while (choice != 0) {
		clearScreen2();
		std::cout << "=== KR1 Program - Music Sales Management ===" << std::endl;
		std::cout << "1. Show task info" << std::endl;
		std::cout << "2. Do Task 1 (Music)" << std::endl;
		std::cout << "3. Do Task 2 (Circle)" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "============================" << std::endl;
		std::cout << "Your choice: ";

		while (!(std::cin >> choice)) {
			std::cout << "Error: Invalid input. Try again: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}

		if (choice == 1) {
			ShowInfo();
			showInfo2();
		}
		else if (choice == 2) {
			DoTask1();
		}
		else if (choice == 3) {
			doTask2();
		}
		else if (choice != 0) {
			std::cout << "Error: Invalid choice. Try again." << std::endl;
			system("pause");
		}
	}
	return 0;
}