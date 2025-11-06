#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

namespace task {
	class Task
	{
	private:
		std::string m_task;
		bool m_complete;

	public:
		Task();
		Task(const std::string&);

		// Default the copy constructor and assignment
		Task(const Task&) = default;
		Task& operator=(const Task&) = default;

		// Friend functions
		friend std::ostream& operator<<(std::ostream& os, const Task& task)
		{
			os << task.m_task << ' ' << (task.m_complete ? "Complete" : "In-Progress") << std::endl;
			return os;
		}
	};
}

#endif // !TASK_H