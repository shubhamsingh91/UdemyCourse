#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
 
       vector<int> sortedSquares(vector<int>& nums) {

           vector<int> vec_out(nums.size());

           for (int ii=0; ii<nums.size(); ii++)
           {
               vec_out[ii] = abs(nums[ii]);
           }

            std::sort(vec_out.begin(), vec_out.end());

            for (int ii=0; ii<nums.size(); ii++)
           {
               vec_out[ii] = pow(vec_out[ii],2);
           }

           return vec_out;
    }
};

int main()
{  
   vector<int> vec1 {-4,-1,0,3,10};
   vector<int> vec2;
   
    Solution sol;

    vec2 = sol.sortedSquares(vec1);

for (int ii=0; ii<vec2.size(); ii++)
{
   cout << vec2[ii] << " " << endl;
}

}