#include <iostream>
#include "../../utils.h"

int main() {

    int &&ref {45}; // r value reference
    print(ref);

    ref = 56;
    print(ref);

    return 0;
}