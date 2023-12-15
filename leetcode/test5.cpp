#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <limits.h>
#include<algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
    int cl=0;
    string::iterator it1={},it2={}; 
     set<string> set1 {};

     for (auto &c:emails){   
      it1 = c.begin();
        cl=0;
         while((*it1)!='@'){
           if(*it1=='.') {c.erase(it1);}
           if((*it1=='+')&&(cl==0)){it2=it1;cl=1;}
          it1++;
         }
         if (cl==1){
            //cout << "erasing +" << endl;
         c.erase(it2,it1);}

      //  cout << c << endl;
      }
       auto it3 = std::unique(emails.begin(), emails.end());
       
    for (auto &c: emails){
        if (c!=""){
            set1.insert(c);
        }
        cout << c<< endl;
        cout << c.size() << endl;
    }
    cout << "set sie = " << set1.size() << endl;


    return set1.size();
    }
};

int main(){
  
  Solution sol1;

  //vector<string> v1 {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
  vector<string> v2 {"fg.r.u.uzj+o.pw@kziczvh.com","r.cyo.g+d.h+b.ja@tgsg.z.com","fg.r.u.uzj+o.f.d@kziczvh.com","r.cyo.g+ng.r.iq@tgsg.z.com","fg.r.u.uzj+lp.k@kziczvh.com","r.cyo.g+n.h.e+n.g@tgsg.z.com","fg.r.u.uzj+k+p.j@kziczvh.com","fg.r.u.uzj+w.y+b@kziczvh.com","r.cyo.g+x+d.c+f.t@tgsg.z.com","r.cyo.g+x+t.y.l.i@tgsg.z.com","r.cyo.g+brxxi@tgsg.z.com","r.cyo.g+z+dr.k.u@tgsg.z.com","r.cyo.g+d+l.c.n+g@tgsg.z.com","fg.r.u.uzj+vq.o@kziczvh.com","fg.r.u.uzj+uzq@kziczvh.com","fg.r.u.uzj+mvz@kziczvh.com","fg.r.u.uzj+taj@kziczvh.com","fg.r.u.uzj+fek@kziczvh.com"};


  //cout << sol1.numUniqueEmails(v1) << endl;

  cout << sol1.numUniqueEmails(v2) << endl;


    return 0;
}