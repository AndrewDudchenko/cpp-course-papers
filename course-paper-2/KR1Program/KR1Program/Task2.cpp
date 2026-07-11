#include "Task2.h"
#include "Circle.h"
#include <iostream>
#include <fstream>

void clearScreen2() {
    system("cls");
}

void showInfo2() {
    clearScreen2();
    std::cout << "=== Circle Class ===" << std::endl;
    std::cout << "Class: Circle" << std::endl;
    std::cout << "Attributes:" << std::endl;
    std::cout << " - X coordinate of the center" << std::endl;
    std::cout << " - Y coordinate of the center" << std::endl;
    std::cout << " - Radius" << std::endl;
    std::cout << " - Color" << std::endl;
    std::cout << "Available colors: Red, Green, Blue, Yellow, White, Black" << std::endl;
    std::cout << "Task 2:" << std::endl;
    std::cout << "Create two Circle objects." << std::endl;
    std::cout << "Apply operator% to get a new circle:" << std::endl;
    std::cout << " - radius = sum of both radii" << std::endl;
    std::cout << " - center = center of the first circle" << std::endl;
    std::cout << " - color = color of circle with bigger radius" << std::endl;
    std::cout << "=====================================================================" << std::endl;
    system("pause");
}

void doTask2() {
    clearScreen2();
    std::cout << "=== Task 2 ===" << std::endl;

    std::cout << "--- Circle 1 ---" << std::endl;
    Circle c1;
    std::cin >> c1;

    std::cout << "--- Circle 2 ---" << std::endl;
    Circle c2;
    std::cin >> c2;

    int choice = -1;
    while (choice != 0) {
        clearScreen2();
        std::cout << "=== Task 2 Menu ===" << std::endl;
        std::cout << "1. Show both circles" << std::endl;
        std::cout << "2. Apply operator% and show the result" << std::endl;
        std::cout << "0. Return to main menu" << std::endl;
        std::cout << "============================" << std::endl;
        std::cout << "Your choice: ";

        while (!(std::cin >> choice)) {
            std::cout << "Error: Invalid input. Try again: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        if (choice == 1) {
            clearScreen2();
            std::cout << "--- Circles Info ---" << std::endl;
            std::cout << "Operand 1: " << c1 << std::endl;
            std::cout << "Operand 2: " << c2 << std::endl;
            std::cout << "-----------------------------------------------------" << std::endl;
            system("pause");
        }
        else if (choice == 2) {
            clearScreen2();
            Circle result = c1 % c2;
            std::cout << "--- Operation Result % ---" << std::endl;
            std::cout << "Circle 1: " << c1 << std::endl;
            std::cout << "Circle 2: " << c2 << std::endl;
            std::cout << "Result: " << result << std::endl;
            std::cout << "-----------------------------------------------------" << std::endl;

            int saveChoice;
            std::cout << "Do you want to save the report in a text file? (1 for Yes, 0 for No): ";
            while (!(std::cin >> saveChoice) || (saveChoice != 0 && saveChoice != 1)) {
                std::cout << "Error: Enter 1 for Yes or 0 for No: ";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }

            if (saveChoice == 1) {
                std::ofstream file("report2.txt");
                if (file) {
                    file << "--- Operation Result % ---" << std::endl;
                    file << "Circle 1: " << c1 << std::endl;
                    file << "Circle 2: " << c2 << std::endl;
                    file << "Result: " << result << std::endl;
                    file.close();
                    std::cout << "Report is saved to 'report2.txt'." << std::endl;
                }
                else {
                    std::cout << "Error: Could not open the file." << std::endl;
                }
            }
            system("pause");
        }
    }
}