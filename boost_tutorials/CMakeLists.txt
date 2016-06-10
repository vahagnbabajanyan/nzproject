cmake_minimum_required (VERSION 3.4)

project (BoostTutorialsLib)



#-------------------------------------------------------

## Platform
if (MSVC)
  if (CMAKE_CL_64)
    set (NZ_PLATFORM x64)
  else ()
    set (NZ_PLATFORM win32)
  endif ()
else ()
  set (NZ_PLATFORM macrohard)
endif ()

## Compiler
if (MSVC14)
  set (ZN_COMPILER msvc-14.0)
elseif (MSVC12)
  set (ZN_COMPILER msvc-12.0)
elseif (MSVC11)
  set (ZN_COMPILER msvc-11.0)
elseif (MSVC10)
  set (ZN_COMPILER msvc-10.0)
elseif (MSVC90)
  set (ZN_COMPILER msvc-9.0)
endif ()

#-------------------------------------------------------


set (MR_ROOT "C:/MR")


if (MSVC)
	set (DEFAULT_BOOST_VERSION 1.60.0)

	if (NOT DEFINED BOOST_VERSION)
		set (BOOST_VERSION ${DEFAULT_BOOST_VERSION})
	endif()

	set (BOOST_DIR ${MR_ROOT}/Boost/${BOOST_VERSION})
	set (BOOST_INCLUDE ${BOOST_DIR}/include)
	set (BOOST_LIB ${BOOST_DIR}/lib/${NZ_COMPILER}/${NZ_PLATFORM})
	
	set (BOOST_LIBRARY_SUFFIX -vc110-mt-1_60)
	set (BOOST_LIBRARY_DEBUG_SUFFIX -vc110-mt-gd-1_60)
endif ()

#-------------------------------------------------------




set (HEADER_FILES
  stdafx.h
)

set (SOURCE_FILES
  stdafx.cpp
  main.cpp
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