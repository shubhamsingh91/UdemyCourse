// long pressed name
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{

 string name ="alex";
 string typed = "aaleexa";
 bool b=false;
 string::iterator it1 = typed.begin();
 cout << "name.size = " << name.size() << endl;


 for (int i=0;i<name.size();i++){
    b=false;
    cout << "name[i] = " << name[i] << endl;
     cout << "it1 = " <<*it1 << endl;
    while((name[i]!=*it1)&&(it1!=typed.end())){
        it1++;
        cout << "it1++ = " <<*it1 << endl;
    }
    if(name[i]==*it1){
        cout << "Found!" << endl;
        it1++;
        b=true;
        cout << "it1++ = " <<*it1 << endl;

    } 
     
    }
    if(name[])

   cout << "b =" << b << endl;

    return 0;
}