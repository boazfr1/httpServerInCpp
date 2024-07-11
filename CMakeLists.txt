cmake_minimuserver_required(VERSION 3.10)

# Set the project name
project(TcpServer)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(TcpServer
    http_tcpServer_linux.cpp
    server_linux.cpp
    routes.cpp
)

# Include directories
target_include_directories(TcpServer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link necessary libraries
target_link_libraries(TcpServer PRIVATE pthread)
