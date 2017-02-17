cmake_minimum_required(VERSION 3.4)

project (nzproject)

include (CMake/nzproject.cmake)

include (CMake/boost.cmake)

add_subdirectory (boost_tutorials)
add_subdirectory (cormen)
add_subdirectory (evacuation)
add_subdirectory (codefights)
add_subdirectory (geeksforgeeks)
add_subdirectory (concurrency)
add_subdirectory (performance_tricks)
add_subdirectory (stroustrup)
add_subdirectory (meyers_alexandrescu_satter)
add_subdirectory (unit_tests )

