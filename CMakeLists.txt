cmake_minimum_required(VERSION 3.10)

# Устанавливаем имя проекта
project(MyProject)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_definitions(__cpp_concepts=202002L)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-builtin-macro-redefined")

# Добавляем файл BigNums.h в список включаемых директорий
include_directories(${CMAKE_SOURCE_DIR}/deps/include)

# Создаем список подпапок, в которых находятся main.cpp
set(SUBDIRS 2)


# Проходим по каждой подпапке и добавляем цель для компиляции main.cpp
foreach(SUBDIR ${SUBDIRS})
    # Компиляция main.cpp и algos.cpp
    add_executable(main_${SUBDIR} ${SUBDIR}/main.cpp)

endforeach()