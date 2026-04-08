#ifndef BACKEND_DIJKSTRA_PATH_SOLVER_H
#define BACKEND_DIJKSTRA_PATH_SOLVER_H

#include "data_parser.h"
#include "edge.h"
#include "node_distance.h"
#include "shortest_path_result.h"

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
#include <queue>
#include <limits>
#include <unordered_map>

namespace maps {
  class DijkstraPathSolver {
  public:
    DijkstraPathSolver(const std::string& file_path);

    ShortestPathResult solve(size_t start_node, size_t end_node);

  private:
    DataParser parser_;

    std::ifstream input_file_stream;
    std::vector<Edge> edges_;

    std::unordered_map<size_t, std::vector<NodeDistance>> adjacency_list_;

    static const size_t INF = std::numeric_limits<size_t>::max();
};

}

#endif //BACKEND_DIJKSTRA_PATH_SOLVER_H