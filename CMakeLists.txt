cmake_minimum_required(VERSION 2.8.3)
project(rhoban_random)

find_package(catkin REQUIRED COMPONENTS
  eigen)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES rhoban_random
  CATKIN_DEPENDS eigen
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  )

set(DIRECTORIES
  src/rhoban_random
  )

# Build ALL_SOURCES
set (SOURCES)
set (ALL_SOURCES)
set (PREFIXED_SOURCES)
foreach (DIRECTORY ${DIRECTORIES})
    include_directories("${CMAKE_CURRENT_SOURCE_DIR}/${DIRECTORY}")
    include (${DIRECTORY}/sources.cmake)

    foreach (SOURCE ${SOURCES})
        set (PREFIXED_SOURCES ${PREFIXED_SOURCES} ${DIRECTORY}/${SOURCE})
    endforeach (SOURCE)

    set (ALL_SOURCES ${ALL_SOURCES} ${PREFIXED_SOURCES})
endforeach (DIRECTORY)

add_library(rhoban_random
  ${ALL_SOURCES}
)
