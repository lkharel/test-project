#include <chrono>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

enum class Priority
{
	Low = 1,
	Medium = 2,
	High = 3,
	Critical = 4
};

struct Task
{
	int id{};
	std::string description;
	Priority priority{Priority::Low};
	std::chrono::system_clock::time_point createdAt;
};

struct TaskComparator
{
	bool operator()(const Task &left, const Task &right) const
	{
		if (left.priority != right.priority)
		{
			return static_cast<int>(left.priority) <
				   static_cast<int>(right.priority);
		}

		return left.createdAt > right.createdAt;
	}
};

class TaskScheduler
{
private:
	std::priority_queue<
		Task,
		std::vector<Task>,
		TaskComparator>
		tasks_;

	int nextId_{1};

public:
	int addTask(const std::string &description, Priority priority)
	{
		const int id = nextId_++;
		tasks_.push({id,
					 description,
					 priority,
					 std::chrono::system_clock::now()});
		return id;
	}

	bool empty() const
	{
		return tasks_.empty();
	}

	Task processNextTask()
	{
		if (tasks_.empty())
		{
			throw std::runtime_error("No tasks available.");
		}

		Task task = tasks_.top();
		tasks_.pop();
		return task;
	}

	std::size_t pendingCount() const
	{
		return tasks_.size();
	}
};

std::string priorityToString(Priority priority)
{
	switch (priority)
	{
	case Priority::Low:
		return "Low";
	case Priority::Medium:
		return "Medium";
	case Priority::High:
		return "High";
	case Priority::Critical:
		return "Critical";
	}
	return "Unknown";
}

int main()
{
	TaskScheduler scheduler;

	scheduler.addTask("Update documentation", Priority::Low);
	scheduler.addTask("Fix login failure", Priority::Critical);
	scheduler.addTask("Review pull request", Priority::Medium);
	scheduler.addTask("Investigate memory leak", Priority::High);

	while (!scheduler.empty())
	{
		const Task task = scheduler.processNextTask();

		std::cout << "Processing task #" << task.id
				  << " [" << priorityToString(task.priority) << "] "
				  << task.description << '\n';
	}
}
