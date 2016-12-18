cmake_minimum_required (VERSION 3.5)
project (plt)

# Directories
include_directories ("${PROJECT_SOURCE_DIR}/src")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Enable C++11
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF(CMAKE_COMPILER_IS_GNUCC)
	SET(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -Wall -std=c11   -pthread -g")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -pthread -g")
ENDIF(CMAKE_COMPILER_IS_GNUCC)


# Generate headers
set(DIA2CODE "${PROJECT_SOURCE_DIR}/dia2code/bin/dia2code")
exec_program(${DIA2CODE} ARGS -d ../src -t cpp ../src/server.dia)
exec_program(${DIA2CODE} ARGS -d ../src -t cpp ../src/AI.dia)
exec_program(${DIA2CODE} ARGS -d ../src -t cpp ../src/engine.dia)
exec_program(${DIA2CODE} ARGS -d ../src -t cpp ../src/render.dia)
exec_program(${DIA2CODE} ARGS -d ../src -t cpp ../src/state.dia)

# Sources
file(GLOB_RECURSE game_sources src/render/*.cpp src/AI/*.cpp src/engine/*.cpp src/state/*.cpp)
file(GLOB_RECURSE server_sources src/server/*.cpp)

# jsoncpp
include_directories ("${PROJECT_SOURCE_DIR}/extern/jsoncpp-0.10.5/dist")
file(GLOB jsoncpp_sources "${PROJECT_SOURCE_DIR}/extern/jsoncpp-0.10.5/dist/jsoncpp.cpp")

# Executables
add_executable(run ${game_sources} src/main.cpp)
add_executable(serv ${server_sources} ${jsoncpp_sources})

# SFML
if(WIN32)
set(SFML_ROOT "D:/Utils/SFML-2.3")
set(CMAKE_MODULE_PATH "${SFML_ROOT}/cmake/Modules" ${CMAKE_MODULE_PATH})
else(WIN32)
SET(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
endif(WIN32)
find_package(SFML 2 COMPONENTS audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(run ${SFML_LIBRARIES})
endif()

# libmicrohttpd
include_directories ("${PROJECT_SOURCE_DIR}/extern/libmicrohttpd/include")
target_link_libraries(serv "${PROJECT_SOURCE_DIR}/extern/libmicrohttpd/lib/libmicrohttpd.so")

# Writing sources files
MESSAGE("Surprise motherfucker !")
MESSAGE(${game_sources})
MESSAGE("Surprise motherfucker !")
MESSAGE(${server_sources})

