#ifndef BACKEND_DATA_PARSER_H
#define BACKEND_DATA_PARSER_H

#include "edge.h"

#include <iterator>
#include <vector>

namespace maps {
  class DataParser {
   public:
    std::vector<Edge> parse(std::ifstream& data_stream);

   private:
    template <typename String>
    Edge edgeFromString(String&& data);
  };
}

#endif //BACKEND_DATA_PARSER_H