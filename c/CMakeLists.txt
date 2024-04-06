cmake_minimum_required(VERSION 3.15)
project(cc CXX)


find_package(aa)
find_package(bb)


add_library(cc src/c.cpp)
target_include_directories(cc PUBLIC include)


target_link_libraries(cc PRIVATE aa::aa bb::bb)


set_target_properties(cc PROPERTIES PUBLIC_HEADER "include/c.h")
install(TARGETS cc)
