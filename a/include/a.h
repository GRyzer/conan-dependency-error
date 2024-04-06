#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define A_EXPORT __declspec(dllexport)
#else
  #define A_EXPORT
#endif

A_EXPORT void a();
A_EXPORT void a_print_vector(const std::vector<std::string> &strings);
