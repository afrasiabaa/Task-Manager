#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <iostream>
#include "Task.h"

namespace task
{
	class TaskManager
	{
	private:
		Task* m_tasks; // Allocating memory for array rather than vector cause why not.
		size_t m_size;
		size_t m_capacity;
	
	public:
		// Constructors
		TaskManager();
		TaskManager(const Task&);
		TaskManager(const Task*, const size_t&);
		
		// Rule of 5
		TaskManager(const TaskManager&);
		TaskManager& operator=(const TaskManager&);

		TaskManager(TaskManager&&) noexcept;
		TaskManager& operator=(TaskManager&&) noexcept;

		~TaskManager();

		// Methods
		void addTask(const Task&);

		// Helper functions
		friend std::ostream& operator<<(std::ostream& os, const TaskManager& taskManager)
		{
			for (size_t i = 0; i < taskManager.m_size; ++i)
				os << taskManager.m_tasks[i] << std::endl;
			return os;
		}
	};
}


#endif // !TASK_MANAGER_H