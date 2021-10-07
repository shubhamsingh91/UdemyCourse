#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include <algorithm>

using namespace std;

// Move Zeros at the end of the array without making a copy of the array, and keeping the relative order of 
// other elements intact

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int size_ini = nums.size();

        int ii=0,jj=0;
        while(jj<size_ini)
        {
            if(nums[ii]==0)
            {
                //cout << "ii is" << ii << endl;
                
                 nums.push_back(0);
                 nums.erase(nums.begin()+ii);
            }else{
              //  cout << "incrementing ii here" << endl;
                ii++;
            }
            jj++;
            
        }



    }
};


int main()
{
    vector<int> vec1 {0,1,0,3,12};
    vector<int> vec2 {0};
    vector<int> vec3 {2,1};
    vector<int> vec4 {0,0,1};

    Solution sol1;

    sol1.moveZeroes(vec1);

    sol1.moveZeroes(vec2);
    sol1.moveZeroes(vec3);
    sol1.moveZeroes(vec4);

   for(int ii=0;ii<vec1.size();ii++)
    {
        cout << vec1[ii] << " ";

    }

 cout  << " " << endl;

   for(int ii=0;ii<vec2.size();ii++)
    {
        cout << vec2[ii] << " ";

    }

 cout  << " " << endl;

   for(int ii=0;ii<vec3.size();ii++)
    {
        cout << vec3[ii] << " ";

    }

 cout  << " " << endl;

   for(int ii=0;ii<vec4.size();ii++)
    {
        cout << vec4[ii] << " ";

    }

}