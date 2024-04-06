cmake_minimum_required(VERSION 3.15)
project(bb CXX)

find_package(aa)


add_library(bb src/b.cpp)
target_include_directories(bb PUBLIC include)

target_link_libraries(bb PRIVATE aa::aa)

set_target_properties(bb PROPERTIES PUBLIC_HEADER "include/b.h")
install(TARGETS bb)
