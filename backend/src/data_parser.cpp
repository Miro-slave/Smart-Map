#include "data_parser.h"

#include "edge.h"

#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>

namespace maps {
  std::vector<Edge> DataParser::parse(std::ifstream& data_stream) {
    auto it = std::istream_iterator<std::string>(data_stream);

    std::vector<Edge> edges;

    it++;
    for (; it != std::istream_iterator<std::string>(); it++) {
      edges.push_back(edgeFromString(*it));
    }

    return edges;
  }

  template <typename String>
  Edge DataParser::edgeFromString(String&& data) {
    std::stringstream sstream(data);
    std::vector<std::string> lexemes;

    std::string lexeme;
    while (std::getline(sstream, lexeme, ',')) {
      lexemes.push_back(lexeme);
    }

    return Edge{
      std::stoull(lexemes[2]),
      std::stoull(lexemes[3]),
      std::stod(lexemes[5]),
      std::stod(lexemes[0]),
      std::stod(lexemes[1])
       };
  }
}
