#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

       for (int ii=0; ii<n;ii++)
       {
           nums1[m+ii] = nums2[ii];
       } 

        sort(nums1.begin(),nums1.end());
    }
};

int main()
{
  
//    vector<int> nums1 {1,2,3,0,0,0};
//    vector<int> nums2 {2,5,6};
//    int m=3,n=3;

// vector<int> nums1 {1};
//    vector<int> nums2 {};
//    int m=1,n=0;


   vector<int> nums1 {0};
   vector<int> nums2 {1};
   int m=0,n=1;

   Solution sol1;

   sol1.merge(nums1, m, nums2, n);

    for (int ii=0; ii<m+n;ii++)
    {
       cout << nums1[ii] <<  " ";
    }


}