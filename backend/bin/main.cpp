#include "dijkstra_path_solver.h"

#include <iostream>

using maps::DijkstraPathSolver;
using maps::ShortestPathResult;

int main(int argc, char* argv[]) {
  /*	if (argc != 2) {
      std::cout << "error: invalid argument count\n"
        << "usage: dist <file-path>\n";
    }

    std::string file_path(argv[1]);*/

  std::string data_file_path("SaintPetersburg_Edgelist_Short.csv");

  DijkstraPathSolver solver(data_file_path);

  ShortestPathResult path_result = solver.solve(500, 2910);

  if (path_result.path_exists) {
    std::cout << "total distance: " << path_result.distance << '\n';
  } else {
    std::cout << "the path does not exist\n";
  }

  std::cout.precision(20);

  std::cout << path_result.start_x_coordinate << ' ' << path_result.start_y_coordinate << '\n'
    << path_result.end_x_coordinate << ' ' << path_result.end_y_coordinate << '\n';

  return 0;
}
