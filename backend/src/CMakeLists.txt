add_library(backend_lib
        data_parser.cpp
        dijkstra_path_solver.cpp
)

target_include_directories(backend_lib
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
