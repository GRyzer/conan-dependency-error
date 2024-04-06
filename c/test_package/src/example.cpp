#include "c.h"
#include <vector>
#include <string>

int main() {
    c();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    c_print_vector(vec);
}
