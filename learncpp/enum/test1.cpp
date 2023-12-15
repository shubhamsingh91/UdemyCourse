#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

enum class Color  {red, green, color,};

enum Pet 
{
    cat,
    dog,
    pig,
    whale,
};

std::ostream& operator<<(std::ostream& out, Pet pet){
    switch (pet)
    {
    case cat:
        cout << " cat";
        break;
     case dog:
        cout << " dog";
        break;
     case pig:
        cout << " pig";
        break;
     case whale:
        cout << " whale";
        break;          
    default:
        break;
    }
    return out;
}

namespace monster{

enum MonsterType{orcs, goblins, trolls, ogres, skeletons,};

}

int main(){
 
 Color apple {Color::red};
 Color cup {Color::green};

 Pet john {dog};

 cout << static_cast<int>(Color::red) << endl;
 Color c1 = static_cast<Color>(2);
 

 cout << "john is a " << john << endl;

   cout << static_cast<int>(cup) << endl;

 if(john==cat){
    cout << "John is a cat" << endl;
 }


 monster::MonsterType m {monster::ogres};


    return 0;
}