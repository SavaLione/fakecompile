cmake_minimum_required (VERSION 2.6)

################################
# Вывод информации
################################
set(FC_MSG_LOGO                 "   __      _\n  / _|    | |\n | |_ __ _| | _____\n |  _/ _` | |/ / _ \\                     _ _\n | || (_| |   <  __/                    (_) |\n |_| \\__,_|_|\\_\\___|___  _ __ ___  _ __  _| | ___\n               / __/ _ \\| '_ ` _ \\| '_ \\| | |/ _ \\\n              | (_| (_) | | | | | | |_) | | |  __/\n               \\___\\___/|_| |_| |_| .__/|_|_|\\___|\n                                  | |\n                                  |_|")

set(FC_MSG_CONNECTING_LIBRARIES "Connecting libraries to the project")

set(FC_MSG_INCLUDE_LIBRARIES "Include libraries to the project")

set(FC_MSG_BUILD "Build")

set(FC_MSG_WINDOWS      "You are trying to compile the program under windows")
set(FC_MSG_UNIX         "You are trying to compile a program under *nix")

message(${FC_MSG_LOGO})

################################
# Variables
################################
set(    FC_WINDOWS 0    )
set(    FC_UNIX    0    )

set(    FC_NAME          fakecompile         )

if(MINGW)
    set(    FC_WINDOWS 1    )
    set(    FC_UNIX    0    )
    message(${FC_MSG_WINDOWS})
else()
    set(    FC_WINDOWS 0    )
    set(    FC_UNIX    1    )
    message(${FC_MSG_UNIX})
endif()

################################
# Lib
################################
message(${FC_MSG_CONNECTING_LIBRARIES})

set(    CXXOPTS_LIB_INCLUDE     "${CMAKE_SOURCE_DIR}/lib/cxxopts"                       CACHE PATH "cxxopts lib include"                     )
set(    RLUTIL_LIB_INCLUDE      "${CMAKE_SOURCE_DIR}/lib/rlutil"                        CACHE PATH "rlutil lib include"                      )

################################
# Inclu desu
################################
message(${FC_MSG_INCLUDE_LIBRARIES})

# OS Specific

if(FC_UNIX)
    include_directories(/usr/include)
    link_directories(/usr/lib)
endif()

################################
# Build
################################
message(${FC_MSG_BUILD})

if(FC_WINDOWS)
    #debug
    add_compile_options(-Wall -O0 -pipe)

    #release
    #add_compile_options(-Wall -O2 -pipe)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

if(FC_UNIX)
    #debug
    add_compile_options(-Wall -O0 -g -pipe)

    #release
    #add_compile_options(-Wall -O2 -g -lncurses -pipe)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

################################################################################################################################

################################
# app
################################

project(${FC_NAME})

################################
# Sources
################################

set(FC_HEADERS
    src/fakecompile.h
    src/compilers/tpl.h
    src/compilers/make.h
    src/compilers/cmake.h)

set(FC_SOURCES
    src/fakecompile.cpp)

################################
# Executable
################################

add_executable(${FC_NAME} ${FC_HEADERS} ${FC_SOURCES})

################################
# Link Lib
################################

target_include_directories(${FC_NAME} PUBLIC ${CXXOPTS_LIB_INCLUDE})
target_include_directories(${FC_NAME} PUBLIC ${RLUTIL_LIB_INCLUDE})