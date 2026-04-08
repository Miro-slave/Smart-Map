add_executable(backend_app main.cpp)

target_link_libraries(backend_app
        PRIVATE backend_lib
)

configure_file(
        ${CMAKE_SOURCE_DIR}/resources/SaintPetersburg_Edgelist.csv
        ${CMAKE_BINARY_DIR}/bin/SaintPetersburg_Edgelist.csv
        COPYONLY
)

configure_file(
        ${CMAKE_SOURCE_DIR}/resources/SaintPetersburg_Edgelist_Short.csv
        ${CMAKE_BINARY_DIR}/bin/SaintPetersburg_Edgelist_Short.csv
        COPYONLY
)

