#ifndef _TEMPLATEBASE_H_
#define _TEMPLATEBASE_H_

#include <iostream>
#include <stdio.h>
using namespace std;

template <typename T, typename N,template <typename> class base1> // example of a template template prameter, a template class is used as a template here
class templatebase{

    public:
        
        base1<N> b1;
        templatebase(T n):num1{n}{};
        void printnum(){cout << "num1 = " << num1 << endl;}
        ~templatebase(){};

    private:
        T num1;

};





#endif