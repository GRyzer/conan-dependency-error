#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define C_EXPORT __declspec(dllexport)
#else
  #define C_EXPORT
#endif

C_EXPORT void c();
C_EXPORT void c_print_vector(const std::vector<std::string> &strings);
