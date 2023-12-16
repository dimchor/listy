cmake_minimum_required(VERSION 3.20)
project(listy)

set(SOURCES
    source/listy.c
)

add_library(listy ${SOURCES})

target_include_directories(listy
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(listy PUBLIC c_std_11)

install(TARGETS listy
    DESTINATION lib)

add_executable(main examples/main.c)
target_link_libraries(main listy)
