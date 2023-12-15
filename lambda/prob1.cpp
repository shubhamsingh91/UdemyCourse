#include<iostream>
#include<stdio.h>
#include "displayer.h"
#include <string>
#include <vector>
#include<algorithm>
#include<functional>
using namespace std;


template<typename T, typename Predicate>
std::vector<T> filterVector(const std::vector<T>& input, Predicate predicate) {
    std::vector<T> result;
    std::copy_if(input.begin(), input.end(), std::back_inserter(result), predicate);
    return result;
}

std::vector<std::string> transformVector( std::vector<string>& input, std::function<std::string( std::string&)> lambda){

    std::vector<std::string> result;

    std::transform(input.begin(),input.end(),std::back_inserter(result),lambda);
    return result;


}

int main(){

    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Example 1: Filter even numbers
    std::vector<int> evenNumbers = filterVector(numbers, [](int num) { return num % 2 == 0; });
    std::cout << "Even numbers: ";
    for (int num : evenNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example 2: Filter numbers greater than 5
    std::vector<int> greaterThanFive = filterVector(numbers, [](int num) { return num > 5; });
    std::cout << "Numbers greater than 5: ";
    for (int num : greaterThanFive) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Example 3
    std::vector<std::string> vs, vs_trans;
    vs.push_back("Hello");
    vs.push_back("World");

    vs_trans = transformVector(vs,[](std::string s){return (s+"!");});

        for (string s : vs_trans) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

}