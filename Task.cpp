#include "Task.h"

using namespace task;

Task::Task()
{
	this->m_task = "";
	this->m_complete = false;
}

Task::Task(const std::string& string)
{
	this->m_task = string;
	this->m_complete = false;
}