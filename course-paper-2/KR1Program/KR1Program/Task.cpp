#include "Task.h"
#include "Music.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void ClearScreen() {
    system("cls");
}

void ShowInfo() {
    ClearScreen();
    std::cout << "=== Music Sales Management ===" << std::endl;
    std::cout << "Class: Music" << std::endl;
    std::cout << " - Sale date" << std::endl;
    std::cout << " - Title" << std::endl;
    std::cout << " - Copies sold" << std::endl;
    std::cout << " - Available on DVD (Yes/No)" << std::endl;
    std::cout << "Task 1:" << std::endl;
    std::cout << "Build an array of Music objects." << std::endl;
    std::cout << "Find the total number of sold copies for a title entered by the user." << std::endl;
    std::cout << "Save the report to a text file." << std::endl;
    std::cout << "=====================================================================" << std::endl;
    system("pause");
}

void PrintHeader() {
    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << std::setw(12) << "Date" << " | "
        << std::setw(12) << "Title" << " | "
        << std::setw(12) << "Copies" << " | "
        << "DVD" << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl;
}


void DoTask1() {
    ClearScreen();
    std::cout << "=== Task 1 ===" << std::endl;

    int n;
    std::cout << "Enter the number of music records: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Error: Number must be positive." << std::endl;
        system("pause");
        return;
    }

    Music* catalog = new Music[n];

    for (int i = 0; i < n; ++i) {
        std::cout << "---  Record # " << i + 1 << "---" << std::endl;
        std::cin >> catalog[i];
    }

    int choice = -1;
    while (choice != 0) {
        ClearScreen();
        std::cout << "=== Task 1 Menu ===" << std::endl;
        std::cout << "1. Show catalog" << std::endl;
        std::cout << "2. Search for a title" << std::endl;
        std::cout << "0. Return to main menu" << std::endl;
        std::cout << "============================" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            ClearScreen();
            std::cout << "--- Whole catalog ---" << std::endl;

            PrintHeader();

            for (int i = 0; i < n; i++) {
                std::cout << catalog[i];
            }
            std::cout << "-----------------------------------------------------" << std::endl;
            system("pause");
        }
        else if (choice == 2) {
            ClearScreen();
            std::string searchTitle;
            std::cout << "Enter title to search: ";
            std::cin >> searchTitle;

            long long totalCopies = 0;
            bool found = false;

            for (int i = 0; i < n; i++) {
                if (catalog[i].GetTitle() == searchTitle) {
                    totalCopies += catalog[i].GetCopies();
                    found = true;
                }
            }

            if (found) {
                std::cout << "Total copies of '" << searchTitle << "': " << totalCopies << std::endl;
            }
            else {
                std::cout << "Title '" << searchTitle << "' not found." << std::endl;
            }

            int saveChoice;
            std::cout << "Do you want to save the report in a text file? (1 for Yes, 0 for No): ";
            std::cin >> saveChoice;

            if (saveChoice == 1) {
                std::ofstream file("report.txt");
                if (file) {
                    file << "Report for title: " << searchTitle << std::endl;
                    if (found) {
                        file << "Total copies of '" << searchTitle << "': " << totalCopies << std::endl;
                    }
                    else {
                        file << "Title '" << searchTitle << "' not found." << std::endl;
                    }
                    file.close();
                    std::cout << "Report is saved to 'report.txt'." << std::endl;
                }
                else {
                    std::cout << "Error: Could not open the file." << std::endl;
                }
            }
            system("pause");
        }
    }
    delete[] catalog;
}