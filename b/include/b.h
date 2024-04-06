#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define B_EXPORT __declspec(dllexport)
#else
  #define B_EXPORT
#endif

B_EXPORT void b();
B_EXPORT void b_print_vector(const std::vector<std::string> &strings);
