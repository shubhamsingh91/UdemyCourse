#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>       /* pow */

using namespace std;
// Convert Binary Number in a Linked List to Integer
// Definition for singly-linked list.

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        int decimal=0;
        vector<int> v;

        while(head!=NULL){
         v.push_back(head->val);  
          head = head->next;
        }
        std::reverse(v.begin(),v.end());
        
        for (int i=0;i<v.size();i++){
            decimal+=v[i]*pow(2,i);
        }
   return decimal;

    }
};

int main()
{



    return 0;
}