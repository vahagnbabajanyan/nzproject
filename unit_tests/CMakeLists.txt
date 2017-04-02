cmake_minimum_required (VERSION 3.4)

project (UnitTests)

set (HEADER_FILES
  stdafx.h
  # here could be headers
)

set (SOURCE_FILES
  stdafx.cpp
  main.cpp
  CormenSortingTests.cpp
)


source_group ("header files" FILES ${HEADER_FILES})
source_group ("source files" FILES ${SOURCE_FILES})

add_executable (UnitTests ${HEADER_FILES} ${SOURCE_FILES})

# extract_debug_information (UnitTests)

# include_directories ("${PROJECT_SOURCE_DIR}")
include_directories ( "${CMAKE_CURRENT_BINARY_DIR}/.." )

set_property (TARGET UnitTests PROPERTY FOLDER "unit_tests")

target_link_libraries (UnitTests 
  CormenLib
  ${lib_boost_unit_test_framework}
  ${lib_boost_system} 
  ${lib_boost_thread} 
  ${lib_boost_date_time}
  ${lib_boost_filesystem} 
  ${lib_pthread}
  ${lib_xml2} 
  ${lib_dl} 
  ${lib_rt} 
  ${lib_ws2_32}
  ${lib_xerces}
)

