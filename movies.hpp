// Movies class declaration

#include<stdio.h>
#include<iostream>
#include<string>
#include"movie.hpp"
#include<vector>

#ifndef _MOVIES_H_  // include guards  class
#define _MOVIES_H_


class Movies
{

private:

    std::vector<Movie> vec_movies;

public:


    // constructor
    Movies(); // Default constructor

    //  functions
    void add_movie(std::string name_in,std::string rating_in, int watched_in);
    void display_movies();
    void increment_watched(std::string name_in, int num_in);
    // destructor
    ~Movies();
};



#endif