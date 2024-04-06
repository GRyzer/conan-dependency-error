#include "b.h"
#include <vector>
#include <string>

int main() {
    b();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    b_print_vector(vec);
}
