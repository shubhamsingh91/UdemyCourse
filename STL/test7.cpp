// testing std::pair

#include <iostream>
#include <stdio.h>
#include "../utils.h"
#include <utility>
#include <string>

int main(){

std::pair<std::string, int> fruit;
fruit.first = "tomato";
fruit.second = 12;

print("fruits name = ", fruit.first);
print("fruits num =", fruit.second);

}