cmake_minimum_required(VERSION 3.13)
project(GuessTheWord)

set(CMAKE_CXX_STANDARD 14)
set( CMAKE_CXX_FLAGS "-Wl,--export-dynamic " )

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0 gmodule-export-2.0)

INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})

add_executable(GuessTheWord main.cpp fields.h consts.h headers.h game.h eventHandler.h dialogs.h)

TARGET_LINK_LIBRARIES(GuessTheWord ${GTK3_LIBRARIES})

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
        DEPENDS ${destination}
        COMMENT "symbolic link resources folder from ${source} => ${destination}"
)
