#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

 vector<int> nums1 {84,46};
 vector<int> nums2 {84,46};
 vector<int> map{};
 vector<int>::iterator it1;

 for (int i=0; i<nums1.size(); i++){
   it1 = nums2.begin();
    int c=0;

   while(it1!=nums2.end()){
    if(nums1[i]==*it1){
        map.push_back(c);
        break;
    }
    it1++;
    c+=1;
   }

 }
 for(auto c:map){
    cout << c << " "<<endl;
 }



    return 0;
}