#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

class Solution{

public:
    int searchInsert(vector<int>& nums, int target) {

        int temp=-1;
        for(int ii=0; ii<nums.size();ii++)
        {
               if(nums[ii]==target)
               {
                   temp=ii;
                   break;
               }else if (nums[ii]>target)
               {
                   temp=ii;
                   break;
               }else
               {
                   temp=ii+1;
               }
        }
        return temp;
        
    }

};

int main()
{
    vector<int> vec1 {-1,0,3,5,9,12};
    vector<int> vec2 {1,3,5,6};

    Solution sol1;

    cout << sol1.searchInsert(vec2,5) << endl;
    cout << sol1.searchInsert(vec2,2) << endl;
    cout << sol1.searchInsert(vec2,7) << endl;
    cout << sol1.searchInsert(vec2,0) << endl;
    cout << sol1.searchInsert(vec2,0) << endl;


}