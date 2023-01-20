#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>    // std::min_element, std::max_element

using namespace std;


int max_of_four(int a, int b, int c, int d);


int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}

int max_of_four(int a, int b, int c, int d)
{
 
    vector<int> vec1 (4);
    vec1[0]=a;
    vec1[1]=b;
    vec1[2]=c;
    vec1[3]=d;
    int num1;
    num1 = *max_element(vec1.begin(), vec1.end());
    return num1;
}