#include <stdio.h>
#include <iostream>

int num8  = 34;  // dont need extern keyword here
extern const int num9 {45}; // need extern here-since const makes it internal linkage

int fun3(int x){ // accessed by other files
    return x+34;
}

static int fun4(int x){ // only accessible to this file- internal linkage (means this is internal to this file only)
    return x+3;
}

constexpr int fun5(int x){  // constexpr makes this function internal to this file
    return x+6;
}

extern constexpr int fun6(int x){  // constexpr makes this function internal to this file
    return x+7;
}