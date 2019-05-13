cmake_minimum_required(VERSION 3.13)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)
set( CMAKE_CXX_FLAGS "-Wl,--export-dynamic " )

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0 gmodule-export-2.0)

INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

add_executable(untitled2 main.cpp fields.h consts.h headers.h smth.h game.h eventHandlers.h)

TARGET_LINK_LIBRARIES(untitled2 ${GTK3_LIBRARIES})