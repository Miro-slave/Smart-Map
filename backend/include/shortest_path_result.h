#ifndef BACKEND_SHORTEST_PATH_RESULT_H
#define BACKEND_SHORTEST_PATH_RESULT_H

#include <vector>

namespace maps {
  struct ShortestPathResult {
    bool path_exists;
    double distance;
    std::vector<size_t> path;
    double start_x_coordinate;
    double start_y_coordinate;
    double end_x_coordinate;
    double end_y_coordinate;
  };
}


#endif //BACKEND_SHORTEST_PATH_RESULT_H