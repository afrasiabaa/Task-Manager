#include "TaskManager.h"

using namespace task;

TaskManager::TaskManager() 
{
	this->m_size = 0;
	this->m_capacity = 0;
	this->m_tasks = nullptr;
}

TaskManager::TaskManager(const Task& task)
{
	this->m_size = 1;
	this->m_capacity = 4;
	this->m_tasks = new Task[m_capacity];
	
	this->m_tasks[0] = task;
}

TaskManager::TaskManager(const Task* tasks, const size_t& size)
{
	this->m_size = size;
	this->m_capacity = size + 16;
	this->m_tasks = new Task[m_capacity];

	if (tasks != nullptr)
		for	(size_t i = 0; i < m_size; ++i)
			m_tasks[i] = tasks[i];
}

// Rule of 5
TaskManager::TaskManager(const TaskManager& other)
{
	this->m_size = other.m_size;
	this->m_capacity = other.m_capacity;
	this->m_tasks = nullptr;

	if (m_size > 0)
	{
		this->m_tasks = new Task[m_capacity];
		for (size_t i = 0; i < m_size; ++i)
			this->m_tasks[i] = other.m_tasks[i];
	}
}

TaskManager& TaskManager::operator=(const TaskManager& other)
{
	if (this == &other)
		return *this;

	// Check if current instance contains any values
	delete[] this->m_tasks;

	// Shallow copy
	this->m_size = other.m_size;
	this->m_capacity = other.m_capacity;

	// Deep copy
	if (m_size > 0)
	{
		this->m_tasks = new Task[m_capacity];
		for (size_t i = 0; i < m_size; ++i)
			this->m_tasks[i] = other.m_tasks[i];
	}
	else
		m_tasks = nullptr;

	return *this;
}

TaskManager::TaskManager(TaskManager&& other) noexcept
{
	// Move all attributes
	this->m_size = other.m_size;
	this->m_capacity = other.m_capacity;
	this->m_tasks = other.m_tasks;

	// Remove all info from other
	other.m_size = 0;
	other.m_capacity = 0;
	other.m_tasks = nullptr;
}

TaskManager& TaskManager::operator=(TaskManager&& other) noexcept 
{
	// Check if same instance
	if (this == &other)
		return *this;

	// Check if m_tasks has any allocated memory
	delete[] this->m_tasks;

	// Move all attributes
	this->m_size = other.m_size;
	this->m_capacity = other.m_capacity;
	this->m_tasks = other.m_tasks;

	// Remove all info from other
	other.m_size = 0;
	other.m_capacity = 0;
	other.m_tasks = nullptr;

	return *this;
}

TaskManager::~TaskManager()
{
	delete[] this->m_tasks;
}

// Methods
void TaskManager::addTask(const Task& task)
{
	if (this->m_size == this->m_capacity) // if the size of the array is the same as the allocated memory
	{
		this->m_capacity += 8;
		
		Task* newTasks = new Task[m_capacity];
		for (size_t i = 0; i < this->m_size; ++i) // Deep copy to new allocated block
			newTasks[i] = m_tasks[i];
		delete[] this->m_tasks;
		this->m_tasks = newTasks;
	}
	
	++this->m_size;
	this->m_tasks[this->m_size] = task;
}