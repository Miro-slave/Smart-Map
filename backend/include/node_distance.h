#ifndef BACKEND_NODE_DISTANCE_H
#define BACKEND_NODE_DISTANCE_H

#include <cstdint>

namespace maps {
  struct NodeDistance {
    size_t node;
    double distance;

    bool operator<(const NodeDistance& other) const {
      return distance < other.distance;
    }
  };
}

#endif //BACKEND_NODE_DISTANCE_H