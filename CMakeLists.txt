cmake_minimum_required(VERSION 3.0)
project(Highlighter VERSION 1.0.0)


# Versioning the project
configure_file(HighlighterConfig.h.in HighlighterConfig.h)

add_executable(${PROJECT_NAME} main.cpp)


find_library(myGlewLib glew NAMES glew2 GLEW GLEW2)

if (${myGlewLib} STREQUAL "myGlewLib-NOTFOUND")
    message(FATAL_ERROR "Glew library not found")
else()
    message(STATUS "Glew library found")
    list(APPEND EXTRA_LINKS myGlewLib)
endif()

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${PROJECT_BINARY_DIR}
)

#Options
option(USE_ADDER "Use the basic adder for adding 2 float" ON)

if (USE_ADDER)
    add_subdirectory(Adder)

    list(APPEND EXTRA_LIB_DIRS  "Adder")
    list(APPEND EXTRA_INCLUDE_DIRS "Adder")
    list(APPEND EXTRA_LINKS add)

endif()


add_subdirectory(external/glfw)

target_include_directories( ${PROJECT_NAME}   PUBLIC external/glfw/include ${EXTRA_INCLUDE_DIRS} )

target_link_directories(${PROJECT_NAME} 
PUBLIC external/glfw/src
${EXTRA_LIB_DIRS}
)

list(APPEND EXTRA_LINKS glfw)
target_link_libraries(${PROJECT_NAME} ${EXTRA_LINKS})





install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/HighlighterConfig.h" DESTINATION include)
