#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include <algorithm>

using namespace std;

class Solution
{
    public:
       void rotate(vector<int>& nums, int k) {
               cout << k << endl;
        
        k=k%nums.size();

            cout << k << endl;

        if(k<0){
            k+=nums.size();
        }
        reverse(nums.end()-k,nums.end());
         reverse(nums.begin(),nums.end()-k);
         reverse(nums.begin(),nums.end());
    }

};

int main()
{   

    vector<int> vec1 {1,2,3,4,5,6,7};
    int k=3;

    vector<int> vec2 {-1,-100,3,99};


    Solution sol1;
    sol1.rotate(vec1,3);
//     sol1.rotate(vec2,4);

    cout << "first element is " << vec1[0] << endl;
    cout << "last element is " << vec1[6] << endl;

//    cout << "first element is " << vec2[0] << endl;
//     cout << "last element is " << vec2[3] << endl;

}