#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class WeightedGraph
{
private:
	using Edge = std::pair<std::string, int>;
	std::unordered_map<std::string, std::vector<Edge>> adjacency_;

public:
	void addEdge(const std::string &from,
				 const std::string &to,
				 int weight,
				 bool bidirectional = true)
	{
		adjacency_[from].push_back({to, weight});
		adjacency_[to];

		if (bidirectional)
		{
			adjacency_[to].push_back({from, weight});
		}
	}

	void shortestPath(const std::string &start,
					  const std::string &destination) const
	{
		const int infinity = std::numeric_limits<int>::max();

		std::unordered_map<std::string, int> distance;
		std::unordered_map<std::string, std::string> previous;

		for (const auto &[node, edges] : adjacency_)
		{
			distance[node] = infinity;
		}

		if (!distance.contains(start) || !distance.contains(destination))
		{
			std::cout << "Start or destination node does not exist.\n";
			return;
		}

		using QueueItem = std::pair<int, std::string>;
		std::priority_queue<
			QueueItem,
			std::vector<QueueItem>,
			std::greater<QueueItem>>
			queue;

		distance[start] = 0;
		queue.push({0, start});

		while (!queue.empty())
		{
			auto [currentDistance, currentNode] = queue.top();
			queue.pop();

			if (currentDistance != distance[currentNode])
			{
				continue;
			}

			if (currentNode == destination)
			{
				break;
			}

			for (const auto &[neighbor, weight] : adjacency_.at(currentNode))
			{
				const int newDistance = currentDistance + weight;

				if (newDistance < distance[neighbor])
				{
					distance[neighbor] = newDistance;
					previous[neighbor] = currentNode;
					queue.push({newDistance, neighbor});
				}
			}
		}

		if (distance[destination] == infinity)
		{
			std::cout << "No path found.\n";
			return;
		}

		std::vector<std::string> path;
		for (std::string current = destination; !current.empty();)
		{
			path.push_back(current);
			if (current == start)
			{
				break;
			}
			current = previous[current];
		}

		std::cout << "Shortest distance: " << distance[destination] << '\n';
		std::cout << "Path: ";

		for (auto it = path.rbegin(); it != path.rend(); ++it)
		{
			std::cout << *it;
			if (std::next(it) != path.rend())
			{
				std::cout << " -> ";
			}
		}
		std::cout << '\n';
	}
};

int main()
{
	WeightedGraph graph;

	graph.addEdge("Huntsville", "Birmingham", 102);
	graph.addEdge("Huntsville", "Nashville", 112);
	graph.addEdge("Birmingham", "Atlanta", 147);
	graph.addEdge("Nashville", "Chattanooga", 134);
	graph.addEdge("Chattanooga", "Atlanta", 118);
	graph.addEdge("Birmingham", "Chattanooga", 147);

	graph.shortestPath("Huntsville", "Atlanta");
}
