cmake_minimum_required (VERSION 3.4)

project (PerformanceTricksLib)

set (HEADER_FILES
  stdafx.h
)

set (SOURCE_FILES
  stdafx.cpp
  main.cpp
)


source_group ("header files" FILES ${HEADER_FILES})
source_group ("source files" FILES ${SOURCE_FILES})


include_directories ("${PROJECT_SOURCE_DIR}")


add_library (PerformanceTricksLib ${HEADER_FILES} ${SOURCE_FILES} )



#add_custom_command (OUTPUT --std c++11 )

set_property (TARGET PerformanceTricksLib PROPERTY FOLDER "performance_tricks")

target_link_libraries ( PerformanceTricksLib )
	
#use_precompiled_header (Platform stdafx.h stdafx.cpp SOURCE_FILES)