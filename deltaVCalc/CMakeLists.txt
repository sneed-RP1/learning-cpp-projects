cmake_minimum_required(VERSION 3.5)

project(deltaVCalc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(deltaVCalc main.cpp
    DeltaVCalc.h)

include(GNUInstallDirs)
install(TARGETS deltaVCalc
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
