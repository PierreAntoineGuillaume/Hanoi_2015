cmake_minimum_required(VERSION 3.3)
project(Hanoi_2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic -o3")
set(EXECUTABLE_NAME Hanoi_2015)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

########################################################
# Linking & stuff
#########################################################
include_directories(./include)
file(GLOB Cepepes ./cepepe/*.cpp)

add_executable(Hanoi_2015 main.cpp ${Cepepes})


if (WIN32)
    add_definitions(-DGRENABLE)
    #########################################################
    # FIND OPENGL
    #########################################################

    find_package(OpenGL REQUIRED)
    if (OPENGL_FOUND)
        include_directories(${OpenGL_INCLUDE_DIRS})
        link_directories(${OpenGL_LIBRARY_DIRS})
        add_definitions(${OpenGL_DEFINITIONS})
        target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES})

    endif (OPENGL_FOUND)


    #########################################################
    # FIND SFML
    #########################################################
    set(SFML_ROOT D:/SFML2/)
    find_package(SFML 2 REQUIRED audio graphics network window system)

    if(SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
       target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
    endif()
endif(WIN32)