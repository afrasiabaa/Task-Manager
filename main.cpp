#include <iostream>
#include "TaskManager.h"

using namespace std;

int main(int argc, char* argv[])
{
	task::Task task1("Test Task");

	task::TaskManager T1;
	task::TaskManager T2(task1);

	std::cout << "TaskManager1: " << T1;
	std::cout << "TaskManager2: " << T2;
	std::cout << "Task1: " << task1;
}