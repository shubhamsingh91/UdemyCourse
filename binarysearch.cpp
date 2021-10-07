#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

class Solution{

public:
    int search(vector<int>& nums, int target) {

        int temp=-1;
        for(int ii=0; ii<nums.size();ii++)
        {
               if(nums[ii]==target)
               {
                   temp=ii;
               }
        }
        return temp;
        
    }

};

int main()
{
    vector<int> vec1 {-1,0,3,5,9,12};

    Solution sol1;

    cout << sol1.search(vec1,9) << endl;


}