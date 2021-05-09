cmake_minimum_required(VERSION 3.19)
project(ft_containers)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ft_containers
        Node.hpp
        list.hpp
        vector.hpp
        mainList.cpp
#        mainVector.cpp
        )
