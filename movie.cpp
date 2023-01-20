
#include<stdio.h>
#include<iostream>
#include<string>
#include "movie.hpp"
using namespace std;

// Constructors----------------------
Movie::Movie()
{
  // cout<< "Default constructor here!" << endl;    
}

Movie:: Movie(string name_in,string rating_in,int watched_in)
 :name {name_in},rating {rating_in},watched {watched_in}
 {
  //     cout<< "Second constructor here!" << endl;    
 
 }

void Movie::set_name(string name_in)
{
    name = name_in;
}

void Movie::set_rating(string rating_in)
{
    rating = rating_in;
}

void Movie::set_watched(int watched_in)
{
    watched = watched_in;
}

string Movie::get_name()
{
    return name;
}

string Movie::get_rating()
{
    return rating;
}

int Movie::get_watched()
{
    return watched;
}

void Movie::increment_watched(int add_in)
{
    watched+=add_in;
}

// Destructor--------------------------
Movie::~Movie()
{
   //   cout<< "Destructor here!" << endl;    
 
}