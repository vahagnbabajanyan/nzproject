project (runner)

set (HEADER_FILES
  stdafx.h
)

set (SOURCE_FILES
  main.cpp
  stdafx.cpp
)

source_group ("header files" FILES ${HEADER_FILES})
source_group ("source files" FILES ${SOURCE_FILES})

include_directories ( "${CMAKE_CURRENT_BINARY_DIR}/.." )

add_executable (runner ${HEADER_FILES} ${SOURCE_FILES} )

set_property (TARGET runner PROPERTY FOLDER "runner")

target_link_libraries (runner 
  CormenLib 
  ConcurrencyLib
)

#use_precompiled_header (Platform stdafx.h stdafx.cpp SOURCE_FILES)