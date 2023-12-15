#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    std::string name;
    int grade;
    Student(){};
    Student(std::string n, int m=0):name{n}{}
    ~Student(){;}
};

void display(vector<Student> & list){
    
    for (auto c:list){
        cout << c.name << " : " << c.grade << endl;
    }
}

bool compareGrades(Student &s1, Student &s2){
    return (s1.grade>s2.grade);
}

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
    return;
}

void display_char_str(const char* s){
    while(*s!='\0'){
        cout << *s << " ";
        s++;
    }
}

int main(){

  vector<Student> list1;
  int num;
//   cout << "How many students? " << endl;
//   cin >> num;
  
//   for (int i=0;i<num;i++){
//    cout << "Enter the name of " << i+1 << " student: " << endl;
//    Student s;
//    cin >> s.name;
//    cout << "Enter the grade for " << s.name << endl;
//    cin >> s.grade;
//    list1.push_back(s);

//   }

    display(list1);
   std::sort(list1.begin(),list1.end(),compareGrades);
   cout << "sorted list" << endl;
   display(list1);
   int a1 = 12,b1 = 45;

   cout << "a1, b1 = " << a1 << ", " << b1 << endl;
    cout << "swapping " << endl;
    swap(a1,b1);
    cout << "a1, b1 = " << a1 << ", " << b1 << endl;

    const char* c_ptr {"Hello world"};
    display_char_str(c_ptr);
  

    return 0;
}