cmake_minimum_required (VERSION 3.4)

project (StroustrupLib)

set (HEADER_FILES
  stdafx.h
  ch_2_3_1.hpp
)

set (SOURCE_FILES
  stdafx.cpp
  main.cpp
)


source_group ("header files" FILES ${HEADER_FILES})
source_group ("source files" FILES ${SOURCE_FILES})


include_directories ("${PROJECT_SOURCE_DIR}")


add_library (StroustrupLib ${HEADER_FILES} ${SOURCE_FILES} )



#add_custom_command (OUTPUT --std c++11 )

set_property (TARGET StroustrupLib PROPERTY FOLDER "stroustrup")

target_link_libraries ( StroustrupLib )
	
#use_precompiled_header (Platform stdafx.h stdafx.cpp SOURCE_FILES)