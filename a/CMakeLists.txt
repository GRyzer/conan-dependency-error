cmake_minimum_required(VERSION 3.15)
project(aa CXX)




add_library(aa src/a.cpp)
target_include_directories(aa PUBLIC include)



set_target_properties(aa PROPERTIES PUBLIC_HEADER "include/a.h")
install(TARGETS aa)
