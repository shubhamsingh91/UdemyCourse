#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
   std::vector<int> twoSum(vector<int>& nums, int target) {
        
    }
};


int main()
{

    std::vector<int> nums {2,7,11,15};
  //   std::vector<int> nums {3,2,4};
   //     std::vector<int> nums {3,3};

    std::vector<int> vec;
   
   // std::vector<int> nums {2,7,11,15};

    int target = 9;
    int temp1, index2;
    std::vector<int>::iterator it;

    for (int ii=0; ii<nums.size(); ii++)
    {   
        temp1 = target-nums[ii];
        it = std::find(nums.begin()+ii+1, nums.end(),temp1);

        if (it!=nums.end())
        {
            vec.push_back(ii);
            cout << "element found!" << endl;
            index2 = it - nums.begin();
            vec.push_back(index2);
            break;
        }
    }

 // cout << "["<<vec[0] << "," << vec[1] << "]"<< endl;


  // unordered map solution

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> result;
        
//         unordered_map<int, int> hm; //key - element, value- index
        
//         for(int i = 0; i < nums.size(); i++)
//         {
            
//             if(hm.find(target - nums[i]) != hm.end()) //if target - element , in the hashmap
//             {
//                 result.push_back(hm[target - nums[i]]);
//                 result.push_back(i);
//                 break;
//             }
            
//             hm[nums[i]] = i;
//         }
//         return result;
//     }
// };

  return 0;

}