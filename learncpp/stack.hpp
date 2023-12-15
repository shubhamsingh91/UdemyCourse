#ifndef _STACK_H_
#define _STACK_H_

#include <assert.h>     /* assert */
#include<vector>

using namespace std;

class Stack{
private:
 std::vector<int> arr {};
 int s; 

 public:

  Stack(){s=arr.size();}
  void reset(){arr.clear();}

  bool push(int z){
    if (arr.size()<10){
        arr.push_back(z);
        return true;
    }else{
        return false;
    }
  }

 void pop(){
    assert(arr.size()>0);
     arr.pop_back();
  }

  void print(){
    for (int i=0; i<arr.size(); i++){
     cout <<  (this->arr).at(i) << endl;
    }
  }
  

  ~Stack(){}



};



#endif