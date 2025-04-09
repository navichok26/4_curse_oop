cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_definitions(__cpp_concepts=202002L)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-builtin-macro-redefined")

include_directories(${CMAKE_SOURCE_DIR}/deps/include)

set(SUBDIRS 2)

foreach(SUBDIR ${SUBDIRS})
    add_executable(main_${SUBDIR} ${SUBDIR}/main.cpp)
endforeach()