cmake_minimum_required (VERSION 3.4)

project (CormenLib)

set (HEADER_FILES
  stdafx.h
  HornersRule.h
  Searching.h
  Sorting.h
  Utilities.h
  ExercisesChapter_2.h
  ProblemsChapter_2.h
)

set (SOURCE_FILES
  stdafx.cpp
  main.cpp
  Searching.cpp
  Sorting.cpp
  ExercisesChapter_2.cpp
)


source_group ("header files" FILES ${HEADER_FILES})
source_group ("source files" FILES ${SOURCE_FILES})


include_directories ("${PROJECT_SOURCE_DIR}")


add_library (CormenLib ${HEADER_FILES} ${SOURCE_FILES} )



#add_custom_command (OUTPUT --std c++11 )

set_property (TARGET CormenLib PROPERTY FOLDER "cormen")

target_link_libraries (
	CormenLib )