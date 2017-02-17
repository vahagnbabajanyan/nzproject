cmake_minimum_required (VERSION 3.4)

project (BoostTutorialsLib)

set (HEADER_FILES
	DateTime.h
	stdafx.h
    FormatTutorial.h
)

set (SOURCE_FILES
  stdafx.cpp
  main.cpp
  FormatTutorial.cpp
)


source_group ("header files" FILES ${HEADER_FILES})
source_group ("source files" FILES ${SOURCE_FILES})


include_directories ("${PROJECT_SOURCE_DIR}"  ${BOOST_INCLUDE})

link_directories (${BOOST_LIB})


add_library (BoostTutorialsLib ${HEADER_FILES} ${SOURCE_FILES} )



#add_custom_command (OUTPUT --std c++11 )

set_property (TARGET BoostTutorialsLib PROPERTY FOLDER "concurrency")

target_link_libraries ( BoostTutorialsLib )
	
#use_precompiled_header (Platform stdafx.h stdafx.cpp SOURCE_FILES)