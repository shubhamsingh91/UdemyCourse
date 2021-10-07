// Movie class declaration

#include<stdio.h>
#include<iostream>
#include<string>
#ifndef _MOVIE_H_  // include guards  class
#define _MOVIE_H_


class Movie
{

private:

    std::string name;
    std::string rating;
    int watched;

public:


    // constructor
    Movie(); // Default constructor
    Movie(std::string name_in,std::string rating_in,int watched_in); // another constructor

    //  functions
    void set_name(std::string name_in);
    void set_rating(std::string rating_in);
    void set_watched(int watched_in);

    std::string get_name();
    std::string get_rating();
    int get_watched();
    void increment_watched(int add_in);
   


    // destructor
    ~Movie();
};



#endif