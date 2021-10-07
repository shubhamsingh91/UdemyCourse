
#include<stdio.h>
#include<iostream>
#include<string>
#include "movie.hpp"
#include "movies.hpp"
using namespace std;

int main()
{

     
    Movies movies_list;

    movies_list.add_movie("Monster","PG",3);
    movies_list.add_movie("Big","PG-13",5);

    movies_list.display_movies();

    movies_list.increment_watched("monster",41);
    movies_list.increment_watched("Big",5);

    movies_list.display_movies();
    movies_list.add_movie("Big","PG-14",1);
    movies_list.display_movies();

}