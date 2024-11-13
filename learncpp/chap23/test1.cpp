#include <iostream>
#include "../../utils.h"
#include "Point2D.h"
#include "creature.h"
#include <vector>
#include <functional>

using namespace std;

int main(){
    
    print("chap-23- Templates & Classes!");
    Point2D p{23,1};
    Point2D p2{};
    print("p = ",p);

    Creature s{"Jack",p};
    print(s);
    s.moveTo(45,78);
    print(s);

    std::vector<std::reference_wrapper<int>> vec;
    int n1 = 4;
    vec.emplace_back(n1);


}