//
// Created by YF on 26.03.2026.
//

#ifndef BACKEND_EDGE_H
#define BACKEND_EDGE_H

#include <cstdint>

namespace maps {
  struct Edge {
    size_t start_node;
    size_t end_node;
    double length;
    double x_coordinate;
    double y_coordinate;
  };
}

#endif //BACKEND_EDGE_H