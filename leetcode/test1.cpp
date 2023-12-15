// You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.

// We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.

// Return the reformatted license key.

#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<list>

using namespace std;

int main()
{
   std::string s = "2";
   int k=2;
   std::string s_new;
   std::string s_f;
   std::list<char> l_f;
   int num_c=0;

  for(int i=0;i<s.size();i++){
    if(s[i]!='-')
    {
        s_new.push_back(s[i]);
    }
  }
  for(int i=s_new.size()-1;i>-1;i--){
    l_f.push_front(toupper(s_new[i]));
    if ((num_c==k-1)&&(i!=0)){
        l_f.push_front('-');
        num_c=0;
    } else{
     num_c=num_c+1;}

  }
  std::list<char>::iterator it2 = l_f.begin();

 while(it2!=l_f.end()){
    s_f.push_back(*it2);
    it2++;
 }
 
 for(auto c:s_f){
    cout << c << " ";
 }
 cout << endl;
  



 

    return 0;
}