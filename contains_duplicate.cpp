#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include <algorithm>
#include<map>
using namespace std;

// checking if any value appears twice
// expensive solution

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
        
//         map<int,int> m;

//         for(int ii=0;ii<nums.size();ii++)
//         {
          
//           for (int jj=ii+1;jj<nums.size();jj++)
//           {
//               if(nums[jj]==nums[ii])
//               {return true;
//               break;
//               }
//           }

//         }

//         return false;


//     }
// };


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int,int> m;

        for(int ii=0;ii<nums.size();ii++)
        {
          
            if(m.find(nums[ii])!=m.end())
            {
                return true;
                break;
            }
            m[nums[ii]]=ii;

        }

        return false;


    }
};


int main()
{

    vector<int> vec1 {1,2,3,1};
    vector<int> vec2 {1,2,3,4};
    vector<int> vec3 {1,1,1,3,3,4,3,2,4,2};

    Solution sol1;

    cout << sol1.containsDuplicate(vec1) << endl;
    cout << sol1.containsDuplicate(vec2) << endl;
    cout << sol1.containsDuplicate(vec3) << endl;

}