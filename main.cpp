#include <iostream>
#include "TaskManager.h"

using namespace std;

int main(int argc, char* argv[])
{
	// Testing the task manager
	task::TaskManager T1;
	task::Task Task1("Task#1");

	T1.addTask("Task#2");

	std::cout << "TaskManager1" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << T1 << std::endl;

	T1.addTask("Task#3");

	std::cout << "TaskManager1" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << T1 << std::endl;
}