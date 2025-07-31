cmake_minimum_required(VERSION 3.10)

project(BigDataMonitor VERSION 1.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Charts PrintSupport)

file(GLOB_RECURSE SOURCE_H ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB_RECURSE SOURCE_CPP ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

set(SOURCE_FILES
    ${SOURCE_H}
    ${SOURCE_CPP}
    res/res.qrc
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Charts Qt5::PrintSupport)
