#include <iostream>
#include <stdio.h>
using namespace std;

class Fraction{

 public:
 int num, den;

 Fraction(){};
 Fraction(int x, int y):num{x},den{y}{};
 void print(){
    cout << num << "/"<< den << endl;
 }
 friend Fraction operator*(const Fraction &f1,const Fraction &f2){
    Fraction f3;
    f3.num = f1.num*f2.num;
    f3.den = f1.den*f2.den;
    return f3;
 }
  friend Fraction operator*(const Fraction &f1, const int &x){
    Fraction f3;
    f3.num = f1.num*x;
    f3.den = f1.den;
    return f3;
 }
 friend Fraction operator*(const int &x,Fraction &f1){
    Fraction f3;
    f3.num = f1.num*x;
    f3.den = f1.den;
    return f3;
 }
 friend std::ostream& operator<<(std::ostream& out, const Fraction&f1){
    out<< f1.num <<"/"<< f1.den << endl;
    return out;
 }
  friend std::istream& operator>>(std::istream& in,  Fraction&f1){
    char c{};
    in>> f1.num >>c >> f1.den;
    return in;
 }
friend bool operator==(const Fraction&f1, const Fraction&f2){
    return ((f1.num==f2.num)&&(f1.den==f2.den));
}

friend bool operator!=(const Fraction&f1, const Fraction&f2){
    return !((f1.num==f2.num)&&(f1.den==f2.den));
}
friend bool operator<(const Fraction&f1, const Fraction&f2){
    double d1,d2;
    d1 = static_cast<double>(f1.num)/(static_cast<double>(f1.den));
    d2 = static_cast<double>(f2.num)/(static_cast<double>(f2.den));
   
    return (d1<d2);
}
friend bool operator>(const Fraction&f1, const Fraction&f2){

    return !(f1<f2);
}

 ~Fraction(){};

};

int main(){

//   Fraction f1{2,5};
//   f1.print();

//   Fraction f2{3,8};
//   f2.print();

//   Fraction f3{f1*f2};
//   f3.print();

//   Fraction f4{f1*2};
//   f4.print();

//   Fraction f5{2*f2};
//   f5.print();
  
//   Fraction f6{Fraction{1,2}*Fraction{2,3}*Fraction{3,4}};
//   f6.print();

//  Fraction f1;
//  cout<< "Enter fraction f1: ";
//  cin >> f1;

//  Fraction f2;
//  cout<< "Enter fraction f2: ";
//  cin >> f2;

//  cout << f1 << " * " << f2 << "is " << f1*f2 << endl;

  Fraction f1{3,2};
  Fraction f2{5,8};

 cout << (f1!=f2) << endl;
 cout << (f1<f2) << endl;
 cout << (f1>f2) << endl;

    return 0;
}