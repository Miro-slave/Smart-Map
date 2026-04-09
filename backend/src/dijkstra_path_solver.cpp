#include "dijkstra_path_solver.h"

#include "data_parser.h"
#include "edge.h"
#include "node_distance.h"
#include "shortest_path_result.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

namespace maps {
	DijkstraPathSolver::DijkstraPathSolver(const std::string& file_path) : input_file_stream(file_path), adjacency_list_(1000000) {
		edges_ = parser_.parse(input_file_stream);
		// adjacency_list_.resize(1000000);

		for (const Edge& edge : edges_) {
			adjacency_list_[edge.start_node].push_back(NodeDistance{edge.end_node, edge.length});
			// adjacency_list_[edge.end_node].push_back(NodeDistance{edge.start_node, edge.length});
		}
	}
	ShortestPathResult DijkstraPathSolver::solve(size_t start_node, size_t end_node) {
		if (start_node == end_node) {
			return ShortestPathResult{false};
		}

		std::unordered_map<size_t, size_t> prev;
		std::unordered_map<size_t, double> full_distance;

		std::priority_queue<NodeDistance> nodes;
		nodes.push(NodeDistance{start_node, 0});
		full_distance[start_node] = 0;

		while (!nodes.empty()) {
			size_t current_node = nodes.top().node;
			nodes.pop();

			std::cout << "current node: " << current_node << '\n';

			if (current_node == end_node) {
				std::vector<size_t> path;

				size_t node = end_node;

				while (node != start_node) {
					path.push_back(node);
					node = prev[node];
				}

				path.push_back(start_node);

				std::reverse(path.begin(), path.end());

				for (auto it = path.begin(); it != path.end(); it++) {
					std::cout << *it << ' ' << full_distance[*it] << '\n';
				}

				return ShortestPathResult{
					true,
					full_distance[end_node],
					path,
					edges_[start_node].x_coordinate,
					edges_[start_node].y_coordinate,
					edges_[end_node].x_coordinate,
					edges_[end_node].y_coordinate
				};
			}

			for (const NodeDistance& neighbour : adjacency_list_[current_node]) {
				if (full_distance.find(neighbour.node) == full_distance.end()) {
					prev[neighbour.node] = current_node;
					full_distance[neighbour.node] = full_distance[current_node] + neighbour.distance;
					nodes.emplace(NodeDistance{neighbour.node, full_distance[current_node] + neighbour.distance});
				}
			}
		}

		return ShortestPathResult{false};
	}
}
