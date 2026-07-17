#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <thread>

class ThreadSafeQueue
{
private:
	std::queue<int> queue_;
	std::mutex mutex_;
	std::condition_variable condition_;
	bool finished_{false};

public:
	void push(int value)
	{
		{
			std::lock_guard<std::mutex> lock(mutex_);
			queue_.push(value);
		}
		condition_.notify_one();
	}

	bool pop(int &value)
	{
		std::unique_lock<std::mutex> lock(mutex_);

		condition_.wait(lock, [this]
						{ return !queue_.empty() || finished_; });

		if (queue_.empty())
		{
			return false;
		}

		value = queue_.front();
		queue_.pop();
		return true;
	}

	void finish()
	{
		{
			std::lock_guard<std::mutex> lock(mutex_);
			finished_ = true;
		}
		condition_.notify_all();
	}
};

void producer(ThreadSafeQueue &queue, int itemCount)
{
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<int> distribution(10, 99);

	for (int i = 0; i < itemCount; ++i)
	{
		const int value = distribution(generator);
		queue.push(value);

		std::cout << "Produced: " << value << '\n';
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	queue.finish();
}

void consumer(ThreadSafeQueue &queue)
{
	int value{};

	while (queue.pop(value))
	{
		std::cout << "  Consumed: " << value
				  << ", square = " << value * value << '\n';

		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
}

int main()
{
	ThreadSafeQueue queue;

	std::thread producerThread(producer, std::ref(queue), 10);
	std::thread consumerThread(consumer, std::ref(queue));

	producerThread.join();
	consumerThread.join();

	std::cout << "All items processed.\n";
}
