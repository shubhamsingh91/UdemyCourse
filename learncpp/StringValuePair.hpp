#ifndef _STRINGVALUEPAIR_H_
#define _STRINGVALUEPAIR_H_

#include "Pair.hpp"
#include <string>
#include <stdio.h>
// demo for partial template specialization from Pair
template <typename T>
class StringValuePair : public Pair<std::string,T>{

using Pair<std::string,T>::Pair;

public:
StringValuePair(std::string s1,T n1):Pair<std::string ,T>(s1,n1){}

~StringValuePair(){}


};







#endif
