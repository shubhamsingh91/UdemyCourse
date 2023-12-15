#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Average{
 private:
 std::int32_t num {0};
 std::int8_t len {0};

 public:
 Average(){};
 Average& operator+=(const int n){
    num+=n;
    len+=1;
    return *this;
 }
 double get_avg() const {
   return static_cast<double>(this->num)/static_cast<double>(this->len);
 }
 friend std::ostream& operator<<(std::ostream& out, const Average& a){
    out << a.get_avg() ;
    return out;
 }

 ~Average(){};

};


int main(){

    Average avg{};
    avg+=4;
    cout << avg << endl;
  
     avg+=8;
     cout << avg << endl;
     
     avg+=24;
     cout << avg << endl;
    
     avg+=-10;
     cout << avg << endl;

     (avg+=6)+=10;
     cout << avg << endl;
      
      Average copy{avg};
     cout << copy << endl;
   

    return 0;
}