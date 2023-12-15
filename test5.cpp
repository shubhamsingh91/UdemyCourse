#include<iostream>
#include <stdio.h>
#include"goo.h"

using namespace std;

int g_x = 5;
static int g_y = 6;
int dosomething(int x, int y);

int main(){
 
 cout << "Enter a smaller num " << endl;
 int smaller; 
 cin >> smaller;

 cout << "Enter a larger num " << endl;
 int larger;
 cin >> larger;

 if (smaller>larger){
    int temp=smaller;
    smaller=larger;
    larger=temp;   
 }
 int g_x = 45;

 cout << "The smaller value is " << smaller << endl;
 cout << "The larger value is " << larger << endl;

 cout << "::g_x = " << ::g_x << endl;
 cout << "g_x = " << g_x << endl;
 cout << "g_y = " << g_y << endl;

 cout << add(56,43) << endl;
 cout << dosomething(56,4) <<endl;

}