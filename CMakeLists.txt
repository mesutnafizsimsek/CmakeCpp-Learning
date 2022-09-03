cmake_minimum_required(VERSION 3.0)
project(Highlighter)
add_executable(${PROJECT_NAME} main.cpp)


add_subdirectory(external/glfw)
add_subdirectory(Adder)

target_include_directories(${PROJECT_NAME} 
    PRIVATE Adder 
    PRIVATE external/glfw/include
)

target_link_directories(${PROJECT_NAME} 
PRIVATE Adder/ 
PRIVATE external/glfw/src
)

target_link_libraries(${PROJECT_NAME} add glfw)