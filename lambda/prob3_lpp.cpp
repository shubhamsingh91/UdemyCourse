#include <iostream>
#include <string>
#include <algorithm>
#include <random>

int get_num(const std::string &s){
    int n;
 std::cout << s << std::endl;
 std::cin >> n;
 return n;
}

int main(){

int begin_int =get_num("Start where?");
int num_n =get_num("How many?");
int rand = random();

std::cout << "I generated 5 square numbers. Do you know what each number is after multiplying it by " << rand << std::endl;

}