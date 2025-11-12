#include <iostream>
#include "TaskManager.h"
#include "Utils.h"

using namespace std;

// Function definitions.
void printMenu();
void printTitle();

int main(int argc, char* argv[])
{
	task::TaskManager manager;
	bool running = true;

	printTitle();

	do {
		printMenu();

		int choice;
		utils::input(choice, 1, 4);
		std::cin.ignore(); // Clear the stream buffer.

		switch (choice)
		{
		case 1: 
		{
			
			break;
		}
		case 2: 
		{
			
			break;
		}
		case 3:
		{
			

			break;
		}
		case 4: { running = false; break; }

		default: { std::cout << "Invalid option."; std::cout << std::endl; break; } 
			   // Don't know how you would've gotten here, but just incase.
		}

	} while (running);

	std::cout << "\nExiting...\n"; // Exiting program.
	return 0;
}

void printMenu()
{
	std::cout << "+--------------------------------+\n";
	std::cout << "|        TASK MANAGER            |\n";
	std::cout << "+--------------------------------+\n";
	std::cout << "| 1 | Add Task                   |\n";
	std::cout << "| 2 | View Tasks                 |\n";
	std::cout << "| 3 | Mark Task Complete         |\n";
	std::cout << "| 4 | Exit                       |\n";
	std::cout << "+--------------------------------+\n";
	std::cout << "Select an option: ";
}

void printTitle()
{
	std::cout << "======================================\n";
	std::cout << "           TASK MANAGER               \n";
	std::cout << "======================================\n\n";
}