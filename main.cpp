#include <iostream>
#include "stack.h"
#include "vecmath.h"

int main() {
    using namespace vecmath;
    DSAcpp::Stack<Vec3<float>> stack(10);

    for (int i = 0; i < 20; i++) {
        Vec3<float> vec(1.0f);
        stack.push(vec);
        std::cout << stack[i] << '\n';
    }

    for (int i = 20; i > 0; i--) {
        Vec3<float> vec3 = stack.pop();
        std::cout << vec3 << '\n';
    }
}
