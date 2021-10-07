#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include <algorithm>
#include<map>
using namespace std;

// Two sum sorted array
// very expensive soluton

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {

//         vector<int> result;

//         for(int ii=0;ii<numbers.size();ii++)
//         {
//             for(int jj=ii+1;jj<numbers.size();jj++)
//             {
//                 if(numbers[ii]+numbers[jj]==target)
//                 {
//                     result.push_back(ii+1);
//                     result.push_back(jj+1);
//                     break;
//                 }

//             }

//         }
//      return result;

//     }
// };

// using Maps
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> result;
        map<int,int> m;

        int temp;

        for(int ii=0;ii<numbers.size();ii++)
        {
           temp=target-numbers[ii];

           if(m.find(temp)!=m.end())
           {
               result.push_back(m[temp]+1);
               result.push_back(ii+1);
               break;
           }
           m[numbers[ii]]=ii;


        }
     return result;

    }
};

int main()
{
    vector<int> vec1 {2,7,11,15};
    vector<int> vec2 {2,3,4};
    vector<int> vec3 {-1,0};

    vector<int> result;


Solution sol1;

 result = sol1.twoSum(vec1,9);
 cout << "result is: " << result[0] << " " << result[1] << endl; 

 result = sol1.twoSum(vec2,6);
 cout << "result is: " << result[0] << " " << result[1] << endl; 

  result = sol1.twoSum(vec3,-1);
 cout << "result is: " << result[0] << " " << result[1] << endl; 

}